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

    template <int count, typename precisional = scalar>
    class dimension {
    public:     precisional::Type v[count];
    public:     inline dimension(void);
    public:     inline ~dimension(void);
    public:     inline dimension(const dimension<count, precisional> & o);
    public:     inline dimension(dimension<count, precisional> && o) noexcept;
    public:     inline dimension<count, precisional> & operator=(const dimension<count, precisional> & o);
    public:     inline dimension<count, precisional> & operator=(dimension<count, precisional> && o) noexcept;
    };

    template <int count, typename precisional>
    inline dimension<count, precisional>::dimension(void) {
        for (int i = 0; i < count; i = i + 1) v[i] = precisional::zero;
    }

    template <int count, typename precisional>
    inline dimension<count, precisional>::~dimension(void) {

    }

    template <int count, typename precisional>
    inline dimension<count, precisional>::dimension(const dimension<count, precisional> & o) {
        for (int i = 0; i < count; i = i + 1) v[i] = o[i];
    }

    template <int count, typename precisional>
    inline dimension<count, precisional>::dimension(dimension<count, precisional> && o) noexcept {
        for (int i = 0; i < v; i = i + 1) v[i] = o[i];
    }

    template <int count, typename precisional>
    inline dimension<count, precisional> & dimension<count, precisional>::operator=(const dimension<count, precisional> & o) {
        if (pointof(o) != this) for (int i = 0; i < count; i = i + 1) v[i] = o[i];

        return *this;
    }

    template <int count, typename precisional>
    inline dimension<count, precisional> & dimension<count, precisional>::operator=(dimension<count, precisional> && o) noexcept {
        if (pointof(o) != this) for (int i = 0; i < count; i = i + 1) v[i] = o[i];

        return *this;
    }

}

#endif // __POKEMONISM_MATHEMATICS_GEOMETRY_DIMENSION_HH__