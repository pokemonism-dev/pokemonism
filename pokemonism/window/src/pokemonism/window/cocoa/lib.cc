/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */


#include "lib.hh"

namespace pokemonism::window {

    WindowCocoaLib::WindowCocoaLib(void) {

    }

    WindowCocoaLib::~WindowCocoaLib(void) {

    }

    int WindowCocoaLib::lock(void) {
        return declaration::fail;
    }

    int WindowCocoaLib::unlock(void) {
        return declaration::fail;
    }

    int WindowCocoaLib::wait(void) {
        return declaration::fail;
    }

    int WindowCocoaLib::wakeup(void) {
        return declaration::fail;
    }

    int WindowCocoaLib::wait(long second, long nano) {
        return declaration::fail;
    }

    int WindowCocoaLib::wakeup(bool all) {
        return declaration::fail;
    }

}