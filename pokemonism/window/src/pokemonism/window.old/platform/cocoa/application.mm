/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#include <Cocoa/Cocoa.h>

#include "application.hh"

#include "../application.hh"

@implementation CocoaPlatformWindowApplicationDelegator

- (void) applicationDidFinishLaunching: (NSNotification *) notification {

  }

- (BOOL) applicationShouldTerminateAfterLastWindowClosed: (NSApplication *) sender {
        return YES;
  }

@end

namespace pokemonism::window {

    CocoaPlatformWindowApplication::CocoaPlatformWindowApplication(void) {
        application = nil;
        delegator = nil;
    }

    CocoaPlatformWindowApplication::~CocoaPlatformWindowApplication(void) {
    }

    const char * CocoaPlatformWindowApplication::platformNameGet(void) const noexcept {
        return "cocoa";
    }

    CocoaPlatformWindow * CocoaPlatformWindowApplication::windowGen(const WindowConfig & config) {
        CocoaPlatformWindow * window = new CocoaPlatformWindow(config);

        return window;
    }

    int CocoaPlatformWindowApplication::run(void) {
        @autoreleasepool {
            application = [NSApplication sharedApplication];

            delegator = [[CocoaPlatformWindowApplicationDelegator alloc] init];
            application.delegate = delegator;
            [application run];
        }
        return declaration::success;
    }

    PlatformWindowApplication & PlatformWindowApplication::get(void) {
        static CocoaPlatformWindowApplication singleton;

        return singleton;
    }

}
