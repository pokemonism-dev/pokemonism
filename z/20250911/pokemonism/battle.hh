/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_BATTLE_HH__
#define   __POKEMONISM_BATTLE_HH__

#include <pokemonism.hh>

namespace pokemonism {

    class battle {
    public:     struct result {
                public:     constexpr static int unknown = declaration::unknown;
                public:     constexpr static int defeat = declaration::fail;
                public:     constexpr static int win = declaration::success;
                };
    public:     battle(void) {}
    public:     virtual ~battle(void) {}
    public:     battle(const battle & o) = delete;
    public:     battle(battle && o) noexcept = delete;
    public:     battle & operator=(const battle & o) = delete;
    public:     battle & operator=(battle && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_BATTLE_HH__