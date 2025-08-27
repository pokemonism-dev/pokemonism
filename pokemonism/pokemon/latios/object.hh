/**
 * @file        pokemon/latios/object.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_OBJECT__HH__
#define   __POKEMONISM_POKEMON_LATIOS_OBJECT__HH__

#include <pokemon/latios.hh>

namespace pokemon { namespace latios {

    class object : public virtual pokemon::object {
    protected:  subscription * subscription;
    // public:     virtual int64 on(uint32 type);
    public:     object(void) {}
    public:     ~object(void) override {}
    public:     inline object(const object & o) = delete;
    public:     inline object(object && o) noexcept = delete;
    public:     inline object & operator=(const object & o) = delete;
    public:     inline object & operator=(object && o) noexcept = delete;
    };

    // latios::engine.

} }

#endif // __POKEMONISM_POKEMON_LATIOS_OBJECT__HH__
