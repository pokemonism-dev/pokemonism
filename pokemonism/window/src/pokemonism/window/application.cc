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

    Application::Application(void) : size(declaration::zero), head(nullptr), tail(nullptr) {

    }

    Application::~Application(void) {
        Collection::clear(this);
    }

}