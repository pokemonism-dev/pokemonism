/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#include <pokemonism/petilil.hh>

using namespace pokemonism;

int main(int argc, char ** argv) {
    petilil * petilil = petilil::go();

    return pokemon::ball::recall(petilil->start());
}