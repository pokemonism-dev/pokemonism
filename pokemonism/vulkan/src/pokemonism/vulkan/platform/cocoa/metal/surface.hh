/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 17, 2025
 */

#ifndef   __POKEMONISM_VULKAN_PLATFORM_COCOA_METAL_SURFACE_HH__
#define   __POKEMONISM_VULKAN_PLATFORM_COCOA_METAL_SURFACE_HH__

#include <vulkan/vulkan.h>

#include <pokemonism/vulkan/platform/cocoa/metal.hh>
#include <pokemonism/vulkan/platform/cocoa/surface.hh>

#ifndef   __OBJC__
typedef void NSView;
#endif // __OBJC__

namespace pokemonism::vulkan::platform::cocoa::metal {

    class surface : public cocoa::surface {
    public:     static VkMetalSurfaceCreateInfoEXT createInformationGen(NSView * view);
    public:     static cocoa::metal::surface gen(VkInstance instance, NSView * view, const VkAllocationCallbacks * pAllocator = nullptr);
    public:     inline explicit surface(VkSurfaceKHR handle);
    public:     inline surface(void);
    public:     inline ~surface(void) override;
    public:     inline surface(const surface & o);
    public:     inline surface(surface && o) noexcept;
    public:     inline surface & operator=(const surface & o);
    public:     inline surface & operator=(surface && o) noexcept;
    };

    inline surface::surface(VkSurfaceKHR handle) : cocoa::surface(handle) {

    }

    inline surface::surface(void) {

    }

    inline surface::~surface(void) {

    }

    inline surface::surface(const surface & o) : cocoa::surface(o) {

    }

    inline surface::surface(surface && o) noexcept : cocoa::surface(std::move(o)) {

    }

    inline surface & surface::operator=(const surface & o) {
        if (pointof(o) != this) {
            cocoa::surface::operator=(o);
        }
        return *this;
    }

    inline surface & surface::operator=(surface && o) noexcept {
        if (pointof(o) != this) {
            cocoa::surface::operator=(std::move(o));
        }
        return *this;
    }

}

#endif // __POKEMONISM_VULKAN_PLATFORM_COCOA_METAL_SURFACE_HH__