/**
* @file        pokemon/sprigatito/streamable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_STREAMABLE_STRING__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_STREAMABLE_STRING__HH__

#include <pokemon/sprigatito/streamable.hh>

#include <pokemon/typographer.hh>

namespace pokemon { namespace sprigatito {

    // template <typename element_type>
    // template <typename primitive_tag = typographer<element_type>::primitive, typename character_tag = typographer<element_type>::character, uint64 unit = typographer<element_type>::width>
    // class streamable<element_type>::string : public virtual streamable<element> {
    //
    // };

    // template <typename element_type>
    // class streamable : public virtual continuable<element_type> {
    // public:     typedef element_type element;
    // public:     virtual uint64 capacity(void) const = 0;
    // public:     template <typename primitive_tag = typographer<element>::primitive, typename character_tag = typographer<element>::character, uint64 unit = typographer<element>::width>
    //             class string : public virtual streamable<element>;
    // public:     streamable(void) {}
    // public:     ~streamable(void) override {}
    // public:     streamable(const streamable<element> & o) = delete;
    // public:     streamable(streamable<element> && o) noexcept = delete;
    // public:     streamable<element> & operator=(const streamable<element> & o) = delete;
    // public:     streamable<element> & operator=(streamable<element> && o) noexcept = delete;
    // };

} }



#endif // __POKEMONISM_POKEMON_SPRIGATITO_STREAMABLE_STRING__HH__
