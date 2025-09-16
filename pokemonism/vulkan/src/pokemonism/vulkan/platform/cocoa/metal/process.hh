/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 17, 2025
 */

#ifndef   __POKEMONISM_PROCESS_HH__
#define   __POKEMONISM_PROCESS_HH__

#include <pokemonism/vulkan.hh>

#include <pokemonism/vulkan/process.hh>
#include <pokemonism/vulkan/platform/cocoa/metal.hh>

namespace pokemonism::vulkan::platform::cocoa::metal {

    struct process {
    public:     typedef VkResult (*PFN_vkCreateMetalSurfaceEXT)(VkInstance, const VkMetalSurfaceCreateInfoEXT *, const VkAllocationCallbacks *, VkSurfaceKHR *);
    public:     inline static VkResult vkCreateMetalSurfaceEXT(VkInstance instance, const VkMetalSurfaceCreateInfoEXT * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface);
    public:     constexpr static PFN_vkCreateMetalSurfaceEXT CreateMetalSurfaceEXT = cocoa::metal::process::vkCreateMetalSurfaceEXT;
    };

    inline VkResult process::vkCreateMetalSurfaceEXT(VkInstance instance, const VkMetalSurfaceCreateInfoEXT * pCreateInfo, const VkAllocationCallbacks * pAllocator, VkSurfaceKHR * pSurface) {
        if (const PFN_vkCreateMetalSurfaceEXT func = vulkan::process::get<PFN_vkCreateMetalSurfaceEXT>(instance, "vkCreateMetalSurfaceEXT"); func != nullptr) {
            return func(instance, pCreateInfo, pAllocator, pSurface);
        }

        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }



}

#endif // __POKEMONISM_PROCESS_HH__