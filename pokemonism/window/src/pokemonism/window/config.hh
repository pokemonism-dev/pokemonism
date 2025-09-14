/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 13, 2025
 */

#ifndef   __POKEMONISM_WINDOW_CONFIG_HH__
#define   __POKEMONISM_WINDOW_CONFIG_HH__

#include <pokemonism/collection/string.hh>
#include <pokemonism/window/structure/rect.hh>

namespace pokemonism::window {

    class WindowConfig {
    public:     String          title;
    public:     Rect            rect;
    public:     unsigned int    style;
    public:     inline WindowConfig(void);
    public:     inline virtual ~WindowConfig(void);
    public:     inline WindowConfig(const WindowConfig & o);
    public:     inline WindowConfig(WindowConfig && o) noexcept;
    public:     inline WindowConfig & operator=(const WindowConfig & o);
    public:     inline WindowConfig & operator=(WindowConfig && o) noexcept;
    };

    inline WindowConfig::WindowConfig(void) : style(declaration::none) {

    }

    inline WindowConfig::~WindowConfig(void) {

    }

    inline WindowConfig::WindowConfig(const WindowConfig & o) : title(o.title), rect(o.rect), style(o.style) {

    }

    inline WindowConfig::WindowConfig(WindowConfig && o) noexcept : title(std::move(o.title)), rect(o.rect), style(o.style) {

    }

    inline WindowConfig & WindowConfig::operator=(const WindowConfig & o) {
        if (pointof(o) != this) {
            title = o.title;
            rect = o.rect;
            style = o.style;
        }

        return *this;
    }

    inline WindowConfig & WindowConfig::operator=(WindowConfig && o) noexcept {
        if (pointof(o) != this) {
            title = std::move(o.title);
            rect = std::move(o.rect);
            style = o.style;
        }

        return *this;
    }

}

#endif // __POKEMONISM_WINDOW_CONFIG_HH__