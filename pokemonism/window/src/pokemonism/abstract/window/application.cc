/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 14, 2025
 */


#include "application.hh"

namespace pokemonism::abstract {

    interface::window * window::application::windowGen(const interface::window::config & config) {
        abstract::window * window = new abstract::window(adapter.windowGen(config));

        collection::add(this, window);

        return window;
    }

    window::application::application(platform::window::application & adapter) : size(declaration::zero), head(nullptr), tail(nullptr), adapter(adapter) {

    }

    window::application::~application(void) {
        collection::clear(this);
    }

}