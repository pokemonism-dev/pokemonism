/**
 * @file        pokemonism/latios/package/pack.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_PACKAGE_PACK__HH__
#define   __POKEMONISM_LATIOS_PACKAGE_PACK__HH__

#include <pokemonism/latios/package/eventable.hh>

namespace pokemonism {
    namespace latios {
        namespace package {

            template <class object, class objectable = pokemonism::command, class generatable = void>
            class pack {
            public:     class node;
            public:     class event;
            public:     class subscription;
            public:     typedef eventable<object, objectable, objectable>::generator   generator;
            // public:     typedef eventable<object, objectable, objectable>::processor   processor;
            public:     class event : public eventable<object, objectable, generatable>::event {
                        public:     typedef typename eventable<object, objectable, generatable>::event::type     type;
                        public:     event(const uint32 tag, eventable<object, objectable, generatable>::node * node) : eventable<object, objectable, generatable>::event(tag, node) {}
                        public:     event(void) = delete;
                        public:     ~event(void) override {}
                        public:     event(const event & o) = delete;
                        public:     event(event && o) noexcept = delete;
                        public:     event & operator=(const event & o) = delete;
                        public:     event & operator=(event && o) noexcept = delete;
                        };
            public:     class subscription : public eventable<object, objectable, generatable>::subscription {

                        };
            public:     class node : public eventable<object, objectable, generatable>::node {

                        };
            };

        }
    }
}

#include <pokemonism/latios/package/pack/command.hh>
#include <pokemonism/latios/package/pack/descriptor.hh>

#endif // __POKEMONISM_LATIOS_PACKAGE_PACK__HH__
