/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 01, 2025
 */

#ifndef   __POKEMONISM_LATIOS_SUBSCRIPTION_HH__
#define   __POKEMONISM_LATIOS_SUBSCRIPTION_HH__

#include <pokemonism/wattrel/subscription.hh>

namespace pokemonism {
    namespace latios {
        template <class objectable, class messageable = objectable::output, class tag = objectable::tag>
        class subscription : public virtual wattrel::subscription {
        public:     constexpr static const char * name = "interface";   // ### 20250901 | REMOVE THIS FOR DEBUG
        public:     explicit subscription(uint32 properties) : wattrel::subscription(properties) {}
        public:     subscription(void) = delete;
        public:     ~subscription(void) override {}
        public:     subscription(const subscription & o) = delete;
        public:     subscription(subscription && o) noexcept = delete;
        public:     subscription & operator=(const subscription & o) = delete;
        public:     subscription & operator=(subscription && o) noexcept = delete;
        };
    }
}

#endif // __POKEMONISM_LATIOS_SUBSCRIPTION_HH__