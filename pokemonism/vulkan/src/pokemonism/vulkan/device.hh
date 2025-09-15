// /**
//  * @file
//  * @brief
//  * @details
//  *
//  * @author          snorlax <snorlax@pokemonism.dev>
//  * @since           Sep 15, 2025
//  */
//
// #ifndef   __POKEMONISM_VULKAN_DEVICE_HH__
// #define   __POKEMONISM_VULKAN_DEVICE_HH__
//
// #include <vulkan/vulkan.h>
//
// #include <cstdio>
// #include <pokemonism/sdk/exception.hh>
// #include <pokemonism/collection/continuous.hh>
// #include <pokemonism/collection/tuple/pair.hh>
//
// namespace pokemonism::vulkan {
//
//     class device {
//     protected:  VkPhysicalDevice handle;
//     public:     virtual VkPhysicalDeviceFeatures & get(VkPhysicalDeviceFeatures & features) const;
//     public:     virtual VkFormatProperties & get(VkFormat format, VkFormatProperties & properties) const;
//     public:     virtual VkImageFormatProperties & get(VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties & properties) const;
//     public:     virtual VkPhysicalDeviceProperties & get(VkPhysicalDeviceProperties & properties) const;
//     public:     virtual collection::continuous<VkQueueFamilyProperties> & get(collection::continuous<VkQueueFamilyProperties> & properties) const;
//     public:     virtual VkPhysicalDeviceMemoryProperties & get(VkPhysicalDeviceMemoryProperties & properties) const;
//     public:     virtual collection::continuous<VkExtensionProperties> & get(const char* pLayerName, collection::continuous<VkExtensionProperties> & properties) const;
//     public:     virtual collection::continuous<VkLayerProperties> & get(collection::continuous<VkLayerProperties> & properties) const;
//     public:     virtual collection::continuous<VkSparseImageFormatProperties> & get(VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, collection::continuous<VkSparseImageFormatProperties> & properties) const;
//     public:     virtual VkDevice gen(const VkDeviceCreateInfo* pCreateInfo, const VkAllocationCallbacks* pAllocator);
//     public:     inline virtual void close(void);
//     public:     inline explicit device(VkPhysicalDevice handle);
//     public:     inline device(void);
//     public:     inline virtual ~device(void);
//     public:     inline device(const vulkan::device & o) : handle(nullptr) { pokemon_develop_throw((void)(0)); }
//     public:     inline device(vulkan::device && o) noexcept : handle(o.handle) { o.handle = nullptr; }
//     public:     inline vulkan::device & operator=(const vulkan::device & o) { pokemon_develop_throw(return *this); }
//     public:     inline vulkan::device & operator=(vulkan::device && o) noexcept { pokemon_develop_exit_check(true, return *this); }
//     };
//
//
//     inline void device::close(void) {
//
//     }
//
//     inline device::device(VkPhysicalDevice handle) : handle(handle) {
//
//     }
//
//     inline device::device(void) : handle(nullptr) {
//
//     }
//
//     inline device::~device(void) {
//
//     }
//
// }
//
// #endif // __POKEMONISM_VULKAN_DEVICE_HH__