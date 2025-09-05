/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */


#include "trainerizable.hh"

#include "pokemon.hh"

namespace pokemonism {

    trainerizable * trainerizable::singleton = nullptr;

    int trainerizable::recall(pokemon * monster) {
        pokemon::center::heal(monster);
        printf("%s: you did it, %s!\n", name(), monster->name());

        return monster->resultGet();
    }

}