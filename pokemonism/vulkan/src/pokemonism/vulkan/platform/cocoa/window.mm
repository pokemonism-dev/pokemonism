/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 15, 2025
 */

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
