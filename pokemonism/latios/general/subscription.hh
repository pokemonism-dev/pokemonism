/**
 * @file        pokemonism/latios/general/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_GENERAL_SUBSCRIPTION__HH__
#define   __POKEMONISM_LATIOS_GENERAL_SUBSCRIPTION__HH__

#include <pokemonism/latios/external/subscription.hh>
#include <pokemonism/latios/general/event.hh>

namespace pokemonism {
    namespace latios {
        namespace general {

            class event;
            class node;

            class subscription : public virtual pokemonism::subscription {
            public:     virtual general::node * nodeGen(uint32 type) = 0;
            public:     virtual general::event * eventOn(uint32 type) { throw pokemonism::exception(); }

            public:     subscription(void) {}
            public:     ~subscription(void) override {}
            public:     subscription(const subscription & o) = delete;
            public:     subscription(subscription && o) noexcept = delete;
            public:     subscription & operator=(const subscription & o) = delete;
            public:     subscription & operator=(subscription && o) noexcept = delete;
            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_GENERAL_SUBSCRIPTION__HH__
