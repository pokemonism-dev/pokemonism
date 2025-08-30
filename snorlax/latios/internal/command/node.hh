/**
 * @file        pokemonism/latios/internal/command/node.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_COMMAND_NODE__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_COMMAND_NODE__HH__

// #include <pokemonism/latios/general/event.hh>
// #include <pokemonism/latios/general/queue.hh>
// #include <pokemonism/latios/general/generator.hh>
// #include <pokemonism/latios/general/subscription.hh>
//
// #include <pokemonism/latios/external/event.hh>
// #include <pokemonism/latios/external/subscription.hh>
// #include <pokemonism/latios/internal/observable.hh>
// #include <pokemonism/psyduck/linked/list.hh>

#include <pokemonism/latios/package/pack.hh>
#include <pokemonism/latios/internal/node.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {
            namespace command {
                class node : public internal::node<pokemonism::command, pokemonism::command, pokemonism::command> {

                };
            }

            // subscription::node ... node, subscription


        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_COMMAND_NODE__HH__
