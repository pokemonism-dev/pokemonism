/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 14, 2025
 */

#ifndef   __POKEMONISM_INTERFACE_WINDOW_CONFIG_HH__
#define   __POKEMONISM_INTERFACE_WINDOW_CONFIG_HH__

#include <pokemonism/interface/window.hh>
#include <pokemonism/collection/string.hh>

namespace pokemonism::interface {
    struct window::config {
    public:     string name;
    public:     interface::window::rectangle rect;
    public:     inline config(void);
    public:     inline ~config(void);
    public:     inline config(const interface::window::config & o);
    public:     inline config(interface::window::config && o) noexcept;
    public:     inline interface::window::config & operator=(const interface::window::config & o);
    public:     inline interface::window::config & operator=(interface::window::config && o) noexcept;
    };

    inline window::config::config(void) {

    }

    inline window::config::~config(void) {

    }

    inline window::config::config(const interface::window::config & o) : name(o.name), rect(o.rect) {

    }

    inline window::config::config(interface::window::config && o) noexcept : name(std::move(o.name)), rect(std::move(o.rect)) {

    }

    inline interface::window::config & window::config::operator=(const interface::window::config & o) {
        if (pointof(o) != this) {
            name = o.name;
            rect = o.rect;
        }

        return *this;
    }

    inline interface::window::config & window::config::operator=(interface::window::config && o) noexcept {
        if (pointof(o) != this) {
            name = std::move(o.name);
            rect = std::move(o.rect);
        }

        return *this;
    }
}

#endif // __POKEMONISM_INTERFACE_WINDOW_CONFIG_HH__