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

#import <Cocoa/Cocoa.h>

#include <pokemonism/window.hh>

@interface PokemonismWindowApplicationDelegator : NSObject <NSApplicationDelegate>

@property (nonatomic, assign) pokemonism::platform::window::application * application;

@end

namespace pokemonism::platform::cocoa {

    class window : public platform::window {
    public:     class application : public platform::window::application {
                protected:  NSApplication * internal;
                protected:  PokemonismWindowApplicationDelegator * delegator;
                public:     inline const char * platformNameGet(void) const noexcept override;
                public:     platform::cocoa::window * windowGen(const window::config & config) override;
                protected:  int run(void) override;
                public:     application(void);
                public:     ~application(void) override;
                public:     application(const platform::cocoa::window::application & o) = delete;
                public:     application(platform::cocoa::window::application && o) noexcept = delete;
                public:     platform::cocoa::window::application & operator=(const platform::cocoa::window::application & o) = delete;
                public:     platform::cocoa::window::application & operator=(platform::cocoa::window::application && o) noexcept = delete;
                };
    protected:  NSWindow * internal;

    public:     explicit window(const window::config & o);
    public:     window(void) = delete;
    public:     ~window(void) override;
    public:     window(const platform::cocoa::window & o) = delete;
    public:     window(platform::cocoa::window && o) noexcept = delete;
    public:     platform::cocoa::window & operator=(const platform::cocoa::window & o) = delete;
    public:     platform::cocoa::window & operator=(platform::cocoa::window && o) noexcept = delete;
    };

}

#include <pokemonism/platform/cocoa/window/application.hh>

#endif // __POKEMONISM_PLATFORM_COCOA_WINDOW_HH__