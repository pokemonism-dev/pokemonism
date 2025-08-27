/**
 * @file        pokemon/latios/internal/link.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_LINK__HH__
#define   __POKEMONISM_POKEMON_LATIOS_LINK__HH__

#include <pokemon/latios/internal.hh>

namespace pokemon { namespace latios { namespace internal {

    template <typename subscription_type, typename event_type>
    class link {
    /** PUBLIC TYPE DEFINITION */
    public:     typedef subscription_type   subscription;
    public:     typedef event_type          event;
    /** PROTECTED MEMBER VARIABLE */
    protected:  subscription *              container;
    protected:  event *                     prev;
    protected:  event *                     next;
    protected:  event *                     ev;
    /** PUBLIC INLINE METHOD */
    public:     inline subscription * subscriptionGet(void) const;
    public:     inline event * eventGet(void) const;
    /** CUSTOM CONSTRUCTOR */
    public:     inline explicit link(subscription * oSubscription);
    /** DEFAULT MEMBER METHOD */
    protected:  inline link(void);
    public:     inline virtual ~link(void);
    public:     link(const link & o) = delete;
    public:     link(link && o) noexcept = delete;
    public:     link & operator=(const link & o) = delete;
    public:     link & operator=(link && o) noexcept = delete;
    };

    /** PUBLIC INLINE METHOD */
    template <typename subscription, typename event>
    subscription * link<subscription, event>::subscriptionGet(void) const {
        return container;
    }

    template <typename subscription, typename event>
    event * link<subscription, event>::eventGet(void) const {
        return ev;
    }

    /** CUSTOM CONSTRUCTOR */
    template <typename subscription, typename event>
    link<subscription, event>::link(subscription * oSubscription) : container(nullptr), prev(nullptr), next(nullptr), ev(nullptr) {
        oSubscription->add(this);
    }

    /** DEFAULT MEMBER METHOD */
    template <typename subscription, typename event>
    link<subscription, event>::link(void) : container(nullptr), prev(nullptr), next(nullptr), ev(nullptr) {

    }

    template <typename subscription, typename event>
    link<subscription, event>::~link(void) {
        if (ev != nullptr) {
            ev->node = nullptr;
            ev = event::rel(ev, this);
        }

        if (container != nullptr) container->del(this);
    }

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_LINK__HH__