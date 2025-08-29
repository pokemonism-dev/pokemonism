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

// #include <pokemonism/latios/general/event.hh>
// #include <pokemonism/latios/general/queue.hh>
// #include <pokemonism/latios/general/generator.hh>
// #include <pokemonism/latios/general/subscription.hh>
//
// #include <pokemonism/latios/external/event.hh>
// #include <pokemonism/latios/external/subscription.hh>
// #include <pokemonism/latios/internal/observable.hh>
//
// #include <pokemonism/psyduck/linked/list.hh>

#include <pokemonism/latios/package/pack.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {

            // subscription::node ... node, subscription
            template <class object, class objectable, class generatable = void>
            class subscription : public package::pack<object, objectable, generatable>::subscription {
            public:     bool cancel(void) override;
            public:     virtual int on(void);
            public:     const object * objectGet(void) const override { return this->target; }


            };

            template <class object, class objectable, class generatable>
            bool subscription<object, objectable, generatable>::cancel(void) {
                // TODO: IMPLEMENT THIS
                return false;
            }

            template <class object, class objectable, class generatable>
            int subscription<object, objectable, generatable>::on(void) {
                return declaration::fail;
            }

        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_SUBSCRIPTION__HH__
