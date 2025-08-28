/**
 * @file        pokemon/sprigatito/memorizable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 24, 2025
 *
 * VOID 타입에 대한 MEMORIZABLE 을 만들 수는 있다.
 */

#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_MEMORIZABLE__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_MEMORIZABLE__HH__

#include <pokemon/sprigatito/containable.hh>
#include <pokemon/sprigatito/sequenceable.hh>
#include <pokemon/memorizer.hh>

namespace pokemon { namespace sprigatito {

    template <typename element_type>
    class continuable : public containable<element_type>, sequenceable<element_type>, memorizer<element_type> {
    public:     typedef element_type            declaration_type;
    public:     typedef declaration_type *      pointer_type;
    public:     typedef declaration_type &      reference_type;
    public:     typedef declaration_type &&     revalue_reference_type;
    protected:  declaration_type * storage;
    public:     continuable(void);
    public:     ~continuable(void) override;
    public:     continuable(const continuable & o);
    public:     continuable(continuable && o) noexcept;
    public:     continuable & operator=(const continuable & o);
    public:     continuable & operator=(continuable && o) noexcept;
    };

} }

#endif // __POKEMONISM_POKEMON_SPRIGATITO_MEMORIZABLE__HH__
