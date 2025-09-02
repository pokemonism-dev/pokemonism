/**
 * @file            pokemonism/ralts/kirlia/gardevoir/queue.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_GARDEVOIR_QUEUE_HH__
#define   __POKEMONISM_GARDEVOIR_QUEUE_HH__

#include <pokemonism/pokemon/object.hh>
#include <pokemonism/psyduck/linked/list.hh>

#include <pokemonism/ralts/kirlia/gardevoir/event.hh>

namespace pokemonism {
    namespace gardevoir {

        class node;

        class queue : public pokemon::object {
        public:     typedef psyduck::linked::list<gardevoir::queue, gardevoir::event> collection;
        protected:  uint64              size;
        protected:  gardevoir::event *  head;
        protected:  gardevoir::event *  tail;
        public:     uint64 on(uint64 total = declaration::infinite);
        public:     inline void clear(void);
        public:     inline void add(gardevoir::event * event);
        public:     inline void del(gardevoir::event * event);
        public:     inline queue(void) : size(declaration::zero), head(nullptr), tail(nullptr) {}
        public:     inline ~queue(void) override;
        public:     queue(const gardevoir::queue & o) = delete;
        public:     queue(gardevoir::queue && o) noexcept = delete;
        public:     gardevoir::queue & operator=(const gardevoir::queue & o) = delete;
        public:     gardevoir::queue & operator=(gardevoir::queue && o) noexcept = delete;
        public:     friend collection;
        public:     friend gardevoir::event;
        };

        inline void queue::clear(void) {
            collection::clear(this, gardevoir::event::rel);
        }

        inline void queue::add(gardevoir::event * event) {
            if (event != nullptr) collection::add(this, event, *this);
        }

        inline void queue::del(gardevoir::event * event) {
            if (event != nullptr) collection::del(this, event, *this);
        }

        inline queue::~queue(void) {
            collection::clear(this, gardevoir::event::rel);
        }

    }
}

#endif // __POKEMONISM_GARDEVOIR_QUEUE_HH__