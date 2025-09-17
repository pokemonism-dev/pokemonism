/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 14, 2025
 */

#ifndef   __POKEMONISM_MATHEMATICS_GEOMETRY_RECTANGLE_HH__
#define   __POKEMONISM_MATHEMATICS_GEOMETRY_RECTANGLE_HH__

#include <pokemonism/mathematics/scalar.hh>

namespace pokemonism::mathematics::geometry {

    template <typename unit = mathematics::generic::length<double, mathematics::unit::length::none>>
    struct rectangle {
    public:     typename unit::type x;
    public:     typename unit::type y;
    public:     typename unit::type width;
    public:     typename unit::type height;
    public:     inline void set(typename unit::type x, typename unit::type y, typename unit::type width, typename unit::type height);
    public:     inline rectangle(typename unit::type x, typename unit::type y, typename unit::type width, typename unit::type height);
    public:     inline rectangle(void);
    public:     inline ~rectangle(void);
    public:     inline rectangle(const rectangle<unit> & o);
    public:     inline rectangle(rectangle<unit> && o) noexcept;
    public:     inline rectangle<unit> & operator=(const rectangle<unit> & o);
    public:     inline rectangle<unit> & operator=(rectangle<unit> && o) noexcept;
    };

    template <typename unit>
    inline void rectangle<unit>::set(typename unit::type x, typename unit::type y, typename unit::type width, typename unit::type height) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    }

    template <typename unit>
    inline rectangle<unit>::rectangle(typename unit::type x, typename unit::type y, typename unit::type width, typename unit::type height) : x(x), y(y), width(width), height(height) {

    }

    template <typename unit>
    inline rectangle<unit>::rectangle(void) : x(unit::zero), y(unit::zero), width(unit::zero), height(unit::zero) {

    }

    template <typename unit>
    inline rectangle<unit>::~rectangle(void) {

    }

    template <typename unit>
    inline rectangle<unit>::rectangle(const rectangle<unit> & o) : x(o.x), y(o.y), width(o.width), height(o.height) {

    }

    template <typename unit>
    inline rectangle<unit>::rectangle(rectangle<unit> && o) noexcept : x(o.x), y(o.y), width(o.width), height(o.height) {

    }

    template <typename unit>
    inline rectangle<unit> & rectangle<unit>::operator=(const rectangle<unit> & o) {
        if (pointof(o) != this) {
            x = o.x;
            y = o.y;
            width = o.width;
            height = o.height;
        }

        return *this;
    }

    template <typename unit>
    inline rectangle<unit> & rectangle<unit>::operator=(rectangle<unit> && o) noexcept {
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