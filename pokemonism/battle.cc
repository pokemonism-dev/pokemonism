/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */


#include "battle.hh"

#include "pokemon.hh"

namespace pokemonism {

    pokemon * battle::start(pokemon * monster) {
        printf("%s: ready!\n", monster->name());
        monster->ready();
        printf("%s: fight!\n", monster->name());
        return monster->fight();
    }

    pokemon * battle::finish(pokemon * monster) {
        printf("%s: %s!\n", monster->name(), monster->cry());
        return monster;
    }
}