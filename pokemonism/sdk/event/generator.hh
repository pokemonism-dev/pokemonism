/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_SDK_EVENT_GENERATOR_HH__
#define   __POKEMONISM_SDK_EVENT_GENERATOR_HH__

#include <pokemonism/sdk/event.hh>

namespace pokemonism::sdk {

    inline unsigned long event::generator::on(unsigned long n) {
        return queue(n);
    }

    inline event::generator::generator(pokemonism::sdk::engine * engine) : size(declaration::zero), head(nullptr), tail(nullptr), engine(engine) {
        pokemon_develop_check(engine == nullptr, (void)(0));
    }

    inline event::generator::~generator(void) {
        clear();

        engine = nullptr;
    }

}

#endif // __POKEMONISM_SDK_EVENT_GENERATOR_HH__