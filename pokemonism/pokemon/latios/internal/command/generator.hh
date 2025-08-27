/**
 * @file        pokemon/latios/internal/command/generator.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 28, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_GENERATOR__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_GENERATOR__HH__

#include <pokemon/latios/internal/generator.hh>

namespace pokemon { namespace latios { namespace internal { namespace command {

    class subscription;
    class event;

    class generator : public internal::generator<subscription, event> {
    /** IMPLEMENT OVERRIDE METHOD */
    public:     event * eventGen(subscription * o, uint32 type) override;
    public:     void dispatch(subscription * o, uint32 type) override;
    /** CUSTOM CLASS CONSTRUCTOR */
    public:     explicit generator(engine * parent);
    /** DEFAULT CLASS METHOD */
    public:     generator(void) = delete;
    public:     ~generator(void) override;
    public:     generator(const generator & o) = delete;
    public:     generator(generator && o) noexcept = delete;
    public:     generator & operator=(const generator & o) = delete;
    public:     generator & operator=(generator && o) noexcept = delete;
    };

} } } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_GENERATOR__HH__