/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 12, 2025
 */


#include "config.hh"

#include "../platform.hh"

namespace pokemonism::window {

    WindowCocoaConfig::WindowCocoaConfig(void) : menu(false) {
        platform = WindowPlatform::cocoa;
        angle = WindowPlatform::Angle::metal;
    }
    WindowCocoaConfig::~WindowCocoaConfig(void) {

    }

}