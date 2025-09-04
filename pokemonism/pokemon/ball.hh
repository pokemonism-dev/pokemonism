/**
 * @file            pokemonism/pokemon/ball.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_BALL_HH__
#define   __POKEMONISM_BALL_HH__

#include <pokemonism/allocator.hh>

#include <pokemonism/pokemon.hh>

namespace pokemonism {

    // ReSharper disable once CppDFAConstantFunctionResult
    inline int pokemon::ball::recall(const pokemon * monster) {
        pokemon_training_check(monster == nullptr, return declaration::fail);

        printf("bye, %s!\n", monster->name());

        delete monster;

        return declaration::success;
    }


}

#endif // __POKEMONISM_BALL_HH__