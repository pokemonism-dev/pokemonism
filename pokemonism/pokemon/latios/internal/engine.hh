/**
 * @file        pokemon/latios/internal/engine.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_ENGINE__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_ENGINE__HH__

#include <pokemon/latios/external/engine.hh>

namespace pokemon { namespace latios { namespace internal {

    class engine : public external::engine {
    public:     static internal::engine & get(void);
    public:     const char * tag(void) const override { return "internal"; }
    protected:  engine(void) {}
    public:     ~engine(void) override {}
    public:     engine(engine & o) = delete;
    public:     engine(engine && o) noexcept = delete;
    public:     engine & operator=(engine & o) = delete;
    public:     engine & operator=(engine && o) noexcept = delete;
    };

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_ENGINE__HH__
