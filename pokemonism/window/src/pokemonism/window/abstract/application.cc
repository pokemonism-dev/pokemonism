/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */


#include "application.hh"

#include "window.hh"

#include "../platform/application.hh"

namespace pokemonism::window {

    AbstractWindow * AbstractWindowApplication::add(AbstractWindow * node) {
        return Collection::add(this, node);
    }

    AbstractWindow * AbstractWindowApplication::del(AbstractWindow * node) {
        return Collection::del(this, node);
    }

    void AbstractWindowApplication::clear(void) {
        Collection::clear(this);
    }

    AbstractWindowApplication::AbstractWindowApplication(void) : size(declaration::zero), head(nullptr), tail(nullptr), adapter(PlatformWindowApplication::get())  {

    }

    AbstractWindowApplication::~AbstractWindowApplication(void) {
        Collection::clear(this);
    }

    Window * AbstractWindowApplication::windowGen(const WindowConfig & config) {
        PlatformWindow * platform = adapter.windowGen(config);

        if (platform != nullptr) {
            AbstractWindow * window = new AbstractWindow(platform);
            add(window);
        }

        return platform;
    }

}