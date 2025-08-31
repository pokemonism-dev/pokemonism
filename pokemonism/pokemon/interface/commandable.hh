/**
 * @file        pokemonism/pokemon/interface/commandable.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 30, 2025
 */

#ifndef   __POKEMONISM_POKEMON_INTERFACE_COMMANDABLE__HH__
#define   __POKEMONISM_POKEMON_INTERFACE_COMMANDABLE__HH__

#include <pokemonism/pokemon/interface/primitivable.hh>

namespace pokemonism {
    namespace pokemon {
        class commandable {
        public:     virtual primitivable::object * operator()(void) = 0;
        public:     inline commandable(void) {}
        public:     inline virtual ~commandable(void) {}
        public:     commandable(const commandable & o) = delete;
        public:     commandable(commandable && o) noexcept = delete;
        public:     commandable & operator=(const commandable & o) = delete;
        public:     commandable & operator=(commandable && o) noexcept = delete;
        };
    }
    using commandable = pokemon::commandable;
}

#endif // __POKEMONISM_POKEMON_INTERFACE_COMMANDABLE__HH__s