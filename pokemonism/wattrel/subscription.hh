/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_WATTREL_SUBSCRIPTION_HH__
#define   __POKEMONISM_WATTREL_SUBSCRIPTION_HH__

#include <pokemonism/pokemon/object.hh>
#include <pokemonism/pokemon/exception.hh>
#include <pokemonism/psyduck/linked/list.hh>
#include <pokemonism/mareep/subscription.hh>

namespace pokemonism {
    namespace wattrel {
        class node;
        class generator;

        class subscription : public pokemon::subscription, public virtual pokemon::object {
        public:     typedef psyduck::linked::list<subscription, node> collection;
        public:     wattrel::generator * container;
        public:     wattrel::subscription * prev;
        public:     wattrel::subscription * next;
        public:     uint32 size;
        public:     wattrel::node * head;
        public:     wattrel::node * tail;
        public:     virtual void add(wattrel::node * node);
        public:     virtual void del(wattrel::node * node);
        public:     virtual void clear(void);
        public:     virtual int dispatch(void) = 0;
        public:     virtual void raise(pokemon::exception * e) = 0;
        public:     virtual void complete(void) = 0;
        public:     virtual int on(uint32 type) = 0;
        public:     subscription(void);
        public:     ~subscription(void) override;
        public:     subscription(const subscription & o) = delete;
        public:     subscription(subscription && o) noexcept = delete;
        public:     subscription & operator=(const subscription & o) = delete;
        public:     subscription & operator=(subscription && o) noexcept = delete;
        };
    }
}

#endif // __POKEMONISM_WATTREL_SUBSCRIPTION_HH__