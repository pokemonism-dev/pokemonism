/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_COCOA_MOUSE_HH__
#define   __POKEMONISM_WINDOW_COCOA_MOUSE_HH__

#include <pokemonism/window/src/pokemonism/window.old/interface/mouse.hh>

namespace pokemonism::window::cocoa {

    class Window;

    class Mouse : public pokemonism::window::interface::Mouse {
    protected:  Window * window;
    public:     void passthroughSet(bool enable) override;
    public:     explicit Mouse(Window * window);
    public:     Mouse(void) = delete;
    public:     ~Mouse(void) override;
    public:     Mouse(const Mouse & o) = delete;
    public:     Mouse(Mouse && o) noexcept = delete;
    public:     Mouse & operator=(const Mouse & o) = delete;
    public:     Mouse & operator=(Mouse && o) noexcept = delete;
    public:     friend Window;
    };

}

#endif // __POKEMONISM_WINDOW_COCOA_MOUSE_HH__