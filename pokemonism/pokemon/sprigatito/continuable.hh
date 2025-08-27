/**
 * @file        pokemon/sprigatito/continuable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_CONTINUABLE__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_CONTINUABLE__HH__

#include <pokemon/sprigatito/sequenceable.hh>
#include <pokemon/sprigatito/capable.hh>

namespace pokemon { namespace sprigatito {

    template <typename element_type>
    class continuable : public virtual sequenceable<element_type>, public virtual capable<element_type> {
    public:     typedef element_type    element;
    public:     virtual void set(const element & item, uint64 n) = 0;
    public:     virtual void set(element && item, uint64 n) = 0;
    public:     virtual void set(const element * source, uint64 n) = 0;
    public:     virtual void cat(const element & item, uint64 n) = 0;
    public:     virtual void cat(element && item, uint64 n) = 0;
    public:     virtual void cat(const element * source, uint64 n) = 0;
    public:     virtual void put(uint64 offset, const element & item, uint64 n) = 0;
    public:     virtual void put(uint64 offset, element && item, uint64 n) = 0;
    public:     virtual void put(uint64 offset, const element * source, uint64 n) = 0;
    public:     virtual void cut(uint64 offset) = 0;
    public:     virtual void pop(uint64 length) = 0;
    public:     virtual void rem(uint64 offset, uint64 length) = 0;
    public:     virtual void mod(uint64 offset, uint64 length, const element & item, uint64 n) = 0;
    public:     virtual void mod(uint64 offset, uint64 length, element && item, uint64 n) = 0;
    public:     virtual void mod(uint64 offset, uint64 length, const element * source, uint64 n) = 0;
    public:     virtual void shrink(void) = 0;
    public:     continuable(void) {}
    public:     ~continuable(void) override {}
    public:     continuable(const continuable<element> & o) = delete;
    public:     continuable(continuable<element> && o) noexcept = delete;
    public:     continuable<element> & operator=(const continuable<element> & o) = delete;
    public:     continuable<element> & operator=(continuable<element> && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_SPRIGATITO_CONTINUABLE__HH__
