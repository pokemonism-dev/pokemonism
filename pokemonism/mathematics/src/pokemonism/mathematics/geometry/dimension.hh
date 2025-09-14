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

namespace pokemonism::mathematics::geometry {

    template <int dimension, typename Precisional = ScalarTag>
    class Dimension {
    public:     Precisional::Type v[dimension];
    public:
    };

}

#endif // __POKEMONISM_MATHEMATICS_GEOMETRY_DIMENSION_HH__