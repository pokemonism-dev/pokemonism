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
                        // public:     class processor : public package::processor<subscription, event> {
                        // protected:  static int (*on)(subscription *, uint32, event *);
                        // protected:  static int (*execute)(subscription *, event *);
                        // public:     friend general::engine;
                        // public:     processor(void) {}
                        // public:     ~processor(void) {}
                        // public:     processor(const processor & o) = delete;
                        // public:     processor(processor && o) noexcept = delete;
                        // public:     processor & operator=(const processor & o) = delete;
                        // public:     processor & operator=(processor && o) noexcept = delete;
                        // };
            public:     class event : public virtual external::event<object>, public general::event {
                        public:     class type {
                        public:     constexpr static uint32 gen     = external::event<object>::type::gen;
                        public:     constexpr static uint32 rel     = external::event<object>::type::rel;
                        public:     constexpr static uint32 add     = external::event<object>::type::add;
                        public:     constexpr static uint32 del     = external::event<object>::type::del;
                        public:     constexpr static uint32 execute = external::event<object>::type::max;
                        public:     constexpr static uint32 max     = external::event<object>::type::max + 1;
                        };
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
                        public:     typedef int (*callback)(subscription *, uint32, event *, primitivable::object *, pokemonism::exception *);
                        public:     uint32  size;
                        public:     eventable<object, pokemonism::command, pokemonism::command>::node * head;
                        public:     eventable<object, pokemonism::command, pokemonism::command>::node * tail;
                        public:     generator * container;
                        public:     generator::subscription * prev;
                        public:     generator::subscription * next;
                        public:     object * target;
                        public:     uint32 properties;
                        public:     uint32 status;
                        public:     callback callbacks[event::type::max];

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
                        public:     eventable<object, pokemonism::command, pokemonism::command>::event * event;
                        public:     subscription * container;
                        public:     node * prev;
                        public:     node * next;
                        public:     node(void) : event(nullptr), container(nullptr), prev(nullptr), next(nullptr) {}
                        public:     virtual ~node(void) {}
                        };
            };

            // template <class object>
            // int (*eventable<object, pokemonism::command, pokemonism::command>::processor::on)(subscription *, uint32, event *) = nullptr;
            //
            // template <class object>
            // int (*eventable<object, pokemonism::command, pokemonism::command>::processor::execute)(subscription *, event *) = nullptr;

        }
    }
}

#endif // __POKEMONISM_LATIOS_PACKAGE_EVENTABLE_COMMAND__HH__
