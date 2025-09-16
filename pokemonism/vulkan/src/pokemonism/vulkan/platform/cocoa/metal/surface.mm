/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 17, 2025
 */

#include "surface.hh"

#include "process.hh"

namespace pokemonism::vulkan::platform::cocoa::metal {

    VkMetalSurfaceCreateInfoEXT surface::createInformationGen(NSView * view) {
        pokemon_develop_check(view == nil, return {});

        VkMetalSurfaceCreateInfoEXT info;

        @autoreleasepool {
            CAMetalLayer * layer = [CAMetalLayer layer];
            view.wantsLayer = YES;
            view.layer = layer;

            info.sType = VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT;
            info.pNext = nullptr;
            info.flags = declaration::none;
            info.pLayer = layer;
        }

        return info;
    }

    cocoa::metal::surface surface::gen(VkInstance instance, NSView * view, const VkAllocationCallbacks * pAllocator) {
        VkMetalSurfaceCreateInfoEXT info = createInformationGen(view);

        if(info.pLayer != nullptr) {
            if(VkSurfaceKHR handle = nullptr; cocoa::metal::process::CreateMetalSurfaceEXT(instance, pointof(info), pAllocator, pointof(handle)) == VK_SUCCESS) {
                return cocoa::metal::surface(handle);
            }
        }

        return cocoa::metal::surface();
    }

}