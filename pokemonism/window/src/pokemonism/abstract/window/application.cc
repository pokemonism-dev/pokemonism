/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */


#include "application.hh"

namespace pokemonism::abstract {

    pokemonism::window * window::application::windowGen(const window::config & config) {
        abstract::window * window = new abstract::window(adapter.windowGen(config));

        collection::add(this, window);

        return window;
    }

    abstract::window * window::application::del(abstract::window * node) {
        return collection::del(this, node);
    }

    window::application::application(void) : adapter(platform::window::application::get()), size(declaration::zero), head(nullptr), tail(nullptr) {

    }

    window::application::~application(void) {
        collection::clear(this);
    }

}