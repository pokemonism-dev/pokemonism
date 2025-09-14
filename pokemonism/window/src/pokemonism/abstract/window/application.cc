/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 14, 2025
 */

#include <pokemonism/sdk/memorizer.hh>

#include "application.hh"

namespace pokemonism::abstract {

    interface::window * window::application::windowGen(const interface::window::config & config) {
        abstract::window * window = new abstract::window(adapter.windowGen(config));

        add(window);

        return window;
    }

    abstract::window * window::application::add(abstract::window * node) {
        return collection::add(this, node);
    }

    abstract::window * window::application::del(abstract::window * node) {
        return collection::del(this, node);
    }

    void window::application::clear(void) {
        while (head != nullptr) delete del(head);
    }

    window::application::application(platform::window::application & adapter) : size(declaration::zero), head(nullptr), tail(nullptr), adapter(adapter) {

    }

    window::application::~application(void) {
        clear();
    }

}