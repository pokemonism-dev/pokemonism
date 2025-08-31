/**
 * @file
 * @brief
 * @details         이벤트 객체는 이벤트 처리에 필요한 데이터를 관리하여 실제 이벤트를 처리하는
 *                  모듈로 전달하는 객체다.
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 *
 * @protected
 */

#ifndef   __POKEMONISM_WATTREL_EVENT_HH__
#define   __POKEMONISM_WATTREL_EVENT_HH__

#include <pokemonism/psyduck/linked/list.hh>

namespace pokemonism {
    namespace wattrel {

        class queue;
        class node;

        class event {
        public:     typedef psyduck::linked::list<queue, event> collection;
        public:     static event * rel(wattrel::event * o);
        public:     wattrel::queue * container;
        public:     wattrel::event * prev;
        public:     wattrel::event * next;
        public:     wattrel::node * node;
        public:     uint32 type;
        public:     pokemon::exception * exception;
        public:     virtual int dispatch(void);
        public:     virtual void raise(pokemon::exception * e);
        public:     virtual void complete(void);
        public:     inline uint32 eventGet(void) const { return type; }
        public:     inline const pokemon::exception * exceptionGet(void) const { return exception; }
        public:     event(void) : container(nullptr), prev(nullptr), next(nullptr), node(nullptr), type(declaration::invalid), exception(nullptr) {}
        public:     event(uint32 type, wattrel::node * node) : container(nullptr), prev(nullptr), next(nullptr), node(node), type(type), exception(nullptr) {}
        public:     virtual ~event(void) { event::rel(this);  }
        public:     event(const event & o) = delete;
        public:     event(event && o) noexcept = delete;
        public:     event & operator=(const event & o) = delete;
        public:     event & operator=(event && o) noexcept = delete;
        };

    }

    namespace pokemon {
        using event = wattrel::event;
    }
}

#endif // __POKEMONISM_WATTREL_EVENT_HH__