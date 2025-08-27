/**
 * @file        pokemon/latios/internal/link.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_INTERNAL_LINK__HH__
#define   __POKEMONISM_POKEMON_INTERNAL_LINK__HH__

#include <pokemon/latios/exception.hh>

namespace pokemon { namespace latios { namespace internal {

    template <typename subscription_type, typename event_type>
    class link {
    /** PUBLIC STATIC DESCRIPTION */
    public:     typedef event_type              event;
    public:     typedef subscription_type       subscription;
    /** PUBLIC STATIC METHOD */
    public:     inline static link<subscription, event> * rem(link<subscription, event> * o);
    public:     inline static link<subscription, event> * rem(link<subscription, event> * o, event * link);
    /** PROTECTED MEMBER VARIABLE*/
    protected:  subscription *                  container;
    protected:  link<subscription, event> *     prev;
    protected:  link<subscription, event> *     next;
    protected:  event *                         origin;
    /** CUSTOM OBJECT CONSTRUCTOR */
    public:     explicit link(subscription * container);
    /** DEFAULT OBJECT METHOD */
    public:     link(void) = delete;
    public:     virtual ~link(void);
    public:     link(const link<subscription, event> & o) = delete;
    public:     link(link<subscription, event> && o) noexcept = delete;
    public:     link<subscription, event> & operator=(const link<subscription, event> & o) = delete;
    public:     link<subscription, event> & operator=(link<subscription, event> && o) noexcept = delete;
    };

    /** PUBLIC STATIC METHOD */
    template <typename subscription, typename event>
    link<subscription, event> * link<subscription, event>::rem(link<subscription, event> * o) {
        if (event * origin = o->origin; origin != nullptr) {
            origin->del();
            if (int ret = origin->on(nullptr); ret == event::retry) {
                origin->on(exceptional::deleted::event());
            }

            o->origin = nullptr;
            event::rem(origin, o);
        }

        return o;
    }

    template <typename subscription, typename event>
    link<subscription, event> * link<subscription, event>::rem(link<subscription, event> * o, event * link) {
        if (link != nullptr) delete link; // NOLINT(*-delete-null-pointer)
        return nullptr;
    }

    /** DEFAULT OBJECT METHOD */

    template <typename subscription, typename event>
    link<subscription, event>::link(subscription * container) : container(nullptr), prev(nullptr), next(nullptr), origin(nullptr) {
        container->add(this);
    }

    template <typename subscription, typename event>
    link<subscription, event>::~link(void) {
        link<subscription, event>::rem(this);
    }

} } }

#endif // __POKEMONISM_POKEMON_INTERNAL_LINK__HH__