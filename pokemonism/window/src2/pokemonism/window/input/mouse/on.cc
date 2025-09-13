/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */


#include "on.hh"

#include "../mouse.hh"

namespace pokemonism::window::input {

    MouseOn::MouseOn(void) : container(nullptr), prev(nullptr), next(nullptr) {

    }

    MouseOn::~MouseOn(void) {
        if (container) container->del(this);
    }


}