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
#include <pokemon/latios/subscription.hh>

#include <pokemon/latios/internal/linked/list.hh>

namespace pokemon { namespace latios { namespace internal {

    template <typename generator_type, typename object_type, typename event_type, typename node_type>
    class subscription : public virtual latios::subscription {
    /** PUBLIC TYPE DEFINITION */
    public:     typedef generator_type                          generator;
    public:     typedef object_type                             object;
    public:     typedef event_type                              event;
    public:     typedef node_type                               node;
    public:     typedef object::event::handler                  handler;
    public:     typedef handler                                 callback[object::event::max];
    public:     constexpr static uint32                         max = object::event::max;
    /** PRIVATE MEMBER DESCRIPTION */
    private:    generator *                                     container;
    private:    subscription<generator, object, event, node> *  prev;
    private:    subscription<generator, object, event, node> *  next;
    protected:  uint64                                          size;
    protected:  node *                                          head;
    protected:  node *                                          tail;
    protected:  uint32                                          properties;
    protected:  uint32                                          status;
    protected:  object *                                        origin;
    protected:  callback *                                      callbackSet;
    /** PROTECTED VIRTUAL METHOD */
    protected:  virtual uint32 pre(uint32 type, event ** parameter, primitivable::object ** result);
    protected:  virtual void post(uint32 type, event * parameter, primitivable::object * result, int ret);
    /** PUBLIC VIRTUAL METHOD */
    public:     virtual node * add(node * link);
    public:     virtual node * del(node * link);
    public:     virtual void clear(void);
    public:     virtual int on(uint32 type, event * parameter, primitivable::object * result);
    /** CUSTOM CONSTRUCTOR METHOD */
    public:     subscription(object * origin, uint32 properties, callback * callbackSet);
    /** DEFAULT CLASS METHOD */
    public:     subscription(void) = delete;
    public:     ~subscription(void) override;
    public:     subscription(const subscription<generator, object, event, node> & o) = delete;
    public:     subscription(subscription<generator, object, event, node> && o) noexcept = delete;
    public:     subscription<generator, object, event, node> & operator=(const subscription<generator, object, event, node> & o) = delete;
    public:     subscription<generator, object, event, node> & operator=(subscription<generator, object, event, node> && o) noexcept = delete;
    };

    /** PROTECTED VIRTUAL METHOD */
    template<typename generator, typename object, typename event, typename node>
    uint32 subscription<generator, object, event, node>::pre(const uint32 type, event ** parameter, primitivable::object ** result) {
        return type;
    }

    template<typename generator, typename object, typename event, typename node>
    void subscription<generator, object, event, node>::post(uint32 type, event * parameter, primitivable::object * result, int ret) {
        // ### 20250828 | IMPLEMENT THIS
    }

    /** PUBLIC VIRTUAL METHOD */
    template<typename generator, typename object, typename event, typename node>
    node * subscription<generator, object, event, node>::add(node * link) {
        return linked::list::add(this, link);
    }

    template<typename generator, typename object, typename event, typename node>
    node * subscription<generator, object, event, node>::del(node * link) {
        return linked::list::del(this, link);
    }

    template<typename generator, typename object, typename event, typename node>
    void subscription<generator, object, event, node>::clear(void) {
        linked::list::clear(container);
    }

    template<typename generator, typename object, typename event, typename node>
    int subscription<generator, object, event, node>::on(uint32 type, event * parameter, primitivable::object * result) {
        if ((type = pre(type, addressof(parameter), addressof(result))) < max) {
            const int ret = on(type, parameter, result);
            post(type, parameter, result, ret);

            return ret;
        }

        return event::fail;
    }

    /** CUSTOM CONSTRUCTOR METHOD */
    template<typename generator, typename object, typename event, typename node>
    subscription<generator, object, event, node>::subscription(object * origin, const uint32 properties, callback * callbackSet) :
    container(nullptr), prev(nullptr), next(nullptr), size(0), head(nullptr), tail(nullptr), properties(properties), status(none), origin(origin), callbackSet(callbackSet) {
        // ReSharper disable once CppVirtualFunctionCallInsideCtor
        on(object::event::gen, nullptr, primitivable::object::gen(success));
    }

    /** DEFAULT CLASS METHOD */
    template<typename generator, typename object, typename event, typename node>
    subscription<generator, object, event, node>::~subscription() {
        // ReSharper disable CppVirtualFunctionCallInsideCtor
        on(object::event::rem, nullptr, primitivable::object::gen(success));
        clear();
        // ReSharper restore CppVirtualFunctionCallInsideCtor

        if (container != nullptr) container->del(this);

        // ### 20250828 | RELEASE OBJECT WHEN PROPERTIES SET RELEASE OBJECT ON REM
        if (origin != nullptr) origin = nullptr;

        properties = none;
        status = none;
        callbackSet = nullptr;
    }


} } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_SUBSCRIPTION__HH__