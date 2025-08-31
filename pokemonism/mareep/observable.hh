/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 01, 2025
 */

#ifndef   __POKEMONISM_MAREEP_OBSERVABLE_HH__
#define   __POKEMONISM_MAREEP_OBSERVABLE_HH__

#include <pokemonism/pokemon/interface/primitivable.hh>

namespace pokemonism {
    namespace mareep {
        template <typename elementable = primitivable::object>
        class observable {
        public:     observable(void) {}
        public:     virtual ~observable(void) {}
        public:     observable(const observable & o) = delete;
        public:     observable(observable && o) noexcept = delete;
        public:     observable & operator=(const observable & o) = delete;
        public:     observable & operator=(observable && o) noexcept = delete;
        };
    }
}

#endif // __POKEMONISM_MAREEP_OBSERVABLE_HH__