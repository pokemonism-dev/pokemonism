/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_GAMMARAMP_HH__
#define   __POKEMONISM_GAMMARAMP_HH__

#include <pokemonism/sdk/allocator.hh>

namespace pokemonism::window::graphics {

    struct GammaRamp {
    public:     unsigned short * red;
    public:     unsigned short * green;
    public:     unsigned short * blue;
    public:     unsigned int size;
    public:     GammaRamp(void) : red(nullptr), green(nullptr), blue(nullptr), size(declaration::zero) {}
    public:     ~GammaRamp(void) {
                    red = static_cast<unsigned short *>(Allocator::rel(red));
                    green = static_cast<unsigned short *>(Allocator::rel(green));
                    blue = static_cast<unsigned short *>(Allocator::rel(blue));
                    size = declaration::zero;
                }
    };

}

#endif // __POKEMONISM_GAMMARAMP_HH__