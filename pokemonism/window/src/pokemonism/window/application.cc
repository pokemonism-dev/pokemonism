/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */


#include "application.hh"

#ifndef   __EXPORT_POKEMONISM_WINDOW_APPLICATION_EXAMPLE

namespace pokemonism::window {
}

#else
#include <cstdio>
#include <pokemonism/sdk/application.hh>
#include <pokemonism/window/platform/application.hh>
#include <pokemonism/window/config.hh>

using namespace pokemonism;
using namespace pokemonism::window;

int main(int argc, char ** argv) {

    Application<AbstractWindowApplication> * application = Application<AbstractWindowApplication>::gen();

    printf("%s\n", application->platformNameGet());

    WindowConfig config;

    config.title = "hello world!";
    config.rect.set(100, 100, 400, 300);
    Window * window = application->windowGen(config);

    window->create();

    return Application<AbstractWindowApplication>::exec(application);
}
#endif // __EXPORT_POKEMONISM_WINDOW_APPLICATION_EXAMPLE