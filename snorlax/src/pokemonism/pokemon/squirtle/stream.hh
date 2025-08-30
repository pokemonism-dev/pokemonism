/**
 * @file        pokemon/squirtle/stream.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SQUIRTLE_STREAM__HH__
#define   __POKEMONISM_POKEMON_SQUIRTLE_STREAM__HH__

#include <pokemon/memorizer.hh>
#include <pokemon/sprigatito/continuable.hh>

namespace pokemon { namespace squirtle {

    template <typename element_type>
    class stream : public sprigatito::continuable<element_type> {
    public:     typedef element_type        element;
    protected:  uint64 capacity;
    protected:  element * storage;
    public:     stream(void);
    public:     ~stream(void) override;
    public:     stream(const stream<element> & o);
    public:     stream(stream<element> && o) noexcept;
    public:     stream<element> & operator=(const stream<element> & o);
    public:     stream<element> & operator=(stream<element> && o) noexcept;
    };

} }


#endif // __POKEMONISM_POKEMON_SQUIRTLE_STREAM__HH__
