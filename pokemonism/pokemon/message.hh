/**
 * @file        pokemonism/pokemon/message.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 30, 2025
 */

#ifndef   __POKEMONISM_POKEMON_MESSAGE__HH__
#define   __POKEMONISM_POKEMON_MESSAGE__HH__

#include <primitivable.hh>

namespace pokemonism {
    namespace pokemon {

        class message {
        public:     virtual const primitivable::object & peak(void) const = 0;
        public:     message(void) {}
        public:     virtual ~message(void) {}
        public:     message(const message & o) = delete;
        public:     message(message && o) noexcept = delete;
        public:     message & operator=(const message & o) = delete;
        public:     message & operator=(message && o) noexcept = delete;
        };

    }

    using message = pokemon::message;
}

#endif // __POKEMONISM_POKEMON_MESSAGE__HH__
