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


describe_handle_typographer(VkPhysicalDevice, unsigned, void, VkPhysicalDevice, sizeof(VkPhysicalDevice));
describe_handle_typographer(VkQueue, unsigned, void, VkQueue, sizeof(VkQueue));
describe_handle_typographer(VkDevice, unsigned, void, VkDevice, sizeof(VkDevice));
describe_handle_typographer(VkSurfaceKHR, unsigned, void, VkSurfaceKHR, sizeof(VkSurfaceKHR));

namespace pokemonism::vulkan {

    extern VkPhysicalDevice del(VkPhysicalDevice o);
    extern VkQueue del(VkQueue o);
    extern VkDevice del(VkDevice o);
    extern VkSurfaceKHR del(VkSurfaceKHR o);

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
    public:     struct string {
                public:     inline static const char * to(VkBool32 v) { return v ? "true" : "false"; }
                public:     inline static const char * to(VkPhysicalDeviceType v);
                public:     struct uuid {
                            public:     inline static const char * to(const unsigned char * storage, char * buffer);
                            };
                };
    };

    inline VKAPI_ATTR VkBool32 VKAPI_CALL extension::debug::consoleOut(VkDebugUtilsMessageSeverityFlagBitsEXT severity, VkDebugUtilsMessageTypeFlagsEXT type, const VkDebugUtilsMessengerCallbackDataEXT * data, void * user) {
        printf("%s\n", data->pMessage);
        return VK_FALSE;
    }

    inline const char * extension::debug::string::to(VkPhysicalDeviceType v) {
        switch (v) {
            case VK_PHYSICAL_DEVICE_TYPE_OTHER:             return "other";
            case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:    return "integrated gpu";
            case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:      return "discrete gpu";
            case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:       return "virtual gpu";
            case VK_PHYSICAL_DEVICE_TYPE_CPU:               return "cpu";
            default:                                        return "other";
        }
    }

    inline const char * extension::debug::string::uuid::to(const unsigned char * storage, char * buffer) {
        for (int i = 0; i < 32; i = i + 1) {
            snprintf(buffer + i * 2, 4, "%02x", storage[i]);
        }
        return buffer;
    }

}

#include <pokemonism/vulkan/process.hh>

#endif // __POKEMONISM_VULKAN_HH__