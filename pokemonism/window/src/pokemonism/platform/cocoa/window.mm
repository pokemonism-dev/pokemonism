/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */


#include "window.hh"

@implementation PokemonismWindowDelegator

@end

namespace pokemonism::platform::cocoa {

    int window::open(void) {
        [internal makeKeyAndOrderFront: nil];

        return declaration::success;
    }

    int window::close(void) {
        // TODO: SEND CLOSE

        return declaration::success;
    }

    window::window(const window::config & o) : internal(nil), delegator(nil) {
        @autoreleasepool {
            NSRect contentRect = NSMakeRect(o.rect.x, o.rect.y, o.rect.width, o.rect.height);
            internal = [[NSWindow alloc] initWithContentRect: contentRect
                                                              styleMask: NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable
                                                              backing: NSBackingStoreBuffered
                                                              defer: NO];

            internal.title = [NSString stringWithUTF8String: o.title.stringGet()];

            delegator = [[PokemonismWindowDelegator alloc] init];
            delegator.window = this;
        }
    }

    window::~window(void) {
        // TODO: REMOVE `internal` OBJECT
    }

}