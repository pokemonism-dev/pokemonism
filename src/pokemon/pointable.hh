/**
 * @file        pokemon/pointable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_POINTABLE__HH__
#define   __POKEMONISM_POKEMON_POINTABLE__HH__

#include <pokemonism.hh>

#include <pokemon/dynamical.hh>
#include <pokemon/exception.hh>

namespace pokemon {

    template <typename element>
    struct pointable final {
    public:     typedef element     declaration_type;
    public:     declaration_type *  internal;
    public:     inline declaration_type * pointer(void) { return internal; }
    public:     inline const declaration_type * pointer(void) const { return internal; }
    public:     inline declaration_type & value(void) { critical_quick_throw_check(internal == nil, exceptional::nullpointer, return *internal); }
    public:     inline const declaration_type & value(void) const { critical_quick_throw_check(internal == nil, exceptional::nullpointer, return *internal); }
    public:     pointable(void) : internal(nil) {}
    public:     pointable(const pointable<declaration_type> & o) : internal(dynamical::gen(o.internal)) {}
    public:     pointable(pointable<declaration_type> && o) noexcept : internal(o.internal) { o.internal = nil; }
    public:     pointable<declaration_type> & operator=(const pointable<declaration_type> & o) {
                    if (&o != this) {
                        dynamical::rel(internal);
                        internal = dynamical::gen(o.internal);
                    }
                    return *this;
                }
    public:     pointable<declaration_type> & operator=(pointable<declaration_type> && o) noexcept {
                    if (&o != this) {
                        dynamical::rel(internal);
                        internal = o.internal;
                        o.internal = nil;
                    }
                    return *this;
                }
    public:     ~pointable(void) { internal = dynamical::rel(internal); }
    public:     inline declaration_type & operator*(void) { critical_quick_throw_check(internal == nil, exceptional::nullpointer, return *internal); }
    public:     inline const declaration_type & operator*(void) const { critical_quick_throw_check(internal == nil, exceptional::nullpointer, return *internal); }
    public:     inline declaration_type * operator->(void) { return internal; }
    public:     inline const declaration_type * operator->(void) const { return internal; }
    public:     friend bool operator==(const pointable<declaration_type> & left, const pointable<declaration_type> & right) { return left.internal == right.internal; }
    public:     friend bool operator==(const pointable<declaration_type> & left, declaration::type::null right) { return left.internal == right; }
    public:     friend bool operator==(declaration::type::null left, const pointable<declaration_type> & right) { return left == right.internal; }
    public:     friend bool operator!=(const pointable<declaration_type> & left, const pointable<declaration_type> & right) { return left.internal != right.internal; }
    public:     friend bool operator!=(const pointable<declaration_type> & left, declaration::type::null right) { return left.internal != right; }
    public:     friend bool operator!=(declaration::type::null left, const pointable<declaration_type> & right) { return left != right.internal; }
    };

}

#endif // __POKEMONISM_POKEMON_POINTABLE__HH__