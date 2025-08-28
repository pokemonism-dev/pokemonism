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

#include <pokemon/latios/internal/command/event.hh>
#include <pokemon/latios/internal/generator.hh>

namespace pokemon { namespace latios { namespace internal { namespace command {

    class event;
    class subscription;

    class generator : public internal::generator {
    /** IMPLEMENT OVERRIDE METHOD */
    protected:  virtual command::event * eventGen(command::subscription * o, uint32 type);
    public:     virtual void dispatch(command::subscription * o, uint32 type);
    public:     virtual void post(command::subscription * o, uint32 type);
    public:     virtual command::subscription * subscriptionGen(latios::command * command, uint32 properties, latios::command::event::listener (*on)[latios::command::event::max]);
    public:     command::subscription * reg(command::subscription * o);
    public:     command::subscription * del(command::subscription * o);
    /** CUSTOM CLASS CONSTRUCTOR */
    public:     inline explicit generator(engine * parent);
    /** DEFAULT CLASS METHOD */
    public:     generator(void) = delete;
    public:     inline ~generator(void) override;
    public:     generator(const generator & o) = delete;
    public:     generator(generator && o) noexcept = delete;
    public:     generator & operator=(const generator & o) = delete;
    public:     generator & operator=(generator && o) noexcept = delete;
    };

    generator::generator(engine * parent) : internal::generator(parent) {

    }

    generator::~generator(void) {

    }



} } } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_GENERATOR__HH__