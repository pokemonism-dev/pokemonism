/**
 * @file        pokemonism/latios/general/queue.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_GENERAL_QUEUE__HH__
#define   __POKEMONISM_LATIOS_GENERAL_QUEUE__HH__

#include <pokemonism/latios/event.hh>

#include <pokemonism/psyduck/linked/list.hh>

namespace pokemonism {
    namespace latios {
        namespace general {
            class event;

            class queue : public virtual pokemonism::event, public virtual pokemonism::object {
            public:     typedef pokemonism::psyduck::linked::list<general::queue, general::event>   collection;
            private:    uint64 size;
            private:    general::event * head;
            private:    general::event * tail;
            public:     virtual uint64 on(uint64 total = declaration::max);
            public:     virtual void clear(void);
            public:     virtual general::event * pop(void);
            public:     virtual general::event * del(general::event * o);
            public:     virtual void push(general::event * event);
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

#endif // __POKEMONISM_LATIOS_GENERAL_QUEUE__HH__
