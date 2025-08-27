/**
 * @file        pokemon/latios/internal.temp/generator.hh
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

#include <pokemon/latios/internal.hh>
#include <pokemon/latios/internal.temp/linked/list.hh>

namespace pokemon { namespace latios { namespace internal {

    template <typename object = latios::object, typename subscription = subscription<object>>
    class generator : public virtual pokemon::object {
    protected:  internal::engine * engine;
    protected:  uint64 size;
    protected:  subscription * head;
    protected:  subscription * tail;
    public:     virtual subscription * gen(object * o) = 0;
    public:     virtual void clear(void) {}
    public:     virtual subscription * del(subscription * o) { return o; }
    /** CUSTOM CONSTRUCTOR */
    public:     explicit generator(internal::engine * engine) {}
    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    public:     generator(void) = delete;
    public:     ~generator(void) override {}
    public:     generator(const generator & o) = delete;
    public:     generator(generator && o) noexcept = delete;
    public:     generator & operator=(const generator & o) = delete;
    public:     generator & operator=(generator && o) noexcept = delete;
    };


} } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_GENERATOR__HH__