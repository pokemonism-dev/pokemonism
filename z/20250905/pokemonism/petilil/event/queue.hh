/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_PETILIL_EVENT_QUEUE_HH__
#define   __POKEMONISM_PETILIL_EVENT_QUEUE_HH__

#include <pokemonism.hh>

namespace pokemonism {

    inline petilil::event::queue::queue(void) : size(declaration::zero), head(nullptr), tail(nullptr) {

    }

    inline petilil::event::queue::~queue(void) {
        clear();
    }
}

#endif // __POKEMONISM_PETILIL_EVENT_QUEUE_HH__