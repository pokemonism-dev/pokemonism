/**
 * @file            pokemonism/interface/observable.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_INTERFACE_OBSERVABLE_HH__
#define   __POKEMONISM_INTERFACE_OBSERVABLE_HH__

namespace pokemonism {
    namespace interface {

        template <typename elementable>
        class observable {
        public:     observable(void) {}
        public:     virtual ~observable(void) {}
        public:     observable(const observable<elementable> & o) = delete;
        public:     observable(observable<elementable> && o) noexcept = delete;
        public:     observable<elementable> & operator=(const observable<elementable> & o) = delete;
        public:     observable<elementable> & operator=(observable<elementable> && o) noexcept = delete;
        };

    }

    template <typename elementable> using observable = interface::observable<elementable>;

}

#endif // __POKEMONISM_INTERFACE_OBSERVABLE_HH__