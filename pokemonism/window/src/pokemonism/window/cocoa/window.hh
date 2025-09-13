/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_COCOA_WINDOW_HH__
#define   __POKEMONISM_WINDOW_COCOA_WINDOW_HH__

#include <Cocoa/Cocoa.h>

#include <pokemonism/window/interface/window.hh>

#include <pokemonism/window/cocoa/mouse.hh>
#include <pokemonism/window/cocoa/monitor.hh>
#include <pokemonism/window/cocoa/keyboard.hh>

namespace pokemonism::window::cocoa {

    class Window : public pokemonism::window::interface::Window {
    protected:  id object;
    public:     Mouse mouse;
    public:     Monitor monitor;
    public:     Keyboard keyboard;
    public:     Window(void);
    public:     ~Window(void) override;
    public:     Window(const Window & o) = delete;
    public:     Window(Window && o) noexcept = delete;
    public:     Window & operator=(const Window & o) = delete;
    public:     Window & operator=(Window && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_WINDOW_COCOA_WINDOW_HH__