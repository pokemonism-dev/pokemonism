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

    platform::window::application * platform::window::application::gen(void) {
        if(platform::window::application::singleton == nullptr) {
            platform::window::application::singleton = new platform::cocoa::application<platform::window::application>();
        }

        return platform::window::application::singleton;
    }

}