/**
 * @file        pokemon/sprigatito/scannable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_SCANNABLE__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_SCANNABLE__HH__

#include <pokemon/sprigatito/collectable.hh>

namespace pokemon { namespace sprigatito {
    /**
     * 이터레이터를 내어 놓는다.
     * @tparam element_type
     */
    template <typename element_type>
    class scannable : public virtual collectable<element_type> {
    public:     typedef element_type element;
    public:     virtual element * scan(const element & item) = 0;
    public:     virtual bool exist(const element & item) const = 0;
    public:     scannable(void) {}
    public:     ~scannable(void) override {}
    public:     scannable(const scannable<element> & o) = delete;
    public:     scannable(scannable<element> && o) noexcept = delete;
    public:     scannable<element> & operator=(const scannable<element> & o) = delete;
    public:     scannable<element> & operator=(scannable<element> && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_SPRIGATITO_SCANNABLE__HH__
