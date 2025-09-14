/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 14, 2025
 */

#ifndef   __POKEMONISM_INTERFACE_WINDOW_HH__
#define   __POKEMONISM_INTERFACE_WINDOW_HH__

#include <pokemonism/graphics/color.hh>
#include <pokemonism/mathematics/geometry/rectangle.hh>

#include <pokemonism/applicationable.hh>

namespace pokemonism::interface {

    class window {
    public:     struct unit {
                public:     struct color : public mathematics::generic::unit<int, mathematics::unit::classification::color> {};
                public:     struct pixel : public mathematics::generic::length<int, mathematics::unit::length::pixel> {};
                public:     unit(void) {}
                public:     ~unit(void) {}
                public:     unit(const interface::window::unit & o) {}
                public:     unit(interface::window::unit && o) noexcept {}
                public:     interface::window::unit & operator=(const interface::window::unit & o) { return *this; }
                public:     interface::window::unit & operator=(interface::window::unit && o) noexcept { return *this; }
                };
    public:     using color = graphics::color<>;
    public:     using rectangle = mathematics::geometry::rectangle<interface::window::unit::pixel>;
    public:     struct config;
    public:     class application : public pokemonism::applicationable {
                public:     virtual interface::window * windowGen(const interface::window::config & config) = 0;
                public:     inline application(void);
                public:     inline ~application(void) override;
                public:     inline application(const window::application & o);
                public:     inline application(window::application && o) noexcept;
                public:     inline window::application & operator=(const window::application & o);
                public:     inline window::application & operator=(window::application && o) noexcept;
                };
    public:     inline window(void);
    public:     inline virtual ~window(void);
    public:     inline window(const interface::window & o);
    public:     inline window(interface::window && o) noexcept;
    public:     inline interface::window & operator=(const interface::window & o);
    public:     inline interface::window & operator=(interface::window && o) noexcept;
    };

    inline window::window(void) {

    }

    inline window::~window(void) {

    }

    inline window::window(const interface::window & o) {

    }

    inline window::window(interface::window && o) noexcept {

    }

    inline interface::window & window::operator=(const interface::window & o) {
        return *this;
    }

    inline interface::window & window::operator=(interface::window && o) noexcept {
        return *this;
    }

}

// ReSharper disable CppUnusedIncludeDirective
#include <pokemonism/interface/window/application.hh>
// ReSharper restore CppUnusedIncludeDirective

#endif // __POKEMONISM_INTERFACE_WINDOW_HH__
