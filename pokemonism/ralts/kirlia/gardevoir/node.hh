/**
 * @file            pokemonism/ralts/kirlia/gardevoir/node.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_GARDEVOIR_NODE_HH__
#define   __POKEMONISM_GARDEVOIR_NODE_HH__

#include <pokemonism/ralts/kirlia/gardevoir/envelope.hh>
#include <pokemonism/ralts/kirlia/gardevoir/subscription.hh>

namespace pokemonism {
    namespace gardevoir {

        class event;

        class node : public gardevoir::envelope {
        protected:  static gardevoir::node * rem(gardevoir::node * o);
        protected:  gardevoir::subscription *   container;
        protected:  gardevoir::node *           prev;
        protected:  gardevoir::node *           next;
        protected:  gardevoir::event *          event;
        protected:  inline virtual gardevoir::event * eventGet(void) const { return event; }
        protected:  inline void raise(pokemon::exception * e) {
                        pokemon_critical_check(e == nullptr || container == nullptr, do {
                            e = allocator::del(e);
                            return;
                        } while (0));

                        exception = allocator::del(exception);
                        exception = e;
                        container->raise(this);
                    }
        protected:  inline int on(void) { return container->on(this); }
        protected:  inline explicit node(gardevoir::subscription * container) : container(nullptr), prev(nullptr), next(nullptr), event(nullptr) {
                        pokemon_develop_check(container == nullptr, return);

                        container->add(this);
                    }
        protected:  inline node(void) : container(nullptr), prev(nullptr), next(nullptr), event(nullptr) {}
        public:     inline ~node(void) override { gardevoir::node::rem(this); }
        public:     node(const gardevoir::node & o) = delete;
        public:     node(gardevoir::node && o) noexcept = delete;
        public:     gardevoir::node & operator=(const gardevoir::node & o) = delete;
        public:     gardevoir::node & operator=(gardevoir::node && o) noexcept = delete;
        public:     friend psyduck::linked::list<gardevoir::subscription, gardevoir::node>;
        public:     friend gardevoir::event;
        public:     friend gardevoir::subscription;
        };

    }
}

#endif // __POKEMONISM_GARDEVOIR_NODE_HH__