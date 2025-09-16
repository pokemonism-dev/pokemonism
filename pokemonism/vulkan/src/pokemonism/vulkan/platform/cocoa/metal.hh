/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 17, 2025
 */

#ifndef   __POKEMONISM_METAL_HH__
#define   __POKEMONISM_METAL_HH__

#import <QuartzCore/CAMetalLayer.h>
#import <Cocoa/Cocoa.h>

#include <pokemonism/vulkan.hh>

#ifdef __OBJC__
@class CAMetalLayer;
#else
typedef void CAMetalLayer;
#endif

typedef VkFlags VkMetalSurfaceCreateFlagsEXT;

typedef struct VkMetalSurfaceCreateInfoEXT {
public:     VkStructureType                 sType;
public:     const void *                    pNext;
public:     VkMetalSurfaceCreateFlagsEXT    flags;
public:     const CAMetalLayer *            pLayer;
public:     VkMetalSurfaceCreateInfoEXT(void) {
                sType = VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT;
                pNext = nullptr;
                flags = 0;
                pLayer = nullptr;
            }
public:     explicit VkMetalSurfaceCreateInfoEXT(const CAMetalLayer * layer) {
                sType = VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT;
                pNext = nullptr;
                flags = 0;
                pLayer = layer;
            }
} VkMetalSurfaceCreateInfoEXT;

namespace pokemonism::vulkan::platform::cocoa::metal {
}

#endif // __POKEMONISM_METAL_HH__