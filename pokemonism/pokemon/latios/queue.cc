/**
 * @file        pokemon/latios/queue.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#include "queue.hh"

#include "event.hh"

namespace pokemon { namespace latios {
    uint64 queue::on(void) {
        const uint64 limit = size;
        uint64 count = 0;
        lock();
        while (count < limit && size > 0) {
            event * e = linked::list::pop<queue, event>(this);
            if (e) {
                unlock();
                count = count + 1;
                e = e->on();
                lock();
                if (e != nullptr) linked::list::push<queue, event>(this, e);
                continue;
            }
            break;
        }
        unlock();

        return count;
    }

    void queue::clear(void) {
        on();

        linked::list::clear<queue, event>(this, event::cancel);
    }
} }
