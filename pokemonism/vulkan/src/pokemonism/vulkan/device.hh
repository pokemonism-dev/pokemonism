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

#include <cstdio>
#include <pokemonism/sdk/exception.hh>
#include <pokemonism/collection/continuous.hh>
#include <pokemonism/collection/tuple/pair.hh>

namespace pokemonism::vulkan {

    class device {
    protected:  VkDevice handle;
    public:     device(void);
    public:     virtual ~device(void);
    public:     device(const device & o);
    public:     device(device && o) noexcept;
    public:     device & operator=(const device & o);
    public:     device & operator=(device && o) noexcept;
    };

}

#endif // __POKEMONISM_VULKAN_DEVICE_HH__