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
    /** PUBLIC CLASS DEFINITION */
    public:     class node;
    /** PUBLIC STATIC METHOD */
    public:     static subscription * rel(subscription * o);
    /** PRIVATE MEMBER DESCRIPTION */
    private:    internal::generator *       container;
    private:    internal::subscription *    prev;
    private:    internal::subscription *    next;
    protected:  uint64                      size;
    protected:  subscription::node *        head;
    protected:  subscription::node *        tail;
    protected:  uint32                      properties;
    protected:  uint32                      status;
    /** PROTECTED VIRTUAL METHOD */
    protected:  inline virtual uint32 pre(uint32 type, internal::event ** parameter, primitivable::object ** result);
    protected:  inline virtual void post(uint32 type, internal::event * parameter, primitivable::object * result, int ret);
    /** PUBLIC VIRTUAL METHOD */
    public:     inline virtual subscription::node * add(subscription::node * link);
    public:     inline virtual subscription::node * del(subscription::node * link);
    public:     inline virtual void clear(void);
    public:     inline virtual int on(uint32 type, internal::event * parameter, primitivable::object * result) = 0;
    /** PUBLIC GET & SET */
    public:     inline virtual const internal::generator * generatorGet(void) const;
    /** CUSTOM CONSTRUCTOR METHOD */
    protected:  inline explicit subscription(uint32 properties);
    /** DEFAULT CLASS METHOD */
    public:     inline ~subscription(void) override;
    public:     subscription(const internal::subscription & o) = delete;
    public:     subscription(internal::subscription && o) noexcept = delete;
    public:     internal::subscription & operator=(const internal::subscription & o) = delete;
    public:     internal::subscription & operator=(internal::subscription && o) noexcept = delete;
    /** FRIEND CLASS & METHOD DESCRIPTION */
    public:     friend class linked::list<generator, subscription>;
    public:     friend class linked::list<subscription, subscription::node>;
    };

    class subscription::node : public virtual latios::object {
    /** PROTECTED MEMBER DESCRIPTION */
    protected:  internal::subscription *    container;
    protected:  subscription::node *        prev;
    protected:  subscription::node *        next;
    protected:  internal::event *           event;
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
    };

} } }

#include <pokemon/latios/internal/generator.hh>

namespace pokemon { namespace latios { namespace internal {

    /** PROTECTED VIRTUAL METHOD */
    uint32 subscription::pre(uint32 type, internal::event ** parameter, primitivable::object ** result) {
        return type;
    }

    void subscription::post(uint32 type, internal::event * parameter, primitivable::object * result, int ret) {

    }

    /** PUBLIC VIRTUAL METHOD */
    subscription::node * subscription::add(subscription::node * link) {
        return linked::list<subscription, subscription::node>::add(this, link);
    }

    subscription::node * subscription::del(subscription::node * link) {
        return linked::list<subscription, subscription::node>::del(this, link);
    }

    void subscription::clear(void) {
        linked::list<generator, subscription>::clear(container, subscription::rel);
    }

    /** PUBLIC GET & SET */
    const internal::generator * subscription::generatorGet(void) const {
        return container;
    }

    /** CUSTOM CONSTRUCTOR METHOD */
    subscription::subscription(const uint32 properties) :
    container(nullptr), prev(nullptr), next(nullptr), size(0), head(nullptr), tail(nullptr), properties(properties), status(none) {

    }

    /** DEFAULT CLASS METHOD */

    subscription::~subscription(void) {
        properties = none;
        status = none;
    }

    /** CUSTOM CONSTRUCTOR */
    subscription::node::node(internal::subscription * container) : container(nullptr), prev(nullptr), next(nullptr), event(nullptr) {
        linked::list<internal::subscription, subscription::node>::add(container, this);
    }

    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    // node(void) = delete;
    subscription::node::~node(void) {
        if (container != nullptr) linked::list<internal::subscription, subscription::node>::del(container, this);
        // TODO: IMPLEMENT
    }

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_SUBSCRIPTION__HH__