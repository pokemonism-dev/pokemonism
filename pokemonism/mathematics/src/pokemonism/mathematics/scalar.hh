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
    public:     typedef int                 Type;
    public:     constexpr static int        zero = 0.0F;
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
    public:     constexpr static int        zero = 0;
    };

    struct LongTag : public IntegerTag {
    public:     typedef long                Type;
    public:     constexpr static long       zero = 0;
    };

    struct UnitType {
    public:     constexpr static unsigned int   none   = 0;
    public:     constexpr static unsigned int   length = 1;
    public:     constexpr static unsigned int   mass   = 2;
    };

    template <typename Super = ScalarTag>
    struct UnitTag : public Super {
    public:     constexpr static unsigned int   type   = UnitType::none;
    };

    struct UnitSuffixType {
    public:     constexpr static int            yotta       =  24;
    public:     constexpr static int            zetta       =  21;
    public:     constexpr static int            exa         =  18;
    public:     constexpr static int            peta        =  15;
    public:     constexpr static int            tera        =  12;
    public:     constexpr static int            giga        =   9;
    public:     constexpr static int            mega        =   6;
    public:     constexpr static int            kilo        =   3;
    public:     constexpr static int            hecto       =   2;
    public:     constexpr static int            deka        =   1;
    public:     constexpr static int            base        =   0;
    public:     constexpr static int            deci        =  -1;
    public:     constexpr static int            centi       =  -2;
    public:     constexpr static int            milli       =  -3;
    public:     constexpr static int            micro       =  -6;
    public:     constexpr static int            nano        =  -9;
    public:     constexpr static int            pico        = -12;
    public:     constexpr static int            femto       = -15;
    public:     constexpr static int            atto        = -18;
    public:     constexpr static int            zepto       = -21;
    public:     constexpr static int            yocto       = -24;
    };

    struct LengthUnitType {
    public:     constexpr static unsigned int   none        = 0;
    public:     constexpr static unsigned int   meter       = 1;
    };

    struct SecondUnitType {
    public:     constexpr static unsigned int   none        = 0;
    public:     constexpr static unsigned int   second      = 1;
    };

    struct MassUnitType {
    public:     constexpr static unsigned int   none        = 0;
    public:     constexpr static unsigned int   gram        = 1;
    };

    namespace generic {
        template <typename scalar = ScalarTag>
        struct meter : public scalar {
        public:     constexpr static unsigned int unit = LengthUnitType::meter;
        };

        template <typename unit>
        struct milli : public unit {
        public:     constexpr static int            suffix = UnitSuffixType::milli;
        };
    }


    struct millimeter : public generic::milli<generic::meter<>> {};


}

#endif // __POKEMONISM_MATHEMATICS_SCALAR_HH__