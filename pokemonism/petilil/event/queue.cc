/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#include "../../petilil.hh"

namespace pokemonism {

    // ReSharper disable once CppDFAConstantFunctionResult
    petilil::event * petilil::event::queue::add(petilil::event * event) {
        pokemon_training_check(event == nullptr || event->container != nullptr, return event);

        collection::add(this, event, *this);

        return nullptr;
    }

    petilil::event * petilil::event::queue::del(petilil::event * event) {
        pokemon_training_check(event == nullptr || event->container != this, return event);

        collection::del(this, event, *this);

        return event;
    }

    void petilil::event::queue::clear(void) {
        collection::clear(this, petilil::event::rem, *this);
    }

    unsigned long petilil::event::queue::on(unsigned long n) {
        lock();
        const unsigned long limit = size < n ? size : n;
        for (n = 0; n < limit && n < size; n = n + 1) {
            petilil::event * event = collection::pop(this);
            unlock();
            if ((event = petilil::event::dispatch(event)) != nullptr) {
                lock();
                collection::add(this, event);
                continue;
            }
            lock();
        }
        unlock();
        return n;
    }

}