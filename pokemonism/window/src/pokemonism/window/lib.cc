/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */


#include <pokemonism/sdk/exception.hh>

#include "lib.hh"

#include "cocoa/lib.hh"

namespace pokemonism::window {

    WindowLib * WindowLib::singleton = nullptr;

    void WindowLib::init(void) {
        pokemon_debug_check(WindowLib::singleton == nullptr, return);

        WindowLib::singleton = new WindowCocoaLib();
    }

    void WindowLib::term(void) {

    }

    WindowLib::WindowLib(void) {

    }

    WindowLib::~WindowLib(void) {

    }

}