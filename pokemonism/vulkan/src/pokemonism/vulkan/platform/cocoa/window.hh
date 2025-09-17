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

#include <Cocoa/Cocoa.h>

#include <pokemonism/vulkan/window.hh>
#include <pokemonism/platform/cocoa/window.hh>

/**
 * 이 뷰는 불칸 렌더링을 위한 메탈 레이어를 제공하는 역할을 합니다.
 */
@interface PokemonismVulkanView : NSView
@end


namespace pokemonism::vulkan::platform::cocoa {

    class window : public pokemonism::platform::cocoa::window {
    public:     template <class super = pokemonism::platform::cocoa::window::application<vulkan::platform::window::application>>
                class application : public vulkan::platform::window::application {
                protected:  static vulkan::platform::cocoa::window::application<super> * singleton;
                public:     static vulkan::platform::cocoa::window::application<super> * get(void);
                protected:  pokemonism::platform::cocoa::window::application<super> * windowable;
                protected:  collection::continuous<const char *> extensions;
                protected:  collection::continuous<const char *> layers;
                protected:  vulkan::extension::debug::callback debugger;
                public:     void debugSet(vulkan::extension::debug::callback callback) override;
                public:     vulkan::extension::debug::callback debugGet(void) const override;
                public:     VkInstanceCreateInfo creationGen(VkApplicationInfo & info, const collection::continuous<VkExtensionProperties> & extensionSet, const collection::continuous<VkLayerProperties> & layerSet) override;
                public:     void extensionCat(const char * name) override;
                public:     void layerCat(const char * name) override;
                public:     inline const char * platformNameGet(void) const noexcept override;
                public:     inline const collection::continuous<const char *> & extensionGet(void) const override;
                public:     inline const collection::continuous<const char *> & layerGet(void) const override;
                public:     int run(void) override;
                public:     vulkan::platform::cocoa::window * windowGen(const window::config & config) override;
                public:     application(void);
                public:     ~application(void) override;
                public:     application(const vulkan::platform::cocoa::window::application<super> & o) = delete;
                public:     application(vulkan::platform::cocoa::window::application<super> && o) noexcept = delete;
                public:     vulkan::platform::cocoa::window::application<super> & operator=(const vulkan::platform::cocoa::window::application<super> & o) = delete;
                public:     vulkan::platform::cocoa::window::application<super> & operator=(vulkan::platform::cocoa::window::application<super> && o) noexcept = delete;
                };
    protected:  PokemonismVulkanView * vulkanView;
    public:     int open(void) override;
    public:     int close(void) override;
    public:     explicit window(window::config & o);
    public:     window(void) = delete;
    public:     ~window(void) override;
    public:     window(const vulkan::platform::cocoa::window & o) = delete;
    public:     window(vulkan::platform::cocoa::window && o) noexcept = delete;
    public:     vulkan::platform::cocoa::window & operator=(const vulkan::platform::cocoa::window & o) = delete;
    public:     vulkan::platform::cocoa::window & operator=(vulkan::platform::cocoa::window && o) noexcept = delete;
    };

    template <class super>
    vulkan::platform::cocoa::window::application<super> * vulkan::platform::cocoa::window::application<super>::singleton = nullptr;

}

#include <pokemonism/vulkan/platform/cocoa/window/application.hh>

#endif // __POKEMONISM_VULKAN_PLATFORM_COCOA_WINDOW_HH__