/**
 * @file        pokemonism/latios/internal/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_EVENT__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_EVENT__HH__

#include <pokemonism/latios/event.hh>

#include <pokemonism/psyduck/linked/list.hh>


namespace pokemonism {
    namespace latios {
        namespace internal {
            class queue;

            class event : public virtual pokemonism::event {
            protected:  internal::queue *           container;
            protected:  pokemonism::exception *     exception;
            protected:  uint32                      id;
            private:    internal::event *           prev;
            private:    internal::event *           next;
            public:     virtual int on(void) = 0;
            public:     inline virtual int raise(pokemonism::exception * e) {
                            exception = allocator::del(exception);
                            exception = e;
                            return declaration::fail;
                        }
            public:     inline uint32 type(void) const override { return id; }
            public:     inline const pokemonism::exception * exceptionGet(void) const override { return exception; }
            protected:  event(void) = delete;
            public:     inline explicit event(const uint32 id) : container(nullptr), exception(nullptr), id(id), prev(nullptr), next(nullptr) {}
            public:     ~event(void) override;
            public:     event(const event & o) = delete;
            public:     event(event && o) noexcept = delete;
            public:     event & operator=(const event & o) = delete;
            public:     event & operator=(event && o) noexcept = delete;
            public:     friend pokemonism::psyduck::linked::list<internal::queue, internal::event>;
            };
        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_EVENT__HH__
