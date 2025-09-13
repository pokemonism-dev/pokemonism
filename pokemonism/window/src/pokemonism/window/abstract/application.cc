/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */


#include "application.hh"

#include "../platform/application.hh"

namespace pokemonism::window {

    AbstractWindowApplication::AbstractWindowApplication(void) : size(declaration::zero), head(nullptr), tail(nullptr), adapter(PlatformWindowApplication::get())  {

    }

    AbstractWindowApplication::~AbstractWindowApplication(void) {

    }

    Window * AbstractWindowApplication::gen(const WindowConfig & config) {
        return adapter.gen(config);
    }

}