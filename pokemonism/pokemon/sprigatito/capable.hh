/**
 * @file        pokemon/sprigatito/capable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_CAPABLE__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_CAPABLE__HH__

#include <pokemon/typographer.hh>
#include <pokemon/sprigatito/collectable.hh>

namespace pokemon { namespace sprigatito {

    template <typename element_type, typename character_type = typographer<element_type>::character>
    class capable {
    public:     typedef element_type        element;
    public:     typedef character_type      character;
    public:     constexpr static uint64     align = 64;
    public:     static inline uint64 capacityCal(uint64 n);
    public:     static inline uint64 capacityCal(uint64 n, uint64 page);
    public:     virtual uint64 capacity(void) const = 0;
    public:     virtual uint64 maximum(void) const = 0;
    public:     capable(void) {}
    public:     virtual ~capable(void) {}
    public:     capable(const capable<element, character> & o) = delete;
    public:     capable(capable<element, character> && o) noexcept = delete;
    public:     capable<element, character> & operator=(const capable<element, character> & o) = delete;
    public:     capable<element, character> & operator=(capable<element, character> && o) noexcept = delete;
    };

    template <typename element, typename character>
    uint64 capable<element, character>::capacityCal(const uint64 n) { return capacityCal(n, align); }

    template <typename element, typename character>
    uint64 capable<element, character>::capacityCal(const uint64 n, const uint64 page) {
        return (n / page + (n % page > 0 ? 1 : 0)) * page;
    }

} }

#include <pokemon/sprigatito/capable.template.character.hh>

#endif // __POKEMONISM_POKEMON_SPRIGATITO_CAPABLE__HH__
