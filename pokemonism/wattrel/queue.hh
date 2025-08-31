/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_WATTREL_QUEUE_HH__
#define   __POKEMONISM_WATTREL_QUEUE_HH__

#include <pokemonism.hh>

#include <pokemon/object.hh>
#include <pokemonism/psyduck/linked/list.hh>

namespace pokemonism {
    namespace wattrel {
        class event;

        class queue : public pokemon::object {
        public:     typedef psyduck::linked::list<queue, event> collection;
        protected:  uint32 size;
        protected:  wattrel::event * head;
        protected:  wattrel::event * tail;
        public:     virtual uint64 on(uint64 total = declaration::infinite);
        public:     virtual void clear(void);
        public:     virtual void add(wattrel::event * item);
        public:     virtual void del(wattrel::event * item);
        public:     queue(void) : size(0), head(nullptr), tail(nullptr) {}
        public:     ~queue(void) override { clear(); }
        public:     queue(const queue & o) = delete;
        public:     queue(queue && o) noexcept = delete;
        public:     queue & operator=(const queue & o) = delete;
        public:     queue & operator=(queue && o) noexcept = delete;
        public:     friend collection;
        public:     friend event;
        };
    }
}

#endif // __POKEMONISM_WATTREL_QUEUE_HH__