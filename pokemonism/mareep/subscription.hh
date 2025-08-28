/**
 * @file        pokemonism/mareep/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 */

#ifndef   __POKEMONISM_MAREEP_SUBSCRIPTION__HH__
#define   __POKEMONISM_MAREEP_SUBSCRIPTION__HH__

namespace pokemonism {
    namespace mareep {

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

    using subscription = mareep::subscription;

}

#endif // __POKEMONISM_MAREEP_SUBSCRIPTION__HH__