/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 18, 2025
 */

#ifndef   __POKEMONISM_PLATFORM_COCOA_APPLICATION_HH__
#define   __POKEMONISM_PLATFORM_COCOA_APPLICATION_HH__

#include <pokemonism/platform/cocoa/window.hh>

#ifdef    __OBJC__
#import <Cocoa/Cocoa.h>

@interface PokemonismWindowApplicationDelegator : NSObject <NSApplicationDelegate>

@property (nonatomic, assign) pokemonism::platform::window::application * application;

@end
#else
typedef void NSApplication;
typedef void PokemonismWindowApplicationDelegator;
#endif // __OBJC__

namespace pokemonism::platform::cocoa {

    template <class super = platform::window::application>
    class application : public super {
    protected:  NSApplication * internal;
    protected:  PokemonismWindowApplicationDelegator * delegator;
    public:     inline const char * platformNameGet(void) const noexcept override;
    public:     platform::window * windowGen(const pokemonism::window::config & config) override;
    public:     void eventWait(void) override;
    public:     void eventPoll(void) override;
    public:     int run(void) override;
    public:     application(void);
    public:     ~application(void) override;
    public:     application(const platform::cocoa::application<super> & o) = delete;
    public:     application(platform::cocoa::application<super> && o) noexcept = delete;
    public:     platform::cocoa::application<super> & operator=(const platform::cocoa::application<super> & o) = delete;
    public:     platform::cocoa::application<super> & operator=(platform::cocoa::application<super> && o) noexcept = delete;
    };

    template <class super>
    inline const char * application<super>::platformNameGet(void) const noexcept {
        return "cocoa";
    }

    template <class super>
    platform::window * application<super>::windowGen(const pokemonism::window::config & config) {
        return new platform::cocoa::window<>(config);
    }

    template <class super>
    application<super>::~application(void) {
    }

#ifdef    __OBJC__
    template <class super>
    application<super>::application(void) : internal(nil), delegator(nil) {

        @autoreleasepool {
            internal = [NSApplication sharedApplication];
            delegator = [[PokemonismWindowApplicationDelegator alloc] init];
            delegator.application = this;
            [NSApp setDelegate: delegator];
        }
    }

    template <class super>
    int application<super>::run(void) {
        @autoreleasepool {
            [internal run];
            printf("fail\n");
        }
        return declaration::success;
    }

    template <class super>
    void application<super>::eventPoll(void) {
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
    void application<super>::eventWait(void) {
        @autoreleasepool {
            NSEvent * event = [NSApp nextEventMatchingMask: NSEventMaskAny
                                                            untilDate: [NSDate distantFuture]
                                                            inMode: NSDefaultRunLoopMode
                                                            dequeue: YES];

            [NSApp sendEvent: event];
            eventPoll();
        }
    }
#else
    /**
     * 이 구현은 실제 Objective C 로 링크되면 컴파일 되지 않습니다.
     * 코드 에디터에서 오류를 출력하지 않기 위한 더미 코드입니다.
     */
    template <class super>
    application<super>::application(void) : internal(nullptr), delegator(nullptr) {
        pokemon_develop_throw((void)(0));
    }

    template <class super>
    int application<super>::run(void) {
        pokemon_develop_throw(return declaration::success);
    }

    template <class super>
    void application<super>::eventPoll(void) {
        pokemon_develop_throw((void)(0));
    }

    template <class super>
    void application<super>::eventWait(void) {
        pokemon_develop_throw((void)(0));
    }
#endif // __OBJC__

}

#endif // __POKEMONISM_PLATFORM_COCOA_APPLICATION_HH__