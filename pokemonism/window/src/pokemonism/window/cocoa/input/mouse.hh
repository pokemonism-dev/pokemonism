/**
 * @file
 * @brief
 * @details
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_COCOA_INPUT_MOUSE_HH__
#define   __POKEMONISM_WINDOW_COCOA_INPUT_MOUSE_HH__

#include <Carbon/Carbon.h>
#include <Cocoa/Cocoa.h>

#include <pokemonism/window/input/mouse.hh>

namespace pokemonism::window::cocoa {

    class Window;

    namespace input {

        class Mouse : public pokemonism::window::input::Mouse {
        protected:  cocoa::Window * window;
        public:     void rawMouseMotionSet(bool enable) override;
        public:     bool rawMouseMotionSupportGet(void) const override;
        public:     void passthroughSet(bool enable) override;
        protected:  virtual void windowSet(cocoa::Window * o);
        public:     Mouse(void) : window(nullptr) {}
        public:     ~Mouse(void) override {}
        public:     Mouse(const Mouse & o) = delete;
        public:     Mouse(Mouse && o) noexcept = delete;
        public:     Mouse & operator=(const Mouse & o) = delete;
        public:     Mouse & operator=(Mouse && o) noexcept = delete;;
        public:     friend class cocoa::Window;
        };


    }



}

#endif // __POKEMONISM_WINDOW_COCOA_INPUT_MOUSE_HH__