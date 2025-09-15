/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 15, 2025
 */

#ifndef   __POKEMONISM_VULKAN_PLATFORM_COCOA_WINDOW_HH__
#define   __POKEMONISM_VULKAN_PLATFORM_COCOA_WINDOW_HH__

#include <pokemonism/vulkan/window.hh>
#include <pokemonism/platform/cocoa/window.hh>

namespace pokemonism::vulkan::platform::cocoa {

    class window : public pokemonism::platform::cocoa::window {
    public:     class application : public vulkan::platform::window::application {
                public:     static vulkan::platform::cocoa::window::application & get(void);
                protected:  pokemonism::platform::cocoa::window::application & windowable;
                protected:  collection::continuous<const char *> extensions;
                public:     inline const char * platformNameGet(void) const noexcept override;
                public:     VkInstanceCreateInfo creationGen(VkApplicationInfo & info, collection::continuous<VkExtensionProperties> & properties) override;
                public:     int run(void) override;
                public:     application(void);
                public:     ~application(void) override;
                public:     application(const vulkan::platform::cocoa::window::application & o) = delete;
                public:     application(vulkan::platform::cocoa::window::application && o) noexcept = delete;
                public:     vulkan::platform::cocoa::window::application & operator=(const vulkan::platform::cocoa::window::application & o) = delete;
                public:     vulkan::platform::cocoa::window::application & operator=(vulkan::platform::cocoa::window::application && o) noexcept = delete;
                };
    };

}

#include <pokemonism/vulkan/platform/cocoa/window/application.hh>

#endif // __POKEMONISM_VULKAN_PLATFORM_COCOA_WINDOW_HH__