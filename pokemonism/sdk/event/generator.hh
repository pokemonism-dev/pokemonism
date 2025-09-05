/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_EVENT_GENERATOR_HH__
#define   __POKEMONISM_EVENT_GENERATOR_HH__

#include <pokemonism/sdk/event.hh>

namespace pokemonism::sdk {

    inline event::generator::generator(event::engine * engine) : size(declaration::zero), head(nullptr), tail(nullptr), engine(engine) {
        pokemon_develop_check(engine == nullptr, (void)(0));
    }

    inline event::generator::~generator(void) {
        clear();

        engine = nullptr;
    }

}

#endif // __POKEMONISM_EVENT_GENERATOR_HH__