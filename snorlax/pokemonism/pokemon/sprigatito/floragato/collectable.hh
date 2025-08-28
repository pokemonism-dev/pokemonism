/**
 * @file        pokemon/sprigatito/floragato/collectable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_FLORAGATO_COLLECTABLE__HH__
#define   __POKEMONISM_POKEMON_FLORAGATO_COLLECTABLE__HH__

#include <pokemonism.hh>

#include <pokemon/function.hh>
#include <pokemon/exception.hh>
#include <pokemon/sprigatito/collectable.hh>

namespace pokemon { namespace floragato {

    template <typename element_type>
    class collectable : public virtual sprigatito::collectable<element_type> {
    public:     typedef element_type        element;
    // public:     virtual uint64 size(void) const = 0;
    public:     virtual void size(void (*func)(uint64)) = 0;
    public:     virtual void size(const function<void (uint64, exception *)> & func) = 0;
    public:     virtual void size(const declaration::type::function<void (uint64, exception *)> & func) = 0;
    // public:     virtual bool empty(void) const = 0;
    // public:     virtual bool exist(const element & item) const = 0;
    // public:     virtual bool add(const element & item) = 0;
    // public:     virtual bool add(element && item) = 0;
    // public:     virtual uint64 add(const element & item, uint64 n) = 0;
    // public:     virtual uint64 add(element && item, uint64 n) = 0;
    // public:     virtual uint64 add(const element * items, uint64 n) = 0;
    // public:     virtual bool del(const element & item) = 0;
    // public:     virtual bool del(element && item) = 0;
    // public:     virtual bool del(const element & item, uint64 n) = 0;
    // public:     virtual bool del(element && item, uint64 n) = 0;
    // public:     virtual uint64 del(const element * items, uint64 n) = 0;
    public:     collectable(void) {}
    public:     ~collectable(void) override {}
    public:     collectable(const collectable & o) = delete;
    public:     collectable(collectable && o) noexcept = delete;
    public:     collectable & operator=(const collectable & o) = delete;
    public:     collectable & operator=(collectable && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_FLORAGATO_COLLECTABLE__HH__