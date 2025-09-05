/**
 * @file        pokemon/dynamical.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_DYNAMICAL__HH__
#define   __POKEMONISM_POKEMON_DYNAMICAL__HH__

#include <pokemonism.hh>

namespace pokemon {
    class dynamical {
    public:     template <typename declaration_type> static declaration_type * rel(declaration_type * o) {
                    if (o != nil) delete o;
                    return nil;
                }
    public:     template <typename declaration_type> static declaration_type * gen(declaration_type * o) {
                    return o != nil ? new declaration_type(o) : new declaration_type();
                }
    public:     dynamical(void) {}
    public:     virtual ~dynamical(void) {}
    public:     dynamical(const dynamical & o) = delete;
    public:     dynamical(dynamical && o) noexcept = delete;
    public:     dynamical & operator=(const dynamical & o) = delete;
    public:     dynamical & operator=(dynamical && o) noexcept = delete;
    };
}

#endif // __POKEMONISM_POKEMON_DYNAMICAL__HH__
