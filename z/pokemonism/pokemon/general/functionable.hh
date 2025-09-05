/**
 * @file        pokemonism/pokemon/general/functionable.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 31, 2025
 */

#ifndef   __POKEMONISM_POKEMON_GENERAL_FUNCTIONABLE__HH__
#define   __POKEMONISM_POKEMON_GENERAL_FUNCTIONABLE__HH__

#include <pokemonism/functionable.hh>

namespace pokemonism {
    namespace pokemon {
        namespace general {

            template <typename returnable, typename... argumentable>
            struct functionable : public pokemonism::functionable {
            public:     typedef returnable (*type)(argumentable...);
            };

        }
    }
}

#endif // __POKEMONISM_POKEMON_GENERAL_FUNCTIONABLE__HH__
