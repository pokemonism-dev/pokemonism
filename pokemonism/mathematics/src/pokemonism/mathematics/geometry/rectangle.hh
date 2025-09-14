/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 14, 2025
 */

#ifndef   __POKEMONISM_MATHEMATICS_GEOMETRY_RECTANGLE_HH__
#define   __POKEMONISM_MATHEMATICS_GEOMETRY_RECTANGLE_HH__

#include <pokemonism/mathematics/scalar.hh>

namespace pokemonism::mathematics::geometry {

    template <typename Precisional = ScalarTag>
    struct Rectangle {
    public:     Precisional::Type x;
    public:     Precisional::Type y;
    public:     Precisional::Type width;
    public:     Precisional::Type height;
    public:     inline void set(Precisional::Type _x, Precisional::Type _y, Precisional::Type _width, Precisional::Type _height);
    public:     inline Rectangle(Precisional::Type x, Precisional::Type y, Precisional::Type width, Precisional::Type height);
    public:     inline Rectangle(void);
    public:     inline ~Rectangle(void);
    public:     inline Rectangle(const Rectangle<Precisional> & o);
    public:     inline Rectangle(Rectangle<Precisional> && o) noexcept;
    public:     inline Rectangle<Precisional> & operator=(const Rectangle<Precisional> & o);
    public:     inline Rectangle<Precisional> & operator=(Rectangle<Precisional> && o) noexcept;
    };

    template <typename Precisional>
    inline void Rectangle<Precisional>::set(typename Precisional::Type _x, typename Precisional::Type _y, typename Precisional::Type _width, typename Precisional::Type _height) {
        this->x      = _x;
        this->y      = _y;
        this->width  = _width;
        this->height = _height;
    }

    template <typename Precisional>
    inline Rectangle<Precisional>::Rectangle(typename Precisional::Type x, typename Precisional::Type y, typename Precisional::Type width, typename Precisional::Type height) :
    x(x), y(y), width(width), height(height) {

    }

    template <typename Precisional>
    inline Rectangle<Precisional>::Rectangle(void) : x(declaration::zero), y(declaration::zero), width(declaration::zero), height(declaration::zero) {

    }

    template <typename Precisional>
    inline Rectangle<Precisional>::~Rectangle(void) {

    }

    template <typename Precisional>
    inline Rectangle<Precisional>::Rectangle(const Rectangle<Precisional> & o) : x(o.x), y(o.y), width(o.width), height(o.height) {

    }

    template <typename Precisional>
    inline Rectangle<Precisional>::Rectangle(Rectangle<Precisional> && o) noexcept : x(o.x), y(o.y), width(o.width), height(o.height) {

    }

    template <typename Precisional>
    inline Rectangle<Precisional> & Rectangle<Precisional>::operator=(const Rectangle<Precisional> & o) {
        if (pointof(o) != this) {
            x = o.x;
            y = o.y;
            width = o.width;
            height = o.height;
        }
        return *this;
    }

    template <typename Precisional>
    inline Rectangle<Precisional> & Rectangle<Precisional>::operator=(Rectangle<Precisional> && o) noexcept {
        if (pointof(o) != this) {
            x = o.x;
            y = o.y;
            width = o.width;
            height = o.height;
        }
        return *this;
    }

}

#endif // __POKEMONISM_MATHEMATICS_GEOMETRY_RECTANGLE_HH__