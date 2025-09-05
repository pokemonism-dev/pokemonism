/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_BATTLE_HH__
#define   __POKEMONISM_BATTLE_HH__

#include <pokemonism.hh>

#include "sdk/sync.hh"

namespace pokemonism {

    class pokemon;

    class battle : public pokemonism::sdk::sync {
    public:     static pokemon * start(pokemon * monster);
    public:     battle(void) {}
    public:     ~battle(void) override {}
    public:     battle(const battle & o) = delete;
    public:     battle(battle && o) noexcept = delete;
    public:     battle & operator=(const battle & o) = delete;
    public:     battle & operator=(battle && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_BATTLE_HH__