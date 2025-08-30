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

#include <pokemon/exception.hh>

namespace pokemonism {
    namespace pokemon {

        class message : public primitivable::object {
        public:     virtual message * pop(void) const = 0;
        public:     virtual const message * peak(void) const = 0;
        public:     virtual const exception * exceptionGet(void) const  = 0;
        public:     message(void) {}
        public:     ~message(void) override {}
        public:     message(const message & o) = delete;
        public:     message(message && o) noexcept = delete;
        public:     message & operator=(const message & o) = delete;
        public:     message & operator=(message && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_POKEMON_MESSAGE__HH__
