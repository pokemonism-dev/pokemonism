/**
 * @file        pokemon/latios/command.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_COMMAND__HH__
#define   __POKEMONISM_POKEMON_LATIOS_COMMAND__HH__

#include <pokemon/primitivable.hh>

#include <pokemon/latios/object.hh>

#include <pokemon/latios/subscription.hh>

namespace pokemon { namespace latios {

    class command : public object {
    public:     class event {
                public:     typedef int (*handler)(command *, uint32, event *, primitivable::object *);
                public:     constexpr static int gen = 0;
                public:     constexpr static int rem = 1;
                public:     constexpr static int reg = 2;
                public:     constexpr static int del = 3;
                public:     constexpr static int exe = 4;
                public:     constexpr static int max = 5;
                };
    public:     typedef int64 (*on)(command *, uint32, primitivable::object *);
    public:     virtual primitivable::object * operator()(void) = 0;
    public:     inline command(void) {}
    public:     inline ~command(void) override {}
    public:     command(const command & o) = delete;
    public:     command(command && o) noexcept = delete;
    public:     command & operator=(const command & o) = delete;
    public:     command & operator=(command && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_LATIOS_COMMAND__HH__