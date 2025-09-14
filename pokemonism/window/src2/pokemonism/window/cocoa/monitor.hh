/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_COCOA_MONITOR_HH__
#define   __POKEMONISM_WINDOW_COCOA_MONITOR_HH__

#include <pokemonism/window/src/pokemonism/window.old/interface/monitor.hh>

namespace pokemonism::window::cocoa {

    class Window;

    class Monitor : public pokemonism::window::interface::Monitor {
    protected:  Window * window;
    public:     explicit Monitor(Window * window);
    public:     Monitor(void) = delete;
    public:     ~Monitor(void) override;
    public:     Monitor(const Monitor & o) = delete;
    public:     Monitor(Monitor && o) noexcept = delete;
    public:     Monitor & operator=(const Monitor & o) = delete;
    public:     Monitor & operator=(Monitor && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_WINDOW_COCOA_MONITOR_HH__