/**
 * @file        pokemon/sprigatito/iterable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_ITERABLE__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_ITERABLE__HH__

#include <pokemon/object.hh>

namespace pokemon { namespace sprigatito {

    template <typename element_type>
    class iterable : public virtual object {
    public:     typedef element_type element;
    public:     iterable(void) {}
    public:     ~iterable(void) override {}
    public:     iterable(const iterable<element> & o) = delete;
    public:     iterable(iterable<element> && o) noexcept = delete;
    public:     iterable<element> & operator=(const iterable<element> & o) = delete;
    public:     iterable<element> & operator=(iterable<element> && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_SPRIGATITO_ITERABLE__HH__
