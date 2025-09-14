/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_PLATFORM_HH__
#define   __POKEMONISM_WINDOW_PLATFORM_HH__

#include <pokemonism/window/src/pokemonism/window.old/cocoa/window.hh>

namespace pokemonism::window::platform {

    using Window = pokemonism::window::cocoa::Window;

    // using Mouse = pokemonism::window::cocoa::Mouse;
    // using Monitor = pokemonism::window::cocoa::Monitor;
    // using Keyboard = pokemonism::window::cocoa::Keyboard;



    // struct WindowPlatform {
    // public:     constexpr static unsigned int cocoa = 1;
    // public:     struct Angle {
    //             public:     constexpr static unsigned int metal = 1;
    //             };
    // };


}

#endif // __POKEMONISM_PLATFORM_HH__