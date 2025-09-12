/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_MATHEMATICS_PRECISION_HH__
#define   __POKEMONISM_MATHEMATICS_PRECISION_HH__

#include <pokemonism/mathematics.hh>

namespace pokemonism::mathematics {

    struct PrecisionTag : public mathematics::Tag {
    public:     typedef double  Type;
    public:     constexpr static double zero = 0.0F;
    };

    struct IntegerPrecisionTag : public PrecisionTag {
    public:     typedef long    Type;
    public:     constexpr static long zero = 0L;
    };

}

#endif // __POKEMONISM_MATHEMATICS_PRECISION_HH__