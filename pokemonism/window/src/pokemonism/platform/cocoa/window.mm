/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */


#include "window.hh"

namespace pokemonism::platform::cocoa {

    window::window(const window::config & o) : internal(nil) {
        @autoreleasepool {
            NSRect contentRect = NSMakeRect(o.rect.x, o.rect.y, o.rect.width, o.rect.height);
            internal = [[NSWindow alloc] initWithContentRect: contentRect
                                                              styleMask: NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable
                                                              backing: NSBackingStoreBuffered
                                                              defer: NO];
        }
    }
//
//
//    public:     window(void) = delete;
//    public:     ~window(void) override;

}