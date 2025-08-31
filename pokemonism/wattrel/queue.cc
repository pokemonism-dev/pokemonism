/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#include "queue.hh"

#include "event.hh"

namespace pokemonism {
    namespace wattrel {

        uint64 queue::on(uint64 total) {
            lock();
            const uint64 limit = total < size ? total : size;

            total = 0;

            for (uint64 i = 0; i < size && i < limit; i = i + 1) {
                wattrel::event * event = collection::pop(this);
                unlock();
                if (event != nullptr) {
                    total = total + 1;
                    if (event->dispatch() > declaration::success) {
                        lock();
                        collection::add(this, event);
                        continue;
                    }
                    event->complete();
                    delete event;
                }
                lock();
            }
            unlock();

            return total;
        }

        void queue::clear(void) {
            collection::clear(this, event::rel);
        }

        void queue::add(event * item) {
            if (item != nullptr) collection::add(this, item, *this);
        }

        void queue::del(event * item) {
            if (item != nullptr) collection::del(this, item, *this);
        }

    }
}