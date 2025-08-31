/**
 * @file        pokemonism/pokemon/interface/functionable.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 31, 2025
 */

#ifndef   __POKEMONISM_POKEMON_INTERFACE_FUNCTIONABLE__HH__
#define   __POKEMONISM_POKEMON_INTERFACE_FUNCTIONABLE__HH__

namespace pokemonism {
    namespace pokemon {

        struct functionable {
        public:     typedef void (*type)(void);
        public:     type func;
        };

    }

    using functionable = pokemon::functionable;
}

#endif // __POKEMONISM_POKEMON_INTERFACE_FUNCTIONABLE__HH__
