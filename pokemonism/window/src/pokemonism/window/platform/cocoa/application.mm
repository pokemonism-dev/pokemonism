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

      NSRect windowRect = NSMakeRect(100, 100, 400, 300);
      NSWindowStyleMask styleMask = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable | NSWindowStyleMaskMiniaturizable;

      self.window = [[NSWindow alloc] initWithContentRect: windowRect
                                      styleMask: styleMask
                                      backing: NSBackingStoreBuffered
                                      defer: NO];

      self.window.title = @"Hello, world!";

      // Label Create & Set
      NSRect labelRect = NSMakeRect(0, 0, 400, 300);
      NSTextField * label = [[NSTextField alloc] initWithFrame: labelRect];

      label.stringValue = @"Objective-C Window Application";
      label.alignment = NSTextAlignmentCenter;
      label.editable = NO;
      label.bordered = NO;
      label.drawsBackground = NO;

      printf("hello\n");

      [self.window.contentView addSubview: label];

      [self.window makeKeyAndOrderFront: nil];

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
