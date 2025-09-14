/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 14, 2025
 */

#ifndef   __POKEMONISM_GRAPHICS_COLOR_HH__
#define   __POKEMONISM_GRAPHICS_COLOR_HH__

#include <pokemonism/graphics.hh>

namespace pokemonism::graphics {

    template <typename unit = graphics::unit::rgb>
    struct color {
    public:     unit::type v[3];
    public:     inline color(void);
    public:     inline ~color(void);
    public:     inline color(const color<unit> & o);
    public:     inline color(color<unit> && o) noexcept;
    public:     inline color<unit> & operator=(const color<unit> & o);
    public:     inline color<unit> & operator=(color<unit> && o) noexcept;
    };

    template <typename unit>
    inline color<unit>::color(void) {
        v[unit::red] = unit::zero;
        v[unit::green] = unit::zero;
        v[unit::blue] = unit::zero;
    }

    template <typename unit>
    inline color<unit>::~color(void) {

    }

    template <typename unit>
    inline color<unit>::color(const color<unit> & o) {
        v[unit::red] = o.v[unit::red];
        v[unit::green] = o.v[unit::green];
        v[unit::blue] = o.v[unit::blue];
    }

    template <typename unit>
    inline color<unit>::color(color<unit> && o) noexcept {
        v[unit::red] = o.v[unit::red];
        v[unit::green] = o.v[unit::green];
        v[unit::blue] = o.v[unit::blue];
    }

    template <typename unit>
    inline color<unit> & color<unit>::operator=(const color<unit> & o) {
        if (pointof(o) != this) {
            v[unit::red] = o.v[unit::red];
            v[unit::green] = o.v[unit::green];
            v[unit::blue] = o.v[unit::blue];
        }
        return *this;
    }

    template <typename unit>
    inline color<unit> & color<unit>::operator=(color<unit> && o) noexcept {
        if (pointof(o) != this) {
            v[unit::red] = o.v[unit::red];
            v[unit::green] = o.v[unit::green];
            v[unit::blue] = o.v[unit::blue];
        }
        return *this;
    }

}

#endif // __POKEMONISM_GRAPHICS_COLOR_HH__