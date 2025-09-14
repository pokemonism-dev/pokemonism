/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 14, 2025
 */

#ifndef   __POKEMONISM_WINDOW_PLATFORM_COCOA_WINDOW_HH__
#define   __POKEMONISM_WINDOW_PLATFORM_COCOA_WINDOW_HH__

#import <Cocoa/Cocoa.h>

#include <pokemonism/window/platform/window.hh>

namespace pokemonism::window {

    class CocoaPlatformWindow : public PlatformWindow {
    protected:  NSWindow * window;
    public:     CocoaPlatformWindow(void);
    public:     ~CocoaPlatformWindow(void) override;
    public:     CocoaPlatformWindow(const CocoaPlatformWindow & o) = delete;
    public:     CocoaPlatformWindow(CocoaPlatformWindow && o) noexcept = delete;
    public:     CocoaPlatformWindow & operator=(const CocoaPlatformWindow & o) = delete;
    public:     CocoaPlatformWindow & operator=(CocoaPlatformWindow && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_WINDOW_PLATFORM_COCOA_WINDOW_HH__