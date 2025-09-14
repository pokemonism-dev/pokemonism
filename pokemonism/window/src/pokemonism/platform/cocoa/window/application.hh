/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */

#ifndef   __POKEMONISM_APPLICATION_HH__
#define   __POKEMONISM_APPLICATION_HH__

#include <pokemonism/platform/cocoa/window.hh>

namespace pokemonism::platform::cocoa {

    inline const char * window::application::platformNameGet(void) const noexcept {
        return "cocoa";
    }

}

#endif // __POKEMONISM_APPLICATION_HH__