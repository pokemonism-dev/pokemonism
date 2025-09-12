/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_COCOA_WINDOW_HH__
#define   __POKEMONISM_WINDOW_COCOA_WINDOW_HH__

#include <Carbon/Carbon.h>
#include <Cocoa/Cocoa.h>

#include <pokemonism/window.hh>

#include <pokemonism/window/cocoa/monitor.hh>
#include <pokemonism/window/cocoa/input/mouse.hh>
#include <pokemonism/window/cocoa/input/keyboard.hh>

namespace pokemonism::window::cocoa {

    // class Window : public pokemonism::window::Window {
    // protected:  id object;
    // protected:  cocoa::input::Keyboard keyboard;
    // protected:  cocoa::input::Mouse mouse;
    // protected:  cocoa::Monitor monitor;
    // public:     Window(void);
    // public:     friend cocoa::input::Mouse;
    //
    //
    // };

}

#endif // __POKEMONISM_WINDOW_COCOA_WINDOW_HH__