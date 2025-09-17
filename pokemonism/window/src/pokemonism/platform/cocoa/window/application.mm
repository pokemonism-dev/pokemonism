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

    platform::window::application * platform::window::application::get(void) {
        return platform::window::application::singleton;
    }

    namespace cocoa {

        template <class super>
        platform::cocoa::window::application<super> * platform::cocoa::window::application<super>::get(void) {
            if(platform::window::application::singleton == nullptr) {
                static platform::cocoa::window::application<super> instance;
                platform::cocoa::window::application<super>::singleton = pointof(instance);
                platform::window::application::singleton = platform::cocoa::window::application<super>::singleton;
            }

            return platform::window::application::singleton;
        }

        template <class super>
        platform::cocoa::window * window::application<super>::windowGen(const window::config & config) {
            return new platform::cocoa::window(config);
        }

        template <class super>
        window::application<super>::application(void) : internal(nil), delegator(nil) {
            @autoreleasepool {
                internal = [NSApplication sharedApplication];
                delegator = [[PokemonismWindowApplicationDelegator alloc] init];
                delegator.application = this;
                [NSApp setDelegate: delegator];
            }
        }

        template <class super>
        window::application<super>::~application(void) {
        }

        template <class super>
        int window::application<super>::run(void) {
            @autoreleasepool {
                [internal run];
                printf("fail\n");
            }
            return declaration::success;
        }

        template <class super>
        void window::application<super>::eventPoll(void) {
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

        template <class super>
        void window::application<super>::eventWait(void) {
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