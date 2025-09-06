/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_SDK_COMMAND_EVENT_GENERATOR_HH__
#define   __POKEMONISM_SDK_COMMAND_EVENT_GENERATOR_HH__

#include <pokemonism/sdk/command/event.hh>

namespace pokemonism::sdk {



    inline command::event::generator::generator(pokemonism::sdk::engine * engine) : pokemonism::sdk::event::generator(engine) {

    }

    inline command::event::generator::~generator(void) {

    }

}

#endif // __POKEMONISM_SDK_COMMAND_EVENT_GENERATOR_HH__