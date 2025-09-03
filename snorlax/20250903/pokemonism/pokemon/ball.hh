/**
 * @file            pokemonism/pokemon/ball.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_POKEMON_BALL_HH__
#define   __POKEMONISM_POKEMON_BALL_HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace pokemon {
        class ball {
        public:     ball(void) {}
        public:     virtual ~ball(void) {}
        public:     ball(const pokemon::ball & o) = delete;
        public:     ball(pokemon::ball && o) noexcept = delete;
        public:     pokemon::ball & operator=(const pokemon::ball & o) = delete;
        public:     pokemon::ball & operator=(pokemon::ball && o) noexcept = delete;
        };
    }
}

#endif // __POKEMONISM_POKEMON_BALL_HH__