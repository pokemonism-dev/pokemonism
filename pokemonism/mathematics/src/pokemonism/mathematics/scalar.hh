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

    struct scalar : public pokemonism::tag {
    public:     typedef long                        type;
    public:     constexpr static long               zero    = 0;
    };

    struct number : public scalar {};

    struct integer : public number {};

    struct real : public number {
    public:     typedef double                      type;
    public:     constexpr static double             zero    = 0.0f;
    };

    struct unit : public real {
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
    public:     constexpr static int                kind    = unit::classification::scalar;
    public:     constexpr static int                fix     = unit::prefix::none;
    };

    namespace generic {
        template <typename declaration>
        struct number : public mathematics::number {
        public:     typedef declaration             type;
        public:     constexpr static type           zero    = 0;
        };

        template <typename declaration, int classification, int prefix = mathematics::unit::prefix::none>
        struct unit : public generic::number<declaration> {
        public:     constexpr static int            kind    = classification;
        public:     constexpr static int            subkind = declaration::none;
        public:     constexpr static int            fix     = prefix;
        };

        template <typename declaration, int category, int prefix = mathematics::unit::prefix::none>
        struct length : public generic::unit<declaration, mathematics::unit::classification::length, prefix> {
        public:     constexpr static int            subkind = category;
        };

    }

    struct millimeter : public generic::length<double, mathematics::unit::length::meter, mathematics::unit::prefix::milli> {};

}

#endif // __POKEMONISM_MATHEMATICS_SCALAR_HH__