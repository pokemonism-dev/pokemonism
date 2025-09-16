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

#include <pokemonism/closeable.hh>
#include <pokemonism/sdk/exception.hh>
#include <pokemonism/collection/continuous.hh>
#include <pokemonism/collection/tuple/pair.hh>

namespace pokemonism::vulkan::physical {

    class device : public closeable<> {
    protected:  VkPhysicalDevice handle;
    protected:  VkPhysicalDeviceFeatures feature;
    protected:  VkPhysicalDeviceProperties property;
    protected:  collection::continuous<VkQueueFamilyProperties> queueSet;
    public:     virtual VkPhysicalDeviceFeatures & get(VkPhysicalDeviceFeatures & features) const;
    public:     virtual VkFormatProperties & get(VkFormat format, VkFormatProperties & properties) const;
    public:     virtual VkImageFormatProperties & get(VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties & properties) const;
    public:     virtual VkPhysicalDeviceProperties & get(VkPhysicalDeviceProperties & properties) const;
    public:     virtual collection::continuous<VkQueueFamilyProperties> & get(collection::continuous<VkQueueFamilyProperties> & properties) const;
    public:     virtual VkPhysicalDeviceMemoryProperties & get(VkPhysicalDeviceMemoryProperties & properties) const;
    public:     virtual collection::continuous<VkExtensionProperties> & get(const char* pLayerName, collection::continuous<VkExtensionProperties> & properties) const;
    public:     virtual collection::continuous<VkLayerProperties> & get(collection::continuous<VkLayerProperties> & properties) const;
    public:     virtual collection::continuous<VkSparseImageFormatProperties> & get(VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, collection::continuous<VkSparseImageFormatProperties> & properties) const;
    public:     virtual const VkPhysicalDeviceFeatures & featuresGen(void);
    public:     virtual const VkPhysicalDeviceProperties & propertiesGen(void);
    public:     virtual const collection::continuous<VkQueueFamilyProperties> & queuesGen(void);
    public:     virtual VkDevice gen(const VkDeviceCreateInfo * pCreateInfo, const VkAllocationCallbacks * pAllocator);
    public:     virtual const VkQueueFamilyProperties * queueFamilyPropertyGet(unsigned long index) const;
    public:     inline const VkPhysicalDeviceFeatures & featuresGet(void) const;
    public:     inline const VkPhysicalDeviceProperties & propertiesGet(void) const;
    public:     inline const collection::continuous<VkQueueFamilyProperties> & queuesGet(void) const;
    public:     inline int close(void) override;
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
        memset(pointof(feature), declaration::zero, sizeof(VkPhysicalDeviceFeatures));
        memset(pointof(property), declaration::zero, sizeof(VkPhysicalDeviceProperties));

        return declaration::success;
    }

    inline device::device(VkPhysicalDevice handle) : handle(handle) {
        memset(pointof(feature), declaration::zero, sizeof(VkPhysicalDeviceFeatures));
        memset(pointof(property), declaration::zero, sizeof(VkPhysicalDeviceProperties));
    }

    inline device::device(void) : handle(nullptr) {
        memset(pointof(feature), declaration::zero, sizeof(VkPhysicalDeviceFeatures));
        memset(pointof(property), declaration::zero, sizeof(VkPhysicalDeviceProperties));
    }

    inline device::~device(void) {
        handle = nullptr;
    }

    inline device::device(const vulkan::physical::device & o) : handle(nullptr) {
        pokemon_develop_throw((void)(0));

        // ReSharper disable CppDFAUnreachableCode
        if (o.handle != nullptr) {
            memcpy(pointof(feature), pointof(o.feature), sizeof(VkPhysicalDeviceFeatures));
            memcpy(pointof(property), pointof(o.property), sizeof(VkPhysicalDeviceProperties));
            queueSet = o.queueSet;
        } else {
            memset(pointof(feature), declaration::zero, sizeof(VkPhysicalDeviceFeatures));
            memset(pointof(property), declaration::zero, sizeof(VkPhysicalDeviceProperties));
        }
        // ReSharper restore CppDFAUnreachableCode
    }

    inline device::device(vulkan::physical::device && o) noexcept : handle(o.handle), feature(), property() {
        if (handle != nullptr) {
            memcpy(pointof(feature), pointof(o.feature), sizeof(VkPhysicalDeviceFeatures));
            memcpy(pointof(property), pointof(o.property), sizeof(VkPhysicalDeviceProperties));
            queueSet = std::move(o.queueSet);
        }
        o.handle = nullptr;
    }

    inline vulkan::physical::device & device::operator=(const vulkan::physical::device & o) {
        pokemon_develop_throw((void)(0));
        // ReSharper disable CppDFAUnreachableCode
        if (pointof(o) != this) {
            if (o.handle) {
                memcpy(pointof(feature), pointof(o.feature), sizeof(VkPhysicalDeviceFeatures));
                memcpy(pointof(property), pointof(o.property), sizeof(VkPhysicalDeviceProperties));
                queueSet = o.queueSet;
            } else {
                memset(pointof(feature), declaration::zero, sizeof(VkPhysicalDeviceFeatures));
                memset(pointof(property), declaration::zero, sizeof(VkPhysicalDeviceProperties));
                queueSet.clean();
            }
        }
        return *this;
        // ReSharper restore CppDFAUnreachableCode
    }

    inline vulkan::physical::device & device::operator=(vulkan::physical::device && o) noexcept {
        pokemon_develop_exit_check(true, (void)(0));
        // ReSharper disable CppDFAUnreachableCode
        if (pointof(o) != this) {
            handle = o.handle;
            if (o.handle) {
                memcpy(pointof(feature), pointof(o.feature), sizeof(VkPhysicalDeviceFeatures));
                memcpy(pointof(property), pointof(o.property), sizeof(VkPhysicalDeviceProperties));
                queueSet = std::move(o.queueSet);
            } else {
                memset(pointof(feature), declaration::zero, sizeof(VkPhysicalDeviceFeatures));
                memset(pointof(property), declaration::zero, sizeof(VkPhysicalDeviceProperties));
                queueSet.clean();
            }
            o.handle = nullptr;
        }
        return *this;
        // ReSharper restore CppDFAUnreachableCode
    }

    inline const VkPhysicalDeviceFeatures & device::featuresGen(void) {
        if (handle != nullptr) {
            get(feature);
            return feature;
        }

        memset(pointof(feature), declaration::zero, sizeof(VkPhysicalDeviceFeatures));
        return feature;
    }

    inline const VkPhysicalDeviceProperties & device::propertiesGen(void) {
        if (handle != nullptr) {
            get(property);
            return property;
        }

        memset(pointof(property), declaration::zero, sizeof(VkPhysicalDeviceFeatures));
        return property;
    }

    inline const collection::continuous<VkQueueFamilyProperties> & device::queuesGen(void) {
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

}

#endif // __POKEMONISM_VULKAN_PHYSICAL_DEVICE_HH__