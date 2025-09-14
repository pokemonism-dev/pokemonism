/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 14, 2025
 */


#include "window.hh"

namespace pokemonism::abstract {

    window::window(platform::window * adapter) : container(nullptr), prev(nullptr), next(nullptr), adapter(nullptr) {
        pokemon_develop_check(adapter == nullptr, return);
    }

    window::window(void) : container(nullptr), prev(nullptr), next(nullptr), adapter(nullptr) {

    }

    window::~window(void) {
        if (container != nullptr) container->del(this);
    }

}