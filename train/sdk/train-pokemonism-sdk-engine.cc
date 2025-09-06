/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#include <pokemonism/sdk/engine.hh>



int main(int argc, char ** argv) {
    pokemonism::sdk::engine * engine = new pokemonism::sdk::engine();

    engine->on(nullptr);

    const int ret = engine->run();

    delete engine;

    return ret;
}
