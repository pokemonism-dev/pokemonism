/**
 * @file        pokemonism/latios/internal/node.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_NODE__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_NODE__HH__

// #include <pokemonism/latios/general/event.hh>
// #include <pokemonism/latios/general/queue.hh>
// #include <pokemonism/latios/general/generator.hh>
// #include <pokemonism/latios/general/subscription.hh>
//
// #include <pokemonism/latios/external/event.hh>
// #include <pokemonism/latios/external/subscription.hh>
// #include <pokemonism/latios/internal/observable.hh>
// #include <pokemonism/psyduck/linked/list.hh>

#include <pokemonism/latios/internal/pack.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {

            // subscription::node ... node, subscription
            template <class object, class objectable, class generatable = void>
            class node : public internal::pack<object, objectable, generatable>::node {

            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_EVENT__HH__
