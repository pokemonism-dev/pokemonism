/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_WINDOW_HH__
#define   __POKEMONISM_WINDOW_WINDOW_HH__

#include <pokemonism.hh>

namespace pokemonism::window {

    class Window {
    public:     inline Window(void);
    public:     inline virtual ~Window(void);
    public:     Window(const Window & o) = delete;
    public:     Window(Window && o) noexcept = delete;
    public:     Window & operator=(const Window & o) = delete;
    public:     Window & operator=(Window && o) noexcept = delete;
    };

    inline Window::Window(void) {

    }

    inline Window::~Window(void) {

    }

}

#endif // __POKEMONISM_WINDOW_WINDOW_HH__