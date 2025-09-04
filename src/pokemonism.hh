/**
 * @file
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
    namespace declaration {
        typedef char                int8;
        typedef short               int16;
        typedef int                 int32;
        typedef long                int64;
        typedef unsigned char       uint8;
        typedef unsigned short      uint16;
        typedef unsigned int        uint32;
        typedef unsigned long       uint64;

        constexpr int               fail = -1;
        constexpr int               success = 0;
        constexpr int               invalid = -1;
        constexpr int               infinite = -1;

        using                       exception = std::exception;
    }

    const char * version(void);
}

#define pointof(o)                  (&(o))
#define pokemonname                 typename


#endif // __POKEMONISM__HH__