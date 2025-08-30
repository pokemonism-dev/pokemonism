/**
 * @file        pokemon/sprigatito/streamable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_STREAMABLE__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_STREAMABLE__HH__

#include <pokemon/typographer.hh>
#include <pokemon/sprigatito/continuable.hh>

namespace pokemon { namespace sprigatito {

    template <typename element_type>
    class streamable : public virtual continuable<element_type> {
    public:     typedef element_type element;
    public:     virtual uint64 position(void) const = 0;
    public:     streamable(void) {}
    public:     ~streamable(void) override {}
    public:     streamable(const streamable<element> & o) = delete;
    public:     streamable(streamable<element> && o) noexcept = delete;
    public:     streamable<element> & operator=(const streamable<element> & o) = delete;
    public:     streamable<element> & operator=(streamable<element> && o) noexcept = delete;
    };

} }

#include <pokemon/sprigatito/streamable/string.tcc>

#endif // __POKEMONISM_POKEMON_SPRIGATITO_STREAMABLE__HH__
