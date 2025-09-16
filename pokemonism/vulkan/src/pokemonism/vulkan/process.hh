/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 15, 2025
 */

#ifndef   __POKEMONISM_VULKAN_PROCESS_HH__
#define   __POKEMONISM_VULKAN_PROCESS_HH__

#include <pokemonism/vulkan.hh>

namespace pokemonism::vulkan {

    struct process {
    public:     template <typename func = PFN_vkVoidFunction> static func get(VkInstance o, const char * name);
    public:     inline static VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pMessenger);
    public:     inline static void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
        // public:     static

    public:     constexpr static PFN_vkGetPhysicalDeviceFeatures GetPhysicalDeviceFeatures = vkGetPhysicalDeviceFeatures;
    public:     constexpr static PFN_vkGetPhysicalDeviceFormatProperties GetPhysicalDeviceFormatProperties = vkGetPhysicalDeviceFormatProperties;
    public:     constexpr static PFN_vkGetPhysicalDeviceImageFormatProperties GetPhysicalDeviceImageFormatProperties = vkGetPhysicalDeviceImageFormatProperties;
    public:     constexpr static PFN_vkGetPhysicalDeviceProperties GetPhysicalDeviceProperties = vkGetPhysicalDeviceProperties;
    public:     constexpr static PFN_vkGetPhysicalDeviceQueueFamilyProperties GetPhysicalDeviceQueueFamilyProperties = vkGetPhysicalDeviceQueueFamilyProperties;
    public:     constexpr static PFN_vkGetPhysicalDeviceMemoryProperties GetPhysicalDeviceMemoryProperties = vkGetPhysicalDeviceMemoryProperties;
    public:     constexpr static PFN_vkEnumerateDeviceExtensionProperties EnumerateDeviceExtensionProperties = vkEnumerateDeviceExtensionProperties;
    public:     constexpr static PFN_vkEnumerateDeviceLayerProperties EnumerateDeviceLayerProperties = vkEnumerateDeviceLayerProperties;
    public:     constexpr static PFN_vkGetPhysicalDeviceSparseImageFormatProperties GetPhysicalDeviceSparseImageFormatProperties = vkGetPhysicalDeviceSparseImageFormatProperties;
    public:     constexpr static PFN_vkCreateDevice CreateDevice = vkCreateDevice;
    public:     constexpr static PFN_vkDestroyDevice DestroyDevice = vkDestroyDevice;
    public:     constexpr static PFN_vkGetDeviceQueue GetDeviceQueue = vkGetDeviceQueue;
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

#endif // __POKEMONISM_VULKAN_PROCESS_HH__