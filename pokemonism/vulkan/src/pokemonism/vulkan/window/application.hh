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
#include <pokemonism/vulkan/window.hh>

namespace pokemonism::vulkan {

    template <class super>
    window::application<super>::application(void) : instance(nullptr), vulkanable(vulkan::platform::window::application::get()) {

    }

    template <class super>
    window::application<super>::~application(void) {

    }

    template <class super>
    int window::application<super>::vulkanRet(void) {
        if (instance == nullptr) {
            extensionRet();

            VkApplicationInfo info;

            info.pNext = nullptr;
            info.apiVersion = VK_API_VERSION_1_2;
            info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
            info.pApplicationName = this->name.stringGet();
            info.applicationVersion = VK_MAKE_VERSION(this->major, this->minor, this->revision);
            info.pEngineName = this->name.stringGet();
            info.engineVersion = VK_MAKE_VERSION(this->major, this->minor, this->revision);

            const VkInstanceCreateInfo creation = vulkanable.creationGen(info, extensions);

            if (const VkResult result = vkCreateInstance(pointof(creation), nullptr, pointof(instance)); result != VK_SUCCESS) return declaration::fail;
        }

        return declaration::success;
    }

    template <class super>
    void window::application<super>::vulkanRel(void) {
        vkDestroyInstance(instance, nullptr);
        instance = nullptr;
    }

    template <class super>
    int window::application<super>::run(void) {
        if (vulkanRet() == declaration::success) {
            const int ret = super::run();
            vulkanRel();
            printf("rel\n");
            return ret;
        }

        return declaration::fail;
    }

    template <class super>
    int window::application<super>::extensionRet(void) {
        extensions.clean();
        unsigned int count = 0;

        vkEnumerateInstanceExtensionProperties(nullptr, pointof(count), nullptr);

        extensions.grow(count);

        vkEnumerateInstanceExtensionProperties(nullptr, pointof(count), extensions.storageGet());

        return declaration::success;
    }

}

#endif // __POKEMONISM_VULKAN_WINDOW_APPLICATION_HH__