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
    namespace gallade {

        class subscription : public virtual kirlia::subscription {
        public:     struct state {
                    public:     constexpr static const uint32 none = (0x00000000U <<  0U);
                    public:     constexpr static const uint32 gen  = (0x00000001U <<  0U);
                    public:     constexpr static const uint32 reg  = (0x00000001U <<  1U);
                    };
        protected:  uint32 status;
        public:     virtual inline uint32 check(uint32 state) { return (status & state); }
        // private:    bool cancel(void) override;
        public:     subscription(void);
        public:     ~subscription(void) override;
        public:     subscription(const gallade::subscription & o) = delete;
        public:     subscription(gallade::subscription && o) noexcept = delete;
        public:     gallade::subscription & operator=(const gallade::subscription & o) = delete;
        public:     gallade::subscription & operator=(gallade::subscription && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_SUBSCRIPTION_HH__