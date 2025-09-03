/**
 * @file            pokemonism/meowth/petilil.cc
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */


#include "petilil.hh"

#include <pokemonism/petilil.hh>
#include <pokemonism/event.hh>

using namespace pokemonism;

int main(int argc, char ** argv) {
    {
        meowth::randomizer randomize;
        printf("randomized number => %ld\n", primitivable::to<int64>(randomize()));
    }

    event::callback<meowth::randomizer> callback([](const meowth::randomizer & o, uint32 type, meowth::randomizer::envelope & envelope) {

    });

    // petilil::command::event::callback::set<meowth::randomizer, primitivable>::gen();








    {
        meowth::randomizer randomize(1004);
        printf("randomized number => %ld\n", primitivable::to<int64>(randomize()));
    }

    return 0;
}
