/**
 * @file
 * @brief
 * @details
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_LATIOS_COMMAND_HH__
#define   __POKEMONISM_LATIOS_COMMAND_HH__

#include <pokemonism/latios/subscription.hh>

namespace pokemonism {
    namespace latios {
        namespace command {

            template <typename objectable>
            class subscription {
            public:     subscription(void) {}
            public:     virtual ~subscription(void) {}
            public:     subscription(const latios::command::subscription<objectable> & o) = delete;
            public:     subscription(latios::command::subscription<objectable> && o) noexcept = delete;
            public:     latios::command::subscription<objectable> & operator=(const latios::command::subscription<objectable> & o) = delete;
            public:     latios::command::subscription<objectable> & operator=(latios::command::subscription<objectable> && o) noexcept = delete;
            };
        }
    }
}

#endif // __POKEMONISM_LATIOS_COMMAND_HH__