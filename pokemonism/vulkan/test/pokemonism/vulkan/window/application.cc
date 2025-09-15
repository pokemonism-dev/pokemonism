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

    window::config config;  // ### TODO: BUILDER PATTERN

    config.title = "hello";
    config.rect.set(100, 100, 400, 300);

    pokemonism::window * window = application->windowGen(config);

    window->open();

    return pokemonism::run(application);
}
