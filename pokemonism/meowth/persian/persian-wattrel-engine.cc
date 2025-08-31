/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#include <pokemonism/wattrel.hh>
#include <pokemonism/wattrel/command.hh>

namespace pokemonism {
}

using namespace pokemonism;

int main(int argc, char ** argv) {
    printf("%u\n", wattrel::command::event::type::max);
    wattrel::engine * engine = new wattrel::engine();

    engine->on(nullptr);

    const int ret = engine->run();

    delete engine;

    return ret;
}
