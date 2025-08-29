/**
 * @file        pokemonism/latios/internal/queue.cc
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#include "queue.hh"

#include "event.hh"

namespace pokemonism {
    namespace latios {
        namespace internal {
            uint64 queue::on(uint64 total) {
                lock();
                const uint64 limit = size < total ? size : total;
                total = 0;
                for (uint64 i = 0; i < limit && i <size; i = i + 1) {
                    internal::event * event = collection::pop(this);
                    unlock();
                    if (event != nullptr) {
                        total = total + 1;
                        if (const int ret = event->on(); ret <= success) {
                            delete event;
                            lock();
                            continue;
                        }
                        collection::add(this, event);
                        lock();
                        continue;
                    }
                    lock();
                }
                unlock();
                return total;
            }

            void queue::clear(void) {
                collection::clear(this, *this);
            }

            internal::event * queue::pop(void) {
                return collection::pop(this, *this);
            }

            void queue::push(internal::event * event) {
                collection::add(this, event, *this);
            }

            internal::event * queue::del(internal::event * o) {
                return collection::del(this, o, *this);
            }
        }
    }
}