/**
 * @file        pokemon/latios/internal/command/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_SUBSCRIPTION__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_SUBSCRIPTION__HH__

#include <pokemon/latios/command.hh>

#include <pokemon/latios/external/command/subscription.hh>
#include <pokemon/latios/internal/subscription.hh>


namespace pokemon { namespace latios { namespace internal { namespace command {

    class link;
    class generator;

    class subscription : public internal::subscription, public external::command::subscription {
    protected:  subscription(void) = delete;
    protected:  ~subscription(void) override;
    public:     subscription(const subscription & o) = delete;
    public:     subscription(subscription && o) noexcept = delete;
    public:     subscription & operator=(const subscription & o) = delete;
    public:     subscription & operator=(subscription && o) noexcept = delete;
    public:     friend class linked::list<command::subscription, command::link>;
    };

} } } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_SUBSCRIPTION__HH__