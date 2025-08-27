/**
 * @file        pokemon/latios/command.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_COMMAND__HH__
#define   __POKEMONISM_POKEMON_LATIOS_COMMAND__HH__

#include <pokemon/latios.hh>

#include <pokemon/latios/object.hh>

namespace pokemon { namespace latios {

    class command : public object {
    public:     virtual int64 operator()(void) = 0;
    public:     inline command(void) {}
    public:     inline ~command(void) override {}
    public:     command(const command & o) = delete;
    public:     command(command && o) noexcept = delete;
    public:     command & operator=(const command & o) = delete;
    public:     command & operator=(command && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_LATIOS_COMMAND__HH__