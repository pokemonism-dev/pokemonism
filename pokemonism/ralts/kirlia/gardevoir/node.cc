/**
 * @file            pokemonism/ralts/kirlia/gardevoir/node.cc
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#include "node.hh"

#include "event.hh"
#include "queue.hh"

namespace pokemonism {
    namespace gardevoir {

        gardevoir::node * node::rem(gardevoir::node * o) {
            pokemon_develop_check(o == nullptr, return nullptr);

            if (o->event != nullptr) {
                gardevoir::event * event = o->event;
                if (event->container != nullptr) {
                    event->container->del(event);

                    if (o->container != nullptr) {
                        if (o->container->on(o) > declaration::success) {
                            o->exception = allocator::del(o->exception);
                            o->exception = new pokemon::exception();
                            o->container->raise(o);
                        }
                    }
                }
                event->node =  nullptr;
                o->event = allocator::del(o->event);
            }

            return o;
        }

    }
}