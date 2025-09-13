/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_INPUT_MOUSE_POS_HH__
#define   __POKEMONISM_WINDOW_INPUT_MOUSE_POS_HH__

#include <pokemonism.hh>

namespace pokemonism::window::input {

    struct MousePos {
    public:     MousePos(void) {}
    public:     ~MousePos(void) {}
    public:     MousePos(const MousePos & o) {}
    public:     MousePos(MousePos && o) noexcept {}
    public:     MousePos & operator=(const MousePos & o) { return *this; }
    public:     MousePos & operator=(MousePos && o) noexcept { return *this; }
    };

}

#endif // __POKEMONISM_WINDOW_INPUT_MOUSE_POS_HH__