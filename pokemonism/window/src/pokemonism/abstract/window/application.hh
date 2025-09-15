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

    inline void abstract::window::application::nameSet(const char * s) {
        name = s;
    }

    inline void abstract::window::application::majorSet(unsigned int v) {
        major = v;
    }

    inline void abstract::window::application::minorSet(unsigned int v) {
        minor = v;
    }

    inline void abstract::window::application::revisionSet(unsigned int v) {
        revision = v;
    }

}

#endif // __POKEMONISM_ABSTRACT_WINDOW_APPLICATION_HH__