/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#import <Cocoa/Cocoa.h>

#include <cstdlib>
#include <cstring>

#include <pokemonism/sdk/allocator.hh>

#include "window.hh"

namespace pokemonism::window::cocoa {

//@interface Delegator : NSObject {
//
//}
//
//    @interface GLFWWindowDelegate : NSObject
//{
//    _GLFWwindow* window;
//}
//
//- (instancetype)initWithGlfwWindow:(_GLFWwindow *)initWindow;
//
//@end

    using Allocator = pokemonism::sdk::Allocator;

    struct Window::Cocoa {
    public:    NSWindow * window;
    public:    Cocoa(void) {
                   window = nil;
               }

//          NSRect frame = NSMakeRect(100, 100, 400, 300); // X, Y, Width, Height
//    NSWindow *window = [[NSWindow alloc] initWithContentRect:frame
//                                               styleMask:NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable
//                                                 backing:NSBackingStoreBuffered defer:NO];
//    public:    id window;
    };

    int Window::create(void) {
        printf("create\n");
        printf("internal->window: %p\n", internal->window);
        @autoreleasepool {
            [NSApplication sharedApplication];
            NSRect frame = NSMakeRect(100, 100, 400, 300);
            internal->window = [[NSWindow alloc] initWithContentRect: frame
                                                                      styleMask: NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable
                                                                      backing: NSBackingStoreBuffered
                                                                      defer: NO];
        }
        printf("internal->window: %p\n", internal->window);
        return declaration::success;
    }

    int Window::destroy(void) {
        return declaration::success;
    }

    Window::Window(void) : internal(nullptr), mouse(this), monitor(this), keyboard(this) {
        internal = new Window::Cocoa();
    }

    Window::~Window(void) {
        internal = static_cast<Window::Cocoa *>(Allocator::rel(internal));
    }

}
