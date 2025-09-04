/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_POKEMON_BATTLE_HH__
#define   __POKEMONISM_POKEMON_BATTLE_HH__

#include <pokemonism/pokemon.hh>

namespace pokemonism {

    class pokemon::battle {
    public:     static pokemon * start(pokemon * monster);
    public:     battle(void) {}
    public:     virtual ~battle(void) {}
    public:     battle(const pokemon::battle & o) = delete;
    public:     battle(pokemon::battle && o) noexcept = delete;
    public:     pokemon::battle & operator=(const pokemon::battle & o) = delete;
    public:     pokemon::battle & operator=(pokemon::battle && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_POKEMON_BATTLE_HH__