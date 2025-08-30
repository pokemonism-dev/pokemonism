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

#include <pokemon/latios/event.hh>
#include <pokemon/latios/internal/queue.hh>
#include <pokemon/latios/exception.hh>

#include <pokemon/latios/internal/subscription.hh>
#include <pokemon/latios/internal/linked/list.hh>

namespace pokemon { namespace latios { namespace internal {

    class processor;

    class event : protected virtual latios::event {
    /** STATIC MEMBER DEFINITION */
    public:     constexpr static int    success = latios::event::success;
    public:     constexpr static int    fail = latios::event::fail;
    public:     constexpr static int    retry = latios::event::retry;
    public:     inline static internal::event * on(internal::event * o, pokemon::exception * e);
    /** PROTECTED MEMBER VARIABLE */
    protected:  queue *                 container;
    protected:  event *                 prev;
    protected:  event *                 next;
    protected:  subscription::node *    node;
    /** PUBLIC GET & SET */
    public:     inline virtual pokemon::exception * exceptionGet(void) const { return exception; }
    public:     inline virtual const queue * queueGet(void) const;
    /** PUBLIC VIRTUAL METHOD */
    protected:  virtual int on(pokemon::exception * e) = 0;
    public:     inline virtual int raise(pokemon::exception * e);
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
    public:     friend class subscription::node;
    };

} } }

namespace pokemon { namespace latios { namespace internal {

    internal::event * event::on(internal::event * o, pokemon::exception * e) {
        if (o != nullptr) {
            if (const int ret = o->on(e); ret == retry) return o;

            delete o;
        }
        return nullptr;
    }

    /** PUBLIC GET & SET */
    const queue * event::queueGet(void) const {
        return container;
    }

    int event::raise(pokemon::exception * e) {
        if (e != nullptr && exception != nullptr) delete exception;
        exception = e;
        return fail;
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