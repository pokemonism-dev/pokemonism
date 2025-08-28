/**
 * @file        pokemon/latios/external/command/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_EXTERNAL_COMMAND_SUBSCRIPTION__HH__
#define   __POKEMONISM_POKEMON_LATIOS_EXTERNAL_COMMAND_SUBSCRIPTION__HH__

#include <pokemon/latios/subscription.hh>

namespace pokemon { namespace latios { namespace external { namespace command {

    class subscription : public virtual latios::subscription {
    protected:  subscription(void) {};
    protected:  ~subscription(void) override {};
    public:     subscription(const subscription & o) = delete;
    public:     subscription(subscription && o) noexcept = delete;
    public:     subscription & operator=(const subscription & o) = delete;
    public:     subscription & operator=(subscription && o) noexcept = delete;
    };

} } } }

#endif // __POKEMONISM_POKEMON_LATIOS_EXTERNAL_COMMAND_SUBSCRIPTION__HH__s