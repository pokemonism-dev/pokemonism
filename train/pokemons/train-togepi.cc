/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#include <pokemonism/pokemons/togepi.hh>
#include <pokemonism/trainers/cynthia.hh>

using namespace pokemonism;
using namespace pokemonism::trainers;

int main(int argc, char ** argv) {
    pokemons::togepi<cynthia> * togepi = cynthia::gotcha<pokemons::togepi<cynthia>>();

    togepi->ready();

    // pokemons::togepi<cynthia>::command

    return cynthia::recall(togepi->go());
}
