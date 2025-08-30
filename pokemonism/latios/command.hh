/**
 * @file        pokemonism/latios/command.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_LATIOS_COMMAND__HH__
#define   __POKEMONISM_LATIOS_COMMAND__HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace latios {
        namespace command {

            class type {
            public:     constexpr static uint32 gen = 0;
            public:     constexpr static uint32 rel = 1;
            public:     constexpr static uint32 add = 2;
            public:     constexpr static uint32 del = 3;
            public:     constexpr static uint32 exe = 4;
            public:     constexpr static uint32 max = 5;
            public:     type(void) {}
            public:     ~type(void) {}
            public:     type(const type & o) = delete;
            public:     type(type && o) noexcept = delete;
            public:     type & operator=(const type & o) = delete;
            public:     type & operator=(type && o) noexcept = delete;
            };

            // subscription, ... subscription, envelope, object, envelope ...

            struct callback {

            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_COMMAND__HH__