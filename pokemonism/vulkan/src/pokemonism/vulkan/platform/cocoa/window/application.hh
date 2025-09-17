/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 15, 2025
 */

#ifndef   __POKEMONISM_VULKAN_PLATFORM_COCOA_WINDOW_APPLICATION_HH__
#define   __POKEMONISM_VULKAN_PLATFORM_COCOA_WINDOW_APPLICATION_HH__

#include <pokemonism/vulkan/platform/cocoa/window.hh>

namespace pokemonism::vulkan::platform::cocoa {

    template <class super>
    inline const char * window::application<super>::platformNameGet(void) const noexcept {
        return windowable.platformNameGet();
    }

    template <class super>
    inline const collection::continuous<const char *> & window::application<super>::extensionGet(void) const {
        return extensions;
    }

    template <class super>
    inline const collection::continuous<const char *> & window::application<super>::layerGet(void) const {
        return layers;
    }

}

#endif // __POKEMONISM_VULKAN_PLATFORM_COCOA_WINDOW_APPLICATION_HH__