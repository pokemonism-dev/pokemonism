/**
 * @file        pokemon/latios/external/engine.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_EXTERNAL_ENGINE__HH__
#define   __POKEMONISM_POKEMON_LATIOS_EXTERNAL_ENGINE__HH__

namespace pokemon { namespace latios { namespace external {

    class engine {
    public:     virtual const char * tag(void) const = 0;
    protected:  engine(void) {}
    public:     virtual ~engine(void) {}
    public:     engine(engine & o) = delete;
    public:     engine(engine && o) noexcept = delete;
    public:     engine & operator=(engine & o) = delete;
    public:     engine & operator=(engine && o) noexcept = delete;
    };

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_EXTERNAL_ENGINE__HH__
