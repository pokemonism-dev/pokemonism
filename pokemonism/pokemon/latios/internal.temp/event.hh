/**
 * @file        pokemon/latios/internal.temp/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 26, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_EVENT__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_EVENT__HH__

#include <pokemonism.hh>
#include <pokemon/latios.hh>
#include <pokemon/latios/internal.hh>

#include <pokemon/latios/event.hh>
#include <pokemon/latios/internal.temp/queue.hh>
#include <pokemon/latios/internal.temp/linked/list.hh>

namespace pokemon { namespace latios { namespace internal {

    class queue;

    template <typename link_type>
    class event : public latios::event {
    /** STATIC CLASS TYPE DEFINITION */
    public:     typedef link_type   link;

    /** PUBLIC STATIC METHOD */
    public:     inline static event<link> * rel(event<link> * o);
    public:     inline static event<link> * rel(event<link> * o, link * node);
    /** PRIVATE MEMBER VARIABLE */
    private:    queue *             container;
    private:    event *             prev;
    private:    event *             next;
    protected:  link *              node;
    /** PUBLIC PURE METHOD */
    public:     virtual int on(void) = 0;
    public:     virtual bool cancel(void) = 0;
    /** PUBLIC VIRTUAL METHOD */
    public:     virtual void rem(void);
    /** CUSTOM CONSTRUCTOR */
    public:     inline explicit event(uint32 type, link * node);
    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    public:     event(void) = delete;
    public:     inline ~event(void) override;
    public:     event(const event & o) = delete;
    public:     event(event && o) noexcept = delete;
    public:     event & operator=(const event & o) = delete;
    public:     event & operator=(event && o) noexcept = delete;
    /** FRIEND CLASS */
    public:     friend class linked::list;
    };

    template <typename link>
    void event<link>::rem(void) {
        if (container != nullptr) {
            linked::list::del(container, this);
            const int ret = on();
            if (ret != event::retry) {

            }
        }
    }

    /** CUSTOM CONSTRUCTOR */

    template <typename link>
    event<link>::event(const uint32 type, link * node) : latios::event(type), container(nullptr), prev(nullptr), next(nullptr), node(node) {

    }

    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */

    template <typename link>
    event<link>::~event(void) {
        // ReSharper disable once CppVirtualFunctionCallInsideCtor
        rem();
    }

    // /** STATIC METHOD */
    // event * event::cancel(event * e) {
    //     if (e != nullptr) e->cancel();
    //     return e;
    // }
    //
    // /** DEFAULT EVENT METHOD */
    // event::~event(void) {
    //     if (container != nullptr) allocator::del(linked::list::del(container, this));
    // }
    //
    // /** CUSTOM CONSTRUCTOR */
    // event::event(const uint32 type) : latios::event(type), container(nullptr), prev(nullptr), next(nullptr) {
    //
    // }

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_EVENT__HH__