/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_PLATFORM_APPLICATION_HH__
#define   __POKEMONISM_WINDOW_PLATFORM_APPLICATION_HH__

#include <pokemonism/window/src/pokemonism/window.old/applicationable.hh>
#include <pokemonism/window/src/pokemonism/window.old/platform/window.hh>

namespace pokemonism::window {

    class AbstractWindowApplication;
    class PlatformWindow;

    class PlatformWindowApplication : public WindowApplicationable {
    public:     static PlatformWindowApplication & get(void);
    protected:  PlatformWindow * windowGen(const WindowConfig & config) override = 0;
    public:     PlatformWindowApplication(void);
    public:     ~PlatformWindowApplication(void) override;
    public:     PlatformWindowApplication(const PlatformWindowApplication & o) = delete;
    public:     PlatformWindowApplication(PlatformWindowApplication && o) noexcept = delete;
    public:     PlatformWindowApplication & operator=(const PlatformWindowApplication & o) = delete;
    public:     PlatformWindowApplication & operator=(PlatformWindowApplication && o) noexcept = delete;
    public:     friend AbstractWindowApplication;
    };

    inline PlatformWindowApplication::PlatformWindowApplication(void) {

    }

    inline PlatformWindowApplication::~PlatformWindowApplication(void) {

    }


}

#endif // __POKEMONISM_WINDOW_PLATFORM_APPLICATION_HH__