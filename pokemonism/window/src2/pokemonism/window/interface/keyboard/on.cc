/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */


#include "on.hh"

#include "../keyboard.hh"

namespace pokemonism::window::interface {

    KeyboardOn::KeyboardOn(void) : container(nullptr), prev(nullptr), next(nullptr) {
    }

    KeyboardOn::~KeyboardOn(void) {
        if (container != nullptr) container->del(this);
    }


}