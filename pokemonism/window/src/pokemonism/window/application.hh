/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */

#ifndef   __POKEMONISM_WINDOW_APPLICATION_HH__
#define   __POKEMONISM_WINDOW_APPLICATION_HH__

// ReSharper disable CppUnusedIncludeDirective
#include <pokemonism/window.hh>
// ReSharper restore CppUnusedIncludeDirective

namespace pokemonism {

    inline void window::application::cancel(window::application::terminator f) {
        if (f == nullptr) f = window::application::goodbye;

        if (terminate == nullptr) terminate = f;
    }

    inline window::application::application(platform::window::application * adapter) : abstract::window::application(adapter), terminate(nullptr) {

    }

    inline window::application::application(void) : terminate(nullptr) {

    }

    inline window::application::~application(void) {

    }

}

#endif // __POKEMONISM_WINDOW_APPLICATION_HH__