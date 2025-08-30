/**
 * @file        pokemon/sprigatito/deletable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_DELETABLE__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_DELETABLE__HH__

#include <pokemon/sprigatito/scannable.hh>

namespace pokemon { namespace sprigatito {
    /**
     * 이터레이터를 내어 놓는다.
     * @tparam element_type
     */
    template <typename element_type>
    class deletable : public virtual scannable<element_type> {
    public:     typedef element_type element;
    public:     virtual bool del(const element & item) = 0;
    public:     virtual bool del(element && item) = 0;
    public:     virtual uint64 del(const element & item, uint64 n) = 0;
    public:     virtual uint64 del(element && item, uint64 n) = 0;
    public:     virtual uint64 del(const element * source, uint64 n) = 0;
    public:     deletable(void) {}
    public:     ~deletable(void) override {}
    public:     deletable(const deletable<element> & o) = delete;
    public:     deletable(deletable<element> && o) noexcept = delete;
    public:     deletable<element> & operator=(const deletable<element> & o) = delete;
    public:     deletable<element> & operator=(deletable<element> && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_SPRIGATITO_DELETABLE__HH__
