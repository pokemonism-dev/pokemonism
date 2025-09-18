/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 18, 2025
 */


#include "application.hh"

namespace pokemonism::vulkan::platform {
    vulkan::platform::window::application * vulkan::platform::window::application::gen(void) {
        if(vulkan::platform::window::application::singleton == nullptr) {
            pokemon_develop_check(platform::window::application::singleton != nullptr, return nullptr);
            vulkan::platform::window::application::singleton = new vulkan::platform::cocoa::application<pokemonism::platform::cocoa::application<vulkan::platform::window::application>>();
            platform::window::application::singleton = vulkan::platform::window::application::singleton;
        }
        return vulkan::platform::window::application::singleton;
    }
}
