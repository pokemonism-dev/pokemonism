/**
* @file        pokemon/latios/internal/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_SUBSCRIPTION__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_SUBSCRIPTION__HH__

#include <pokemon/latios.hh>

#include <pokemon/mareep/subscription.hh>

namespace pokemon { namespace latios { namespace internal {

    class subscription : public latios::subscription {
    public:     class node {
                public:     node(void) {}
                public:     virtual ~node(void) {}
                public:     node(const node & o) = delete;
                public:     node(node && o) noexcept = delete;
                public:     node & operator=(const node & o) = delete;
                public:     node & operator=(node && o) noexcept = delete;
                };
    // protected:  latios::generator * container;
    // protected:  subscription * prev;
    // protected:  subscription * next;
    // protected:
    protected:  object * origin;
    public:     subscription(void) : origin(nullptr) {}
    public:     ~subscription(void) override {}
    public:     subscription(const subscription & o) = delete;
    public:     subscription(subscription && o) noexcept;
    public:     subscription & operator=(const subscription & o) = delete;
    public:     subscription & operator=(subscription && o) noexcept;
    };

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_SUBSCRIPTION__HH__