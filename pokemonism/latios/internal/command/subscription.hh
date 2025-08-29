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
#include <pokemonism/latios/internal/pack.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {
            namespace command {

                class event;

                class subscription : public internal::pack<pokemonism::command, pokemonism::command, pokemonism::command>::subscription {
                public:     typedef int (*callback)(subscription *, uint32, event *, primitivable::object *, pokemonism::exception *);
                public:     subscription(pokemonism::command * target, uint32 properties, const callback * callbacks, uint32 n);

                };

            }

        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_COMMAND_SUBSCRIPTION__HH__
