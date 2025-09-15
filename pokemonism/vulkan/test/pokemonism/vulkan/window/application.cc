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
    // pokemonism::application<window::application> * application = new pokemonism::application<window::application>();
    pokemonism::application<vulkan::window::application<window::application>> * application = new pokemonism::application<vulkan::window::application<window::application>>();

    window::config config;

    config.title = "hello";
    config.rect.set(100, 100, 400, 300);

    pokemonism::window * window = application->windowGen(config);
    application->vulkanRet();

    window->open();

    return pokemonism::run(application);
}
