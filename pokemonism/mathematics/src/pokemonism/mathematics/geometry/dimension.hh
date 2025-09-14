/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 14, 2025
 */

#ifndef   __POKEMONISM_MATHEMATICS_GEOMETRY_DIMENSION_HH__
#define   __POKEMONISM_MATHEMATICS_GEOMETRY_DIMENSION_HH__

#include <pokemonism/mathematics/scalar.hh>
#include <pokemonism/mathematics/geometry.hh>

namespace pokemonism::mathematics::geometry {

    template <int dimension, typename Precisional = ScalarTag>
    class Dimension {
    public:     Precisional::Type v[dimension];
    public:     inline Dimension(void);
    public:     inline ~Dimension(void);
    public:     inline Dimension(const Dimension<dimension, Precisional> & o);
    public:     inline Dimension(Dimension<dimension, Precisional> && o) noexcept;
    public:     inline Dimension<dimension, Precisional> & operator=(const Dimension<dimension, Precisional> & o);
    public:     inline Dimension<dimension, Precisional> & operator=(Dimension<dimension, Precisional> && o) noexcept;
    };

    template <int dimension, typename Precisional>
    inline Dimension<dimension, Precisional>::Dimension(void) {
        for (int i = 0; i < dimension; i = i + 1) v[i] = Precisional::zero;
    }

    template <int dimension, typename Precisional>
    inline Dimension<dimension, Precisional>::~Dimension(void) {

    }

    template <int dimension, typename Precisional>
    inline Dimension<dimension, Precisional>::Dimension(const Dimension<dimension, Precisional> & o) {
        for (int i = 0; i < dimension; i = i + 1) v[i] = o[i];
    }

    template <int dimension, typename Precisional>
    inline Dimension<dimension, Precisional>::Dimension(Dimension<dimension, Precisional> && o) noexcept {
        for (int i = 0; i < dimension; i = i + 1) v[i] = o[i];
    }

    template <int dimension, typename Precisional>
    inline Dimension<dimension, Precisional> & Dimension<dimension, Precisional>::operator=(const Dimension<dimension, Precisional> & o) {
        if (pointof(o) != this) for (int i = 0; i < dimension; i = i + 1) v[i] = o[i];

        return *this;
    }

    template <int dimension, typename Precisional>
    inline Dimension<dimension, Precisional> & Dimension<dimension, Precisional>::operator=(Dimension<dimension, Precisional> && o) noexcept {
        if (pointof(o) != this) for (int i = 0; i < dimension; i = i + 1) v[i] = o[i];

        return *this;
    }

}

#include <pokemonism/mathematics/geometry/dimension/two.hh>

#endif // __POKEMONISM_MATHEMATICS_GEOMETRY_DIMENSION_HH__