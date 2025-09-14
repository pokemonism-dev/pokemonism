/**
 * @file            pokemonism.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 04, 2025
 */

#ifndef   __POKEMONISM__HH__
#define   __POKEMONISM__HH__

#include <exception>

namespace pokemonism {

    struct tag {
    public:     struct disposable;
    public:     struct nondisposable;
    };

    struct tag::disposable : public tag {};
    struct tag::nondisposable : public tag {};

    namespace declaration {
        typedef char                int8;
        typedef short               int16;
        typedef int                 int32;
        typedef long                int64;
        typedef unsigned char       uint8;
        typedef unsigned short      uint16;
        typedef unsigned int        uint32;
        typedef unsigned long       uint64;

        constexpr int               unknown = -2;
        constexpr int               fail = -1;
        constexpr int               success = 0;
        constexpr int               again = 1;
        constexpr int               invalid = -1;
        constexpr int               infinite = -1;
        constexpr int               zero = 0;
        constexpr int               one = 1;
        constexpr int               two = 2;
        constexpr int               eight = 8;
        constexpr int               none = 0;

        using                       exception = std::exception;
    }
}

#define pointof(o)                  (&(o))
#define valueof(o)                  (*(o))
#define referenceof(o)              (*(o))
#define pokemonname                 typename
#define trainername                 typename
#define toolname                    typename
#define itemname                    typename


#endif // __POKEMONISM__HH__