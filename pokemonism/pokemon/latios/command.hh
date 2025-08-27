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
    public:     class subscription : public latios::subscription {
                protected:  subscription(void) {};
                protected:  ~subscription(void) override {};
                public:     subscription(const subscription & o) = delete;
                public:     subscription(subscription && o) noexcept = delete;
                public:     subscription & operator=(const subscription & o) = delete;
                public:     subscription & operator=(subscription && o) noexcept = delete;
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