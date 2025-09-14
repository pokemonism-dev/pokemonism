/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 14, 2025
 */

#include "window.hh"

#include "../../structure/style.hh"

namespace pokemonism::window {

    int CocoaPlatformWindow::create(void) {
        @autoreleasepool {
            if (window == nil) {
                NSRect rect = NSMakeRect(config.rect.x, config.rect.y, config.rect.width, config.rect.height);

                NSWindowStyleMask style = NSWindowStyleMaskBorderless;

                switch(config.style) {
                    case WindowStyleType::none:     style = (NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable | NSWindowStyleMaskMiniaturizable);     break;
                    default:                        style = (NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable | NSWindowStyleMaskMiniaturizable);     break;
                }

                window = [[NSWindow alloc] initWithContentRect: rect
                                                                styleMask: style
                                                                backing: NSBackingStoreBuffered
                                                                defer: NO];

                window.title = [NSString stringWithUTF8String: config.title.cstringGet()];

                [window makeKeyAndOrderFront: nil];
            }
        }
        return declaration::fail;
    }

    int CocoaPlatformWindow::destroy(void) {
        return declaration::fail;
    }

    CocoaPlatformWindow::CocoaPlatformWindow(const WindowConfig & config) : PlatformWindow(config) {
    }

    CocoaPlatformWindow::CocoaPlatformWindow(void) {
        window = nil;
    }

    CocoaPlatformWindow::~CocoaPlatformWindow(void) {
    }

}
