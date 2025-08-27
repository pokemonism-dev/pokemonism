/**
 * @file        pokemon/latios/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_SUBSCRIPTION__HH__
#define   __POKEMONISM_POKEMON_LATIOS_SUBSCRIPTION__HH__

#include <pokemon/mareep/subscription.hh>

namespace pokemon { namespace latios {

    class subscription : public virtual mareep::subscription {
    protected:  subscription(void) {}
    protected:  ~subscription(void) override {}
    public:     subscription(const subscription & o) = delete;
    public:     subscription(subscription && o) noexcept = delete;
    public:     subscription & operator=(const subscription & o) = delete;
    public:     subscription & operator=(subscription && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_LATIOS_SUBSCRIPTION__HH__