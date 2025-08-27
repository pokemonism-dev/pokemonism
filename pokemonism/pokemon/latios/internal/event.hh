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

#include <pokemon/latios/internal/linked/list.hh>
#include <pokemon/latios/external/event.hh>
#include <pokemon/latios/exception.hh>

namespace pokemon { namespace latios { namespace internal {

    template <typename link_type>
    class event : protected virtual external::event {
    /** PUBLIC STATIC TYPE DEFINITION */
    public:     typedef link_type   node;
    /** PUBLIC STATIC METHOD */
    public:     inline static event<node> * rem(event<node> * o);
    public:     inline static event<node> * rem(event<node> * o, node * link);
    /** PROTECTED MEMBER VARIABLE */
    protected:  node *              link;
    /** OVERRIDE PURE::EVENT */
    public:     inline void del(void) override;
    /** CUSTOM CONSTRUCTOR */
    protected:  inline explicit event(uint32 type, node * link);
    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    public:     inline event(void) = delete;
    protected:  inline ~event(void) override;
    public:     event(const event & o) = delete;
    public:     event(event && o) noexcept = delete;
    public:     event & operator=(const event & o) = delete;
    public:     event & operator=(event && o) noexcept = delete;
    public:     friend class linked::list;
    };

    /** PUBLIC STATIC METHOD */
    template <typename node>
    event<node> * event<node>::rem(event<node> * o) {
        if (o != nullptr) {
            if (o->container != nullptr) {
                linked::list::del(o->container, o);
                // ReSharper disable once CppAbstractVirtualFunctionCallInCtor
                if (const int ret = o->on(nullptr); ret == retry) {
                    // ReSharper disable once CppAbstractVirtualFunctionCallInCtor
                    o->on(new latios::exceptional::deleted::event());
                }
            }

            node * link = o->link;

            o->link = nullptr;
            node::rem(link, o);
        }

        return o;
    }

    template <typename node>
     event<node> * event<node>::rem(event<node> * o, node * link) {
        if (o != nullptr) delete o; // NOLINT(*-delete-null-pointer)

        return nullptr;
    }

    /** OVERRIDE PURE::EVENT */
    template <typename node>
    void event<node>::del(void) {
        linked::list::del(container, this);
    }

    /** CUSTOM CONSTRUCTOR */

    template <typename node>
    event<node>::event(const uint32 type, node * link) : external::event(type), link(link) {

    }

    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */

    template <typename node>
    event<node>::~event(void) {
        event<node>::rem(this);
    }

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_EVENT__HH__