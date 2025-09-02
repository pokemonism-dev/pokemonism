/**
 * @file            pokemonism/starly/subscription.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_STARLY_SUBSCRIPTION_HH__
#define   __POKEMONISM_STARLY_SUBSCRIPTION_HH__

#include <pokemonism/pokemon/event.hh>


namespace pokemonism {
    namespace starly {

        class subscription : public pokemon::event::subscription {
        public:     bool cancel(void) override = 0;
        protected:  inline subscription(void) {}
        public:     inline ~subscription(void) override {}
        public:     subscription(const starly::subscription & o) = delete;
        public:     subscription(starly::subscription && o) noexcept = delete;
        public:     starly::subscription & operator=(const starly::subscription & o) = delete;
        public:     starly::subscription & operator=(starly::subscription && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_STARLY_SUBSCRIPTION_HH__