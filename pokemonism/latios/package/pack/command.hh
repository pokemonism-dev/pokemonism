/**
 * @file        pokemonism/latios/package/pack/command.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_PACKAGE_PACK_COMMAND__HH__
#define   __POKEMONISM_LATIOS_PACKAGE_PACK_COMMAND__HH__

#include <pokemonism/latios/package/pack.hh>

namespace pokemonism {
    namespace latios {
        namespace package {

            template <class object, class generatable>
            class pack<object, pokemonism::command, generatable> {
            public:     class node;
            public:     class event;
            public:     class subscription;
            public:     typedef eventable<object, pokemonism::command, generatable>::generator   generator;
            // public:     typedef eventable<object, pokemonism::command, generatable>::processor   processor;

            public:     class event : public eventable<object, pokemonism::command, generatable>::event {
                        public:     typedef typename eventable<object, pokemonism::command, pokemonism::command>::event::type     type;
                        public:     event(const uint32 tag, eventable<object, pokemonism::command, generatable>::node * node) : eventable<object, pokemonism::command, generatable>::event(tag, node) {}
                        public:     event(void) = delete;
                        public:     ~event(void) override {}
                        public:     event(const event & o) = delete;
                        public:     event(event && o) noexcept = delete;
                        public:     event & operator=(const event & o) = delete;
                        public:     event & operator=(event && o) noexcept = delete;
                        };
            public:     class subscription : public eventable<object, pokemonism::command, generatable>::subscription {

            };
            public:     class node : public eventable<object, pokemonism::command, generatable>::node {

            };
            };



        }
    }
}

#endif // __POKEMONISM_LATIOS_PACKAGE_PACK_COMMAND__HH__
