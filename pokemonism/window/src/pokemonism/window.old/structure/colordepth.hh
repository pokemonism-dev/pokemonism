/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 14, 2025
 */

#ifndef   __POKEMONISM_WINDOW_STRUCTURE_COLORDEPTH_HH__
#define   __POKEMONISM_WINDOW_STRUCTURE_COLORDEPTH_HH__

#include <pokemonism.hh>

namespace pokemonism::window {

    struct WindowColorDepth {
    public:     int red;
    public:     int green;
    public:     int blue;
    public:     inline WindowColorDepth(void);
    public:     inline ~WindowColorDepth(void);
    public:     inline WindowColorDepth(const WindowColorDepth & o);
    public:     inline WindowColorDepth(WindowColorDepth && o) noexcept;
    public:     inline WindowColorDepth & operator=(const WindowColorDepth & o);
    public:     inline WindowColorDepth & operator=(WindowColorDepth && o) noexcept;
    };

    inline WindowColorDepth::WindowColorDepth(void) : red(declaration::zero), green(declaration::zero), blue(declaration::zero) {

    }

    inline WindowColorDepth::~WindowColorDepth(void) {

    }

    inline WindowColorDepth::WindowColorDepth(const WindowColorDepth & o) : red(o.red), green(o.green), blue(o.blue) {

    }

    inline WindowColorDepth::WindowColorDepth(WindowColorDepth && o) noexcept : red(o.red), green(o.green), blue(o.blue) {

    }

    inline WindowColorDepth & WindowColorDepth::operator=(const WindowColorDepth & o) {
        if (pointof(o) != this) {
            red = o.red;
            green = o.green;
            blue = o.blue;
        }
        return *this;
    }

    inline WindowColorDepth & WindowColorDepth::operator=(WindowColorDepth && o) noexcept {
        if (pointof(o) != this) {
            red = o.red;
            green = o.green;
            blue = o.blue;
        }
        return *this;
    }

}

#endif // __POKEMONISM_WINDOW_STRUCTURE_COLORDEPTH_HH__