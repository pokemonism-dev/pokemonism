/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */


#include "event.hh"

#include "node.hh"
#include "queue.hh"

namespace pokemonism {
    namespace wattrel {

        event * event::rel(wattrel::event * o) {
            if (o == nullptr) throw pokemon::exception();

            if (o->container != nullptr) {
                o->container->del(o);

                if (o->dispatch() > declaration::success) {
                    o->raise(new pokemon::exception());

                    o->node->event = nullptr;
                    o->node = allocator::del(o->node);

                    return o;
                }
            }

            o->complete();

            o->node->event = nullptr;
            o->node = allocator::del(o->node);

            return o;
        }

        int event::dispatch(void) {
            return node != nullptr ? node->dispatch() : declaration::fail;
        }

        void event::raise(pokemon::exception * e) {
            if (e == nullptr) throw pokemon::exception();

            if (container != nullptr) container->del(this);

            if (exception != nullptr) {
                allocator::del(e);
            } else {
                exception = e;
            }

            if (node != nullptr) complete();
        }

        void event::complete(void) {
            if (node != nullptr) node->complete();
        }

        event::event(uint32 id, wattrel::node * node) : container(nullptr), prev(nullptr), next(nullptr), node(node), id(id), exception(nullptr) {
            node->event = this;
        }

    }
}