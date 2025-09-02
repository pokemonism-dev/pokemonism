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

namespace pokemonism {
    namespace gardevoir {

        class event;

        class queue : public pokemon::object {
        public:     typedef psyduck::linked::list<gardevoir::queue, gardevoir::event> collection;
        protected:  uint64              size;
        protected:  gardevoir::event *  head;
        protected:  gardevoir::event *  tail;
        public:     virtual uint64 on(uint64 total = declaration::infinite);
        public:     virtual void clear(void);
        public:     virtual void add(gardevoir::event * event);
        public:     virtual void del(gardevoir::event * event);
        public:     queue(void) : size(declaration::zero), head(nullptr), tail(nullptr) {}
        public:     ~queue(void) override;
        public:     queue(const gardevoir::queue & o) = delete;
        public:     queue(gardevoir::queue && o) noexcept = delete;
        public:     gardevoir::queue & operator=(const gardevoir::queue & o) = delete;
        public:     gardevoir::queue & operator=(gardevoir::queue && o) noexcept = delete;
        public:     friend collection;
        };

    }
}

#endif // __POKEMONISM_GARDEVOIR_QUEUE_HH__