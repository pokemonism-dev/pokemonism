/**
 * @file        pokemonism/latios/general/event.cc
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#include "event.hh"

#include "queue.hh"

namespace pokemonism {
    namespace latios {
        namespace general {

            event::~event(void) {
                if (container != nullptr) container->del(this);
            }

        }
    }
}