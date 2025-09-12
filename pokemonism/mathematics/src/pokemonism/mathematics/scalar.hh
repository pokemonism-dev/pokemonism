/**
 * @file
 * @brief
 * @details
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_MATHEMATICS_SCALAR_HH__
#define   __POKEMONISM_MATHEMATICS_SCALAR_HH__

#include <pokemonism/mathematics.hh>

namespace pokemonism::mathematics {

    struct ScalarTag : public Tag {
    public:     typedef float               Type;
    public:     constexpr static float      zero = 0.0F;
    };

    struct FloatTag : public ScalarTag {
    public:     typedef float               Type;
    public:     constexpr static float      zero = 0.0F;
    };

    struct DoubleTag : public FloatTag {
    public:     typedef double              Type;
    public:     constexpr static double     zero = 0.0F;
    };

    struct IntegerTag : public ScalarTag {
    public:     typedef int                 Type;
    public:     constexpr static int        zero = 0.0F;
    };

    struct LongTag : public IntegerTag {
    public:     typedef long                Type;
    public:     constexpr static long       zero = 0.0F;
    };

}

#endif // __POKEMONISM_MATHEMATICS_SCALAR_HH__