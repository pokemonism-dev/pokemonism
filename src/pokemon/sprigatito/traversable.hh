/**
 * @file        pokemon/sprigatito/traversable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 24, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_TRAVERSABLE__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_TRAVERSABLE__HH__

#include <pokemon/functionable.hh>
#include <pokemon/sprigatito/containable.hh>

namespace pokemon { namespace sprigatito {

    template <typename element_type, typename tag> class traversableFunc;

    template <typename element_type>
    class traversable {
    public:     typedef element_type            declaration_type;
    public:     typedef declaration_type *      pointer_type;
    public:     typedef declaration_type &      reference_type;
    public:     typedef declaration_type &&     revalue_reference_type;
    public:     virtual traversable<element_type> & travel(const traversableFunc<declaration_type, functionable_tag> & func) = 0;
    public:     virtual traversable<element_type> & travel(const traversableFunc<declaration_type, functionable_tag_const> & func) = 0;
    public:     traversable(void) {}
    public:     virtual ~traversable(void) {}
    public:     traversable(const traversable<declaration_type> & o) = delete;
    public:     traversable(traversable<declaration_type> && o) noexcept = delete;
    public:     traversable<declaration_type> & operator=(const traversable<declaration_type> & o) = delete;
    public:     traversable<declaration_type> & operator=(traversable<declaration_type> && o) noexcept = delete;
    };

    template <typename element_type, typename tag = functionable_tag>
    class traversableFunc : public functionable<void (reference<element_type> &)> {
    public:     typedef element_type            declaration_type;
    public:     typedef declaration_type *      pointer_type;
    public:     typedef declaration_type &      reference_type;
    public:     typedef declaration_type &&     revalue_reference_type;
    public:     traversableFunc(void) {}
    public:     ~traversableFunc(void) override {}
    public:     traversableFunc(const traversableFunc<declaration_type, tag> & o) = delete;
    public:     traversableFunc(traversableFunc<declaration_type, tag> && o) noexcept = delete;
    public:     traversableFunc<declaration_type, tag> & operator=(const traversableFunc<declaration_type, tag> & o) = delete;
    public:     traversableFunc<declaration_type, tag> & operator=(traversableFunc<declaration_type, tag> && o) noexcept = delete;
    };

    template <typename element_type>
    class traversableFunc<element_type, functionable_tag_const> : public functionable<void (reference<element_type> &)> {
    public:     typedef element_type            declaration_type;
    public:     typedef declaration_type *      pointer_type;
    public:     typedef declaration_type &      reference_type;
    public:     typedef declaration_type &&     revalue_reference_type;
    public:     traversableFunc(void) {}
    public:     ~traversableFunc(void) override {}
    public:     traversableFunc(const traversableFunc<declaration_type, functionable_tag_const> & o) = delete;
    public:     traversableFunc(traversableFunc<declaration_type, functionable_tag_const> && o) noexcept = delete;
    public:     traversableFunc<declaration_type, functionable_tag_const> & operator=(const traversableFunc<declaration_type, functionable_tag_const> & o) = delete;
    public:     traversableFunc<declaration_type, functionable_tag_const> & operator=(traversableFunc<declaration_type, functionable_tag_const> && o) noexcept = delete;
    };
} }

#endif // __POKEMONISM_POKEMON_SPRIGATITO_TRAVERSABLE__HH__
