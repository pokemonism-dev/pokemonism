/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */


#include "link.hh"

namespace pokemonism::sdk {

    event::link * event::link::rem(event::link * o) {
        pokemon_develop_check(o == nullptr, return nullptr);

        if (event * e = o->e; e != nullptr) {
            if (e->container != nullptr) {
                e->container->del(e);

                if (e->on() > declaration::success) o->raise(new event::exception());
            }

            e->node = nullptr;
            delete e;
            o->e = nullptr;
        }

        if (o->container != nullptr) o->container->del(o);

        return o;
    }

}