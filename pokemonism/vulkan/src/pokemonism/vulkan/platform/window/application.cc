/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */


#include "application.hh"

namespace pokemonism::vulkan::platform {

    VkInstance window::application::instance = nullptr;

    VkInstance window::application::instanceGet(void) {
        return window::application::instance;
    }

    void window::application::instanceSet(VkInstance o) {
        window::application::instance = o;
    }

}