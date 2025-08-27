/**
 * @file        pokemon/mareep/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_MAREEP_SUBSCRIPTION__HH__
#define   __POKEMONISM_POKEMON_MAREEP_SUBSCRIPTION__HH__

#include <pokemon/object.hh>

namespace pokemon { namespace mareep {

    class subscription : public virtual object {
    public:     virtual void cancel(void);
    // public:     virtual void cancel(const function<> &)
    public:     subscription(void) {}
    public:     ~subscription(void) override {};
    public:     subscription(const subscription & o) = delete;
    public:     subscription(subscription && o) noexcept = delete;
    public:     subscription & operator=(const subscription & o) = delete;
    public:     subscription & operator=(subscription && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_MAREEP_SUBSCRIPTION__HH__
