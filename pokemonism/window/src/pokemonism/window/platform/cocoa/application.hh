/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_PLATFORM_COCOA_APPLICATION_HH__
#define   __POKEMONISM_WINDOW_PLATFORM_COCOA_APPLICATION_HH__

#import <Cocoa/Cocoa.h>

@interface CocoaPlatformWindowApplicationDelegator : NSObject <NSApplicationDelegate>;

@property (nonatomic, strong) NSWindow * window;

@end


#include <pokemonism/window/platform/application.hh>
#include <pokemonism/window/platform/cocoa/window.hh>
#include <pokemonism/window/structure/videomode.hh>

namespace pokemonism::window {
    class CocoaPlatformWindowApplication : public PlatformWindowApplication {
    protected:  NSApplication * application;
    protected:  CocoaPlatformWindowApplicationDelegator * delegator;
    protected:  WindowVideoMode videoMode;
    public:     const char * platformNameGet(void) const noexcept override;
    public:     CocoaPlatformWindow * windowGen(const WindowConfig & config) override;
    protected:  int run(void) override;
    protected:  CocoaPlatformWindowApplication(void);
    protected:  ~CocoaPlatformWindowApplication(void) override;
    public:     CocoaPlatformWindowApplication(const CocoaPlatformWindowApplication & o) = delete;
    public:     CocoaPlatformWindowApplication(CocoaPlatformWindowApplication && o) noexcept = delete;
    public:     CocoaPlatformWindowApplication & operator=(const CocoaPlatformWindowApplication & o) = delete;
    public:     CocoaPlatformWindowApplication & operator=(CocoaPlatformWindowApplication && o) noexcept = delete;
    public:     friend PlatformWindowApplication;
    };
}

#endif // __POKEMONISM_WINDOW_PLATFORM_COCOA_APPLICATION_HH__