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
        protected:  wattrel::generator * container;
        protected:  wattrel::subscription * prev;
        protected:  wattrel::subscription * next;
        protected:  uint32 size;
        protected:  wattrel::node * head;
        protected:  wattrel::node * tail;
        protected:  uint32 properties;
        protected:  uint32 status;
        public:     virtual void add(wattrel::node * node);
        public:     virtual void del(wattrel::node * node);
        public:     virtual void clear(void);
        public:     virtual int dispatch(void) = 0;
        public:     virtual void raise(pokemon::exception * e) = 0;
        public:     virtual void complete(void) = 0;
        public:     virtual int on(uint32 type) = 0;
        public:     explicit subscription(uint32 properties) : container(nullptr), prev(nullptr), next(nullptr), size(0), head(nullptr), tail(nullptr), properties(properties), status(declaration::none) {}
        public:     ~subscription(void) override;
        public:     subscription(const subscription & o) = delete;
        public:     subscription(subscription && o) noexcept = delete;
        public:     subscription & operator=(const subscription & o) = delete;
        public:     subscription & operator=(subscription && o) noexcept = delete;
        public:     friend psyduck::linked::list<wattrel::generator, subscription>;
        public:     friend collection;
        public:     friend wattrel::generator;
        public:     friend wattrel::node;
        };
    }
}

#endif // __POKEMONISM_WATTREL_SUBSCRIPTION_HH__