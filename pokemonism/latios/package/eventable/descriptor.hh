/**
 * @file        pokemonism/latios/package/eventable/descriptor.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_PACKAGE_EVENTABLE_DESCRIPTOR__HH__
#define   __POKEMONISM_LATIOS_PACKAGE_EVENTABLE_DESCRIPTOR__HH__

#include <pokemonism/latios/descriptor.hh>
#include <pokemonism/latios/package/eventable.hh>

namespace pokemonism {
    namespace latios {
        namespace package {

            template <class object>
            class eventable<object, pokemonism::descriptor, pokemonism::descriptor> {
            public:     class node;
            public:     class event;
            public:     class subscription;
            public:     class generator;
            public:     class generator : public package::generator<object, subscription> {
                        public:     explicit generator(general::engine * engine) : package::generator<object, subscription>(engine) {}
                        };
            public:     class event : public virtual pokemonism::event, public general::event {
                        public:     class type {
                                    public:     constexpr static uint32 gen     = pokemonism::event::type::gen;
                                    public:     constexpr static uint32 rel     = pokemonism::event::type::rel;
                                    public:     constexpr static uint32 add     = pokemonism::event::type::add;
                                    public:     constexpr static uint32 del     = pokemonism::event::type::del;
                                    public:     constexpr static uint32 open    = pokemonism::event::type::max;
                                    public:     constexpr static uint32 read    = pokemonism::event::type::max + 1;
                                    public:     constexpr static uint32 write   = pokemonism::event::type::max + 2;
                                    public:     constexpr static uint32 close   = pokemonism::event::type::max + 3;
                                    public:     constexpr static uint32 max     = pokemonism::event::type::max + 4;
                                    };
                        public:     eventable<object, pokemonism::descriptor, pokemonism::descriptor>::node * node;
                        public:     event(const uint32 tag, eventable<object, pokemonism::descriptor, pokemonism::descriptor>::node * node) : general::event(tag), node(node) {}
                        public:     event(void) = delete;
                        public:     ~event(void) override {}
                        public:     event(const event & o) = delete;
                        public:     event(event && o) noexcept = delete;
                        public:     event & operator=(const event & o) = delete;
                        public:     event & operator=(event && o) noexcept = delete;
                        };
            public:     class subscription : public package::observable<object>, public external::subscription<object>, public general::subscription {
                        public:     typedef int (*callback)(subscription *, uint32, event *, primitivable::object *, pokemonism::exception *, int);
                        public:     uint32  size;
                        public:     eventable<object, pokemonism::descriptor, pokemonism::descriptor>::node * head;
                        public:     eventable<object, pokemonism::descriptor, pokemonism::descriptor>::node * tail;
                        public:     generator * container;
                        public:     generator::subscription * prev;
                        public:     generator::subscription * next;
                        public:     object * target;
                        public:     uint32 properties;
                        public:     uint32 status;
                        public:     callback callbacks[event::type::max];
                        public:     virtual int eventOn(eventable<object, pokemonism::descriptor, pokemonism::descriptor>::node * node) = 0;
                        public:     virtual int eventOn(uint32 type, eventable<object, pokemonism::descriptor, pokemonism::descriptor>::event * event) = 0;
                        public:     virtual int callbackOn(uint32 type, event * event, primitivable::object * result, pokemonism::exception * exception, int ret) = 0;
                        public:     virtual eventable<object, pokemonism::descriptor, pokemonism::descriptor>::node * add(eventable<object, pokemonism::descriptor, pokemonism::descriptor>::node * node) = 0;
                        public:     virtual eventable<object, pokemonism::descriptor, pokemonism::descriptor>::node * del(eventable<object, pokemonism::descriptor, pokemonism::descriptor>::node * node) = 0;
                        public:     virtual void clear(void) = 0;
                        private:    inline callback callbackGet(uint32 type) const { return type < event::type::max ? callbacks[type] : nullptr; }
                        public:     subscription(object * target, uint32 properties, const callback * callbacks, uint32 n)
                                    : size(0), head(nullptr), tail(nullptr), container(nullptr), prev(nullptr), next(nullptr),
                                    target(target), properties(properties), status(none), callbacks() {
                                            if (event::type::max < n) throw pokemonism::exception();
                                            if (n > 0) memset(this->callbacks, callbacks, n * sizeof(callback));
                                    }


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
                        // }
                        // public:     virtual int completeOn(uint32 type, event * event, primitivable::object * result, pokemonism::exception * exception, int ret) { return ret; }
                        };
            public:     class node : public general::node {
                        public:     eventable<object, pokemonism::descriptor, pokemonism::descriptor>::event * event;
                        public:     subscription * container;
                        public:     node * prev;
                        public:     node * next;
                        public:     node(void) : event(nullptr), container(nullptr), prev(nullptr), next(nullptr) {}
                        public:     virtual ~node(void) {}
                        };

            };

            // template <class object>
            // int (*eventable<object, pokemonism::descriptor, pokemonism::descriptor>::processor::on)(subscription *, uint32, event *) = nullptr;
            //
            // template <class object>
            // int (*eventable<object, pokemonism::descriptor, pokemonism::descriptor>::processor::open)(subscription *, event *) = nullptr;
            //
            // template <class object>
            // int (*eventable<object, pokemonism::descriptor, pokemonism::descriptor>::processor::read)(subscription *, event *) = nullptr;
            //
            // template <class object>
            // int (*eventable<object, pokemonism::descriptor, pokemonism::descriptor>::processor::write)(subscription *, event *) = nullptr;
            //
            // template <class object>
            // int (*eventable<object, pokemonism::descriptor, pokemonism::descriptor>::processor::close)(subscription *, event *) = nullptr;

        }
    }
}

#endif // __POKEMONISM_LATIOS_PACKAGE_EVENTABLE_DESCRIPTOR__HH__
