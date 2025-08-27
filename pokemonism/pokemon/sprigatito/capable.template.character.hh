/**
* @file        pokemon/sprigatito/capable.template.character.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_CAPABLE_TEMPLATE_CHARACTER__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_CAPABLE_TEMPLATE_CHARACTER__HH__

#include <pokemon/sprigatito/capable.template.character.hh>

namespace pokemon { namespace sprigatito {

    template <typename element_type>
    class capable<element_type, char> {
    public:     typedef element_type        element;
    public:     typedef char                character;
    public:     constexpr static uint64     align = 64;
    public:     static inline uint64 capacityCal(uint64 n);
    public:     static inline uint64 capacityCal(uint64 n, uint64 page);
    public:     virtual uint64 capacity(void) const = 0;
    public:     virtual uint64 maximum(void) const = 0;
    public:     capable(void) {}
    public:     virtual ~capable(void) {}
    public:     explicit capable(const capable<element> & o) = delete;
    public:     explicit capable(capable<element> && o) noexcept = delete;
    public:     capable<element> & operator=(const capable<element> & o) = delete;
    public:     capable<element> & operator=(capable<element> && o) noexcept = delete;
    };

    template <typename element>
    uint64 capable<element, char>::capacityCal(const uint64 n) { return capacityCal(n, align); }

    template <typename element>
    uint64 capable<element, char>::capacityCal(const uint64 n, const uint64 page) {
        const uint64 size = n + (n > 0 ? 1 : 0);

        return (size / page + (size % page > 0 ? 1 : 0)) * page;
    }

} }

#endif // __POKEMONISM_POKEMON_SPRIGATITO_CAPABLE_TEMPLATE_CHARACTER__HH__
