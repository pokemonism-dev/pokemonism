/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 15, 2025
 */

#ifndef   __POKEMONISM_PLATFORM_COCOA_WINDOW_HH__
#define   __POKEMONISM_PLATFORM_COCOA_WINDOW_HH__

#include <pokemonism/window.hh>

#ifdef    __OBJC__
#import <Cocoa/Cocoa.h>

@interface PokemonismWindowDelegator : NSObject <NSWindowDelegate>

@property (nonatomic, assign) pokemonism::platform::window * window;

@end
#else
typedef void NSWindow;
typedef void PokemonismWindowDelegator;
#endif // __OBJC__

namespace pokemonism::platform::cocoa {

    template <class super = pokemonism::platform::window>
    class window : public super {
    protected:  NSWindow * internal;
    protected:  PokemonismWindowDelegator * delegator;
    public:     int open(void) override;
    public:     int close(void) override;
    public:     explicit window(const pokemonism::window::config & o);
    public:     window(void) = delete;
    public:     ~window(void) override;
    public:     window(const platform::cocoa::window<super> & o) = delete;
    public:     window(platform::cocoa::window<super> && o) noexcept = delete;
    public:     platform::cocoa::window<super> & operator=(const platform::cocoa::window<super> & o) = delete;
    public:     platform::cocoa::window<super> & operator=(platform::cocoa::window<super> && o) noexcept = delete;
    };

    template <class super>
    int window<super>::close(void) {
        // ### TODO: SEND CLOSE

        return declaration::success;
    }

    template <class super>
    window<super>::~window(void) {
        // ### TODO: REMOVE `internal` OBJECT
    }

#ifdef    __OBJC__
    template <class super>
    int window<super>::open(void) {

        [internal makeKeyAndOrderFront: nil];

        return declaration::success;
    }

    template <class super>
    window<super>::window(const pokemonism::window::config & o) : internal(nil), delegator(nil) {
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
#else
    /**
     * Objective C 로 컴파일 시에 링크되지 않습니다.
     * IDE 에서 오류 출력을 피하기 위한 더미 코드입니다.
     */
    template <class super>
    int window<super>::open(void) {
        pokemon_develop_throw(return declaration::success);
    }

    template <class super>
    window<super>::window(const pokemonism::window::config & o) : internal(nil), delegator(nil) {
        pokemon_develop_throw(void(0));
    }

#endif // __OBJC__

}

#endif // __POKEMONISM_PLATFORM_COCOA_WINDOW_HH__