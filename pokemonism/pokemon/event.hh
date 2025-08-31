/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_EVENT_HH__
#define   __POKEMONISM_EVENT_HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace pokemon {
        class event {
        public:     struct type {
                    public:     constexpr static uint32 gen = 0;
                    public:     constexpr static uint32 rel = 1;
                    public:     constexpr static uint32 add = 2;
                    public:     constexpr static uint32 del = 3;
                    public:     constexpr static uint32 max = 4;
                    };
        public:     virtual uint32 eventGet(void) const = 0;
        public:     event(void) {}
        public:     virtual ~event(void) {}
        public:     event(const event & o) = delete;
        public:     event(event && o) noexcept = delete;
        public:     event & operator=(const event & o) = delete;
        public:     event & operator=(event && o) noexcept = delete;
        };
    }
}

#endif // __POKEMONISM_EVENT_HH__