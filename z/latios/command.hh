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

#include <pokemonism/functionable.hh>

#include <pokemonism/pokemon/general/command.hh>

#include <pokemonism/latios/subscription.hh>

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

            template <class output, class objectable = pokemon::general::command<output>>
            struct callback : public functionable {
            public:     typedef int (*type)(commandable *, uint32, envelope<output, message<output>> &, subscription<pokemon::general::command<output>, envelope<output, message<output>>> &);
            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_COMMAND__HH__