/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */


#include "input.hh"

namespace pokemonism::sdk {

    console::input & console::input::get(void) {
        static console::input singleton;

        return singleton;
    }

}