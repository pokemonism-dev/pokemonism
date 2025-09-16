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

    const collection::continuous<VkExtensionProperties> & extensions = application->extensionLoad();
    const collection::continuous<VkLayerProperties> & layers = application->layerLoad();

    application->extensionCat(VK_KHR_SURFACE_EXTENSION_NAME);
    application->extensionCat("VK_EXT_metal_surface");
    application->extensionCat("VK_MVK_macos_surface");

    application->layerCat("VK_LAYER_KHRONOS_validation");

    application->debugSet(nullptr);

    application->vulkanLoad();

    const collection::continuous<vulkan::physical::device> & devices = application->physicalDeviceGet();

    pokemon_develop_check(devices.sizeGet() == 0, return pokemonism::goodbye(application));

    const unsigned int index = devices[0].queueFamilyIndexGet(vulkan::queue::flag::graphics | vulkan::queue::flag::compute);

    pokemon_develop_check(index == declaration::invalid, return pokemonism::goodbye(application));

    VkDeviceQueueCreateInfo deviceQueueCreateInfo = devices[0].queueCreateInformationGen(index);
    VkDeviceCreateInfo deviceCreateInfo = devices[0].createInformationGen(deviceQueueCreateInfo, application->layerNameGet(), application->extensionNameGet(), devices[0].featuresGet());
    // devices[0].deviceGen(deviceCreateInfo, nullptr);





    // application->deviceGen()

#ifndef   RELEASE_MODE
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
#endif // RELEASE_MODE

    window::config config;  // ### TODO: BUILDER PATTERN

    config.title = "hello";
    config.rect.set(100, 100, 400, 300);

    pokemonism::window * window = application->windowGen(config);

    window->open();

    return pokemonism::run(application);
}
