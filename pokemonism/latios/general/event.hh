/**
 * @file        pokemonism/latios/general/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_GENERAL_EVENT__HH__
#define   __POKEMONISM_LATIOS_GENERAL_EVENT__HH__

#include <pokemonism/latios/event.hh>

#include <pokemonism/psyduck/linked/list.hh>

namespace pokemonism {
    namespace latios {
        namespace general {
            class queue;

            class event : public virtual pokemonism::event {
            protected:  general::queue *           container;
            protected:  pokemonism::exception *    exception;
            protected:  uint32                     tag;
            private:    general::event *           prev;
            private:    general::event *           next;
            public:     virtual int on(void) = 0;
            public:     inline virtual pokemonism::exception * raise(pokemonism::exception * e) {
                            exception = allocator::del(exception);
                            return (exception = e);
                        }
            public:     inline uint32 typeGet(void) const override { return tag; }
            public:     inline const pokemonism::exception * exceptionGet(void) const override { return exception; }
            public:     inline explicit event(const uint32 type) : container(nullptr), exception(nullptr), tag(type), prev(nullptr), next(nullptr) {}
            protected:  event(void) = delete;
            public:     ~event(void) override;
            public:     event(const event & o) = delete;
            public:     event(event && o) noexcept = delete;
            public:     event & operator=(const event & o) = delete;
            public:     event & operator=(event && o) noexcept = delete;
            public:     friend pokemonism::psyduck::linked::list<general::queue, general::event>;
            };
        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_EVENT__HH__
