/**
 * @file        pokemon/latios/command/object.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_COMMAND_OBJECT__HH__
#define   __POKEMONISM_POKEMON_LATIOS_COMMAND_OBJECT__HH__

#include <pokemon/latios.hh>

#include <pokemon/latios/object.hh>

namespace pokemon { namespace latios { namespace command {

    class object : public virtual latios::object {
    public:     virtual int operator()(uint64 n, ...) = 0;
    public:     inline object(void) {}
    public:     inline ~object(void) override {}
    public:     inline object(const object & o) = delete;
    public:     inline object(object && o) noexcept = delete;
    public:     inline object & operator=(const object & o) = delete;
    public:     inline object & operator=(object && o) noexcept = delete;
    };

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_COMMAND_OBJECT__HH__
