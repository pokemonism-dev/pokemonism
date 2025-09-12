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
#include <pokemonism/window/interface/monitor.hh>
#include <pokemonism/window/interface/keyboard.hh>

namespace pokemonism::window {

    class Window;

    namespace interface {

        class Window {
        protected:  virtual interface::Keyboard & keyboardGet(void) const = 0;
        protected:  virtual interface::Mouse & mouseGet(void) const = 0;
        protected:  virtual interface::Monitor & monitorGet(void) const = 0;
        public:     virtual void titleSet(const char * name) = 0;
        public:     inline Window(void);
        public:     inline virtual ~Window(void);
        public:     Window(const Window & o) = delete;
        public:     Window(Window && o) noexcept = delete;
        public:     Window & operator=(const Window & o) = delete;
        public:     Window & operator=(Window && o) noexcept = delete;
        public:     friend window::Window;
        };

        inline Window::Window(void) {}

        inline Window::~Window(void) {}

    }

}

#endif // __POKEMONISM_WINDOW_INTERFACE_WINDOW_HH__