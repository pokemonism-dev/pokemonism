/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */


#include "event.hh"

#include "node.hh"
#include "queue.hh"

namespace pokemonism {
    namespace gardevoir {

        gardevoir::event * event::rel(gardevoir::event * event) {
            pokemon_develop_check(event == nullptr, return nullptr);

            if (event->container != nullptr) {
                event->container->del(event);

                if (event->on() > declaration::success) {
                    if (event->node != nullptr) {
                        event->node->raise(new pokemon::exception());
                        event->node->event = nullptr;
                        event->node = allocator::del(event->node);
                        return event;
                    }
                }
            }

            if (event->node != nullptr) {
                event->node->event = nullptr;
                event->node = allocator::del(event->node);
            }

            return event;
        }

        gardevoir::event * event::dispatch(gardevoir::event * event) {
            pokemon_develop_check(event == nullptr || event->container != nullptr || event->node == nullptr, return nullptr);

            if (event->on() > declaration::success) return event;

            event->node->event = nullptr;
            event->node = allocator::del(event->node);

            return allocator::del(event);
        }
    }
}