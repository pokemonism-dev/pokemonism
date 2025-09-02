/**
 * @file            pokemonism/ralts/observable.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_RALTS_OBSERVABLE_HH__
#define   __POKEMONISM_RALTS_OBSERVABLE_HH__

#include <pokemonism/pokemon/interface/primitivable.hh>

namespace pokemonism {
    namespace ralts {

        template <typename elementable = pokemon::primitivable::object>
        class observable {
        public:     typedef elementable     element;
        public:     observable(void) {}
        public:     virtual ~observable(void) {}
        public:     observable(const ralts::observable<elementable> & o) = delete;
        public:     observable(ralts::observable<elementable> && o) noexcept = delete;
        public:     ralts::observable<elementable> & operator=(const ralts::observable<elementable> & o) = delete;
        public:     ralts::observable<elementable> & operator=(ralts::observable<elementable> && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_RALTS_OBSERVABLE_HH__