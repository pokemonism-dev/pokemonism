/**
 * @file        pokemon/memorizer.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 24, 2025
 */

#ifndef   __POKEMONISM_POKEMON_MEMORIZER__HH__
#define   __POKEMONISM_POKEMON_MEMORIZER__HH__

#include <pokemon/allocator.hh>

namespace pokemon {
    template <typename element_type, typename characterizable_type = typographer<element_type>::characterized_type, typename memorizable_type = typographer<element_type>::memorized_type, uint64 unit = typographer<element_type>::width>
    class memorizer {
    public:     typedef element_type            declaration_type;
    public:     typedef characterizable_type    characterized_type;
    public:     typedef memorizable_type        memorized_type;
    public:     constexpr static uint64         width = unit;
    public:     using                           allocator = allocator<declaration_type>;
    public:     memorizer(void) {}
    public:     virtual ~memorizer(void) {}
    public:     memorizer(const memorizer<declaration_type> & o) = delete;
    public:     memorizer(memorizer<declaration_type> && o) noexcept = delete;
    public:     memorizer<declaration_type> & operator=(const memorizer<declaration_type> & o) = delete;
    public:     memorizer<declaration_type> & operator=(memorizer<declaration_type> && o) noexcept = delete;
    };
}

#endif // __POKEMONISM_POKEMON_MEMORIZER__HH__