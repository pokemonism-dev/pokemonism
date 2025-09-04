/**
 * @file            pokemonism/subscription.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_SUBSCRIPTION_HH__
#define   __POKEMONISM_SUBSCRIPTION_HH__

#include <pokemonism.hh>

namespace pokemonism {

    class subscription {
    public:     virtual bool cancel(void) = 0;
    public:     subscription(void) {}
    public:     virtual ~subscription(void) {}
    public:     subscription(const subscription & o) = delete;
    public:     subscription(subscription && o) noexcept = delete;
    public:     subscription & operator=(const subscription & o) = delete;
    public:     subscription & operator=(subscription && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SUBSCRIPTION_HH__