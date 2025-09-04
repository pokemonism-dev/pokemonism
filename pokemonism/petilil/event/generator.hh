/**
 * @file            pokemonism/petilil/event/generator.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 04, 2025
 */

#ifndef   __POKEMONISM_PETILIL_EVENT_GENERATOR_GENERATOR_HH__
#define   __POKEMONISM_PETILIL_EVENT_GENERATOR_GENERATOR_HH__

#include <pokemonism/petilil.hh>

namespace pokemonism {

    // ReSharper disable once CppParameterMayBeConstPtrOrRef
    inline petilil::event::subscription * petilil::event::generator::subscriptionRel(petilil::event::subscription * o) {
        if (o != nullptr) delete o;

        return nullptr;
    }

    inline unsigned long petilil::event::generator::on(unsigned long n) {
        return queue(n);
    }

    inline petilil::event::generator::generator(petilil::event::engine * engine) : size(declaration::zero), head(nullptr), tail(nullptr), engine(engine) {

    }


    inline petilil::event::generator::generator(void) : size(declaration::zero), head(nullptr), tail(nullptr), engine(nullptr) {

    }

    inline petilil::event::generator::~generator(void) {
        clear();

        engine = nullptr;
    }
}

#endif // __POKEMONISM_PETILIL_EVENT_GENERATOR_GENERATOR_HH__