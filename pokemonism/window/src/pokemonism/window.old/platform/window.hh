/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 14, 2025
 */

#ifndef   __POKEMONISM_WINDOW_HH__
#define   __POKEMONISM_WINDOW_HH__

#include <pokemonism/window/src/pokemonism/window.old/window.hh>
#include <pokemonism/window/src/pokemonism/window.old/config.hh>

namespace pokemonism::window {

    class PlatformWindow : public Window {
    protected:  WindowConfig config;
    protected:  inline explicit PlatformWindow(const WindowConfig & config);
    protected:  inline PlatformWindow(void);
    protected:  inline ~PlatformWindow(void) override;
    public:     PlatformWindow(const PlatformWindow & o) = delete;
    public:     PlatformWindow(PlatformWindow && o) noexcept = delete;
    public:     PlatformWindow & operator=(const PlatformWindow & o) = delete;
    public:     PlatformWindow & operator=(PlatformWindow && o) noexcept = delete;
    };

    inline PlatformWindow::PlatformWindow(const WindowConfig & config) : config(config) {

    }

    inline PlatformWindow::PlatformWindow(void) {

    }

    inline PlatformWindow::~PlatformWindow(void) {

    }

}

#endif // __POKEMONISM_WINDOW_HH__