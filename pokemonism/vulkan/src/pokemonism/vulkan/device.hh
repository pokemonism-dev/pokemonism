/**
 * @file
 * @brief
 * @details
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 15, 2025
 */

#ifndef   __POKEMONISM_VULKAN_DEVICE_HH__
#define   __POKEMONISM_VULKAN_DEVICE_HH__

#include <vulkan/vulkan.h>

#include <pokemonism/vulkan.hh>
#include <pokemonism/collection/reference.hh>

#include <cstdio>
#include <pokemonism/sdk/exception.hh>
#include <pokemonism/collection/continuous.hh>
#include <pokemonism/collection/tuple/pair.hh>

namespace pokemonism::vulkan {

    class device {
    protected:  reference<VkDevice, vulkan::del> handle;
    public:     inline device(void);
    public:     inline virtual ~device(void);
    public:     inline device(const device & o);
    public:     inline device(device && o) noexcept;
    public:     inline device & operator=(const device & o);
    public:     inline device & operator=(device && o) noexcept;
    };

    inline device::device(void) : handle(nullptr) {

    }

    inline device::~device(void) {

    }

    inline device::device(const device & o) : handle(o.handle) {

    }

    inline device::device(device && o) noexcept : handle(std::move(o.handle)) {

    }

    inline device & device::operator=(const device & o) {
        if (pointof(o) != this) {
            handle = o.handle;
        }

        return *this;
    }

    inline device & device::operator=(device && o) noexcept {
        if (pointof(o) != this) {
            handle = std::move(o.handle);
        }

        return *this;
    }

}

#endif // __POKEMONISM_VULKAN_DEVICE_HH__