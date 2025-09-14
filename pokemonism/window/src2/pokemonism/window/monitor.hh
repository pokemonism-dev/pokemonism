/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_MONITOR_HH__
#define   __POKEMONISM_WINDOW_MONITOR_HH__

#include <pokemonism/window/src/pokemonism/window.old/graphics/videomode.hh>
#include <pokemonism/window/src/pokemonism/window.old/graphics/gammaramp.hh>

namespace pokemonism::window {

    class Monitor {
    // public:     virtual void positionGet(int * x, int * y) = 0;
    // public:     virtual void scaleGet(float * x, float * y) = 0;
    // public:     virtual void workareaGet(int * x, int * y, int * width, int * height) = 0;
    // public:     virtual graphics::VideoModeList * videoModeListGet(void) = 0;
    // public:     virtual graphics::VideoMode * videoModeGet(void) = 0;
    // public:     virtual void gammaRampSet(graphics::GammaRamp * o) = 0;
    // public:     virtual graphics::GammaRamp * gammaRampGet(void) = 0;
    public:     Monitor(void) {}
    public:     virtual ~Monitor(void) {}
    public:     Monitor(const Monitor & o) = delete;
    public:     Monitor(Monitor && o) noexcept = delete;
    public:     Monitor & operator=(const Monitor & o) = delete;
    public:     Monitor & operator=(Monitor && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_WINDOW_MONITOR_HH__