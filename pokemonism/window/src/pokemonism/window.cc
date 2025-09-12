/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */


#include "window.hh"

#include "window/application.hh"
#include "window/interface/window.hh"

namespace pokemonism::window {

    Window::Window(interface::Window * window) :
    container(nullptr), prev(nullptr), next(nullptr), window(window),
    keyboard(window->keyboardGet()), mouse(window->mouseGet()), monitor(window->monitorGet()) {

    }

    Window::~Window(void) {
        if (container != nullptr) container->del(this);
        window = Allocator::del(window);
    }

}

#ifdef    __EXPORT_POKEMONISM_WINDOW_EXAMPLE

using namespace pokemonism::window;

int main(int argc, char ** argv) {
    Application * application = new pokemonism::window::Application();

    printf("hello\n");
    return application->run();
}
#endif // __EXPORT_POKEMONISM_WINDOW_EXAMPLE
