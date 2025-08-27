/**
 * @file        pokemon/latios/object.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_OBJECT__HH__
#define   __POKEMONISM_POKEMON_LATIOS_OBJECT__HH__

#include <pokemon/object.hh>
#include <pokemon/primitivable.hh>

namespace pokemon { namespace latios {

    class subscription;

    class object : public virtual pokemon::object {
    public:     struct event {
                public:     typedef int (*handler)(object *, uint32, event *, primitivable::object *);
                public:     constexpr static int gen = 0;
                public:     constexpr static int rem = 1;
                public:     constexpr static int reg = 2;
                public:     constexpr static int del = 3;
                public:     constexpr static int max = 4;
                };
    protected:  subscription * subscription;
    protected:  virtual inline const latios::subscription * subscriptionGet(void) const { return subscription; }
    public:     object(void) : subscription(nullptr) {}
    public:     ~object(void) override {}
    public:     inline object(const object & o) = delete;
    public:     inline object(object && o) noexcept = delete;
    public:     inline object & operator=(const object & o) = delete;
    public:     inline object & operator=(object && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_LATIOS_OBJECT__HH__
