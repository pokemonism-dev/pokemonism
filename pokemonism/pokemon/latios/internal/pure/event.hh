/**
 * @file        pokemon/latios/internal/pure/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 26, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_PURE_EVENT__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_PURE_EVENT__HH__

#include <pokemonism.hh>

#include <pokemon/latios/event.hh>

#include <pokemon/exception.hh>
#include <pokemon/latios/internal/linked/list.hh>

namespace pokemon { namespace latios { namespace internal {

    class queue;

    namespace pure {

        class event : public virtual latios::event {
        /** PROTECTED MEMBER VARIABLE */
        protected:  queue * container;
        protected:  event * prev;
        protected:  event * next;
        /** PUBLIC PURE METHOD */
        public:     virtual int on(pokemon::exception * e) = 0;
        public:     virtual void del(void) = 0;
        /** CUSTOM CONSTRUCTOR */
        protected:  inline explicit event(const uint32 type) : latios::event(type), container(nullptr), prev(nullptr), next(nullptr) {}
        /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
        public:     inline event(void) = delete;
        public:     inline ~event(void) override {}
        public:     event(const event & o) = delete;
        public:     event(event && o) noexcept = delete;
        public:     event & operator=(const event & o) = delete;
        public:     event & operator=(event && o) noexcept = delete;
        /** PUBLIC FRIEND METHOD */
        public:     friend class linked::list;
        };

    }
} } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_PURE_EVENT__HH__