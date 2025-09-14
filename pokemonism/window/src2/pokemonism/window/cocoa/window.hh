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

#include <pokemonism/window/src/pokemonism/window.old/interface/window.hh>

#include <pokemonism/window/src/pokemonism/window.old/cocoa/mouse.hh>
#include <pokemonism/window/src/pokemonism/window.old/cocoa/monitor.hh>
#include <pokemonism/window/src/pokemonism/window.old/cocoa/keyboard.hh>

namespace pokemonism::window::cocoa {

    class Window : public pokemonism::window::interface::Window {
    protected:  struct Cocoa;
    protected:  Window::Cocoa * internal;
    public:     Mouse mouse;
    public:     Monitor monitor;
    public:     Keyboard keyboard;
    protected:  interface::Keyboard & keyboardGet(void) override { return keyboard; };
    protected:  interface::Mouse & mouseGet(void) override { return mouse; }
    protected:  interface::Monitor & monitorGet(void) override { return monitor; }
    public:     void titleSet(const char * name) override { }

    public:     int create(void) override;
    public:     int destroy(void) override;
    public:     Window(void);
    public:     ~Window(void) override;
    public:     Window(const Window & o) = delete;
    public:     Window(Window && o) noexcept = delete;
    public:     Window & operator=(const Window & o) = delete;
    public:     Window & operator=(Window && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_WINDOW_COCOA_WINDOW_HH__