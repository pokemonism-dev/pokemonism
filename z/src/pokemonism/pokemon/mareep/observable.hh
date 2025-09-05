/**
 * @file        pokemon/mareep/observable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_OBSERVABLE__HH__
#define   __POKEMONISM_POKEMON_OBSERVABLE__HH__

#include <pokemon/object.hh>

namespace pokemon { namespace mareep {
    template <typename item>
    class observable : public virtual object {
    protected:  observable<item> * adapter;
    public:     observable(void) : adapter(nullptr) {}
    public:     ~observable(void) override { adapter = allocator::del(adapter); };
    public:     observable<item>(const observable<item> & o) = delete;
    public:     observable<item>(observable<item> && o) noexcept = delete;
    public:     observable<item> & operator=(const observable<item> & o) = delete;
    public:     observable<item> & operator=(observable<item> && o) noexcept = delete;
    };
} }

#endif // __POKEMONISM_POKEMON_OBSERVABLE__HH__
