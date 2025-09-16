/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 17, 2025
 */

#ifndef   __POKEMONISM_VULKAN_SURFACE_HH__
#define   __POKEMONISM_VULKAN_SURFACE_HH__

#include <pokemonism/vulkan.hh>

#include <pokemonism/collection/reference.hh>

namespace pokemonism::vulkan {

    class surface {
    protected:  reference<VkSurfaceKHR, vulkan::del> handle;
    public:     inline explicit surface(VkSurfaceKHR handle);
    public:     inline surface(void);
    public:     inline virtual ~surface(void);
    public:     inline surface(const surface & o);
    public:     inline surface(surface && o) noexcept;
    public:     inline surface & operator=(const surface & o);
    public:     inline surface & operator=(surface && o) noexcept;
    };

    inline surface::surface(VkSurfaceKHR handle) : handle(handle) {

    }

    inline surface::surface(void) {

    }

    inline surface::~surface(void) {

    }

    inline surface::surface(const surface & o) : handle(o.handle) {

    }

    inline surface::surface(surface && o) noexcept : handle(std::move(o.handle)) {

    }

    inline surface & surface::operator=(const surface & o) {
        if (pointof(o) != this) {
            handle = o.handle;
        }

        return *this;
    }

    inline surface & surface::operator=(surface && o) noexcept {
        if (pointof(o) != this) {
            handle = std::move(o.handle);
        }

        return *this;
    }

}

#endif // __POKEMONISM_VULKAN_SURFACE_HH__