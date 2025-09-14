/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */


#include "application.hh"

@implementation PokemonismWindowApplicationDelegator

- (void) applicationDidFinishLaunching:(NSNotification *) notification {
  }

- (BOOL) applicationShouldTerminateAfterLastWindowClosed: (NSApplication *) sender {
      return YES;
  }

@end

namespace pokemonism::platform {

    namespace cocoa {
        pokemonism::platform::cocoa::window::application singleton;
    }

    platform::window::application & platform::window::application::get(void) {
        return pokemonism::platform::cocoa::singleton;
    }

    namespace cocoa {

        platform::cocoa::window * window::application::windowGen(const window::config & config) {
            return nullptr;
        }

        window::application::application(void) : internal(nil) {
            @autoreleasepool {
                internal = [NSApplication sharedApplication];
                delegator = [[PokemonismWindowApplicationDelegator alloc] init];
                delegator.application = this;
                internal.delegate = delegator;
            }
        }

        window::application::~application(void) {
        }

        int window::application::run(void) {
            @autoreleasepool {
                [internal run];
            }
            return declaration::success;
        }
    }
}