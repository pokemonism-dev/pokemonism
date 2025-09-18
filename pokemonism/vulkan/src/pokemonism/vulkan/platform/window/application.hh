/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */

#ifndef   __POKEMONISM_VULKAN_PLATFORM_WINDOW_APPLICATION_HH__
#define   __POKEMONISM_VULKAN_PLATFORM_WINDOW_APPLICATION_HH__

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/vulkan/window.hh>

namespace pokemonism::vulkan::platform {

    inline window::application::application(void) {

    }

    inline window::application::~application(void) {

    }

    inline window::application::application(const vulkan::platform::window::application & o) {

    }

    inline window::application::application(vulkan::platform::window::application && o) noexcept {

    }

    inline vulkan::platform::window::application & window::application::operator=(const vulkan::platform::window::application & o) {
        return *this;
    }

    inline vulkan::platform::window::application & window::application::operator=(vulkan::platform::window::application && o) noexcept {
        return *this;
    }

}

#endif // __POKEMONISM_VULKAN_PLATFORM_WINDOW_APPLICATION_HH__