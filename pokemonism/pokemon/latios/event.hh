/**
 * @file        pokemon/latios/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 26, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_EVENT__HH__
#define   __POKEMONISM_POKEMON_LATIOS_EVENT__HH__

#include <pokemonism.hh>
#include <pokemon/latios.hh>
#include <pokemon/latios/queue.hh>
#include <pokemon/latios/linked/list.hh>

namespace pokemon { namespace latios {

    class event {
    public:     inline static event * cancel(event * e);
    protected:  queue * container;
    protected:  event * prev;
    protected:  event * next;
    public:     virtual event * on(void) = 0;
    public:     virtual event * cancel(void) = 0;
    public:     inline event(void);
    public:     inline virtual ~event(void);
    public:     event(const event & o) = delete;
    public:     event(event && o) noexcept = delete;
    public:     event & operator=(const event & o) = delete;
    public:     event & operator=(event && o) noexcept = delete;
    public:     friend class linked::list;
    };

    /** STATIC METHOD */
    event * event::cancel(event * e) {
        if (e != nullptr) return e->cancel();
        return e;
    }

    /** DEFAULT EVENT METHOD */

    event::event(void) : container(nullptr), prev(nullptr), next(nullptr) {

    }

    event::~event(void) {
        allocator::del(linked::list::del(this->container, this));
    }

} }

#endif // __POKEMONISM_POKEMON_LATIOS_EVENT__HH__