/**
 * @file        pokemon/object.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_OBJECT__HH__
#define   __POKEMONISM_POKEMON_OBJECT__HH__

#include <pokemonism.hh>

#include <pokemon/allocator.hh>

namespace pokemon {
    class object {
    public:     class meta {
                public:     virtual meta * clone(void) const = 0;
                public:     virtual const meta * self(void) const = 0;
                public:     meta(void) {}
                public:     virtual ~meta(void) {}
                public:     meta(const meta & o) = delete;
                public:     meta(meta && o) noexcept = delete;
                public:     meta & operator=(const meta & o) = delete;
                public:     meta & operator=(meta && o) noexcept = delete;
                };
    protected:  meta * meta;
    public:     inline virtual object * clone(void) const { return nullptr; }
    public:     inline virtual const object * self(void) const { return this; }
    public:     inline virtual int lock(void) { return declaration::fail; }
    public:     inline virtual int unlock(void) { return declaration::fail; }
    public:     inline virtual int wait(void) { return declaration::fail; }
    public:     inline virtual int wait(int64 second, int64 nano) { return declaration::fail; }
    public:     inline virtual int wakeup(void) { return declaration::fail; }
    public:     inline virtual int wakeup(bool all) { return declaration::fail; }
    public:     inline object(void) : meta(nullptr) {}
    public:     inline virtual ~object(void) { meta = allocator::del(meta); }
    public:     object(const object & o) = delete;
    public:     object(object && o) noexcept = delete;
    public:     object & operator=(const object & o) = delete;
    public:     object & operator=(object && o) noexcept = delete;
    };
}

#endif // __POKEMONISM_POKEMON_OBJECT__HH__