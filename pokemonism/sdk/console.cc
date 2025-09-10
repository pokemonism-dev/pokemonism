/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */


#include "console.hh"

namespace pokemonism::sdk {

    console::input & console::in = console::input::get();
    console::output & console::out = console::output::get();

}