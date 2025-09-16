/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */


#include "device.hh"

#include "../process.hh"

namespace pokemonism::vulkan::physical {

    VkPhysicalDeviceFeatures & device::get(VkPhysicalDeviceFeatures & features) const {
        vulkan::process::GetPhysicalDeviceFeatures(*handle, pointof(features));

#ifndef   RELEASE_MODE
        printf("robustBufferAccess: %s\n", vulkan::extension::debug::string::to(features.robustBufferAccess));
        printf("fullDrawIndexUint32: %s\n", vulkan::extension::debug::string::to(features.fullDrawIndexUint32));
        printf("imageCubeArray: %s\n", vulkan::extension::debug::string::to(features.imageCubeArray));
        printf("independentBlend: %s\n", vulkan::extension::debug::string::to(features.independentBlend));
        printf("geometryShader: %s\n", vulkan::extension::debug::string::to(features.geometryShader));
        printf("tessellationShader: %s\n", vulkan::extension::debug::string::to(features.tessellationShader));
        printf("sampleRateShading: %s\n", vulkan::extension::debug::string::to(features.sampleRateShading));
        printf("dualSrcBlend: %s\n", vulkan::extension::debug::string::to(features.dualSrcBlend));
        printf("logicOp: %s\n", vulkan::extension::debug::string::to(features.logicOp));
        printf("multiDrawIndirect: %s\n", vulkan::extension::debug::string::to(features.multiDrawIndirect));
        printf("drawIndirectFirstInstance: %s\n", vulkan::extension::debug::string::to(features.drawIndirectFirstInstance));
        printf("depthClamp: %s\n", vulkan::extension::debug::string::to(features.depthClamp));
        printf("depthBiasClamp: %s\n", vulkan::extension::debug::string::to(features.depthBiasClamp));
        printf("fillModeNonSolid: %s\n", vulkan::extension::debug::string::to(features.fillModeNonSolid));
        printf("depthBounds: %s\n", vulkan::extension::debug::string::to(features.depthBounds));
        printf("wideLines: %s\n", vulkan::extension::debug::string::to(features.wideLines));
        printf("largePoints: %s\n", vulkan::extension::debug::string::to(features.largePoints));
        printf("alphaToOne: %s\n", vulkan::extension::debug::string::to(features.alphaToOne));
        printf("multiViewport: %s\n", vulkan::extension::debug::string::to(features.multiViewport));
        printf("samplerAnisotropy: %s\n", vulkan::extension::debug::string::to(features.samplerAnisotropy));
        printf("textureCompressionETC2: %s\n", vulkan::extension::debug::string::to(features.textureCompressionETC2));
        printf("textureCompressionASTC_LDR: %s\n", vulkan::extension::debug::string::to(features.textureCompressionASTC_LDR));
        printf("textureCompressionBC: %s\n", vulkan::extension::debug::string::to(features.textureCompressionBC));
        printf("occlusionQueryPrecise: %s\n", vulkan::extension::debug::string::to(features.occlusionQueryPrecise));
        printf("pipelineStatisticsQuery: %s\n", vulkan::extension::debug::string::to(features.pipelineStatisticsQuery));
        printf("vertexPipelineStoresAndAtomics: %s\n", vulkan::extension::debug::string::to(features.vertexPipelineStoresAndAtomics));
        printf("fragmentStoresAndAtomics: %s\n", vulkan::extension::debug::string::to(features.fragmentStoresAndAtomics));
        printf("shaderTessellationAndGeometryPointSize: %s\n", vulkan::extension::debug::string::to(features.shaderTessellationAndGeometryPointSize));
        printf("shaderImageGatherExtended: %s\n", vulkan::extension::debug::string::to(features.shaderImageGatherExtended));
        printf("shaderStorageImageExtendedFormats: %s\n", vulkan::extension::debug::string::to(features.shaderStorageImageExtendedFormats));
        printf("shaderStorageImageMultisample: %s\n", vulkan::extension::debug::string::to(features.shaderStorageImageMultisample));
        printf("shaderStorageImageReadWithoutFormat: %s\n", vulkan::extension::debug::string::to(features.shaderStorageImageReadWithoutFormat));
        printf("shaderStorageImageWriteWithoutFormat: %s\n", vulkan::extension::debug::string::to(features.shaderStorageImageWriteWithoutFormat));
        printf("shaderUniformBufferArrayDynamicIndexing: %s\n", vulkan::extension::debug::string::to(features.shaderUniformBufferArrayDynamicIndexing));
        printf("shaderSampledImageArrayDynamicIndexing: %s\n", vulkan::extension::debug::string::to(features.shaderSampledImageArrayDynamicIndexing));
        printf("shaderStorageBufferArrayDynamicIndexing: %s\n", vulkan::extension::debug::string::to(features.shaderStorageBufferArrayDynamicIndexing));
        printf("shaderStorageImageArrayDynamicIndexing: %s\n", vulkan::extension::debug::string::to(features.shaderStorageImageArrayDynamicIndexing));
        printf("shaderClipDistance: %s\n", vulkan::extension::debug::string::to(features.shaderClipDistance));
        printf("shaderCullDistance: %s\n", vulkan::extension::debug::string::to(features.shaderCullDistance));
        printf("shaderFloat64: %s\n", vulkan::extension::debug::string::to(features.shaderFloat64));
        printf("shaderInt64: %s\n", vulkan::extension::debug::string::to(features.shaderInt64));
        printf("shaderInt16: %s\n", vulkan::extension::debug::string::to(features.shaderInt16));
        printf("shaderResourceResidency: %s\n", vulkan::extension::debug::string::to(features.shaderResourceResidency));
        printf("shaderResourceMinLod: %s\n", vulkan::extension::debug::string::to(features.shaderResourceMinLod));
        printf("sparseBinding: %s\n", vulkan::extension::debug::string::to(features.sparseBinding));
        printf("sparseResidencyBuffer: %s\n", vulkan::extension::debug::string::to(features.sparseResidencyBuffer));
        printf("sparseResidencyImage2D: %s\n", vulkan::extension::debug::string::to(features.sparseResidencyImage2D));
        printf("sparseResidencyImage3D: %s\n", vulkan::extension::debug::string::to(features.sparseResidencyImage3D));
        printf("sparseResidency2Samples: %s\n", vulkan::extension::debug::string::to(features.sparseResidency2Samples));
        printf("sparseResidency4Samples: %s\n", vulkan::extension::debug::string::to(features.sparseResidency4Samples));
        printf("sparseResidency8Samples: %s\n", vulkan::extension::debug::string::to(features.sparseResidency8Samples));
        printf("sparseResidency16Samples: %s\n", vulkan::extension::debug::string::to(features.sparseResidency16Samples));
        printf("sparseResidencyAliased: %s\n", vulkan::extension::debug::string::to(features.sparseResidencyAliased));
        printf("variableMultisampleRate: %s\n", vulkan::extension::debug::string::to(features.variableMultisampleRate));
        printf("inheritedQueries: %s\n", vulkan::extension::debug::string::to(features.inheritedQueries));
#endif // RELEASE_MODE

        return features;
    }

    VkFormatProperties & device::get(VkFormat format, VkFormatProperties & properties) const {
        vulkan::process::GetPhysicalDeviceFormatProperties(*handle, format, pointof(properties));

        return properties;
    }

    VkImageFormatProperties & device::get(VkFormat format, VkImageType type, VkImageTiling tiling, VkImageUsageFlags usage, VkImageCreateFlags flags, VkImageFormatProperties & properties) const {
        vulkan::process::GetPhysicalDeviceImageFormatProperties(*handle, format, type, tiling, usage, flags, pointof(properties));

        return properties;
    }

    VkPhysicalDeviceProperties & device::get(VkPhysicalDeviceProperties & properties) const {
        vulkan::process::GetPhysicalDeviceProperties(*handle, pointof(properties));

        char buffer[128];

#ifndef   RELEASE_MODE
        printf("apiVersion: %u\n", properties.apiVersion);
        printf("driverVersion: %u\n", properties.driverVersion);
        printf("vendorID: %u\n", properties.vendorID);
        printf("deviceID: %u\n", properties.deviceID);
        printf("deviceType: %s\n", vulkan::extension::debug::string::to(properties.deviceType));
        printf("deviceName: %s\n", properties.deviceName);
        printf("pipelineCacheUUID: %s\n", vulkan::extension::debug::string::uuid::to(properties.pipelineCacheUUID, buffer));
        printf("limits.maxImageDimension1D: %u\n", properties.limits.maxImageDimension1D);
        printf("limits.maxImageDimension2D: %u\n", properties.limits.maxImageDimension2D);
        printf("limits.maxImageDimension3D: %u\n", properties.limits.maxImageDimension3D);
        printf("limits.maxImageDimensionCube: %u\n", properties.limits.maxImageDimensionCube);
        printf("limits.maxImageArrayLayers: %u\n", properties.limits.maxImageArrayLayers);
        printf("limits.maxTexelBufferElements: %u\n", properties.limits.maxTexelBufferElements);
        printf("limits.maxUniformBufferRange: %u\n", properties.limits.maxUniformBufferRange);
        printf("limits.maxStorageBufferRange: %u\n", properties.limits.maxStorageBufferRange);
        printf("limits.maxPushConstantsSize: %u\n", properties.limits.maxPushConstantsSize);
        printf("limits.maxMemoryAllocationCount: %u\n", properties.limits.maxMemoryAllocationCount);
        printf("limits.bufferImageGranularity: %llu\n", properties.limits.bufferImageGranularity);
        printf("limits.sparseAddressSpaceSize: %llu\n", properties.limits.sparseAddressSpaceSize);
        printf("limits.maxBoundDescriptorSets: %u\n", properties.limits.maxBoundDescriptorSets);
        printf("limits.maxPerStageDescriptorSamplers: %u\n", properties.limits.maxPerStageDescriptorSamplers);
        printf("limits.maxPerStageDescriptorUniformBuffers: %u\n", properties.limits.maxPerStageDescriptorUniformBuffers);
        printf("limits.maxPerStageDescriptorStorageBuffers: %u\n", properties.limits.maxPerStageDescriptorStorageBuffers);
        printf("limits.maxPerStageDescriptorSampledImages: %u\n", properties.limits.maxPerStageDescriptorSampledImages);
        printf("limits.maxPerStageDescriptorStorageImages: %u\n", properties.limits.maxPerStageDescriptorStorageImages);
        printf("limits.maxPerStageDescriptorInputAttachments: %u\n", properties.limits.maxPerStageDescriptorInputAttachments);
        printf("limits.maxPerStageResources: %u\n", properties.limits.maxPerStageResources);
        printf("limits.maxDescriptorSetSamplers: %u\n", properties.limits.maxDescriptorSetSamplers);
        printf("limits.maxDescriptorSetUniformBuffers: %u\n", properties.limits.maxDescriptorSetUniformBuffers);
        printf("limits.maxDescriptorSetUniformBuffersDynamic: %u\n", properties.limits.maxDescriptorSetUniformBuffersDynamic);
        printf("limits.maxDescriptorSetStorageBuffers: %u\n", properties.limits.maxDescriptorSetStorageBuffers);
        printf("limits.maxDescriptorSetStorageBuffersDynamic: %u\n", properties.limits.maxDescriptorSetStorageBuffersDynamic);
        printf("limits.maxDescriptorSetSampledImages: %u\n", properties.limits.maxDescriptorSetSampledImages);
        printf("limits.maxDescriptorSetStorageImages: %u\n", properties.limits.maxDescriptorSetStorageImages);
        printf("limits.maxDescriptorSetInputAttachments: %u\n", properties.limits.maxDescriptorSetInputAttachments);
        printf("limits.maxVertexInputAttributes: %u\n", properties.limits.maxVertexInputAttributes);
        printf("limits.maxVertexInputBindings: %u\n", properties.limits.maxVertexInputBindings);
        printf("limits.maxVertexInputAttributeOffset: %u\n", properties.limits.maxVertexInputAttributeOffset);
        printf("limits.maxVertexInputBindingStride: %u\n", properties.limits.maxVertexInputBindingStride);
        printf("limits.maxVertexOutputComponents: %u\n", properties.limits.maxVertexOutputComponents);
        printf("limits.maxTessellationGenerationLevel: %u\n", properties.limits.maxTessellationGenerationLevel);
        printf("limits.maxTessellationPatchSize: %u\n", properties.limits.maxTessellationPatchSize);
        printf("limits.maxTessellationControlPerVertexInputComponents: %u\n", properties.limits.maxTessellationControlPerVertexInputComponents);
        printf("limits.maxTessellationControlPerVertexOutputComponents: %u\n", properties.limits.maxTessellationControlPerVertexOutputComponents);
        printf("limits.maxTessellationControlPerPatchOutputComponents: %u\n", properties.limits.maxTessellationControlPerPatchOutputComponents);
        printf("limits.maxTessellationControlTotalOutputComponents: %u\n", properties.limits.maxTessellationControlTotalOutputComponents);
        printf("limits.maxTessellationEvaluationInputComponents: %u\n", properties.limits.maxTessellationEvaluationInputComponents);
        printf("limits.maxTessellationEvaluationOutputComponents: %u\n", properties.limits.maxTessellationEvaluationOutputComponents);
        printf("limits.maxGeometryShaderInvocations: %u\n", properties.limits.maxGeometryShaderInvocations);
        printf("limits.maxGeometryInputComponents: %u\n", properties.limits.maxGeometryInputComponents);
        printf("limits.maxGeometryOutputComponents: %u\n", properties.limits.maxGeometryOutputComponents);
        printf("limits.maxGeometryOutputVertices: %u\n", properties.limits.maxGeometryOutputVertices);
        printf("limits.maxGeometryTotalOutputComponents: %u\n", properties.limits.maxGeometryTotalOutputComponents);
        printf("limits.maxFragmentInputComponents: %u\n", properties.limits.maxFragmentInputComponents);
        printf("limits.maxFragmentOutputAttachments: %u\n", properties.limits.maxFragmentOutputAttachments);
        printf("limits.maxFragmentDualSrcAttachments: %u\n", properties.limits.maxFragmentDualSrcAttachments);
        printf("limits.maxFragmentCombinedOutputResources: %u\n", properties.limits.maxFragmentCombinedOutputResources);
        printf("limits.maxComputeSharedMemorySize: %u\n", properties.limits.maxComputeSharedMemorySize);
        printf("limits.maxComputeWorkGroupCount[0]: %u\n", properties.limits.maxComputeWorkGroupCount[0]);
        printf("limits.maxComputeWorkGroupCount[1]: %u\n", properties.limits.maxComputeWorkGroupCount[1]);
        printf("limits.maxComputeWorkGroupCount[2]: %u\n", properties.limits.maxComputeWorkGroupCount[2]);
        printf("limits.maxComputeWorkGroupInvocations: %u\n", properties.limits.maxComputeWorkGroupInvocations);
        printf("limits.maxComputeWorkGroupSize[0]: %u\n", properties.limits.maxComputeWorkGroupSize[0]);
        printf("limits.maxComputeWorkGroupSize[1]: %u\n", properties.limits.maxComputeWorkGroupSize[1]);
        printf("limits.maxComputeWorkGroupSize[2]: %u\n", properties.limits.maxComputeWorkGroupSize[2]);
        printf("limits.subPixelPrecisionBits: %u\n", properties.limits.subPixelPrecisionBits);
        printf("limits.subTexelPrecisionBits: %u\n", properties.limits.subTexelPrecisionBits);
        printf("limits.mipmapPrecisionBits: %u\n", properties.limits.mipmapPrecisionBits);
        printf("limits.maxDrawIndexedIndexValue: %u\n", properties.limits.maxDrawIndexedIndexValue);
        printf("limits.maxDrawIndirectCount: %u\n", properties.limits.maxDrawIndirectCount);
        printf("limits.maxSamplerLodBias: %f\n", properties.limits.maxSamplerLodBias);
        printf("limits.maxSamplerAnisotropy: %f\n", properties.limits.maxSamplerAnisotropy);
        printf("limits.maxViewports: %u\n", properties.limits.maxViewports);
        printf("limits.maxViewportDimensions[0]: %u\n", properties.limits.maxViewportDimensions[0]);
        printf("limits.maxViewportDimensions[1]: %u\n", properties.limits.maxViewportDimensions[1]);
        printf("limits.viewportBoundsRange[0]: %f\n", properties.limits.viewportBoundsRange[0]);
        printf("limits.viewportBoundsRange[1]: %f\n", properties.limits.viewportBoundsRange[1]);
        printf("limits.viewportSubPixelBits: %u\n", properties.limits.viewportSubPixelBits);
        printf("limits.minMemoryMapAlignment: %lu\n", properties.limits.minMemoryMapAlignment);
        printf("limits.minTexelBufferOffsetAlignment: %llu\n", properties.limits.minTexelBufferOffsetAlignment);
        printf("limits.minUniformBufferOffsetAlignment: %llu\n", properties.limits.minUniformBufferOffsetAlignment);
        printf("limits.minStorageBufferOffsetAlignment: %llu\n", properties.limits.minStorageBufferOffsetAlignment);
        printf("limits.minTexelOffset: %d\n", properties.limits.minTexelOffset);
        printf("limits.maxTexelOffset: %u\n", properties.limits.maxTexelOffset);
        printf("limits.minTexelGatherOffset: %d\n", properties.limits.minTexelGatherOffset);
        printf("limits.maxTexelGatherOffset: %u\n", properties.limits.maxTexelGatherOffset);
        printf("limits.minInterpolationOffset: %f\n", properties.limits.minInterpolationOffset);
        printf("limits.maxInterpolationOffset: %f\n", properties.limits.maxInterpolationOffset);
        printf("limits.subPixelInterpolationOffsetBits: %u\n", properties.limits.subPixelInterpolationOffsetBits);
        printf("limits.maxFramebufferWidth: %u\n", properties.limits.maxFramebufferWidth);
        printf("limits.maxFramebufferHeight: %u\n", properties.limits.maxFramebufferHeight);
        printf("limits.maxFramebufferLayers: %u\n", properties.limits.maxFramebufferLayers);
        printf("limits.framebufferColorSampleCounts: %08x\n", properties.limits.framebufferColorSampleCounts);
        printf("limits.framebufferDepthSampleCounts: %08x\n", properties.limits.framebufferDepthSampleCounts);
        printf("limits.framebufferStencilSampleCounts: %08x\n", properties.limits.framebufferStencilSampleCounts);
        printf("limits.framebufferNoAttachmentsSampleCounts: %08x\n", properties.limits.framebufferNoAttachmentsSampleCounts);
        printf("limits.maxColorAttachments: %u\n", properties.limits.maxColorAttachments);
        printf("limits.sampledImageColorSampleCounts: %08x\n", properties.limits.sampledImageColorSampleCounts);
        printf("limits.sampledImageIntegerSampleCounts: %08x\n", properties.limits.sampledImageIntegerSampleCounts);
        printf("limits.sampledImageDepthSampleCounts: %08x\n", properties.limits.sampledImageDepthSampleCounts);
        printf("limits.sampledImageStencilSampleCounts: %08x\n", properties.limits.sampledImageStencilSampleCounts);
        printf("limits.storageImageSampleCounts: %08x\n", properties.limits.storageImageSampleCounts);
        printf("limits.maxSampleMaskWords: %u\n", properties.limits.maxSampleMaskWords);
        printf("limits.timestampComputeAndGraphics: %s\n", vulkan::extension::debug::string::to(properties.limits.timestampComputeAndGraphics));
        printf("limits.timestampPeriod: %f\n", properties.limits.timestampPeriod);
        printf("limits.maxClipDistances: %u\n", properties.limits.maxClipDistances);
        printf("limits.maxCullDistances: %u\n", properties.limits.maxCullDistances);
        printf("limits.maxCombinedClipAndCullDistances: %u\n", properties.limits.maxCombinedClipAndCullDistances);
        printf("limits.discreteQueuePriorities: %u\n", properties.limits.discreteQueuePriorities);
        printf("limits.pointSizeRange[0]: %f\n", properties.limits.pointSizeRange[0]);
        printf("limits.pointSizeRange[1]: %f\n", properties.limits.pointSizeRange[1]);
        printf("limits.lineWidthRange[0]: %f\n", properties.limits.lineWidthRange[0]);
        printf("limits.lineWidthRange[1]: %f\n", properties.limits.lineWidthRange[1]);
        printf("limits.pointSizeGranularity: %f\n", properties.limits.pointSizeGranularity);
        printf("limits.lineWidthGranularity: %f\n", properties.limits.lineWidthGranularity);
        printf("limits.strictLines: %s\n", vulkan::extension::debug::string::to(properties.limits.strictLines));
        printf("limits.standardSampleLocations: %s\n", vulkan::extension::debug::string::to(properties.limits.standardSampleLocations));
        printf("limits.optimalBufferCopyOffsetAlignment: %llu\n", properties.limits.optimalBufferCopyOffsetAlignment);
        printf("limits.optimalBufferCopyRowPitchAlignment: %llu\n", properties.limits.optimalBufferCopyRowPitchAlignment);
        printf("limits.nonCoherentAtomSize: %llu\n", properties.limits.nonCoherentAtomSize);
        printf("sparseProperties.residencyStandard2DBlockShape: %s\n", vulkan::extension::debug::string::to(properties.sparseProperties.residencyStandard2DBlockShape));
        printf("sparseProperties.residencyStandard2DMultisampleBlockShape: %s\n", vulkan::extension::debug::string::to(properties.sparseProperties.residencyStandard2DMultisampleBlockShape));
        printf("sparseProperties.residencyStandard3DBlockShape: %s\n", vulkan::extension::debug::string::to(properties.sparseProperties.residencyStandard3DBlockShape));
        printf("sparseProperties.residencyAlignedMipSize: %s\n", vulkan::extension::debug::string::to(properties.sparseProperties.residencyAlignedMipSize));
        printf("sparseProperties.residencyNonResidentStrict: %s\n", vulkan::extension::debug::string::to(properties.sparseProperties.residencyNonResidentStrict));
#endif // RELEASE_MODE

        return properties;
    }

    collection::continuous<VkQueueFamilyProperties> & device::get(collection::continuous<VkQueueFamilyProperties> & properties) const {
        properties.clean();

        unsigned int count = 0;
        vulkan::process::GetPhysicalDeviceQueueFamilyProperties(*handle, pointof(count), nullptr);

        if (count > 0) {
            properties.grow(count);

            vulkan::process::GetPhysicalDeviceQueueFamilyProperties(*handle, pointof(count), properties.storageGet());

#ifndef   RELEASE_MODE
            for (unsigned long i = 0; i < properties.sizeGet(); i = i + 1) {
                printf("properties[%lu].queueFlags: %08x\n", i, properties[i].queueFlags);
                printf("properties[%lu].queueCount: %u\n", i, properties[i].queueCount);
                printf("properties[%lu].timestampValidBits: %u\n", i, properties[i].timestampValidBits);
                printf("properties[%lu].minImageTransferGranularity.width: %u\n", i, properties[i].minImageTransferGranularity.width);
                printf("properties[%lu].minImageTransferGranularity.height: %u\n", i, properties[i].minImageTransferGranularity.height);
                printf("properties[%lu].minImageTransferGranularity.depth: %u\n", i, properties[i].minImageTransferGranularity.depth);
            }
#endif // RELEASE_MODE
        }

        return properties;
    }

    unsigned int device::queueFamilyIndexGet(unsigned int flags) const {
        for (unsigned int i = 0; i < queueSet.sizeGet(); i = i + 1) {
            if ((queueSet[i].queueFlags & flags) == flags) return i;
        }

        pokemon_develop_throw(return declaration::invalid);
    }

    VkPhysicalDeviceMemoryProperties & device::get(VkPhysicalDeviceMemoryProperties & properties) const {
        vulkan::process::GetPhysicalDeviceMemoryProperties(*handle, pointof(properties));

#ifndef   RELEASE_MODE
        printf("memoryTypeCount: %u\n", properties.memoryTypeCount);
        for (unsigned int i = 0; i < properties.memoryTypeCount; i = i + 1) {
            printf("memoryTypes[%u].propertyFlags: %08x\n", i, properties.memoryTypes[i].propertyFlags);
            printf("memoryTypes[%u].heapIndex: %u\n", i, properties.memoryTypes[i].heapIndex);
        }

        printf("memoryHeapCount: %u\n", properties.memoryHeapCount);
        for (unsigned int i = 0; i < properties.memoryHeapCount; i = i + 1) {
            printf("memoryHeaps[%u].flags: %08x\n", i, properties.memoryHeaps[i].flags);
            printf("memoryHeaps[%u].size: %llu\n", i, properties.memoryHeaps[i].size);
        }
#endif // RELEASE_MODE

        return properties;
    }

    collection::continuous<VkExtensionProperties> & device::get(const char* pLayerName, collection::continuous<VkExtensionProperties> & properties) const {
        properties.clean();

        unsigned int count = 0;

        vulkan::process::EnumerateDeviceExtensionProperties(*handle, pLayerName, pointof(count), nullptr);

        if (count > 0) {
            properties.grow(count);

            vulkan::process::EnumerateDeviceExtensionProperties(*handle, pLayerName, pointof(count), properties.storageGet());

#ifndef   RELEASE_MODE
            for (unsigned long i = 0; i < properties.sizeGet(); i = i + 1) {
                printf("properties[%lu].extensionName: %s\n", i, properties[i].extensionName);
                printf("properties[%lu].specVersion: %u\n", i, properties[i].specVersion);
            }
#endif // RELEASE_MODE
        }

        return properties;
    }

    collection::continuous<VkLayerProperties> & device::get(collection::continuous<VkLayerProperties> & properties) const {
        properties.clean();

        unsigned int count = 0;

        vulkan::process::EnumerateDeviceLayerProperties(*handle, pointof(count), nullptr);

        if (count > 0) {
            properties.grow(count);

            vulkan::process::EnumerateDeviceLayerProperties(*handle, pointof(count), properties.storageGet());

#ifndef   RELEASE_MODE
            for (unsigned long i = 0; i < properties.sizeGet(); i = i + 1) {
                printf("properties[%lu].layerName: %s\n", i, properties[i].layerName);
                printf("properties[%lu].description: %s\n", i, properties[i].description);
                printf("properties[%lu].implementationVersion: %u\n", i, properties[i].implementationVersion);
                printf("properties[%lu].specVersion: %u\n", i, properties[i].specVersion);
            }
#endif // RELEASE_MODE
        }

        return properties;
    }

    collection::continuous<VkSparseImageFormatProperties> & device::get(VkFormat format, VkImageType type, VkSampleCountFlagBits samples, VkImageUsageFlags usage, VkImageTiling tiling, collection::continuous<VkSparseImageFormatProperties> & properties) const {
        properties.clean();

        unsigned int count = 0;

        vulkan::process::GetPhysicalDeviceSparseImageFormatProperties(*handle, format, type, samples, usage, tiling, pointof(count), nullptr);

        if (count > 0) {
            properties.grow(count);

            vulkan::process::GetPhysicalDeviceSparseImageFormatProperties(*handle, format, type, samples, usage, tiling, pointof(count), properties.storageGet());

#ifndef   RELEASE_MODE
            for (unsigned long i = 0; i < properties.sizeGet(); i = i + 1) {
                printf("properties[%lu].layerName: %08x\n", i, properties[i].aspectMask);
                printf("properties[%lu].description: %08x\n", i, properties[i].flags);
                printf("properties[%lu].imageGranularity.width: %u\n", i, properties[i].imageGranularity.width);
                printf("properties[%lu].imageGranularity.height: %u\n", i, properties[i].imageGranularity.height);
                printf("properties[%lu].imageGranularity.depth: %u\n", i, properties[i].imageGranularity.depth);
            }
#endif // RELEASE_MODE
        }

        return properties;
    }

    VkDevice device::deviceGen(unsigned int flags, const collection::continuous<const char *> & layers, const collection::continuous<const char *> & extensions, const VkAllocationCallbacks * pAllocator) const {
        if (handle != nullptr) {
            const unsigned int index = queueFamilyIndexGet(flags);

            pokemon_develop_check(index == declaration::fail, return nullptr);

            const VkDeviceQueueCreateInfo deviceQueueCreateInfo = queueCreateInformationGen(index);
            const VkDeviceCreateInfo deviceCreateInfo = createInformationGen(deviceQueueCreateInfo, layers, extensions, feature);

            return deviceGen(deviceCreateInfo, nullptr);
        }

        return nullptr;

    }

}


