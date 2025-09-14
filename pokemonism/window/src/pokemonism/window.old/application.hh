/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_APPLICATION_HH__
#define   __POKEMONISM_WINDOW_APPLICATION_HH__

#include <pokemonism.hh>

// #include <pokemonism/window/interface/application.hh>
// #include <pokemonism/window/platform/application.hh>

#include <pokemonism/window/src/pokemonism/window.old/abstract/application.hh>

namespace pokemonism::window {

    template <class Super = AbstractWindowApplication>
    class WindowApplication : public Super {

    };

}

#endif // __POKEMONISM_WINDOW_APPLICATION_HH__
