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

#include <pokemonism/pokemon/event.hh>

namespace pokemonism {
    namespace wattrel {

        class queue;
        class node;

        class event : public virtual pokemon::event {
        public:     typedef pokemon::event::type type;
        public:     typedef psyduck::linked::list<queue, event> collection;
        public:     static event * rel(wattrel::event * o);
        public:     struct subscription : public virtual pokemon::event::subscription {};
        protected:  wattrel::queue * container;
        protected:  wattrel::event * prev;
        protected:  wattrel::event * next;
        protected:  wattrel::node * node;
        protected:  uint32 id;
        protected:  pokemon::exception * exception;
        public:     virtual int dispatch(void);
        public:     virtual void raise(pokemon::exception * e);
        public:     virtual void complete(void);
        public:     inline uint32 eventGet(void) const override { return id; }
        public:     inline const pokemon::exception * exceptionGet(void) const { return exception; }
        public:     event(uint32 id, wattrel::node * node);
        public:     event(void) = delete;
        public:     ~event(void) override { event::rel(this);  }
        public:     event(const event & o) = delete;
        public:     event(event && o) noexcept = delete;
        public:     event & operator=(const event & o) = delete;
        public:     event & operator=(event && o) noexcept = delete;
        public:     friend wattrel::node;
        public:     friend wattrel::queue;
        public:     friend collection;
        };

    }

}

#endif // __POKEMONISM_WATTREL_EVENT_HH__