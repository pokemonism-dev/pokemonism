/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */


#include "mouse.hpp"

namespace pokemonism::window::cocoa::input {

    void Mouse::rawMouseMotionSet(bool enable) {
        pokemon_develop_throw((void)(0));
    }

    bool Mouse::rawMouseMotionSupportGet(void) const {
        return false;
    }

    // void Mouse::passthroughSet(bool enable) {
    //
    // }

}