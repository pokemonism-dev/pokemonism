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

#include <pokemonism/window.hh>

namespace pokemonism {

    inline window::application::application(platform::window::application & adapter) : abstract::window::application(adapter) {

    }

    inline window::application::application(void) {

    }

    inline window::application::~application(void) {

    }

    inline window::application::application(const window::application & o) {

    }

    inline window::application::application(window::application && o) noexcept {

    }

    inline window::application & window::application::operator=(const window::application & o) {
        return *this;
    }

    inline window::application & window::application::operator=(window::application && o) noexcept {
        return *this;
    }

}

#endif // __POKEMONISM_WINDOW_APPLICATION_HH__