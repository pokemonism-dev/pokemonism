/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */


#include "application.hh"

#include "../window.hh"

namespace pokemonism::window {

    Window * Application::add(Window * node) {
        return Collection::add(this, node);
    }

    Window * Application::del(Window * node) {
        return Collection::del(this, node);
    }

    void Application::clear(void) {
        Collection::clear(this);
    }

    int Application::run(void) {
        while (size > 0) wait(0, 1000);

        return declaration::success;
    }

    Application::Window * Application::gen(const WindowCfg & config) {
        return nullptr;
    }

    Application::Application(void) : size(declaration::zero), head(nullptr), tail(nullptr) {

    }

    Application::~Application(void) {
        Collection::clear(this);
    }

}

#ifndef   __EXPORT_POKEMONISM_WINDOW_APPLICATION_EXAMPLE

using namespace pokemonism::window;

int main(int argc, char ** argv) {
    Application * application = new Application();
    return application->run();
}
#endif // __EXPORT_POKEMONISM_WINDOW_APPLICATION_EXAMPLE
