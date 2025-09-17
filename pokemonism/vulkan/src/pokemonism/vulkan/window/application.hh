/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 15, 2025
 */

#ifndef   __POKEMONISM_VULKAN_WINDOW_APPLICATION_HH__
#define   __POKEMONISM_VULKAN_WINDOW_APPLICATION_HH__

#include <pokemonism/collection/continuous.hh>
// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/vulkan/window.hh>

#include "pokemonism/sdk/continuous.hh"

namespace pokemonism::vulkan {

    template <class super>
    window::application<super>::application(void) : messenger(nullptr), vulkanable(vulkan::platform::window::application::get()), physicalDev(nullptr) {

    }

    template <class super>
    window::application<super>::~application(void) {

    }


    template <class super>
    int window::application<super>::vulkanLoad(void) {
        if (VkInstance instance = platform::window::application::instanceGet(); instance == nullptr) {
            if (extensions.sizeGet() == 0) extensionLoad();
            if (layers.sizeGet() == 0) layerLoad();
            if (physicalDeviceSet.sizeGet() == 0) physicalDeviceLoad();

            VkApplicationInfo info;

            info.pNext = nullptr;
            info.apiVersion = VK_API_VERSION_1_2;
            info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
            info.pApplicationName = this->name.stringGet();
            info.applicationVersion = VK_MAKE_VERSION(this->major, this->minor, this->revision);
            info.pEngineName = this->name.stringGet();
            info.engineVersion = VK_MAKE_VERSION(this->major, this->minor, this->revision);

            VkInstanceCreateInfo creation = vulkanable->creationGen(info, extensions, layers);

            if (vulkanable->debugGet() != nullptr) {
                VkDebugUtilsMessengerCreateInfoEXT debug;

                debug.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
                debug.pNext = nullptr;
                debug.flags = declaration::none;
                debug.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
                debug.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT;
                debug.pUserData = nullptr;
                debug.pfnUserCallback = vulkanable->debugGet();

                creation.pNext = pointof(debug);
            }

            if (const VkResult result = vkCreateInstance(pointof(creation), nullptr, pointof(instance)); result != VK_SUCCESS) {
                platform::window::application::instanceSet(instance);
                return declaration::fail;
            }
        }

        return declaration::success;
    }

    template <class super>
    void window::application<super>::vulkanRel(void) {
        if (messenger != nullptr) {
            vulkan::process::DestroyDebugUtilsMessengerEXT(platform::window::application::instanceGet(), messenger, nullptr);
            messenger = nullptr;
        }

        if (platform::window::application::instanceGet() != nullptr) {
            vkDestroyInstance(platform::window::application::instanceGet(), nullptr);
            platform::window::application::instanceSet(nullptr);
        }
    }

    template <class super>
    int window::application<super>::run(void) {
        if (vulkanLoad() == declaration::success) {
            while (this->terminate == nullptr) {
                this->adapter->eventWait();
            }
            vulkanRel();
            printf("rel\n");
            return declaration::success;
        }

        return declaration::fail;
    }

    template <class super>
    const collection::continuous<VkExtensionProperties> & window::application<super>::extensionLoad(void) {
        extensions.clean();
        unsigned int count = 0;

        vkEnumerateInstanceExtensionProperties(nullptr, pointof(count), nullptr);

        extensions.grow(count);

        vkEnumerateInstanceExtensionProperties(nullptr, pointof(count), extensions.storageGet());

        for (unsigned long i = 0; i < extensions.sizeGet(); i = i + 1) printf("%s\n", extensions[i].extensionName);

        return extensions;
    }

    template <class super>
    const collection::continuous<vulkan::physical::device> & window::application<super>::physicalDeviceLoad(void) {
        physicalDev = nullptr;
        physicalDeviceSet.clean();
        unsigned int count = 0;

        vkEnumeratePhysicalDevices(platform::window::application::instanceGet(), pointof(count), nullptr);

        pokemon_develop_check(count == 0, return physicalDeviceSet);

        collection::continuous<VkPhysicalDevice> handles;

        handles.grow(count);
        vkEnumeratePhysicalDevices(platform::window::application::instanceGet(), pointof(count), handles.storageGet());

        pokemonism::sdk::continuous<VkPhysicalDevice, collection::continuous<VkPhysicalDevice>>::map<vulkan::physical::device>(handles, physicalDeviceSet);

        physicalDev = pointof(physicalDeviceSet[0]);

        return physicalDeviceSet;
    }

    template <class super>
    void window::application<super>::extensionCat(const char * name) {
        vulkanable->extensionCat(name);
    }

    template <class super>
    void window::application<super>::layerCat(const char * name) {
        vulkanable->layerCat(name);
    }

    template <class super>
    void window::application<super>::debugSet(vulkan::extension::debug::callback callback) {
        vulkanable->debugSet(callback);
    }

    template <class super>
    const collection::continuous<VkLayerProperties> & window::application<super>::layerLoad(void) {
        layers.clean();
        unsigned int count = 0;

        vkEnumerateInstanceLayerProperties(pointof(count), nullptr);

        layers.grow(count);

        vkEnumerateInstanceLayerProperties(pointof(count), layers.storageGet());

        for (unsigned long i = 0; i < layers.sizeGet(); i = i + 1) {
            printf("%s\n", layers[i].layerName);
        }

        return layers;
    }

    template <class super>
    inline const collection::continuous<VkExtensionProperties> & window::application<super>::extensionGet(void) const {
        return extensions;
    }

    template <class super>
    inline collection::continuous<VkExtensionProperties> & window::application<super>::extensionGet(void) {
        return extensions;
    }

    template <class super>
    inline const collection::continuous<VkLayerProperties> & window::application<super>::layerGet(void) const {
        return layers;
    }

    template <class super>
    inline collection::continuous<VkLayerProperties> & window::application<super>::layerGet(void) {
        return layers;
    }

    template <class super>
    inline const collection::continuous<vulkan::physical::device> & window::application<super>::physicalDeviceGet(void) const {
        return physicalDeviceSet;
    }

    template <class super>
    inline collection::continuous<vulkan::physical::device> & window::application<super>::physicalDeviceGet(void) {
        return physicalDeviceSet;
    }

    template <class super>
    inline const collection::continuous<const char *> & window::application<super>::layerNameGet(void) const {
        return vulkanable->layerGet();
    }

    template <class super>
    inline const collection::continuous<const char *> & window::application<super>::extensionNameGet(void) const {
        return vulkanable->extensionGet();
    }

}

#endif // __POKEMONISM_VULKAN_WINDOW_APPLICATION_HH__