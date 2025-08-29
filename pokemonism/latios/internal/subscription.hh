/**
 * @file        pokemonism/latios/internal/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_SUBSCRIPTION__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_SUBSCRIPTION__HH__

#include <pokemonism/latios/general/event.hh>
#include <pokemonism/latios/general/queue.hh>
#include <pokemonism/latios/general/generator.hh>
#include <pokemonism/latios/general/subscription.hh>

#include <pokemonism/latios/external/event.hh>
#include <pokemonism/latios/external/subscription.hh>
#include <pokemonism/latios/internal/observable.hh>

#include <pokemonism/psyduck/linked/list.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {

            // subscription::node ... node, subscription
            template <class objectable, class nodeable, class generatable>
            class subscription {

            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_SUBSCRIPTION__HH__
