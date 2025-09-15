/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_VULKAN_HH__
#define   __POKEMONISM_VULKAN_HH__

#include <vulkan/vulkan.h>

#include <pokemonism/window.hh>

namespace pokemonism::vulkan {

    struct extension {
    public:     struct properties;
    public:     struct debug;
    };

    struct extension::properties {
    public:     inline static bool scanner(const VkExtensionProperties & property, const char * item);
    };

    inline bool extension::properties::scanner(const VkExtensionProperties & property, const char *item) {
        return strcmp(property.extensionName, item) == 0;
    }

    struct extension::debug {
    public:     typedef VKAPI_ATTR VkBool32 VKAPI_CALL (*callback)(VkDebugUtilsMessageSeverityFlagBitsEXT, VkDebugUtilsMessageTypeFlagsEXT, const VkDebugUtilsMessengerCallbackDataEXT *, void *);
    public:     inline static VKAPI_ATTR VkBool32 VKAPI_CALL consoleOut(VkDebugUtilsMessageSeverityFlagBitsEXT severity, VkDebugUtilsMessageTypeFlagsEXT type, const VkDebugUtilsMessengerCallbackDataEXT * data, void * user);
    };

    inline VKAPI_ATTR VkBool32 VKAPI_CALL extension::debug::consoleOut(VkDebugUtilsMessageSeverityFlagBitsEXT severity, VkDebugUtilsMessageTypeFlagsEXT type, const VkDebugUtilsMessengerCallbackDataEXT * data, void * user) {
        printf("%s\n", data->pMessage);
        return VK_FALSE;
    }

    struct process {
    public:     template <typename func = PFN_vkVoidFunction> static func get(VkInstance o, const char * name);
    public:     inline static VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger);
    public:     inline static void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
    };

    template <typename func>
    func process::get(VkInstance o, const char * name) {
        return reinterpret_cast<func>(vkGetInstanceProcAddr(o, name));
    }

    inline VkResult process::CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger) {
        const PFN_vkCreateDebugUtilsMessengerEXT func = process::get<PFN_vkCreateDebugUtilsMessengerEXT>(instance, "vkCreateDebugUtilsMessengerEXT");

        pokemon_develop_check(func == nullptr, return VK_ERROR_EXTENSION_NOT_PRESENT);

        return func(instance, pCreateInfo, pAllocator, pMessenger);
    }

    inline void process::DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator) {
        if (const PFN_vkDestroyDebugUtilsMessengerEXT func = process::get<PFN_vkDestroyDebugUtilsMessengerEXT>(instance, "vkDestroyDebugUtilsMessengerEXT"); func != nullptr) {
            func(instance, debugMessenger, pAllocator);
        }
    }

}

#endif // __POKEMONISM_VULKAN_HH__