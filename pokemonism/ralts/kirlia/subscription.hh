/**
 * @file            pokemonism/ralts/kirlia/subscription.hh
 * @brief           [pokemonism event lib] subscription
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_KIRLIA_SUBSCRIPTION_HH__
#define   __POKEMONISM_KIRLIA_SUBSCRIPTION_HH__

#include <pokemonism/ralts/kirlia/event.hh>

namespace pokemonism {
    namespace kirlia {

        class subscription : public kirlia::event::subscription {
        public:     subscription(void) {}
        public:     ~subscription(void) override {}
        public:     subscription(const kirlia::subscription & o) = delete;
        public:     subscription(kirlia::subscription && o) noexcept = delete;
        public:     kirlia::subscription & operator=(const kirlia::subscription & o) = delete;
        public:     kirlia::subscription & operator=(kirlia::subscription && o) noexcept = delete;
        };

    }
}
#endif // __POKEMONISM_KIRLIA_SUBSCRIPTION_HH__