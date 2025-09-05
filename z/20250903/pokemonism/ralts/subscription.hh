/**
 * @file            pokemonism/ralts/subscription.hh
 * @brief           [pokemonism's reactive lib] subscription
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_RALTS_SUBSCRIPTION_HH__
#define   __POKEMONISM_RALTS_SUBSCRIPTION_HH__

namespace pokemonism {
    namespace ralts {

        class subscription {
        public:     virtual bool cancel(void) = 0;
        public:     subscription(void) {}
        public:     virtual ~subscription(void) {}
        public:     subscription(const ralts::subscription & o) = delete;
        public:     subscription(ralts::subscription && o) noexcept = delete;
        public:     ralts::subscription & operator=(const ralts::subscription & o) = delete;
        public:     ralts::subscription & operator=(ralts::subscription && o) noexcept = delete;
        };


    }
}

#endif // __POKEMONISM_RALTS_SUBSCRIPTION_HH__