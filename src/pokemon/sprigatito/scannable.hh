/**
 * @file        pokemon/sprigatito/scannable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 24, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_SCANNABLE__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_SCANNABLE__HH__

#include <pokemon/sprigatito/traversable.hh>

#include <pokemon/sprigatito/iterator.hh>

namespace pokemon { namespace sprigatito {
    /**
     * 이터레이터로 접근이 가능하다.
     * 이터레이터로 삭제하려면, remove 를 호출하거나,
     * TODO: ... IMPLEMENT ITERATOR ...
     * @tparam element_type
     */
    template <typename element_type>
    class scannable : public traversable<element_type> {
    public:     typedef element_type            declaration_type;
    public:     typedef declaration_type *      pointer_type;
    public:     typedef declaration_type &      reference_type;
    public:     typedef declaration_type &&     revalue_reference_type;
    public:     class func;
    public:     virtual iterator<declaration_type> begin(void) = 0;
    public:     virtual iterator<declaration_type> end(void) = 0;
    // public:     virtual scannable<declaration_type> & scan(const function<void (const reference<declaration_type> &)> func) const = 0;
    // public:     virtual scannable<declaration_type> & scan(function<void (reference<declaration_type> &)> func) = 0;
    public:     scannable(void) {}
    public:     ~scannable(void) override {}
    public:     scannable(const scannable<declaration_type> & o) = delete;
    public:     scannable(scannable<declaration_type> && o) noexcept = delete;
    public:     scannable<declaration_type> & operator=(const scannable<declaration_type> & o) = delete;
    public:     scannable<declaration_type> & operator=(scannable<declaration_type> && o) noexcept = delete;
    };

    // template <typename element_type>
    // class scannable<element_type>::func {
    // public:     func(void);
    // public:     virtual ~func(void);
    // };
    // scanner func ...
} }

#endif // __POKEMONISM_POKEMON_SPRIGATITO_SCANNABLE__HH__
