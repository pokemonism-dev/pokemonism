/**
 * @file        pokemon/latios/engine.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_ENGINE__HH__
#define   __POKEMONISM_POKEMON_LATIOS_ENGINE__HH__

#include <pokemon/latios.hh>

namespace pokemon { namespace latios {

    class engine {
    public:     static const engine & singleton;
    public:     static engine & get(void);
    protected:  engine(void);
    public:     virtual ~engine(void);
    public:     engine(engine & o) = delete;
    protected:  engine(engine && o) noexcept {}
    public:     engine & operator=(engine & o) = delete;
    protected:  engine & operator=(engine && o) noexcept { return *this; }
    };

} }

#endif // __POKEMONISM_POKEMON_LATIOS_ENGINE__HH__
