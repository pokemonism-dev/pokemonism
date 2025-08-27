/**
 * @file        pokemon/latios/generator.hh
 * @brief
 * @details
 *
 * @author      pokemon <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_GENERATOR__HH__
#define   __POKEMONISM_POKEMON_LATIOS_GENERATOR__HH__

#include <pokemon/latios.hh>

#include <pokemon/object.hh>

namespace pokemon { namespace latios {

    class generator : public virtual object {
    protected:  engine * engine;
    protected:  uint64 size;
    protected:  subscription * head;
    protected:  subscription * next;
    public:     generator(void);
    public:     ~generator(void) override;
    };
} }

#endif // __POKEMONISM_POKEMON_LATIOS_GENERATOR__HH__