/**
 * @file            pokemonism/subscription.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_SUBSCRIPTION_HH__
#define   __POKEMONISM_SUBSCRIPTION_HH__

#include <pokemonism.hh>

namespace pokemonism {

    class subscription {
    public:     struct event {
                public:     constexpr static uint32 gen         = 0;
                public:     constexpr static uint32 reg         = 1;
                public:     constexpr static uint32 del         = 2;
                public:     constexpr static uint32 rel         = 3;        // popped
                public:     constexpr static uint32 exception   = 4;
                public:     constexpr static uint32 max         = 5;
                };
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