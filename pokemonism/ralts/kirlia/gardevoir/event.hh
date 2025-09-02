/**
 * @file            pokemonism/ralts/kirlia/gardevoir.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_GARDEVOIR_EVENT_HH__
#define   __POKEMONISM_GARDEVOIR_EVENT_HH__

#include <pokemonism/ralts/kirlia/event.hh>

namespace pokemonism {
    namespace gardevoir {

        class event : public kirlia::event {
        public:     event(void) {}
        public:     ~event(void) override {}
        public:     event(const gardevoir::event & o) = delete;
        public:     event(gardevoir::event && o) noexcept = delete;
        public:     gardevoir::event & operator=(const gardevoir::event & o) = delete;
        public:     gardevoir::event & operator=(gardevoir::event && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_GARDEVOIR_EVENT_HH__