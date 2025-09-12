/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_COCOA_INPUT_KEYBOARD_HH__
#define   __POKEMONISM_WINDOW_COCOA_INPUT_KEYBOARD_HH__

#include <pokemonism/window/input/keyboard.hh>

namespace pokemonism::window::cocoa {

    class Window;

    namespace input {

        class Keyboard : public pokemonism::window::input::Keyboard {
        protected:  cocoa::Window * window;
        public:     Keyboard(void);
        public:     ~Keyboard(void) override {}
        public:     Keyboard(const Keyboard & o) = delete;
        public:     Keyboard(Keyboard && o) noexcept = delete;
        public:     Keyboard & operator=(const Keyboard & o) = delete;
        public:     Keyboard & operator=(Keyboard && o) noexcept = delete;
        };

    }

}

#endif // __POKEMONISM_WINDOW_COCOA_INPUT_KEYBOARD_HH__