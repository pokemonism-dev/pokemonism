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

#include <pokemonism/latios/general/node.hh>

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
                        public:     typedef int (*callback)(subscription *, uint32, event *, primitivable::object *, pokemonism::exception *, int);
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
                        public:     virtual int eventOn(eventable<object, objectable, generatable>::node * node) = 0;
                        public:     virtual eventable<object, objectable, generatable>::node * add(eventable<object, objectable, generatable>::node * node) = 0;
                        public:     virtual eventable<object, objectable, generatable>::node * del(eventable<object, objectable, generatable>::node * node) = 0;
                        public:     virtual void clear(void) = 0;
                        private:    inline callback callbackGet(uint32 type) const { return type < event::type::max ? callbacks[type] : nullptr; }
                        public:     subscription(object * target, uint32 properties, const callback * callbacks, uint32 n)
                                    : size(0), head(nullptr), tail(nullptr), container(nullptr), prev(nullptr), next(nullptr),
                                    target(target), properties(properties), status(none), callbacks() {
                                        if (event::type::max < n) throw pokemonism::exception();
                                        if (n > 0) memset(this->callbacks, callbacks, n * sizeof(callback));
                                    }
                        };
            public:     class node : public general::node {
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
