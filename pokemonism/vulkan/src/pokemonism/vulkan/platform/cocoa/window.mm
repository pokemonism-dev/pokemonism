/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */

#import <QuartzCore/CAMetalLayer.h>

#include "window.hh"

@implementation PokemonismVulkanView

+ (Class) layerClass {
    return [CAMetalLayer class];
  }

- (instancetype) initWithFrame: (NSRect) frameRect {
    if(self = [super initWithFrame: frameRect]) {
        self.wantsLayer = YES;
    }
    return self;
  }

- (void) viewDidMoveToWindow {
    [super viewDidMoveToWindow];

    if(self.window) {
      self.layer.contentsScale = [self.window backingScaleFactor];
    }
  }

@end

namespace pokemonism::vulkan::platform::cocoa {

    int window::open(void) {
        return declaration::fail;
    }

    int window::close(void) {
        return declaration::fail;
    }

    window::window(window::config & o) : pokemonism::platform::cocoa::window(o), vulkanView(nullptr) {
        @autoreleasepool {
            NSRect contentRect = [internal.contentView bounds];
            vulkanView = [[PokemonismVulkanView alloc] initWithFrame: contentRect];
            [internal setContentView: vulkanView];
        }
    }

    window::~window(void) {
    }

}
