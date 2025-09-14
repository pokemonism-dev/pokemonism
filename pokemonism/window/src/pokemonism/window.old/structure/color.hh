/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 14, 2025
 */

#ifndef   __POKEMONISM_WINDOW_STRUCTURE_COLOR_HH__
#define   __POKEMONISM_WINDOW_STRUCTURE_COLOR_HH__

#include <pokemonism.hh>

namespace pokemonism::window {

    struct color {
    public:     int red;
    public:     int green;
    public:     int blue;
    public:     inline color(void);
    public:     inline ~color(void);
    public:     inline color(const color & o);
    public:     inline color(color && o) noexcept;
    public:     inline color & operator=(const color & o);
    public:     inline color & operator=(color && o) noexcept;
    };

    inline color::color(void) : red(declaration::zero), green(declaration::zero), blue(declaration::zero) {

    }

    inline color::~color(void) {

    }

    inline color::color(const color & o) : red(o.red), green(o.green), blue(o.blue) {

    }

    inline color::color(color && o) noexcept : red(o.red), green(o.green), blue(o.blue) {

    }

    inline color & color::operator=(const color & o) {
        if (pointof(o) != this) {
            red = o.red;
            green = o.green;
            blue = o.blue;
        }
        return *this;
    }

    inline color & color::operator=(color && o) noexcept {
        if (pointof(o) != this) {
            red = o.red;
            green = o.green;
            blue = o.blue;
        }
        return *this;
    }

}

#endif // __POKEMONISM_WINDOW_STRUCTURE_COLOR_HH__