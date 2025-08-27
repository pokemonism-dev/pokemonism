/**
 * @file        pokemon/latios/generator.hh
 * @brief
 * @details
 *
 * @author      pokemon <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_GENERATOR__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_GENERATOR__HH__

#include <pokemon/latios.hh>

#include <pokemon/object.hh>

#include <pokemon/latios/internal/linked/list.hh>

namespace pokemon { namespace latios {

    class generator : public virtual pokemon::object {
    public:     generator(void) {}
    public:     ~generator(void) override {}
    public:     generator(const generator & o) = delete;
    public:     generator(generator && o) noexcept = delete;
    public:     generator & operator=(const generator & o) = delete;
    public:     generator & operator=(generator && o) noexcept = delete;
    };
} }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_GENERATOR__HH__