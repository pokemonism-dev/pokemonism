/**
 * @file            pokemonism/ralts/kirlia/gardevoir/queue.cc
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */


#include "queue.hh"

#include "event.hh"

namespace pokemonism {
    namespace gardevoir {

        uint64 queue::on(uint64 total) {
            pokemon_develop_check(total == 0, return declaration::zero);

            lock();
            const uint64 limit = size < total ? size : total;
            for (total = 0; total < size && total < limit; total = total + 1) {
                gardevoir::event * event = collection::pop(this);
                unlock();
                if (event != nullptr) {
                    event = gardevoir::event::dispatch(event);
                    if (event != nullptr) {
                        lock();
                        collection::add(this, event);
                        continue;
                    }
                }
                lock();
            }
            unlock();

            return total;
        }

        void queue::clear(void) {
            collection::clear(this, gardevoir::event::rel);
        }

        void queue::add(gardevoir::event * event) {
            if (event != nullptr) collection::add(this, event, *this);
        }

        void queue::del(gardevoir::event * event) {
            if (event != nullptr) collection::del(this, event, *this);
        }

        queue::~queue(void) {
            collection::clear(this, gardevoir::event::rel);
        }

    }
}
