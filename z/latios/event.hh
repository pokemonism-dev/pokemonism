/**
 * @file        pokemonism/latios/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_EVENT__HH__
#define   __POKEMONISM_LATIOS_EVENT__HH__

#include <pokemon.hh>

namespace pokemonism {
    namespace latios {

        class event {
        public:     class type {
                    public:     constexpr static uint32     gen = 0;
                    public:     constexpr static uint32     rel = 1;
                    public:     constexpr static uint32     add = 2;
                    public:     constexpr static uint32     del = 3;
                    public:     constexpr static uint32     max = 4;
                    };
        public:     virtual uint32 eventGet(void) const = 0;
        public:     virtual const exception * exceptionGet(void) const = 0;
        public:     event(void) {}
        public:     virtual ~event(void) {}
        public:     event(const event & o) = delete;
        public:     event(event && o) noexcept = delete;
        public:     event & operator=(const event & o) = delete;
        public:     event & operator=(event && o) noexcept = delete;
        };

    }

    using event = pokemonism::latios::event;

}

#endif // __POKEMONISM_LATIOS_EVENT__HH__
