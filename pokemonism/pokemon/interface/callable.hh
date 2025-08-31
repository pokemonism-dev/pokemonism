/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 01, 2025
 */

#ifndef   __POKEMONISM_POKEMON_INTERFACE_CALLABLE_HH__
#define   __POKEMONISM_POKEMON_INTERFACE_CALLABLE_HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace pokemon {
        namespace interface {

            template <typename returnable>
            class callable {
            public:     virtual returnable operator()(void) = 0;
            public:     callable(void) {}
            public:     virtual ~callable(void) {}
            public:     callable(const callable & o) = delete;
            public:     callable(callable && o) noexcept = delete;
            public:     callable & operator=(const callable & o) = delete;
            public:     callable & operator=(callable && o) noexcept = delete;
            };

        };
    }
}

#endif // __POKEMONISM_POKEMON_INTERFACE_CALLABLE_HH__