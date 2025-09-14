/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 15, 2025
 */

#ifndef   __POKEMONISM_ABSTRACT_WINDOW_APPLICATION_HH__
#define   __POKEMONISM_ABSTRACT_WINDOW_APPLICATION_HH__

#include <pokemonism/window.hh>

namespace pokemonism::abstract {

    inline int abstract::window::application::run(void) {
        return adapter.run();
    }

}

#endif // __POKEMONISM_ABSTRACT_WINDOW_APPLICATION_HH__