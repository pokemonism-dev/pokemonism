/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */


#include "keyboard.hh"

#include "keyboard/on.hh"

namespace pokemonism::window::input {

    KeyboardOn * Keyboard::add(KeyboardOn * observer) {
        return Collection::add(this, observer);
    }

    KeyboardOn * Keyboard::del(KeyboardOn * observer) {
        return Collection::del(this, observer);
    }

    void Keyboard::clear(void) {
        Collection::clear(this);
    }

    Keyboard::Keyboard(void) : size(declaration::zero), head(nullptr), tail(nullptr) {

    }

    Keyboard::~Keyboard(void) {
        Collection::clear(this);
    }

}