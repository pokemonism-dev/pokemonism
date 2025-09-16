/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 15, 2025
 */

#ifndef   __POKEMONISM_VULKAN_PHYSICAL_DEVICE_HH__
#define   __POKEMONISM_VULKAN_PHYSICAL_DEVICE_HH__

#include <cstdio>

#include <vulkan/vulkan.h>

#include <pokemonism/vulkan.hh>
#include <pokemonism/closeable.hh>
#include <pokemonism/collection/reference.hh>
#include <pokemonism/collection/continuous.hh>
#include <pokemonism/collection/tuple/pair.hh>

#include <pokemonism/vulkan/queue.hh>
#include <pokemonism/vulkan/device.hh>

namespace pokemonism::vulkan::physical {

    class device : public closeable<> {
    protected:  reference<VkPhysicalDevice, vulkan::del> handle;
    protected:  VkPhysicalDeviceFeatures feature;               // TODO: OPTIONAL fh qkRnwk...
    protected:  VkPhysicalDeviceProperties property;
    protected:  collection::continuous<VkQueueFamilyProperties> queueSet;
    public:     inline static VkDeviceQueueCreateInfo queueCreateInformationGen(unsigned int index);
    public:     inline static VkDeviceCreateInfo createInformationGen(const VkDeviceQueueCreateInfo & queueCreateInfo, const collection::continuous<const char *> & layers, const collection::continuous<const char *> & extensions, const VkPhysicalDeviceFeatures & features);
    public:     inline static VkDeviceCreateInfo createInformationGen(const collection::continuous<VkDeviceQueueCreateInfo> & queueCreateInfoSet, const collection::continuous<const char *> & layers, const collection::continuous<const char *> & extensions, const VkPhysicalDeviceFeatures & features);
    public:     virtual VkPhysicalDeviceFeatures & get(VkPhysicalDeviceFeatures & features) const;
    public:     virtual VkFormatProperties & get(VkFormat format, VkFormatProperties & properties) const;
    public:     virtual VkImageFormatProperties & get(VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties & properties) const;
    public:     virtual VkPhysicalDeviceProperties & get(VkPhysicalDeviceProperties & properties) const;
    public:     virtual collection::continuous<VkQueueFamilyProperties> & get(collection::continuous<VkQueueFamilyProperties> & properties) const;
    public:     virtual unsigned int queueFamilyIndexGet(unsigned int flags) const;
    public:     virtual VkPhysicalDeviceMemoryProperties & get(VkPhysicalDeviceMemoryProperties & properties) const;
    public:     virtual collection::continuous<VkExtensionProperties> & get(const char* pLayerName, collection::continuous<VkExtensionProperties> & properties) const;
    public:     virtual collection::continuous<VkLayerProperties> & get(collection::continuous<VkLayerProperties> & properties) const;
    public:     virtual collection::continuous<VkSparseImageFormatProperties> & get(VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, collection::continuous<VkSparseImageFormatProperties> & properties) const;
    public:     inline virtual VkDevice deviceGen(const VkDeviceCreateInfo & createInfo, const VkAllocationCallbacks * pAllocator = nullptr) const;
    public:     virtual VkDevice deviceGen(unsigned int flags, const collection::continuous<const char *> & layers, const collection::continuous<const char *> & extensions, const VkAllocationCallbacks * pAllocator = nullptr) const;
    public:     inline const VkQueueFamilyProperties * queueFamilyPropertyGet(unsigned long index) const;
    public:     inline const VkPhysicalDeviceFeatures & featuresGet(void) const;
    public:     inline const VkPhysicalDeviceProperties & propertiesGet(void) const;
    public:     inline const collection::continuous<VkQueueFamilyProperties> & queuesGet(void) const;
    public:     inline int close(void) override;
    public:     const VkPhysicalDeviceFeatures & featuresLoad(void);
    public:     const VkPhysicalDeviceProperties & propertiesLoad(void);
    public:     const collection::continuous<VkQueueFamilyProperties> & queuesLoad(void);
    public:     inline explicit device(VkPhysicalDevice handle);
    public:     inline device(void);
    public:     inline ~device(void) override;
    public:     inline device(const vulkan::physical::device & o);
    public:     inline device(vulkan::physical::device && o) noexcept;
    public:     inline vulkan::physical::device & operator=(const vulkan::physical::device & o);
    public:     inline vulkan::physical::device & operator=(vulkan::physical::device && o) noexcept;
    };

    inline int device::close(void) {
        handle = nullptr;
        allocator::clear(pointof(property));
        allocator::clear(pointof(feature));

        return declaration::success;
    }

    inline device::device(VkPhysicalDevice handle) : handle(handle) {
        if (handle != nullptr) {
            featuresLoad();
            propertiesLoad();
            queuesLoad();
        }
        allocator::clear(pointof(property));
        allocator::clear(pointof(feature));
    }

    inline device::device(void) : handle(nullptr) {
        allocator::clear(pointof(property));
        allocator::clear(pointof(feature));
    }

    inline device::~device(void) {
        handle = nullptr;
    }

    inline device::device(const vulkan::physical::device & o) : handle(o.handle) {
        memcpy(pointof(feature), pointof(o.feature), sizeof(VkPhysicalDeviceFeatures));
        memcpy(pointof(property), pointof(o.property), sizeof(VkPhysicalDeviceProperties));
        queueSet = o.queueSet;
    }

    inline device::device(vulkan::physical::device && o) noexcept : handle(std::move(o.handle)) {
        memcpy(pointof(feature), pointof(o.feature), sizeof(VkPhysicalDeviceFeatures));
        memcpy(pointof(property), pointof(o.property), sizeof(VkPhysicalDeviceProperties));
        queueSet = std::move(o.queueSet);
    }

    inline vulkan::physical::device & device::operator=(const vulkan::physical::device & o) {
        if (pointof(o) != this) {
            handle = o.handle;
            memcpy(pointof(feature), pointof(o.feature), sizeof(VkPhysicalDeviceFeatures));
            memcpy(pointof(property), pointof(o.property), sizeof(VkPhysicalDeviceProperties));
            queueSet = o.queueSet;
        }
        return *this;
    }

    inline vulkan::physical::device & device::operator=(vulkan::physical::device && o) noexcept {
        if (pointof(o) != this) {
            handle = std::move(o.handle);
            memcpy(pointof(feature), pointof(o.feature), sizeof(VkPhysicalDeviceFeatures));
            memcpy(pointof(property), pointof(o.property), sizeof(VkPhysicalDeviceProperties));
            queueSet = std::move(o.queueSet);
        }
        return *this;
    }

    inline const VkPhysicalDeviceFeatures & device::featuresLoad(void) {
        if (handle != nullptr) {
            get(feature);
            return feature;
        }

        allocator::clear(pointof(feature));

        return feature;
    }

    inline const VkPhysicalDeviceProperties & device::propertiesLoad(void) {
        if (handle != nullptr) {
            get(property);
            return property;
        }

        allocator::clear(pointof(property));

        return property;
    }

    inline const collection::continuous<VkQueueFamilyProperties> & device::queuesLoad(void) {
        if (handle != nullptr) {
            get(queueSet);
            return queueSet;
        }

        queueSet.clean();
        return queueSet;
    }

    inline const VkQueueFamilyProperties * device::queueFamilyPropertyGet(unsigned long index) const {
        if (index < queueSet.sizeGet()) return pointof(queueSet[index]);

        return nullptr;
    }

    inline const VkPhysicalDeviceFeatures & device::featuresGet(void) const {
        return feature;
    }

    inline const VkPhysicalDeviceProperties & device::propertiesGet(void) const {
        return property;
    }

    inline const collection::continuous<VkQueueFamilyProperties> & device::queuesGet(void) const {
        return queueSet;
    }

    inline VkDeviceQueueCreateInfo device::queueCreateInformationGen(unsigned int index) {
        VkDeviceQueueCreateInfo info;

        info.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        info.pNext = nullptr;
        info.flags = declaration::none;
        info.queueFamilyIndex = index;
        info.queueCount = declaration::one;
        info.pQueuePriorities = pointof(queue::priority::standard);

        return info;
    }

    inline VkDeviceCreateInfo device::createInformationGen(const VkDeviceQueueCreateInfo & queueCreateInfo, const collection::continuous<const char *> & layers, const collection::continuous<const char *> & extensions, const VkPhysicalDeviceFeatures & features) {
        VkDeviceCreateInfo info;

        info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        info.pNext = nullptr;
        info.flags = declaration::none;
        info.queueCreateInfoCount = declaration::one;
        info.pQueueCreateInfos = pointof(queueCreateInfo);
        info.enabledLayerCount = layers.sizeGet();
        info.ppEnabledLayerNames = layers.storageGet();
        info.enabledExtensionCount = extensions.sizeGet();
        info.ppEnabledExtensionNames = extensions.storageGet();
        info.pEnabledFeatures = pointof(features);

        return info;
    }

    inline VkDeviceCreateInfo device::createInformationGen(const collection::continuous<VkDeviceQueueCreateInfo> & queueCreateInfoSet, const collection::continuous<const char *> & layers, const collection::continuous<const char *> & extensions, const VkPhysicalDeviceFeatures & features) {
        VkDeviceCreateInfo info;

        info.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
        info.pNext = nullptr;
        info.flags = declaration::none;
        info.queueCreateInfoCount = queueCreateInfoSet.sizeGet();
        info.pQueueCreateInfos = queueCreateInfoSet.storageGet();
        info.enabledLayerCount = layers.sizeGet();
        info.ppEnabledLayerNames = layers.storageGet();
        info.enabledExtensionCount = extensions.sizeGet();
        info.ppEnabledExtensionNames = extensions.storageGet();
        info.pEnabledFeatures = pointof(features);

        return info;
    }


    VkDevice device::deviceGen(const VkDeviceCreateInfo & createInfo, const VkAllocationCallbacks * pAllocator) const {
        if (VkDevice dev = nullptr; vulkan::process::CreateDevice(*handle, pointof(createInfo), pAllocator, pointof(dev)) == VK_SUCCESS) return dev;

        return nullptr;
    }



}

#endif // __POKEMONISM_VULKAN_PHYSICAL_DEVICE_HH__