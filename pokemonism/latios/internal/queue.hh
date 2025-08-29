/**
 * @file        pokemonism/latios/internal/queue.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_QUEUE__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_QUEUE__HH__

#include <pokemonism/latios/event.hh>

#include <pokemonism/psyduck/linked/list.hh>

#include <pokemonism/latios/internal/generator.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {
            class event;

            class queue : public virtual pokemonism::event, public virtual pokemonism::object {
            public:     typedef pokemonism::psyduck::linked::list<internal::queue, internal::event>     collection;
            private:    uint64 size;
            private:    internal::event * head;
            private:    internal::event * tail;
            public:     virtual uint64 on(uint64 total = pokemonism::infinite);
            public:     virtual void clear(void);
            public:     virtual internal::event * pop(void);
            public:     virtual internal::event * del(internal::event * o);
            public:     virtual void push(internal::event * event);
            public:     queue(void) : size(0), head(nullptr), tail(nullptr) {}
            public:     ~queue(void) override { queue::clear(); }
            public:     queue(const queue & o) = delete;
            public:     queue(queue && o) noexcept = delete;
            public:     queue & operator=(const queue & o) = delete;
            public:     queue & operator=(queue && o) noexcept = delete;
            public:     friend collection;
            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_QUEUE__HH__
