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

    // pokemonism::window::Application & Application::applicationGen(void) {
    //
    // }
    //
    // pokemonism::window::Application & Application::applicationGet(void) {
    //
    // }

}

#else
#include <cstdio>
#include <pokemonism/sdk/application.hh>
#include <pokemonism/window/platform/application.hh>

using namespace pokemonism;
using namespace pokemonism::window;

// Observable<Window

int main(int argc, char ** argv) {

    Application<AbstractWindowApplication> * application = new Application<AbstractWindowApplication>();

    printf("%s\n", application->platformNameGet());

    application->run();

    delete application;
    //
    // // WindowObservable
    // Application * o = new Application<ObservableWindowApplication<WindowApplication<>>>();
    return declaration::success;
}
#endif // __EXPORT_POKEMONISM_WINDOW_APPLICATION_EXAMPLE