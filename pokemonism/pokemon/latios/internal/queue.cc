/**
 * @file        pokemon/latios/internal/queue.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#include "queue.hh"

#include "event.hh"

namespace pokemon { namespace latios { namespace internal {

    void queue::push(internal::event * item) {
        if (item != nullptr && item->queueGet() == nullptr) {
            linked::list<queue, internal::event>::add(this, item);
        }
    }

    uint64 queue::on(void) {
        const uint64 limit = size;
        uint64 count = 0;
        lock();
        while (count < limit && size > 0) {
            if (internal::event * o = linked::list<queue, internal::event>::pop(this)) {
                unlock();
                count = count + 1;

                if (const int ret = o->on(nullptr); ret != internal::event::retry) {
                    delete o;
                    lock();
                    continue;
                }
                lock();
                linked::list<queue, internal::event>::push(this, o);
            }
            break;
        }
        unlock();

        return count;
    }

    void queue::clear(void) {
        on();

        linked::list<queue, internal::event>::clear(this);
    }

} } }
