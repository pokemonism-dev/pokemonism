/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */

#include <pokemonism/sdk/application.hh>
#include <pokemonism/window.hh>
#include <pokemonism/vulkan/window.hh>

using namespace pokemonism;

int main(int argc, char ** argv) {
    pokemonism::application<vulkan::window::application<window::application>> * application = new pokemonism::application<vulkan::window::application<window::application>>();

    const collection::continuous<VkExtensionProperties> & extensions = application->extensionGet();
    const collection::continuous<VkLayerProperties> & layers = application->layerGet();

    application->extensionCat(VK_KHR_SURFACE_EXTENSION_NAME);
    application->extensionCat("VK_EXT_metal_surface");
    application->extensionCat("VK_MVK_macos_surface");

    application->layerCat("VK_LAYER_KHRONOS_validation");

    application->debugSet(nullptr);

    application->vulkanGen();

    const collection::continuous<vulkan::physical::device> & devices = application->deviceGet();


    for (unsigned long i = 0; i < devices.sizeGet(); i = i + 1) {
        VkPhysicalDeviceFeatures features;
        devices[i].get(features);
        VkPhysicalDeviceProperties properties;
        devices[i].get(properties);
        collection::continuous<VkQueueFamilyProperties> queueFamilyProperties;
        devices[i].get(queueFamilyProperties);
        VkPhysicalDeviceMemoryProperties memory;
        devices[i].get(memory);
        collection::continuous<VkLayerProperties> deviceLayers;
        devices[i].get(deviceLayers);
    }

    window::config config;  // ### TODO: BUILDER PATTERN

    config.title = "hello";
    config.rect.set(100, 100, 400, 300);

    pokemonism::window * window = application->windowGen(config);

    window->open();

    return pokemonism::run(application);
}
