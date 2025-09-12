/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_INTERFACE_WINDOW_HH__
#define   __POKEMONISM_WINDOW_INTERFACE_WINDOW_HH__

#include <pokemonism/window/interface/mouse.hh>
#include <pokemonism/window/interface/keyboard.hh>

namespace pokemonism::window::interface {

    class Window {
    protected:  virtual interface::Keyboard & keyboardGet(void) const = 0;
    protected:  virtual interface::Mouse & mouseGet(void) const = 0;

    // public:     input::Keyboard & keyboard;
    // public:     input::Mouse & mouse;
    // public:     Monitor & monitor;
    public:     virtual void titleSet(const char * name) = 0;
    public:     Window(void) {}
    public:     virtual ~Window(void) {}
    public:     Window(const Window & o) = delete;
    public:     Window(Window && o) noexcept = delete;
    public:     Window & operator=(const Window & o) = delete;
    public:     Window & operator=(Window && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_WINDOW_INTERFACE_WINDOW_HH__