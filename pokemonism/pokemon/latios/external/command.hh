/**
 * @file        pokemon/latios/external/command.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_EXTERNAL_COMMAND__HH__
#define   __POKEMONISM_POKEMON_LATIOS_EXTERNAL_COMMAND__HH__

#include <pokemon/latios.hh>

#include <pokemon/latios/object.hh>

namespace pokemon { namespace latios { namespace external { namespace command {

    class subscription : latios::command::subscription {
    public:     subscription(void) {};
    public:     ~subscription(void) override {};
    public:     subscription(const subscription & o) = delete;
    public:     subscription(subscription && o) noexcept = delete;
    public:     subscription & operator=(const subscription & o) = delete;
    public:     subscription & operator=(subscription && o) noexcept = delete;
    };

    public:     class subscription : public virtual latios::subscription {
    protected:  subscription(void) {};
    protected:  ~subscription(void) override {};
    public:     subscription(const subscription & o) = delete;
    public:     subscription(subscription && o) noexcept = delete;
    public:     subscription & operator=(const subscription & o) = delete;
    public:     subscription & operator=(subscription && o) noexcept = delete;
    };

    typedef int64 (*handler)(latios::command *, uint32, int64);

} } } }

#endif // __POKEMONISM_POKEMON_LATIOS_EXTERNAL_COMMAND__HH__