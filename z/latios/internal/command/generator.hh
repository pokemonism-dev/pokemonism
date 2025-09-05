/**
 * @file        pokemonism/latios/internal/command/generator.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_COMMAND_GENERATOR__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_COMMAND_GENERATOR__HH__

#include <pokemonism/latios/command.hh>
#include <pokemonism/latios/internal/generator.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {
            namespace command {

                class generator : public internal::generator<pokemonism::command, pokemonism::command, pokemonism::command> {

                public:     explicit generator(general::engine * engine) : internal::generator<pokemonism::command, pokemonism::command, pokemonism::command>(engine) {}

                };

            }

        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_COMMAND_GENERATOR__HH__
