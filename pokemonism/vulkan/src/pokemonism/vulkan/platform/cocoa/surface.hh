/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 17, 2025
 */

#ifndef   __POKEMONISM_VULKAN_PLATFORM_COCOA_SURFACE_HH__
#define   __POKEMONISM_VULKAN_PLATFORM_COCOA_SURFACE_HH__

#include <pokemonism/vulkan/surface.hh>

namespace pokemonism::vulkan::platform::cocoa {

    class surface : public vulkan::surface {
    public:     inline explicit surface(VkSurfaceKHR handle);
    public:     inline surface(void);
    public:     inline ~surface(void) override;
    public:     inline surface(const surface & o);
    public:     inline surface(surface && o) noexcept;
    public:     inline surface & operator=(const surface & o);
    public:     inline surface & operator=(surface && o) noexcept;
    };

    inline surface::surface(VkSurfaceKHR handle) : vulkan::surface(handle) {

    }

    inline surface::surface(void) {

    }

    inline surface::~surface(void) {

    }

    inline surface::surface(const surface & o) : vulkan::surface(o) {

    }

    inline surface::surface(surface && o) noexcept : vulkan::surface(std::move(o)) {

    }

    inline surface & surface::operator=(const surface & o) {
        if (pointof(o) != this) {
            vulkan::surface::operator=(o);
        }
        return *this;
    }

    inline surface & surface::operator=(surface && o) noexcept {
        if (pointof(o) != this) {
            vulkan::surface::operator=(std::move(o));
        }
        return *this;
    }

}

#endif // __POKEMONISM_VULKAN_PLATFORM_COCOA_SURFACE_HH__