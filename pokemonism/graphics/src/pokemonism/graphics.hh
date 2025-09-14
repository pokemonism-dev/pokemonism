/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 14, 2025
 */

#ifndef   __POKEMONISM_GRAPHICS_HH__
#define   __POKEMONISM_GRAPHICS_HH__

#include <pokemonism/mathematics/scalar.hh>

namespace pokemonism::graphics {

    namespace unit {
        struct color {
        public:     constexpr static int none   = 0;
        public:     constexpr static int rgb    = 1;
        public:     constexpr static int rgba   = 2;
        };
    }

    namespace generic {

        template <typename declaration = int, int category = graphics::unit::color::rgb, int prefix = mathematics::unit::prefix::none>
        struct color : public mathematics::generic::unit<declaration, category, prefix> {
        public:     constexpr static int red    = 1;
        public:     constexpr static int green  = 2;
        public:     constexpr static int blue   = 3;
        public:     constexpr static int alpha  = 4;
        };

    }

    namespace unit {
        using rgb = graphics::generic::color<>;
    }


}

#endif // __POKEMONISM_GRAPHICS_HH__