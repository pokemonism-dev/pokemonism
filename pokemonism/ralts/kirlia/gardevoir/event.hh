/**
 * @file            pokemonism/ralts/kirlia/gardevoir.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_GARDEVOIR_EVENT_HH__
#define   __POKEMONISM_GARDEVOIR_EVENT_HH__

#include <pokemonism/psyduck/linked/list.hh>

#include <pokemonism/ralts/kirlia/event.hh>

#include <pokemonism/ralts/kirlia/gardevoir/node.hh>

namespace pokemonism {
    namespace gardevoir {

        class queue;

        class event : public virtual kirlia::event {
        public:     typedef psyduck::linked::list<gardevoir::queue, gardevoir::event> collection;
        public:     static gardevoir::event * rel(gardevoir::event * event);
        public:     static gardevoir::event * dispatch(gardevoir::event * event);
        protected:  gardevoir::queue *  container;
        protected:  gardevoir::event *  prev;
        protected:  gardevoir::event *  next;
        protected:  gardevoir::node *   node;
        protected:  uint32              id;
        public:     inline uint32 eventGet(void) const override { return id; }
        public:     inline void raise(pokemon::exception * e) const {
                        pokemon_develop_check(node == nullptr, do {
                            e = allocator::del(e);
                            return;
                        } while (0));

                        node->raise(e);
                    }
        public:     inline int on(void) const {
                        pokemon_develop_check(node == nullptr, return fail);

                        return node->on();
                    }
        public:     explicit event(uint32 id, gardevoir::node * node) : container(nullptr), prev(nullptr), next(nullptr), node(node), id(id) { pokemon_develop_quick_check(node == nullptr); }
        protected:  event(void) : container(nullptr), prev(nullptr), next(nullptr), node(nullptr), id(declaration::invalid) {}
        public:     ~event(void) override { gardevoir::event::rel(this); }
        public:     event(const gardevoir::event & o) = delete;
        public:     event(gardevoir::event && o) noexcept = delete;
        public:     gardevoir::event & operator=(const gardevoir::event & o) = delete;
        public:     gardevoir::event & operator=(gardevoir::event && o) noexcept = delete;
        public:     friend collection;
        };

    }
}

#endif // __POKEMONISM_GARDEVOIR_EVENT_HH__