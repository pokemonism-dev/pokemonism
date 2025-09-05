/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_SDK_EVENT_QUEUE_HH__
#define   __POKEMONISM_SDK_EVENT_QUEUE_HH__

#include <pokemonism/sdk/event.hh>

namespace pokemonism::sdk {

    inline event::queue::queue(void) : size(declaration::zero), head(nullptr), tail(nullptr) {

    }

    inline event::queue::~queue(void) {
        clear();
    }

}

#endif // __POKEMONISM_SDK_EVENT_QUEUE_HH__