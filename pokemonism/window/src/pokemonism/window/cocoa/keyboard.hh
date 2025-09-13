/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_COCOA_KEYBOARD_HH__
#define   __POKEMONISM_WINDOW_COCOA_KEYBOARD_HH__

#include <pokemonism/window/interface/keyboard.hh>

namespace pokemonism::window::cocoa {

    class Window;

    class Keyboard : public pokemonism::window::interface::Keyboard {
    protected:  Window * window;
    public:     explicit Keyboard(Window * window);
    public:     Keyboard(void) = delete;
    public:     ~Keyboard(void) override;
    public:     Keyboard(const Keyboard & o) = delete;
    public:     Keyboard(Keyboard && o) noexcept = delete;
    public:     Keyboard & operator=(const Keyboard & o) = delete;
    public:     Keyboard & operator=(Keyboard && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_WINDOW_COCOA_KEYBOARD_HH__