/**
 * @file        pokemon/sprigatito/sequenceable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_SEQUENCEABLE__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_SEQUENCEABLE__HH__

#include <pokemon/sprigatito/collectable.hh>

namespace pokemon { namespace sprigatito {

    template <typename element_type>
    class sequenceable : public virtual collectable<element_type> {
    public:     typedef element_type element;
    public:     virtual const element & at(uint64 index) const = 0;
    public:     virtual element & at(uint64 index) = 0;
    public:     virtual const element & operator[](uint64 index) const = 0;
    public:     virtual element & operator[](uint64 index) = 0;
    public:     sequenceable(void) {}
    public:     ~sequenceable(void) override {}
    public:     sequenceable(const sequenceable<element> & o) = delete;
    public:     sequenceable(sequenceable<element> && o) noexcept = delete;
    public:     sequenceable<element> & operator=(const sequenceable<element> & o) = delete;
    public:     sequenceable<element> & operator=(sequenceable<element> && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_SPRIGATITO_ITERABLE__HH__
