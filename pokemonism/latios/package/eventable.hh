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

#include <pokemonism/latios/external/event.hh>
#include <pokemonism/latios/package/generator.hh>
#include <pokemonism/latios/package/processor.hh>
#include <pokemonism/latios/package/observable.hh>

namespace pokemonism {
    namespace latios {
        namespace package {

            template <class object, class objectable = pokemonism::command, class generatable = void>
            class eventable {
            public:     class node;
            public:     class event;
            public:     class subscription;
            public:     typedef package::generator<object, eventable<object, objectable, generatable>::subscription>    generator;
            // public:     typedef package::processor<subscription, event>                                                 processor;

            public:     class event : public virtual external::event<object>, public general::event {
                        public:     class type {
                        public:     constexpr static uint32 gen     = external::event<object>::type::gen;
                        public:     constexpr static uint32 rel     = external::event<object>::type::rel;
                        public:     constexpr static uint32 add     = external::event<object>::type::add;
                        public:     constexpr static uint32 del     = external::event<object>::type::del;
                        public:     constexpr static uint32 max     = external::event<object>::type::max;
                        };
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
                        public:     typedef int (*callback)(subscription *, uint32, event *, primitivable::object *, pokemonism::exception *);
                        public:     uint32  size;
                        public:     eventable<object, objectable, generatable>::node * head;
                        public:     eventable<object, objectable, generatable>::node * tail;
                        public:     generator * container;
                        public:     generator::subscription * prev;
                        public:     generator::subscription * next;
                        public:     object * target;
                        public:     uint32 properties;
                        public:     uint32 status;
                        public:     callback callbacks[event::type::max];
                        // public:     template <typename sup = event> int eventOn(uint32 type, sup * event, primitivable::object * result, pokemonism::exception * exception) {
                        //                 return declaration::fail;
                        //             }

                        // public:     virtual uint32 bootstrapOn(uint32 type, event ** event, primitivable::object ** result, pokemonism::exception ** exception) { return type; }
                        // public:     virtual int eventOn(uint32 type, event * event, primitivable::object * result, pokemonism::exception * exception) {
                        //     if ((type = bootstrapOn(type, pointof(event), pointof(result), pointof(exception))) < event::type::max) {
                        //         typename subscription::callback func = this->callbacks[type];
                        //
                        //         const int ret = func != nullptr ? func(this, type, event, result, exception) : declaration::success;
                        //
                        //         return completeOn(type, event, result, exception, ret);
                        //     }
                        //
                        //     return completeOn(type, event, result, exception, declaration::fail);
                        //
                        // }
                        // public:     virtual int completeOn(uint32 type, event * event, primitivable::object * result, pokemonism::exception * exception, int ret) { return ret; }

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
