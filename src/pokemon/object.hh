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

#include <pokemon/dynamical.hh>

namespace pokemon {
    class object {
    public:     class metadata {
                public:     virtual metadata * clone(void) const = 0;
                public:     virtual const metadata * self(void) const = 0;
                public:     metadata(void) {}
                public:     virtual ~metadata(void) {}
                public:     metadata(const metadata & o) = delete;
                public:     metadata(metadata && o) noexcept = delete;
                public:     metadata & operator=(const metadata & o) = delete;
                public:     metadata & operator=(metadata && o) noexcept = delete;
                };
    protected:  metadata * meta;
    public:     virtual object * clone(void) const { return nil; }
    public:     virtual const object * self(void) const { return this; }
    public:     virtual int lock(void) { return fail; }
    public:     virtual int unlock(void) { return fail; }
    public:     virtual int wait(void) { return fail; }
    public:     virtual int wait(int64 second, int64 nano) { return fail; }
    public:     virtual int wakeup(void) { return fail; }
    public:     virtual int wakeup(bool all) { return fail; }
    public:     object(void) : meta(nil) {}
    public:     virtual ~object(void) { meta = dynamical::rel(meta); }
    public:     object(const object & o) = delete;
    public:     object(object && o) noexcept = delete;
    public:     object & operator=(const object & o) = delete;
    public:     object & operator=(object && o) noexcept = delete;
    };
}

#endif // __POKEMONISM_POKEMON_OBJECT__HH__