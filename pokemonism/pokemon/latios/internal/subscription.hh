/**
 * @file        pokemon/latios/internal/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_SUBSCRIPTION__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_SUBSCRIPTION__HH__

#include <pokemon/primitivable.hh>

#include <pokemon/latios/object.hh>
#include <pokemon/latios/subscription.hh>

#include <pokemon/latios/internal/linked/list.hh>

namespace pokemon { namespace latios { namespace internal {

    class generator;
    class event;

    class subscription : public virtual latios::subscription {
    /** PUBLIC TYPE DEFINITION */
    public:     typedef int (*listener)(latios::object *, uint32, internal::event *, primitivable::object *);
    public:     typedef listener *          handlerSet;
    /** PUBLIC CLASS DEFINITION */
    public:     class node;
    public:     struct function {
                public:     typedef uint32 (*bootstrapper)(subscription *, uint32, internal::event **, latios::object *, primitivable::object **);
                public:     typedef void (*packer)(subscription *, uint32, internal::event *, latios::object *, primitivable::object *, int);
                public:     uint32 (*bootstrap)(subscription *, uint32, internal::event **, latios::object *, primitivable::object **);
                public:     void (*pack)(subscription *, uint32, internal::event *, latios::object *, primitivable::object *, int);
                public:     inline function(bootstrapper bootstrap, packer pack);
                };
    /** PUBLIC STATIC METHOD */
    public:     static subscription * rel(subscription * o);
    public:     static subscription * rem(subscription * o);
    public:     inline static uint32 bootstrap(subscription * o, uint32 type, internal::event ** event, latios::object * object, primitivable::object ** result);
    public:     inline static void pack(subscription * o, uint32 type, internal::event * event, latios::object * object, primitivable::object * result, int ret);
    /** PRIVATE MEMBER DESCRIPTION */
    private:    internal::generator *       container;
    private:    internal::subscription *    prev;
    private:    internal::subscription *    next;
    protected:  uint64                      size;
    protected:  subscription::node *        head;
    protected:  subscription::node *        tail;
    protected:  uint32                      properties;
    protected:  uint32                      status;
    protected:  latios::object *            object;
    protected:  handlerSet                  callbackSet;
    protected:  subscription::function      func;
    /** OVERRIDE MAREEP SUBSCRIPTION */
    public:     void cancel(void) override;
    public:     inline virtual latios::object * objectGet(void) const { return object; }
    /** PUBLIC  */
    public:     inline virtual uint32 maximum(void) const { return latios::object::event::max; }
    public:     int on(uint32 type, internal::event * event, primitivable::object * result);
    /** PUBLIC VIRTUAL METHOD */
    public:     inline virtual subscription::node * add(subscription::node * link);
    public:     inline virtual subscription::node * del(subscription::node * link);
    public:     inline virtual void clear(void);
    /** PUBLIC GET & SET */
    public:     inline virtual const internal::generator * generatorGet(void) const;
    protected:  inline void boostrapSet(function::bootstrapper f);
    protected:  inline void packSet(function::packer f);
    /** CUSTOM CONSTRUCTOR METHOD */
    protected:  inline explicit subscription(latios::object * object, uint32 properties, listener * callbackSet);
    /** DEFAULT CLASS METHOD */
    public:     ~subscription(void) override;
    public:     subscription(const internal::subscription & o) = delete;
    public:     subscription(internal::subscription && o) noexcept = delete;
    public:     internal::subscription & operator=(const internal::subscription & o) = delete;
    public:     internal::subscription & operator=(internal::subscription && o) noexcept = delete;
    /** FRIEND CLASS & METHOD DESCRIPTION */
    public:     friend class linked::list<generator, subscription>;
    public:     friend class linked::list<subscription, subscription::node>;
    };

    // ReSharper disable CppParameterMayBeConst
    subscription::function::function(bootstrapper bootstrap, packer pack) : bootstrap(bootstrap), pack(pack) {}
    // ReSharper restore CppParameterMayBeConst

    class subscription::node : public virtual latios::object {
    /** STATIC PUBLIC METHOD */
    public:     static subscription::node * rem(subscription::node * o);
    /** PROTECTED MEMBER DESCRIPTION */
    protected:  internal::subscription *    container;
    protected:  subscription::node *        prev;
    protected:  subscription::node *        next;
    protected:  internal::event *           event;
    public:     inline virtual internal::subscription * subscriptionGet(void) { return container; }
    /** CUSTOM CONSTRUCTOR */
    protected:  inline explicit node(internal::subscription * container);
    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    public:     node(void) = delete;
    public:     inline ~node(void) override;
    public:     node(const subscription::node & o) = delete;
    public:     node(subscription::node && o) noexcept = delete;
    public:     subscription::node & operator=(const subscription::node & o) = delete;
    public:     subscription::node & operator=(subscription::node && o) noexcept = delete;
    /** FRIEND CLASS & METHOD DESCRIPTION */
    public:     friend class linked::list<internal::subscription, subscription::node>;
    public:     friend class internal::event;
    };

    /** PUBLIC STATIC METHOD */

    uint32 subscription::bootstrap(subscription * o, const uint32 type, internal::event ** event, latios::object * object, primitivable::object ** result) { return type; }
    void subscription::pack(subscription * o, uint32 type, internal::event * event, latios::object * object, primitivable::object * result, int ret) {}

    /** PUBLIC VIRTUAL METHOD */
    subscription::node * subscription::add(subscription::node * link) {
        return linked::list<subscription, subscription::node>::add(this, link);
    }

    subscription::node * subscription::del(subscription::node * link) {
        return linked::list<subscription, subscription::node>::del(this, link);
    }

    void subscription::clear(void) {
        linked::list<subscription, subscription::node>::clear(this, subscription::node::rem);
    }

    /** PUBLIC GET & SET */
    const internal::generator * subscription::generatorGet(void) const {
        return container;
    }

    // ReSharper disable CppParameterMayBeConst
    void subscription::boostrapSet(function::bootstrapper f) {
        func.bootstrap = f;
    }

    void subscription::packSet(function::packer f) {
        func.pack = f;
    }
    // ReSharper restore CppParameterMayBeConst

    /** CUSTOM CONSTRUCTOR METHOD */
    subscription::subscription(latios::object * object, const uint32 properties, listener * callbackSet) :
    container(nullptr), prev(nullptr), next(nullptr), size(0), head(nullptr), tail(nullptr), properties(properties), status(none), object(object), callbackSet(callbackSet), func(bootstrap, pack) {
        on(latios::object::event::max, nullptr, primitivable::object::gen(success));
    }


    /** CUSTOM CONSTRUCTOR */
    subscription::node::node(internal::subscription * container) : container(nullptr), prev(nullptr), next(nullptr), event(nullptr) {
        linked::list<internal::subscription, subscription::node>::add(container, this);
    }

    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    // node(void) = delete;
    subscription::node::~node(void) {
        subscription::node::rem(this);
    }

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_SUBSCRIPTION__HH__