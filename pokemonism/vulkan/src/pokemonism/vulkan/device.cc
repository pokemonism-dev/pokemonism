/**
 * @file
 * @brief
 * @details
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */


#include "device.hh"

namespace pokemonism::vulkan {

    device::device(VkDevice dev, const VkDeviceQueueCreateInfo * informationSet, unsigned int n) : handle(dev) {
        if (dev != nullptr && informationSet != nullptr && n > 0) {
            for (unsigned int i = 0; i < n; i = i + 1) {
                const VkDeviceQueueCreateInfo & info = informationSet[i];
                const unsigned long size = queueSet.sizeGet();
                queueSet.grow(info.queueCount);
                for (unsigned int j = 0; j < info.queueCount; j = j + 1) {
                    vulkan::process::GetDeviceQueue(dev, info.queueFamilyIndex,j, pointof(queueSet[size + i]));
                }
            }
        }
    }

}