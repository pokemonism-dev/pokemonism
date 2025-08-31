/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */


#include "node.hh"

#include "event.hh"
#include "queue.hh"
#include "subscription.hh"

namespace pokemonism {
    namespace wattrel {

        node * node::rel(node * o) {
            if (o == nullptr) throw pokemon::exception();

            if (wattrel::event * event = o->event; event != nullptr) {
                if (event->container != nullptr) {
                    event->container->del(event);

                    if (o->dispatch() > declaration::success) {
                        o->raise(new pokemon::exception());

                        o->event->node = nullptr;
                        o->event = allocator::del(o->event);

                        if (o->container != nullptr) o->container->del(o);

                        return o;
                    }
                }

                o->event->node = nullptr;
                o->event = allocator::del(o->event);
            }

            o->complete();

            if (o->container != nullptr) o->container->del(o);

            return o;
        }

        node::node(wattrel::subscription * subscription) : container(nullptr), prev(nullptr), next(nullptr), event(nullptr) {
            if (subscription != nullptr) subscription->add(this);
        }

        int node::dispatch(void) {
            return container != nullptr ? container->dispatch(this) : declaration::success;
        }

        void node::raise(pokemon::exception * e) {
            if (e == nullptr) throw pokemon::exception();

            event->raise(e);
        }

        void node::complete(void) {
            if (container != nullptr) container->complete(this);
        }

    }
}