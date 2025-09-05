/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 01, 2025
 */

#ifndef   __POKEMONISM_POKEMON_GENERIC_FUNCTION_HH__
#define   __POKEMONISM_POKEMON_GENERIC_FUNCTION_HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace pokemon {
        namespace generic {

            template <typename returnable, typename... argumentable>
            class function {
            public:     typedef returnable (*type)(argumentable...);
            public:     virtual returnable & operator()(argumentable...) const = 0;
            public:     function(void) {}
            public:     virtual ~function(void) {}
            public:     function(const function & o) = delete;
            public:     function(function && o) noexcept = delete;
            public:     function & operator=(const function & o) = delete;
            public:     function & operator=(function && o) noexcept = delete;
            };

        };
    }
}

#endif // __POKEMONISM_POKEMON_GENERIC_FUNCTION_HH__