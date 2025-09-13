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
#include <pokemonism/window/platform/application.hh>

using namespace pokemonism;

// Observable<Window

int main(int argc, char ** argv) {

    // WindowObservable
    Application * o = new Application<ObservableWindowApplication<WindowApplication<>>>();
    return declaration::success;
}
#endif // __EXPORT_POKEMONISM_WINDOW_APPLICATION_EXAMPLE