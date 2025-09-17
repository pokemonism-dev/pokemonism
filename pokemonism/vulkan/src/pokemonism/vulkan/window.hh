/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 12, 2025
 */

#ifndef   __POKEMONISM_VULKAN_WINDOW_HH__
#define   __POKEMONISM_VULKAN_WINDOW_HH__

#include <vulkan/vulkan.h>

#include <pokemonism/window.hh>
#include <pokemonism/vulkan.hh>
#include <pokemonism/vulkan/physical/device.hh>
#include <pokemonism/vulkan/platform/window.hh>

namespace pokemonism::vulkan {

    namespace platform {
        class window : public pokemonism::platform::window {
        public:     class application;
        };
    }

    class window : public pokemonism::window {
    public:     template <class super = pokemonism::window::application> class application : public super {
                protected:  VkDebugUtilsMessengerEXT messenger;
                protected:  vulkan::platform::window::application * vulkanable;
                protected:  collection::continuous<VkExtensionProperties> extensions;
                protected:  collection::continuous<VkLayerProperties> layers;
                protected:  collection::continuous<vulkan::physical::device> physicalDeviceSet;
                protected:  vulkan::physical::device * physicalDev;
                public:     int run(void) override;
                public:     virtual int vulkanLoad(void);
                public:     virtual void vulkanRel(void);
                public:     virtual const collection::continuous<VkExtensionProperties> & extensionLoad(void);
                public:     virtual const collection::continuous<VkLayerProperties> & layerLoad(void);
                public:     virtual const collection::continuous<vulkan::physical::device> & physicalDeviceLoad(void);
                public:     inline virtual const collection::continuous<VkExtensionProperties> & extensionGet(void) const;
                public:     inline virtual collection::continuous<VkExtensionProperties> & extensionGet(void);
                public:     inline virtual const collection::continuous<VkLayerProperties> & layerGet(void) const;
                public:     inline virtual collection::continuous<VkLayerProperties> & layerGet(void);
                public:     inline virtual const collection::continuous<vulkan::physical::device> & physicalDeviceGet(void) const;
                public:     inline virtual collection::continuous<vulkan::physical::device> & physicalDeviceGet(void);
                public:     inline virtual const collection::continuous<const char *> & layerNameGet(void) const;
                public:     inline virtual const collection::continuous<const char *> & extensionNameGet(void) const;
                public:     virtual void extensionCat(const char * name);
                public:     virtual void layerCat(const char * name);
                public:     virtual void debugSet(vulkan::extension::debug::callback callback);
                public:     application(void);
                public:     ~application(void) override;
                public:     application(const vulkan::window::application<super> & o) = delete;
                public:     application(vulkan::window::application<super> && o) noexcept = delete;
                public:     vulkan::window::application<super> & operator=(const vulkan::window::application<super> & o) = delete;
                public:     vulkan::window::application<super> & operator=(vulkan::window::application<super> && o) noexcept = delete;
                };
    public:     window(void) {}
    public:     ~window(void) override {}
    public:     window(const vulkan::window & o) = delete;
    public:     window(vulkan::window && o) noexcept = delete;
    public:     vulkan::window & operator=(const vulkan::window & o) = delete;
    public:     vulkan::window & operator=(vulkan::window && o) noexcept = delete;
    };

    class platform::window::application : public pokemonism::platform::window::application {
    protected:  static VkInstance instance;
    public:     static VkInstance instanceGet(void);
    protected:  static void instanceSet(VkInstance instance);
    public:     static vulkan::platform::window::application * get(void);
    public:     virtual VkInstanceCreateInfo creationGen(VkApplicationInfo & info, const collection::continuous<VkExtensionProperties> & extensionSet, const collection::continuous<VkLayerProperties> & layerSet) = 0;
    public:     virtual void extensionCat(const char * name) = 0;
    public:     virtual void layerCat(const char * name) = 0;
    public:     virtual void debugSet(vulkan::extension::debug::callback callback) = 0;
    public:     virtual vulkan::extension::debug::callback debugGet(void) const = 0;
    public:     virtual const collection::continuous<const char *> & extensionGet(void) const = 0;
    public:     virtual const collection::continuous<const char *> & layerGet(void) const = 0;
    public:     inline application(void);
    public:     inline ~application(void) override;
    public:     inline application(const vulkan::platform::window::application & o);
    public:     inline application(vulkan::platform::window::application && o) noexcept;
    public:     inline vulkan::platform::window::application & operator=(const vulkan::platform::window::application & o);
    public:     inline vulkan::platform::window::application & operator=(vulkan::platform::window::application && o) noexcept;
    public:     template <class super> friend class vulkan::window::application;
    };

}

// ReSharper disable CppUnusedIncludeDirective
#include <pokemonism/vulkan/window/application.hh>
#include <pokemonism/vulkan/platform/window/application.hh>
// ReSharper restore CppUnusedIncludeDirective

#endif // __POKEMONISM_VULKAN_WINDOW_HH__
