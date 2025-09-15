/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */

#ifndef   __POKEMONISM_ABSTRACT_WINDOW_HH__
#define   __POKEMONISM_ABSTRACT_WINDOW_HH__

#include <pokemonism/window.hh>

namespace pokemonism::abstract {

    inline int window::open(void) {
        pokemon_develop_check(adapter == nullptr, return declaration::fail);

        return adapter->open();
    }

    inline int window::close(void) {
        pokemon_develop_check(adapter == nullptr, return declaration::fail);

        return adapter->close();
    }

    inline window::window(platform::window * adapter) : container(nullptr), prev(nullptr), next(nullptr), adapter(adapter) {

    }

}

#endif // __POKEMONISM_ABSTRACT_WINDOW_HH__