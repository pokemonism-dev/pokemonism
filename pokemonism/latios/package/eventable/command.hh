/**
 * @file        pokemonism/latios/package/eventable/command.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_PACKAGE_EVENTABLE_COMMAND__HH__
#define   __POKEMONISM_LATIOS_PACKAGE_EVENTABLE_COMMAND__HH__

#include <pokemonism/latios/package/eventable.hh>

namespace pokemonism {
    namespace latios {
        namespace package {

            template <class object>
            class eventable<object, pokemonism::command, pokemonism::command> {
            public:     class node;
            public:     class event;
            public:     class subscription;
            public:     class generator;
            public:     class generator : public package::generator<object, subscription> {
                        public:     explicit generator(general::engine * engine) : package::generator<object, subscription>(engine) {}
                        };
            public:     class event : public virtual external::event<object>, public general::event {
                        public:     eventable<object, pokemonism::command, pokemonism::command>::node * node;
                        public:     event(const uint32 tag, eventable<object, pokemonism::command, pokemonism::command>::node * node) : general::event(tag), node(node) {}
                        public:     event(void) = delete;
                        public:     ~event(void) override {}
                        public:     event(const event & o) = delete;
                        public:     event(event && o) noexcept = delete;
                        public:     event & operator=(const event & o) = delete;
                        public:     event & operator=(event && o) noexcept = delete;
                        };
            public:     class subscription : public package::observable<object>, public external::subscription<object>, public general::subscription {
                        public:     uint32  size;
                        public:     eventable<object, pokemonism::command, pokemonism::command>::node * head;
                        public:     eventable<object, pokemonism::command, pokemonism::command>::node * tail;
                        public:     generator * container;
                        public:     generator::subscription * prev;
                        public:     generator::subscription * next;
                        public:     object * target;
                        public:     uint32 properties;
                        public:     uint32 status;
                        };
            public:     class node {
                        public:     eventable<object, pokemonism::command, pokemonism::command>::event * event;
                        public:     subscription * container;
                        public:     node * prev;
                        public:     node * next;
                        public:     node(void) : event(nullptr), container(nullptr), prev(nullptr), next(nullptr) {}
                        public:     virtual ~node(void) {}
                        };

            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_PACKAGE_EVENTABLE_COMMAND__HH__
