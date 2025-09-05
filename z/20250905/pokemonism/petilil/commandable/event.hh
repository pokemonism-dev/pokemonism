/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_PETILIL_COMMANDABLE_EVENT_HH__
#define   __POKEMONISM_PETILIL_COMMANDABLE_EVENT_HH__

#include <pokemonism/petilil.hh>

namespace pokemonism {
    inline petilil::commandable::event::event(unsigned int identifier, petilil::commandable::link * node) : petilil::event(identifier, node) {

    }

    inline petilil::commandable::event::event(void) {

    }
    inline petilil::commandable::event::~event(void) {

    }
}

#endif // __POKEMONISM_PETILIL_COMMANDABLE_EVENT_HH__