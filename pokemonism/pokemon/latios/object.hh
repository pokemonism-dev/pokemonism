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

#include <pokemon/object.hh>

namespace pokemon { namespace latios {

    class subscription;

    class object : public virtual pokemon::object {
    protected:  subscription * subscription;
    public:     object(void) : subscription(nullptr) {}
    public:     ~object(void) override {}
    public:     inline object(const object & o) = delete;
    public:     inline object(object && o) noexcept = delete;
    public:     inline object & operator=(const object & o) = delete;
    public:     inline object & operator=(object && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_LATIOS_OBJECT__HH__
