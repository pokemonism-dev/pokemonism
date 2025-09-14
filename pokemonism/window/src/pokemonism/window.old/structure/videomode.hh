/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 14, 2025
 */

#ifndef   __POKEMONISM_WINDOW_STRUCTURE_VIDEOMODE_HH__
#define   __POKEMONISM_WINDOW_STRUCTURE_VIDEOMODE_HH__

#include <pokemonism/window/src/pokemonism/window.old/structure/color.hh>

namespace pokemonism::window {

    struct WindowVideoMode {
    public:     int width;
    public:     int height;
    public:     color colorBits;
    public:     int refreshRate;
    public:     inline WindowVideoMode(void);
    public:     inline ~WindowVideoMode(void);
    public:     inline WindowVideoMode(const WindowVideoMode & o);
    public:     inline WindowVideoMode(WindowVideoMode && o) noexcept;
    public:     inline WindowVideoMode & operator=(const WindowVideoMode & o);
    public:     inline WindowVideoMode & operator=(WindowVideoMode && o) noexcept;
    };

    inline WindowVideoMode::WindowVideoMode(void) : width(declaration::zero), height(declaration::zero), refreshRate(declaration::zero) {

    }

    inline WindowVideoMode::~WindowVideoMode(void) {

    }

    inline WindowVideoMode::WindowVideoMode(const WindowVideoMode & o) : width(o.width), height(o.height), colorBits(o.colorBits), refreshRate(o.refreshRate) {

    }

    inline WindowVideoMode::WindowVideoMode(WindowVideoMode && o) noexcept : width(o.width), height(o.height), colorBits(o.colorBits), refreshRate(o.refreshRate) {

    }

    inline WindowVideoMode & WindowVideoMode::operator=(const WindowVideoMode & o) {
        if (pointof(o) != this) {
            width = o.width;
            height = o.height;
            colorBits = o.colorBits;
            refreshRate = o.refreshRate;
        }
        return *this;
    }

    inline WindowVideoMode & WindowVideoMode::operator=(WindowVideoMode && o) noexcept {
        if (pointof(o) != this) {
            width = o.width;
            height = o.height;
            colorBits = o.colorBits;
            refreshRate = o.refreshRate;
        }
        return *this;
    }

}

#endif // __POKEMONISM_WINDOW_STRUCTURE_VIDEOMODE_HH__