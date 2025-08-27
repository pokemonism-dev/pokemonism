/**
 * @file        pokemon/sprigatito/sequenceable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 24, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_SEQUENCEABLE__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_SEQUENCEABLE__HH__

#include <pokemon/sprigatito/traversable.hh>

namespace pokemon { namespace sprigatito {
    template <typename element_type>
    class sequenceable : public traversable<element_type> {
    public:     typedef element_type            declaration_type;
    public:     typedef declaration_type *      pointer_type;
    public:     typedef declaration_type &      reference_type;
    public:     typedef declaration_type &&     revalue_reference_type;
    public:     virtual reference<declaration_type> at(uint64 index) const = 0;
    public:     virtual reference<declaration_type> operator[](uint64 index) const = 0;
    public:     sequenceable(void) {}
    public:     ~sequenceable(void) override {}
    public:     sequenceable(const sequenceable<declaration_type> & o) = delete;
    public:     sequenceable(sequenceable<declaration_type> && o) noexcept = delete;
    public:     sequenceable<declaration_type> & operator=(const sequenceable<declaration_type> & o) = delete;
    public:     sequenceable<declaration_type> & operator=(sequenceable<declaration_type> && o) noexcept = delete;
    };
} }

#endif // __POKEMONISM_POKEMON_SPRIGATITO_SEQUENCEABLE__HH__