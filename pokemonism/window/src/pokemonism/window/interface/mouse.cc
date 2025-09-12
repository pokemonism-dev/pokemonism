/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */


#include "mouse.hh"

#include "mouse/on.hh"

namespace pokemonism::window::interface {

    MouseOn * Mouse::add(MouseOn * observer) {
        return Collection::add(this, observer);
    }

    MouseOn * Mouse::del(MouseOn * observer) {
        return Collection::del(this, observer);
    }

    void Mouse::clear(void) {
        Collection::clear(this);
    }

    Mouse::Mouse(void) : size(declaration::zero), head(nullptr), tail(nullptr) {

    }

    Mouse::~Mouse(void) {
        Collection::clear(this);
    }

}