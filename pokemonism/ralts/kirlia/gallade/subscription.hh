/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_SUBSCRIPTION_HH__
#define   __POKEMONISM_SUBSCRIPTION_HH__

#include <pokemonism.hh>

#include <pokemonism/ralts/kirlia/subscription.hh>

namespace pokemonism {
    namespace gardevoir {
        class subscription;
    }

    namespace gallade {

        class subscription : public virtual kirlia::subscription {
        protected:  gardevoir::subscription * internal;
        public:     bool cancel(void) override;
        public:     explicit subscription(gardevoir::subscription * internal) : internal(internal) {}
        public:     subscription(void) = delete;
        public:     ~subscription(void) override;
        public:     subscription(const gallade::subscription & o) = delete;
        public:     subscription(gallade::subscription && o) noexcept = delete;
        public:     gallade::subscription & operator=(const gallade::subscription & o) = delete;
        public:     gallade::subscription & operator=(gallade::subscription && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_SUBSCRIPTION_HH__