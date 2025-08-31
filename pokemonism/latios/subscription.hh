/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_LATIOS_SUBSCRIPTION_HH__
#define   __POKEMONISM_LATIOS_SUBSCRIPTION_HH__

#include <pokemonism/wattrel/subscription.hh>

namespace pokemonism {
    namespace latios {

        template <class objectable, class envelopeable>
        class subscription : public wattrel::subscription {
        public:     subscription(void) {}
        public:     ~subscription(void) override {}
        public:     subscription(const subscription & o) = delete;
        public:     subscription(subscription && o) noexcept = delete;
        public:     subscription & operator=(const subscription & o) = delete;
        public:     subscription & operator=(subscription && o) noexcept = delete;
        };
    }
}

#endif // __POKEMONISM_LATIOS_SUBSCRIPTION_HH__