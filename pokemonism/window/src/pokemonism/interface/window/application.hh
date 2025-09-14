/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 14, 2025
 */

#ifndef   __POKEMONISM_INTERFACE_WINDOW_APPLICATION_HH__
#define   __POKEMONISM_INTERFACE_WINDOW_APPLICATION_HH__

#include <pokemonism/interface/window.hh>

namespace pokemonism::interface {

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

#endif // __POKEMONISM_INTERFACE_WINDOW_APPLICATION_HH__