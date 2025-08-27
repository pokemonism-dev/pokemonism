/**
 * @file        pokemon/latios/internal/queue.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#include "queue.hh"

#include "../external/event.hh"

namespace pokemon { namespace latios { namespace internal {

    void queue::push(external::event * item) {
        if (item != nullptr && item->containerGet() == nullptr) {
            linked::list::add(this, item);
        }
    }

    uint64 queue::on(void) {
        const uint64 limit = size;
        uint64 count = 0;
        lock();
        while (count < limit && size > 0) {
            if (external::event * o = linked::list::pop<queue, external::event>(this)) {
                unlock();
                count = count + 1;

                if (const int ret = o->on(nullptr); ret != event::retry) {
                    delete o;
                    lock();
                    continue;
                }
                lock();
                linked::list::push<queue, external::event>(this, o);
            }
            break;
        }
        unlock();

        return count;
    }

    void queue::clear(void) {
        on();

        linked::list::clear<queue, external::event>(this);
    }

} } }
