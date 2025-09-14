/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 14, 2025
 */

#ifndef   __POKEMONISM_MATHEMATICS_GEOMETRY_DIMENSION_TWO_HH__
#define   __POKEMONISM_MATHEMATICS_GEOMETRY_DIMENSION_TWO_HH__

#include <pokemonism/mathematics/geometry/dimension.hh>

namespace pokemonism::mathematics::geometry {

    template <typename Precisional>
    class Dimension<geometry::dimension::two, Precisional> {
    public:     Precisional::Type v[geometry::dimension::two];
    public:     inline Precisional::Type width(void) const { return v[0]; }
    public:     inline Precisional::Type height(void) const { return v[1]; }
    public:     inline Dimension(void);
    public:     inline ~Dimension(void);
    public:     inline Dimension(const Dimension<geometry::dimension::two, Precisional> & o);
    public:     inline Dimension(Dimension<geometry::dimension::two, Precisional> && o) noexcept;
    public:     inline Dimension<geometry::dimension::two, Precisional> & operator=(const Dimension<geometry::dimension::two, Precisional> & o);
    public:     inline Dimension<geometry::dimension::two, Precisional> & operator=(Dimension<geometry::dimension::two, Precisional> && o) noexcept;
    };

    template <typename Precisional>
    inline Dimension<geometry::dimension::two, Precisional>::Dimension(void) {
        v[0] = Precisional::zero;
        v[1] = Precisional::zero;
    }

    template <typename Precisional>
    inline Dimension<geometry::dimension::two, Precisional>::~Dimension(void) {

    }

    template <typename Precisional>
    inline Dimension<geometry::dimension::two, Precisional>::Dimension(const Dimension<geometry::dimension::two, Precisional> & o) {
        v[0] = o.v[0];
        v[1] = o.v[1];
    }

    template <typename Precisional>
    inline Dimension<geometry::dimension::two, Precisional>::Dimension(Dimension<geometry::dimension::two, Precisional> && o) noexcept {
        v[0] = o.v[0];
        v[1] = o.v[1];
    }

    template <typename Precisional>
    inline Dimension<geometry::dimension::two, Precisional> & Dimension<geometry::dimension::two, Precisional>::operator=(const Dimension<geometry::dimension::two, Precisional> & o) {
        v[0] = o.v[0];
        v[1] = o.v[1];

        return *this;
    }

    template <typename Precisional>
    inline Dimension<geometry::dimension::two, Precisional> & Dimension<geometry::dimension::two, Precisional>::operator=(Dimension<geometry::dimension::two, Precisional> && o) noexcept {
        v[0] = o.v[0];
        v[1] = o.v[1];

        return *this;
    }

}

#endif // __POKEMONISM_MATHEMATICS_GEOMETRY_DIMENSION_TWO_HH__