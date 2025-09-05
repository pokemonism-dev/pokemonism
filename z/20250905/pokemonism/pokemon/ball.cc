/**
 * @file            pokemonism/pokemon/ball.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#include <pokemonism/allocator.hh>
#include <pokemonism/pokemon/faint.hh>

#include "ball.hh"

namespace pokemonism {

    // ReSharper disable once CppDFAConstantFunctionResult
    int pokemon::ball::recall(const pokemon * monster) {
        pokemon_training_check(monster == nullptr, return declaration::fail);

        printf("Bye, %s!\n", monster->name());

        delete monster;

        return declaration::success;
    }
}