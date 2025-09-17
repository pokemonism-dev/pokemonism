/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */


#include "vulkan.hh"

#include "vulkan/window.hh"

namespace pokemonism::vulkan {

    VkPhysicalDevice del(VkPhysicalDevice o) {
        return nullptr;
    }

    VkQueue del(VkQueue o) {
        return nullptr;
    }

    VkDevice del(VkDevice o) {
        if (o != nullptr) vulkan::process::DestroyDevice(o, nullptr);

        return nullptr;
    }

    VkSurfaceKHR del(VkSurfaceKHR o) {
        if (o != nullptr) vulkan::process::DestroySurfaceKHR(vulkan::platform::window::application::instanceGet(), o, nullptr);

        return nullptr;
    }

}