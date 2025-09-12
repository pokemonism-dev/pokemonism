/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_WINDOW_PLATFORM_HH__
#define   __POKEMONISM_WINDOW_PLATFORM_HH__

namespace pokemonism::window {

    struct WindowPlatform {
    public:     constexpr static unsigned int cocoa = 1;
    public:     struct Angle {
                public:     constexpr static unsigned int metal = 1;
                };
    };


}

#endif // __POKEMONISM_PLATFORM_HH__