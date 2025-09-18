/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 15, 2025
 */

#ifndef   __POKEMONISM_VULKAN_PLATFORM_COCOA_WINDOW_HH__
#define   __POKEMONISM_VULKAN_PLATFORM_COCOA_WINDOW_HH__

#include <Cocoa/Cocoa.h>
#import <QuartzCore/CAMetalLayer.h>

#include <pokemonism/vulkan.hh>

#include <pokemonism/vulkan/window.hh>
#include <pokemonism/platform/cocoa/window.hh>
#include <pokemonism/collection/continuous.hh>

#ifdef __OBJC__
@class CAMetalLayer;
#else
typedef void CAMetalLayer;
#endif

/**
 * 이 뷰는 불칸 렌더링을 위한 메탈 레이어를 제공하는 역할을 합니다.
 */
#ifdef    __OBJC__
@interface PokemonismVulkanView : NSView
@end
#else
typedef void PokemonismVulkanView;
#endif // __OBJC__

namespace pokemonism::vulkan::platform::cocoa {

    template <class super = pokemonism::platform::cocoa::window<vulkan::platform::window>>
    class window : public super {
    protected:  PokemonismVulkanView * vulkanView;
    public:     int open(void) override;
    public:     int close(void) override;
    public:     explicit window(const pokemonism::window::config & o);
    public:     window(void) = delete;
    public:     ~window(void) override;
    public:     window(const vulkan::platform::cocoa::window<super> & o) = delete;
    public:     window(vulkan::platform::cocoa::window<super> && o) noexcept = delete;
    public:     vulkan::platform::cocoa::window<super> & operator=(const vulkan::platform::cocoa::window<super> & o) = delete;
    public:     vulkan::platform::cocoa::window<super> & operator=(vulkan::platform::cocoa::window<super> && o) noexcept = delete;
    };

    template <class super>
    int window<super>::open(void) {
        return declaration::fail;
    }

    template <class super>
    int window<super>::close(void) {
        return declaration::fail;
    }

    template <class super>
    window<super>::window(const pokemonism::window::config & o) : super(o), vulkanView(nullptr) {
#ifdef    __OBJC__
        @autoreleasepool {
            NSRect contentRect = [this->internal.contentView bounds];
            vulkanView = [[PokemonismVulkanView alloc] initWithFrame: contentRect];
            [this->internal setContentView: vulkanView];
        }
#endif // __OBJC__
    }

    template <class super>
    window<super>::~window(void) {

    }

}

#endif // __POKEMONISM_VULKAN_PLATFORM_COCOA_WINDOW_HH__
