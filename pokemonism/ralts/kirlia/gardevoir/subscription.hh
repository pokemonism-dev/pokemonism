/**
 * @file            pokemonism/ralts/kirlia/gardevoir/subscription.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_GARDEVOIR_SUBSCRIPTION_HH__
#define   __POKEMONISM_GARDEVOIR_SUBSCRIPTION_HH__

#include <pokemonism/ralts/kirlia/subscription.hh>

namespace pokemonism {

    namespace gallade {
        class subscription;
    }

    namespace gardevoir {

        class subscription : public virtual kirlia::subscription {
        protected:  gallade::subscription * internal;
        public:     bool cancel(void) override;
        public:     explicit subscription(gallade::subscription * internal) : internal(internal) {}
        public:     subscription(void) = delete;
        public:     ~subscription(void) override;
        public:     subscription(const gardevoir::subscription & o) = delete;
        public:     subscription(gardevoir::subscription && o) noexcept = delete;
        public:     gardevoir::subscription & operator=(const gardevoir::subscription & o) = delete;
        public:     gardevoir::subscription & operator=(gardevoir::subscription && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_GARDEVOIR_SUBSCRIPTION_HH__