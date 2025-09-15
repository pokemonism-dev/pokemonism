/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <ApplicationServices/ApplicationServices.h>

#include "application.hh"

@implementation PokemonismWindowApplicationDelegator

- (void) applicationDidFinishLaunching:(NSNotification *) notification {
     // ### TODO: CHECK WHY NOT CALL THIS WHEN USE EVENT
     printf("notification\n");
  }

- (BOOL) applicationShouldTerminateAfterLastWindowClosed: (NSApplication *) sender {
      // ### TODO: CHECK WHY NOT CALL THIS WHEN USE EVENT
      printf("hello\n");
      return NO;
  }

@end

namespace pokemonism::platform {

    namespace cocoa {
        static platform::cocoa::window::application singleton;
    }

    platform::window::application & platform::window::application::get(void) {
        return platform::cocoa::singleton;
    }

    namespace cocoa {

        platform::cocoa::window::application & platform::cocoa::window::application::get(void) {
            return platform::cocoa::singleton;
        }

        platform::cocoa::window * window::application::windowGen(const window::config & config) {
            return new platform::cocoa::window(config);
        }

        window::application::application(void) : internal(nil), delegator(nil) {
            @autoreleasepool {
                internal = [NSApplication sharedApplication];
                delegator = [[PokemonismWindowApplicationDelegator alloc] init];
                delegator.application = this;
                [NSApp setDelegate: delegator];
            }
        }

        window::application::~application(void) {
        }

        int window::application::run(void) {
            @autoreleasepool {
                [internal run];
                printf("fail\n");
            }
            return declaration::success;
        }

        void window::application::eventPoll(void) {
            @autoreleasepool {
                while(true) {
                    NSEvent * event = [NSApp nextEventMatchingMask: NSEventMaskAny
                                                                    untilDate: [NSDate distantFuture]
                                                                    inMode: NSDefaultRunLoopMode
                                                                    dequeue: YES];

                    if(event == nil) break;

                    [NSApp sendEvent: event];
                }
            }
        }

        void window::application::eventWait(void) {
            @autoreleasepool {
                NSEvent * event = [NSApp nextEventMatchingMask: NSEventMaskAny
                                                                untilDate: [NSDate distantFuture]
                                                                inMode: NSDefaultRunLoopMode
                                                                dequeue: YES];

                [NSApp sendEvent: event];
                eventPoll();
            }
        }
    }
}