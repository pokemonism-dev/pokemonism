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

#include <pokemonism/sdk/continuous.hh>

namespace pokemonism::vulkan {

    template <class policy>
    window::application<policy>::application(void) : policy(vulkan::platform::window::application::gen()),  messenger(nullptr), physicalDev(nullptr) {

    }

    template <class super>
    window::application<super>::~application(void) {

    }

    template <class policy>
    inline vulkan::platform::window::application * window::application<policy>::vulkanApp(void) {
        return static_cast<vulkan::platform::window::application *>(this->adapter);
    }

    template <class policy>
    inline const vulkan::platform::window::application * window::application<policy>::vulkanApp(void) const {
        return static_cast<vulkan::platform::window::application *>(this->adapter);
    }

    template <class policy>
    int window::application<policy>::vulkanLoad(void) {
        if (VkInstance instance = platform::window::application::instanceGet(); instance == nullptr) {
            if (extensions.sizeGet() == 0) extensionLoad();
            if (layers.sizeGet() == 0) layerLoad();

            VkApplicationInfo info;

            info.pNext = nullptr;
            info.apiVersion = VK_API_VERSION_1_2;
            info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
            info.pApplicationName = this->name.stringGet();
            info.applicationVersion = VK_MAKE_VERSION(this->major, this->minor, this->revision);
            info.pEngineName = this->name.stringGet();
            info.engineVersion = VK_MAKE_VERSION(this->major, this->minor, this->revision);

            VkInstanceCreateInfo creation = vulkanApp()->creationGen(info, extensions, layers);

            if (vulkanApp()->debugGet() != nullptr) {
                VkDebugUtilsMessengerCreateInfoEXT debug;

                debug.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
                debug.pNext = nullptr;
                debug.flags = 0;
                debug.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
                debug.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT;
                debug.pUserData = nullptr;
                debug.pfnUserCallback = vulkanApp()->debugGet();

                creation.pNext = pointof(debug);
            }

            if (const VkResult result = vkCreateInstance(pointof(creation), nullptr, pointof(instance)); result != VK_SUCCESS) return declaration::fail;

            platform::window::application::instanceSet(instance);

            if (physicalDeviceSet.sizeGet() == 0) physicalDeviceLoad();
        }

        return declaration::success;
    }

    template <class policy>
    void window::application<policy>::vulkanRel(void) {
        if (messenger != nullptr) {
            vulkan::process::DestroyDebugUtilsMessengerEXT(platform::window::application::instanceGet(), messenger, nullptr);
            messenger = nullptr;
        }

        if (platform::window::application::instanceGet() != nullptr) {
            vkDestroyInstance(platform::window::application::instanceGet(), nullptr);
            platform::window::application::instanceSet(nullptr);
        }
    }

    template <class policy>
    int window::application<policy>::run(void) {
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

    template <class policy>
    const collection::continuous<VkExtensionProperties> & window::application<policy>::extensionLoad(void) {
        extensions.clean();
        unsigned int count = 0;

        vkEnumerateInstanceExtensionProperties(nullptr, pointof(count), nullptr);

        extensions.grow(count);

        vkEnumerateInstanceExtensionProperties(nullptr, pointof(count), extensions.storageGet());

        for (unsigned long i = 0; i < extensions.sizeGet(); i = i + 1) printf("%s\n", extensions[i].extensionName);

        return extensions;
    }

    template <class policy>
    const collection::continuous<vulkan::physical::device> & window::application<policy>::physicalDeviceLoad(void) {
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

    template <class policy>
    void window::application<policy>::extensionCat(const char * name) {
        vulkanApp()->extensionCat(name);
    }

    template <class policy>
    void window::application<policy>::layerCat(const char * name) {
        vulkanApp()->layerCat(name);
    }

    template <class policy>
    void window::application<policy>::debugSet(vulkan::extension::debug::callback callback) {
        vulkanApp()->debugSet(callback);
    }

    template <class policy>
    const collection::continuous<VkLayerProperties> & window::application<policy>::layerLoad(void) {
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

    template <class policy>
    inline const collection::continuous<VkExtensionProperties> & window::application<policy>::extensionGet(void) const {
        return extensions;
    }

    template <class policy>
    inline collection::continuous<VkExtensionProperties> & window::application<policy>::extensionGet(void) {
        return extensions;
    }

    template <class policy>
    inline const collection::continuous<VkLayerProperties> & window::application<policy>::layerGet(void) const {
        return layers;
    }

    template <class policy>
    inline collection::continuous<VkLayerProperties> & window::application<policy>::layerGet(void) {
        return layers;
    }

    template <class policy>
    inline const collection::continuous<vulkan::physical::device> & window::application<policy>::physicalDeviceGet(void) const {
        return physicalDeviceSet;
    }

    template <class policy>
    inline collection::continuous<vulkan::physical::device> & window::application<policy>::physicalDeviceGet(void) {
        return physicalDeviceSet;
    }

    template <class policy>
    inline const collection::continuous<const char *> & window::application<policy>::layerNameGet(void) const {
        return vulkanApp()->layerGet();
    }

    template <class policy>
    inline const collection::continuous<const char *> & window::application<policy>::extensionNameGet(void) const {
        return vulkanApp()->extensionGet();
    }

}

#endif // __POKEMONISM_VULKAN_WINDOW_APPLICATION_HH__