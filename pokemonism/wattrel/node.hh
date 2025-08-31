/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_WATTREL_NODE_HH__
#define   __POKEMONISM_WATTREL_NODE_HH__

#include <pokemonism/pokemon/exception.hh>

#include "subscription.hh"

namespace pokemonism {
    namespace wattrel {

        class event;
        class subscription;

        class node {
        public:     static node * rel(node * o);
        protected:  wattrel::subscription * container;
        protected:  wattrel::node * prev;
        protected:  wattrel::node * next;
        protected:  wattrel::event * event;
        public:     inline virtual wattrel::event * eventGet(void) const { return event; }
        public:     virtual int dispatch(void);
        public:     virtual void raise(pokemon::exception * e);
        public:     virtual void complete(void);
        public:     explicit node(wattrel::subscription * subscription);
        public:     node(void) = delete;
        public:     virtual ~node(void) { node::rel(this); }
        public:     node(const node & o) = delete;
        public:     node(node && o) noexcept = delete;
        public:     node & operator=(const node & o) = delete;
        public:     node & operator=(node && o) noexcept = delete;
        public:     friend psyduck::linked::list<subscription, node>;
        public:     friend wattrel::subscription;
        public:     friend wattrel::event;
        };
    }
}

#endif // __POKEMONISM_WATTREL_NODE_HH__