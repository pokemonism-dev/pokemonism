/**
 * @file        pokemon/latios/queue.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_QUEUE__HH__
#define   __POKEMONISM_POKEMON_LATIOS_QUEUE__HH__

#include <pokemon/object.hh>
#include <pokemon/exception.hh>

#include <pokemon/latios.hh>
#include <pokemon/latios/linked/list.hh>

namespace pokemon { namespace latios {

    // ReSharper disable once CppClassCanBeFinal
    class queue : public virtual object {
    protected:  uint64 size;
    protected:  event * head;
    protected:  event * tail;
    public:     virtual uint64 on(void);
    public:     virtual void clear(void);
    public:     inline queue(void);
    public:     inline ~queue(void) override;
    public:     inline queue(const queue & o) = delete;
    public:     inline queue(queue && o) noexcept;
    public:     inline queue & operator=(const queue & o) = delete;
    public:     inline queue & operator=(queue && o) noexcept;
    public:     friend class linked::list;
    };

    /** DEFAULT QUEUE METHOD */
    queue::queue(void) : size(0), head(nullptr), tail(nullptr) {

    }

    queue::~queue(void) {
        queue::clear();
    }

    queue::queue(queue && o) noexcept : size(o.size), head(o.head), tail(o.tail) {
        o.size = 0;
        o.head = nullptr;
        o.tail = nullptr;
    }

    queue & queue::operator=(queue && o) noexcept {
        if (pointof(o) != this) {
            clear();
            size = o.size;
            head = o.head;
            tail = o.tail;

            o.size = 0;
            o.head = nullptr;
            o.tail = nullptr;

        }
        return *this;
    }

} }

#endif // __POKEMONISM_POKEMON_LATIOS_QUEUE__HH__