/**
 * @file        pokemon/sprigatito/floragato/meowscarada/collectable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_MEOWSCARADA_COLLECTABLE__HH__
#define   __POKEMONISM_POKEMON_MEOWSCARADA_COLLECTABLE__HH__

#include <pokemon/sprigatito/floragato/collectable.hh>
#include <pokemon/mareep/observable.hh>

namespace pokemon { namespace meowscarada {

    template <typename element_type>
    class collectable : public virtual floragato::collectable<element_type> {
    public:     typedef element_type        element;
    public:     virtual mareep::observable<uint64> & size(mareep::observable<uint64> & observable) = 0;
    // public:     virtual void size(const function<void (uint64)> & func) = 0;
    // public:     virtual void size(const declaration::type::function<void (uint64)> & func) = 0;

    public:     collectable(void) {}
    public:     ~collectable(void) override {}
    public:     collectable(const collectable & o) = delete;
    public:     collectable(collectable && o) noexcept = delete;
    public:     collectable & operator=(const collectable & o) = delete;
    public:     collectable & operator=(collectable && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_MEOWSCARADA_COLLECTABLE__HH__