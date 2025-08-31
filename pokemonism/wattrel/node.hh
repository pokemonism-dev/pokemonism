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

#include <pokemonism.hh>

#include <pokemonism/pokemon/exception.hh>

namespace pokemonism {
    namespace wattrel {

        class event;
        class subscription;

        class node {
        public:     static node * rel(node * o);
        public:     wattrel::subscription * container;
        public:     wattrel::node * prev;
        public:     wattrel::node * next;
        public:     wattrel::event * event;
        public:     virtual int dispatch(void);
        public:     virtual void raise(pokemon::exception * e);
        public:     virtual void complete(void);
        public:     node(void);
        public:     virtual ~node(void) { node::rel(this); }
        public:     node(const node & o) = delete;
        public:     node(node && o) noexcept = delete;
        public:     node & operator=(const node & o) = delete;
        public:     node & operator=(node && o) noexcept = delete;
        };
    }
}

#endif // __POKEMONISM_WATTREL_NODE_HH__