/**
 * @file
 * @brief
 * @details         ![ClassDiagramMathematicsScalar](/docs/assets/diagram/pokemonism/mathematics/ClassDiagramMathematicsScalar.jpg)
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 12, 2025
 */

#ifndef   __POKEMONISM_MATHEMATICS_SCALAR_HH__
#define   __POKEMONISM_MATHEMATICS_SCALAR_HH__

#include <pokemonism/mathematics.hh>

namespace pokemonism::mathematics {

    struct scalar : public pokemonism::tag {
    public:     typedef double                      type;
    public:     constexpr static double             zero    = 0.0f;
    };

    struct number : public scalar {};

    struct unit : public number {
    public:     struct prefix {
                public:     constexpr static int    yotta   = 24;
                public:     constexpr static int    zetta   = 21;
                public:     constexpr static int    exa     = 18;
                public:     constexpr static int    peta    = 15;
                public:     constexpr static int    tera    = 12;
                public:     constexpr static int    giga    = 9;
                public:     constexpr static int    mega    = 6;
                public:     constexpr static int    kilo    = 3;
                public:     constexpr static int    hecto   = 2;
                public:     constexpr static int    deka    = 1;
                public:     constexpr static int    none    = 0;
                public:     constexpr static int    deci    = -1;
                public:     constexpr static int    centi   = -2;
                public:     constexpr static int    milli   = -3;
                public:     constexpr static int    micro   = -6;
                public:     constexpr static int    nano    = -9;
                public:     constexpr static int    pico    = -12;
                public:     constexpr static int    femto   = -15;
                public:     constexpr static int    atto    = -18;
                public:     constexpr static int    zepto   = -21;
                public:     constexpr static int    yocto   = -24;
                };
    public:     struct classification {
                public:     constexpr static int    scalar  = 0;
                public:     constexpr static int    length  = 1;
                public:     constexpr static int    mass    = 2;
                public:     constexpr static int    second  = 3;
                public:     constexpr static int    color   = 4;
                };
    public:     struct length {
                public:     constexpr static int    none    = 0;
                public:     constexpr static int    meter   = 1;
                public:     constexpr static int    pixel   = 2;
                };
    public:     constexpr static int                kind    = mathematics::unit::classification::scalar;
    public:     constexpr static int                fix     = mathematics::unit::prefix::none;
    };

    namespace generic {
        template <typename declaration>
        struct number : public mathematics::number {
        public:     typedef declaration             type;
        public:     constexpr static type           zero    = 0;
        };

        template <typename declaration, int classificationVal, int prefixVal = mathematics::unit::prefix::none>
        struct unit : public generic::number<declaration>, public mathematics::unit {
        public:     typedef declaration             type;
        public:     constexpr static int            kind    = classificationVal;
        public:     constexpr static int            subkind = declaration::none;
        public:     constexpr static int            fix     = prefixVal;
        public:     constexpr static type           zero    = generic::number<declaration>::zero;
        };

        template <typename declaration, int categoryVal, int prefixVal = mathematics::unit::prefix::none>
        struct length : public generic::unit<declaration, mathematics::unit::classification::length, prefixVal> {
        public:     constexpr static int            subkind = categoryVal;
        };

    }

    struct millimeter : public generic::length<double, mathematics::unit::length::meter, mathematics::unit::prefix::milli> {};
    struct pixel : public generic::length<int, mathematics::unit::length::pixel> {};

}

#endif // __POKEMONISM_MATHEMATICS_SCALAR_HH__