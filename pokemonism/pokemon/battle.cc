/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#include "battle.hh"

namespace pokemonism {

    void pokemon::battle::fight(pokemon * monster) {
        pokemon_training_check(monster == nullptr, return);

        printf("Hi %s!\n", monster->name());

        monster->start();

        monster->resultSet(monster->fight());
    }
}