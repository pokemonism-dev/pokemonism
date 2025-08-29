/**
 * @file        pokemonism/latios/package/eventable.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_PACKAGE_EVENTABLE__HH__
#define   __POKEMONISM_LATIOS_PACKAGE_EVENTABLE__HH__

#include <pokemonism/latios/command.hh>

#include <pokemonism/latios/package/generator.hh>
#include <pokemonism/latios/package/observable.hh>

namespace pokemonism {
    namespace latios {
        namespace package {

            template <class object, class objectable = pokemonism::command, class generatable = void>
            class eventable {
            public:     class node;
            public:     class event;
            public:     class subscription;
            public:     typedef package::generator<object, eventable<object, objectable, generatable>::subscription> generator;
            public:     class event : public virtual external::event<object>, public general::event {
                        public:     constexpr static uint32 gen     = external::event<object>::gen;
                        public:     constexpr static uint32 rel     = external::event<object>::rel;
                        public:     constexpr static uint32 add     = external::event<object>::add;
                        public:     constexpr static uint32 del     = external::event<object>::del;
                        public:     constexpr static uint32 max     = external::event<object>::max;
                        public:     eventable<object, objectable, generatable>::node * node;
                        public:     event(const uint32 tag, eventable<object, objectable, generatable>::node * node) : general::event(tag), node(node) {}
                        public:     event(void) = delete;
                        public:     ~event(void) override {}
                        public:     event(const event & o) = delete;
                        public:     event(event && o) noexcept = delete;
                        public:     event & operator=(const event & o) = delete;
                        public:     event & operator=(event && o) noexcept = delete;
                        };
            public:     class subscription : public package::observable<object>, public external::subscription<object>, public general::subscription {
                        public:     uint32  size;
                        public:     eventable<object, objectable, generatable>::node * head;
                        public:     eventable<object, objectable, generatable>::node * tail;
                        public:     generator * container;
                        public:     generator::subscription * prev;
                        public:     generator::subscription * next;
                        public:     object * target;
                        public:     uint32 properties;
                        public:     uint32 status;
                        };
            public:     class node {
                        public:     eventable<object, objectable, generatable>::event * event;
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

#include <pokemonism/latios/package/eventable/command.hh>
#include <pokemonism/latios/package/eventable/descriptor.hh>

#endif // __POKEMONISM_LATIOS_PACKAGE_EVENTABLE__HH__
