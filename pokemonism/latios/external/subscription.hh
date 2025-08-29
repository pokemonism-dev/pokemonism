/**
 * @file        pokemonism/latios/external/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_EXTERNAL_SUBSCRIPTION__HH__
#define   __POKEMONISM_LATIOS_EXTERNAL_SUBSCRIPTION__HH__

#include <pokemonism/mareep.hh>

namespace pokemonism {
    namespace latios {
        namespace external {

            template <class objectable>
            class subscription : public pokemonism::subscription {
            public:     bool cancel(void) override = 0;
            public:     virtual const objectable * objectGet(void) const = 0;
            public:     subscription(void) {}
            public:     ~subscription(void) override {}
            public:     subscription(const subscription<objectable> & o) = delete;
            public:     subscription(subscription<objectable> && o) noexcept = delete;
            public:     subscription<objectable> & operator=(const subscription<objectable> & o) = delete;
            public:     subscription<objectable> & operator=(subscription<objectable> && o) noexcept = delete;
            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_EXTERNAL_SUBSCRIPTION__HH__