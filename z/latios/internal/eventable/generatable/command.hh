/**
 * @file        pokemonism/latios/internal/eventable/generatable/command.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_EVENTABLE_GENERATABLE_COMMAND__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_EVENTABLE_GENERATABLE_COMMAND__HH__

#include <pokemonism/latios/command.hh>

#include <pokemonism/latios/internal/eventable.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {

            // template <class object, class node>
            // class generatable : public general::generator {
            // public:     typedef node        subscription;
            // public:     uint64 size;
            // public:     node * head;
            // public:     node * tail;  generatable
            // public:     explicit generatable(general::engine * engine) : general::generator(engine), size(0), head(nullptr), tail(nullptr) {}
            // };

            template <class object, class objectable>
            class eventable<object, objectable, pokemonism::command> {
            public:     class node;
            public:     class event;
            public:     class subscription;
            public:     class generator : public generatable<object, subscription> {
                        public:     explicit generator(general::engine * engine) : internal::generatable<object, subscription>(engine) {}
                        };
            public:     class event : public virtual external::event<object>, public general::event {
                        public:     eventable<object, objectable, pokemonism::command>::node * node;
                        public:     event(const uint32 tag, eventable<object, objectable, pokemonism::command>::node * node) : general::event(tag), node(node) {
                                        node->event = this;
                                    }
                        public:     event(void) = delete;
                        public:     ~event(void) override {}
                        public:     event(const event & o) = delete;
                        public:     event(event && o) noexcept = delete;
                        public:     event & operator=(const event & o) = delete;
                        public:     event & operator=(event && o) noexcept = delete;
                        };
            public:     class subscription : public internal::observable<objectable>, public external::subscription<objectable>, public general::subscription {
                        public:     uint32  size;
                        public:     eventable<object, objectable, pokemonism::command>::node * head;
                        public:     eventable<object, objectable, pokemonism::command>::node * tail;
                        public:     generator * container;
                        public:     generator::subscription * prev;
                        public:     generator::subscription * next;
                        };
            public:     class node {
                        public:     eventable<object, objectable, pokemonism::command>::event * event;
                        };


            //
            // public:     class subscription {
            //             public:     class node {
            //                         public:     subscription * container;
            //                         public:     node * prev;
            //                         public:     node * next;
            //                         public:     eventable * event;
            //                         public:     node(subscription * container) : container(nullptr), prev(nullptr), next(nullptr), event(nullptr) {}
            //                         public:     node(void) = delete;
            //                         public:     virtual ~node(void) {}
            //                         public:     node(const node & o) = delete;
            //                         public:     node(node && o) noexcept = delete;
            //                         public:     node & operator=(const node & o) = delete;
            //                         public:     node & operator=(node && o) noexcept = delete;
            //                         };
            //             };
            // public:     int on(void) override = 0;
            // public:     subscription::node * node;
            // public:     eventable(const uint32 tag, subscription::node * node) : general::event(tag), node(node) {}
            // public:     eventable(void) = delete;
            // public:     ~eventable(void) override {}
            // public:     eventable(const eventable<object, objectable, generatable> & o) = delete;
            // public:     eventable(eventable<object, objectable, generatable> && o) noexcept = delete;
            // public:     eventable<object, objectable, generatable> & operator=(const eventable<object, objectable, generatable> & o) = delete;
            // public:     eventable<object, objectable, generatable> & operator=(eventable<object, objectable, generatable> && o) noexcept = delete;
            };


        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_EVENTABLE_GENERATABLE_VOID__HH__
