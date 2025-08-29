/**
 * @file        pokemonism/latios/internal/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_COMMAND_SUBSCRIPTION__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_COMMAND_SUBSCRIPTION__HH__

// #include <pokemonism/latios/internal/subscription.hh>
// #include <pokemonism/latios/internal/command/generator.hh>

#include <pokemonism/latios/command.hh>
#include <pokemonism/latios/internal/subscription.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {
            namespace command {

                class subscription : public internal::subscription<pokemonism::command, pokemonism::command, pokemonism::command> {

                };

            }

        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_COMMAND_SUBSCRIPTION__HH__
