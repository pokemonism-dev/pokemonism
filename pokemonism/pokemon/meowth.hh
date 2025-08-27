/**
 * @file        meowth.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_MEOWTH__HH__
#define   __POKEMONISM_POKEMON_MEOWTH__HH__

#include <cstdio>

namespace pokemon { namespace meowth {
    // ReSharper disable once CppClassCanBeFinal
    class functionObjectVoid {
    public:     virtual void operator()(void) const { printf("void function object\n"); }
    public:     functionObjectVoid(void) {}
    public:     virtual ~functionObjectVoid(void) {}
    public:     functionObjectVoid(const functionObjectVoid & o) = default;
    public:     functionObjectVoid(functionObjectVoid && o) noexcept = default;
    public:     functionObjectVoid & operator=(const functionObjectVoid & o) = default;
    public:     functionObjectVoid & operator=(functionObjectVoid && o) noexcept = default;
    };

    inline void functionVoid(void) { printf("void function\n"); }
} }

#endif // __POKEMONISM_POKEMON_MEOWTH__HH__
