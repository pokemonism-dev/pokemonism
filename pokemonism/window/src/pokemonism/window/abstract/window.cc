/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */


#include "window.hh"

#include "application.hh"

namespace pokemonism::window {

    AbstractWindow::~AbstractWindow(void) {
        if (container != nullptr) container->del(this);
    }

}