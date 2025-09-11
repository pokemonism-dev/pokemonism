/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */


#include "event.hh"

namespace pokemonism::sdk {

    event * event::rem(event * e) {
        pokemon_develop_check(e == nullptr, return e);

        if (e->container != nullptr) {
            e->container->del(e);

            event::link * node = e->node;

            pokemon_develop_check(node == nullptr, return e);

            if (node->on() > declaration::success) node->raise(new event::exception());

            node->e = nullptr;
            delete node;
            e->node = nullptr;

            return e;
        }

        if (e->node != nullptr) {
            e->node->e = nullptr;
            delete e->node;
            e->node = nullptr;
        }

        return e;
    }

}