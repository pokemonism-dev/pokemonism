/**
 * @file        pokemonism/pokemon/envelope.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 30, 2025
 */

#ifndef   __POKEMONISM_POKEMON_ENVELOPE__HH__
#define   __POKEMONISM_POKEMON_ENVELOPE__HH__

#include <pokemonism/primitivable.hh>

namespace pokemonism {
    namespace pokemon {

        class envelope {
        public:     virtual const primitivable::object & peak(void) const = 0;
        public:     envelope(void) {}
        public:     virtual ~envelope(void) {}
        public:     envelope(const envelope & o) = delete;
        public:     envelope(envelope && o) noexcept = delete;
        public:     envelope & operator=(const envelope & o) = delete;
        public:     envelope & operator=(envelope && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_POKEMON_ENVELOPE__HH__
