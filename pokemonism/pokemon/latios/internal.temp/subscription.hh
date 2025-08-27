/**
 * @file        pokemon/latios/internal.temp/subscription.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_SUBSCRIPTION__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_SUBSCRIPTION__HH__

#include <pokemon/latios.hh>

#include <pokemon/latios/subscription.hh>
#include <pokemon/latios/internal.temp/generator.hh>
#include <pokemon/latios/object.hh>

namespace pokemon { namespace latios { namespace internal {

    template <typename object_type, typename event_type, typename link_type>
    class subscription : public virtual latios::subscription {
    /** STATIC CLASS DESCRIPTION */
    public:     typedef object_type                 object;
    public:     typedef link_type                   node;
    public:     typedef event_type                  event;
    public:     constexpr static int                max = object::event::max;
    public:     typedef object::event::handler      function;
    public:     typedef object::event::handler      handler[max];
    /** PROTECTED STATIC METHOD */
    protected:  static inline int callbackOn(handler * callback, object * o, uint32 type, event * parameter, primitivable::object * ret);
    /** PRIVATE MEMBER VARIABLE */
    private:    generator<object, subscription> *   container;
    private:    subscription *                      prev;
    private:    subscription *                      next;
    /** PROTECTED MEMBER VARIABLE */
    protected:  uint64                              size;
    protected:  node *                              head;
    protected:  node *                              tail;
    protected:  object *                            origin;
    protected:  uint32                              properties;
    protected:  uint32                              status;
    protected:  handler *                           callback;
    /** PUBLIC VIRTUAL METHOD */
    public:     inline virtual void clear(void);
    public:     inline virtual void rem(void);
    public:     inline virtual node * add(node * link);
    public:     inline virtual node * del(node * link);
    public:     inline virtual int on(uint32 type, event * parameter, primitivable::object * result);
    /** PROTECTED VIRTUAL METHOD */
    protected:  inline virtual uint32 pre(uint32 type, event ** parameter, primitivable::object ** result);
    protected:  inline virtual void post(uint32 type, event * parameter, primitivable::object * result, int ret);
    /** CUSTOM CONSTRUCTOR */
    public:     inline subscription(object * origin, handler * callback, uint32 properties);
    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    public:     subscription(void) = delete;
    public:     inline ~subscription(void) override;
    public:     subscription(const subscription & o) = delete;
    public:     subscription(subscription && o) noexcept = delete;
    public:     subscription & operator=(const subscription & o) = delete;
    public:     subscription & operator=(subscription && o) noexcept = delete;
    };

    /** PROTECTED STATIC METHOD */
    template <typename object, typename event, typename node>
    int subscription<object, event, node>::callbackOn(handler * callback, object * o, uint32 type, event * parameter, primitivable::object * ret) {
        if (callback != nullptr && o != nullptr) {
            function func = (*callback)[type];

            if (func) return func(o, type, parameter, ret);
        }

        return declaration::fail;
    }

    /** PUBLIC VIRTUAL METHOD */
    template <typename object, typename event, typename node>
    void subscription<object, event, node>::clear(void) {
        linked::list::clear(this, node::rel);
    }

    template <typename object, typename event, typename node>
    void subscription<object, event, node>::rem(void) {
        on(object::event::rel, reinterpret_cast<primitivable::object *>(this));
        clear();

        if (container != nullptr) container->del(this);

        // ### 20250825 | IF PROPERTIES SET RELEASE OBJECT ON REL
        if (origin != nullptr) origin = nullptr;

        properties = none;
        status = none;
        callback = nullptr;
    }

    template <typename object, typename event, typename node>
    node * subscription<object, event, node>::add(node * link) {
        return linked::list::add(this, link);
    }

    template<typename object, typename event, typename node>
    node * subscription<object, event, node>::del(node * link) {
        return linked::list::del(this, link);
    }

    template<typename object, typename event, typename node>
    int subscription<object, event, node>::on(uint32 type, event * parameter, primitivable::object * result) {
        type = pre(type, addressof(parameter), addressof(result));
        if (type < max) {
            const int ret = subscription<object, event, node>::callbackOn(callback, origin, type, parameter, result);

            post(type, parameter, result, ret);

            return ret;
        }

        return declaration::fail;
    }

    /** PROTECTED VIRTUAL METHOD */
    template<typename object, typename event, typename node>
    uint32 subscription<object, event, node>::pre(const uint32 type, event ** parameter, primitivable::object ** result) {
        return type;
    }

    template<typename object, typename event, typename node>
    void subscription<object, event, node>::post(uint32 type, event * parameter, primitivable::object * result, int ret) {
        // ### 20250827 | IMPLEMENT POST PROCESS
    }

    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    template<typename object, typename event, typename node>
    subscription<object, event, node>::subscription(object * origin, handler * callback, const uint32 properties) :
    container(nullptr), prev(nullptr), next(nullptr), size(0), head(nullptr), tail(nullptr), origin(origin), properties(properties), status(none), callback(callback) {
        // ReSharper disable once CppVirtualFunctionCallInsideCtor
        on(object::event::gen, reinterpret_cast<primitivable::object *>(this));
    }

    template<typename object, typename event, typename node>
    subscription<object, event, node>::~subscription(void) {
        // ReSharper disable once CppVirtualFunctionCallInsideCtor
        rem();
    }

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_SUBSCRIPTION__HH__