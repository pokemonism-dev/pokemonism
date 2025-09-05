/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */


#include "queue.hh"

namespace pokemonism::sdk {

    unsigned long event::queue::on(unsigned long n) {
        lock();
        const unsigned long limit = n;
        for (n = 0; n < limit && n < size; n = n + 1) {
            event * e = collection::pop(this);
            unlock();
            if (e != nullptr) {
                if ((e = event::dispatch(e)) != nullptr) {
                    lock();
                    collection::add(this, e);
                    continue;
                }
            }
            lock();
        }
        unlock();

        return n;
    }

    // ReSharper disable once CppDFAConstantFunctionResult
    event * event::queue::add(event * e) {
        pokemon_develop_check(e == nullptr || e->container != nullptr, return e);

        collection::add(this, e, *this);

        return nullptr;
    }

    event * event::queue::del(event * e) {
        pokemon_develop_check(e == nullptr || e->container != this, return e);

        collection::del(this, e, *this);

        return e;
    }

    void event::queue::clear(void) {
        collection::clear(this, event::dispatch, *this);
    }

}