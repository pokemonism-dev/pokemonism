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
        public:     virtual uint32 typeGet(void) const = 0;
        public:     virtual const pokemonism::exception * exceptionGet(void) const = 0;
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
