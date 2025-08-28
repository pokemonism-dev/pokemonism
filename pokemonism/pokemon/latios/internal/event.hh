/**
 * @file        pokemon/latios/internal/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 26, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_EVENT__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_EVENT__HH__

#include <pokemonism.hh>

#include <pokemon/latios/internal/queue.hh>
#include <pokemon/latios/exception.hh>

#include <pokemon/latios/internal/subscription.hh>
#include <pokemon/latios/internal/linked/list.hh>

namespace pokemon { namespace latios { namespace internal {

    class event : protected virtual latios::event {
    /** STATIC MEMBER DEFINITION */
    public:     constexpr static int    success = latios::event::success;
    public:     constexpr static int    fail = latios::event::fail;
    public:     constexpr static int    retry = latios::event::retry;
    /** PROTECTED MEMBER VARIABLE */
    protected:  queue *                 container;
    protected:  event *                 prev;
    protected:  event *                 next;
    protected:  subscription::node *    node;
    /** PUBLIC GET & SET */
    public:     inline virtual const queue * queueGet(void) const;
    /** PUBLIC VIRTUAL METHOD */
    public:     virtual int on(pokemon::exception * e) = 0;
    /** CUSTOM CONSTRUCTOR */
    protected:  inline event(uint32 type, subscription::node * node);
    protected:  inline explicit  event(subscription::node * node);
    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    public:     inline event(void) = delete;
    public:     inline ~event(void) override;
    public:     event(const event & o) = delete;
    public:     event(event && o) noexcept = delete;
    public:     event & operator=(const event & o) = delete;
    public:     event & operator=(event && o) noexcept = delete;
    /** FRIEND CLASS & METHOD */
    public:     friend class linked::list<queue, internal::event>;
    };

} } }

namespace pokemon { namespace latios { namespace internal {

    /** PUBLIC GET & SET */
    const queue * event::queueGet(void) const {
        return container;
    }

    /** CUSTOM CONSTRUCTOR */
    event::event(const uint32 type, subscription::node * node) : latios::event(type), node(node), container(nullptr), prev(nullptr), next(nullptr) {

    }

    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    event::event(subscription::node * node) : node(node), container(nullptr), prev(nullptr), next(nullptr) {

    }

    event::~event(void) {
        // TODO: IMPLEMENT THIS
    }

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_EVENT__HH__