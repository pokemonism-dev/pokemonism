/**
 * @file        pokemonism/latios/internal/eventable.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_EVENTABLE__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_EVENTABLE__HH__

// #include <pokemonism/latios/general/event.hh>
// #include <pokemonism/latios/general/queue.hh>
// #include <pokemonism/latios/general/generator.hh>
// #include <pokemonism/latios/general/subscription.hh>
//
// #include <pokemonism/latios/external/event.hh>
// #include <pokemonism/latios/external/subscription.hh>
// #include <pokemonism/latios/internal/observable.hh>

// #include <pokemonism/psyduck/linked/list.hh>

#include <pokemonism/latios/command.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {

            template <class object, class objectable, class tag = pokemonism::command>
            class generatable {

            };


            //
            //
            // template <class object, class node>
            // class generatable : public general::generator {
            // public:     typedef node        subscription;
            // public:     uint64 size;
            // public:     node * head;
            // public:     node * tail;
            // public:     explicit generatable(general::engine * engine) : general::generator(engine), size(0), head(nullptr), tail(nullptr) {}
            // };
            //
            // template <class object, class objectable, class generatable = pokemonism::command>
            // class eventable {
            // public:     class node;
            // public:     class event;
            // public:     class subscription;
            // public:     typedef internal::generatable<object, eventable<object, objectable, generatable>::subscription> generator;
            // public:     class event : public virtual external::event<object>, public general::event {
            //             public:     int on(void) override = 0;
            //             public:     eventable<object, objectable, generatable>::node * node;
            //             public:     event(const uint32 tag, eventable<object, objectable, generatable>::node * node) : general::event(tag), node(node) {
            //                             node->event = this;
            //                         }
            //             public:     event(void) = delete;
            //             public:     ~event(void) override {}
            //             public:     event(const event & o) = delete;
            //             public:     event(event && o) noexcept = delete;
            //             public:     event & operator=(const event & o) = delete;
            //             public:     event & operator=(event && o) noexcept = delete;
            //             };
            // public:     class subscription : public internal::observable<objectable>, public external::subscription<objectable>, public general::subscription {
            //             public:     uint32  size;
            //             public:     eventable<object, objectable, generatable>::node * head;
            //             public:     eventable<object, objectable, generatable>::node * tail;
            //             public:     generator * container;
            //             public:     generator::subscription * prev;
            //             public:     generator::subscription * next;
            //             };
            // public:     class node {
            //             public:     eventable<object, objectable, generatable>::event * event;
            //             };
            //
            //
            // //
            // // public:     class subscription {
            // //             public:     class node {
            // //                         public:     subscription * container;
            // //                         public:     node * prev;
            // //                         public:     node * next;
            // //                         public:     eventable * event;
            // //                         public:     node(subscription * container) : container(nullptr), prev(nullptr), next(nullptr), event(nullptr) {}
            // //                         public:     node(void) = delete;
            // //                         public:     virtual ~node(void) {}
            // //                         public:     node(const node & o) = delete;
            // //                         public:     node(node && o) noexcept = delete;
            // //                         public:     node & operator=(const node & o) = delete;
            // //                         public:     node & operator=(node && o) noexcept = delete;
            // //                         };
            // //             };
            // // public:     int on(void) override = 0;
            // // public:     subscription::node * node;
            // // public:     eventable(const uint32 tag, subscription::node * node) : general::event(tag), node(node) {}
            // // public:     eventable(void) = delete;
            // // public:     ~eventable(void) override {}
            // // public:     eventable(const eventable<object, objectable, generatable> & o) = delete;
            // // public:     eventable(eventable<object, objectable, generatable> && o) noexcept = delete;
            // // public:     eventable<object, objectable, generatable> & operator=(const eventable<object, objectable, generatable> & o) = delete;
            // // public:     eventable<object, objectable, generatable> & operator=(eventable<object, objectable, generatable> && o) noexcept = delete;
            // };
            //
            // // // subscription::node ... node, subscription
            // // template <class objectable, class nodeable>
            // // class event : public virtual external::event<objectable>, public general::event {
            // // public:     nodeable * node;
            // // public:     int on(void) override {
            // //
            // //             }
            // // public:     event(uint32 tag, nodeable * node) : general::event(tag), node(node) {}
            // // public:     event(void) = delete;
            // // public:     ~event(void) override {
            // //
            // //             }
            // // public:     event(const event<objectable, nodeable> & o) = delete;
            // // public:     event(event<objectable, nodeable> && o) noexcept = delete;
            // // public:     event<objectable, nodeable> & operator=(const event<objectable, nodeable> & o) = delete;
            // // public:     event<objectable, nodeable> & operator=(event<objectable, nodeable> && o) noexcept = delete;
            // // };
            //
            // // template <class objectable, class generatable>
            // // class event : public virtual external::event<objectable>, public general::event {
            // // public:     typedef objectable          target;
            // // public:     typedef generatable         generator;
            // // public:     using                       processor = general::processor;
            // // public:     class subscription;
            // // public:     typedef int                 (*callback)(external::subscription<objectable> &, uint32, const external::event<objectable> *, primitivable::object *, const pokemonism::exception *);
            // // public:     constexpr static uint32     gen = external::event<objectable>::gen;
            // // public:     constexpr static uint32     rel = external::event<objectable>::rel;
            // // public:     constexpr static uint32     add = external::event<objectable>::add;
            // // public:     constexpr static uint32     del = external::event<objectable>::del;
            // // public:     constexpr static uint32     max = external::event<objectable>::max;
            // // public:     class subscription : public internal::observable<objectable>, public external::subscription<objectable>, public general::subscription {
            // //             public:     class node {
            // //                         public:     event<objectable, generatable>::subscription *          container;
            // //                         public:     event<objectable, generatable>::subscription::node *    prev;
            // //                         public:     event<objectable, generatable>::subscription::node *    next;
            // //                         public:     event<objectable, generatable> *                        event;
            // //                         public:     explicit node(subscription * container);
            // //                         public:     virtual ~node(void);
            // //                         public:     node(const node & o) = delete;
            // //                         public:     node(node && o) noexcept = delete;
            // //                         public:     node & operator=(const node & o) = delete;
            // //                         public:     node & operator=(node && o) noexcept = delete;
            // //                         };
            // //             public:     static event<objectable, generatable> * eventGen(event<objectable, generatable>::subscription * subscription, uint32 type);
            // //             public:     using                               collector = pokemonism::linked::list<subscription, subscription::node>;
            // //             public:     generator *                         container;
            // //             public:     subscription *                      prev;
            // //             public:     subscription *                      next;
            // //             public:     uint64                              size;
            // //             public:     subscription::node *                head;
            // //             public:     subscription::node *                tail;
            // //             public:     target *                            object;
            // //             public:     uint32                              properties;
            // //             public:     uint32                              status;
            // //             public:     event<target, generator>::callback  callback[event<target, generator>::max];
            // //             public:     bool cancel(void) override;
            // //             public:     const target * objectGet(void) const override;
            // //             public:     virtual void add(subscription::node * node);
            // //             public:     virtual void del(subscription::node * node);
            // //             public:     virtual void clear(void);
            // //             public:     virtual int on(uint32 type, event<target, generator> * event, primitivable::object * result, pokemonism::exception * e);
            // //             public:     subscription(target * object, uint32 properties, const event<target, generator>::callback * callbacks, uint32 n);
            // //             public:     ~subscription(void) override;
            // //             public:     subscription(const subscription & o) = delete;
            // //             public:     subscription(subscription && o) noexcept = delete;
            // //             public:     subscription & operator=(const subscription & o) = delete;
            // //             public:     subscription & operator=(subscription && o) noexcept = delete;
            // //             public:     friend collector;
            // //             };
            // // public:     subscription::node * node;
            // // public:     int on(void) override;
            // // public:     event(uint32 tag, subscription::node * node);
            // // public:     event(void) = delete;
            // // public:     ~event(void) override;
            // // public:     event(const event<objectable, generatable> & o) = delete;
            // // public:     event(event<objectable, generatable> && o) noexcept = delete;
            // // public:     event<objectable, generatable> & operator=(const event<objectable, generatable> & o) = delete;
            // // public:     event<objectable, generatable> & operator=(event<objectable, generatable> && o) noexcept = delete;
            // // };
            // //
            // // template <class target, class generator>
            // // event<target, generator>::event(const uint32 tag, typename subscription::node * node) : general::event(tag), node(node) {
            // //     if (node == nullptr) throw pokemonism::exception();
            // //
            // //     node->event = this;
            // // }
            // //
            // // template <class target, class generator>
            // // event<target, generator>::~event(void) {
            // //     if (container != nullptr) {
            // //         container->del(this);
            // //
            // //         if (node != nullptr) {
            // //             event<target, generator>::subscription * subscription = node->container;
            // //             if (subscription != nullptr) {
            // //                 exception = allocator::del(exception);
            // //                 subscription->on(subscription->objectGet(), this, nullptr, exception = new pokemonism::exception());
            // //             }
            // //             node->event = nullptr;
            // //             node = allocator::del(node);
            // //         }
            // //     } else if (node != nullptr) {
            // //         node->event = nullptr;
            // //         node = allocator::del(node);
            // //     }
            // //
            // //     exception = allocator::del(exception);
            // //     tag = declaration::none;
            // // }
            // //
            // // template <class target, class generator>
            // // int event<target, generator>::on(void) {
            // //     if (container != nullptr || node == nullptr || node->container == nullptr) throw pokemonism::exception();
            // //
            // //     event<target, generator>::subscription * subscription = node->container;
            // //
            // //     try {
            // //         return processor::on(subscription, tag, this);
            // //     } catch (const pokemonism::exception & e) {
            // //         exception = allocator::del(exception);
            // //         subscription->on(subscription->object, this, nullptr, exception = e.clone());
            // //     } catch (...) {
            // //         exception = allocator::del(exception);
            // //         subscription->on(subscription->object, this, nullptr, exception = new pokemonism::exception());
            // //     }
            // //
            // //     return fail;
            // // }
            // //
            // // template <class target, class generator>
            // // event<target, generator> * event<target, generator>::subscription::eventGen(event<target, generator>::subscription * subscription, uint32 type) {
            // //     return new event<target, generator>(type, new event<target, generator>::subscription::node(subscription));
            // // }
            // //
            // // template <class target, class generator>
            // // event<target, generator>::subscription::subscription(target * object, const uint32 properties, const event<target, generator>::callback * callbacks, const uint32 n) :
            // // generator::node(), internal::observable<target>(), external::subscription<target>(), general::subscription(), size(0), head(nullptr), tail(nullptr),
            // // object(object), properties(properties), status(none), callback() {
            // //     if (n == 0 || event<target, generator>::max < n || object == nullptr) throw pokemonism::exception();
            // //
            // //     memcpy(callback, callbacks, n * sizeof(event<target, generator>::callback));
            // //
            // //     event<target, generator>::subscription::on(event<target, generator>::gen, nullptr, primitivable::object::gen(success), nullptr);
            // // }
            // //
            // // template <class target, class generator>
            // // event<target, generator>::subscription::~subscription(void) {
            // //     event<target, generator>::subscription::clear();
            // //
            // //     if (this->container != nullptr) this->container->del(this);
            // //
            // //     event<target, generator>::subscription::on(event<target, generator>::rel, nullptr, primitivable::object::gen(success), nullptr);
            // //
            // //     if (object != nullptr) {
            // //         object = (properties & event<target, generator>::subscription::property::release_object_on_rel) ? object = allocator::del(object) : nullptr;
            // //     }
            // //
            // //     properties = declaration::none;
            // //     status = declaration::none;
            // //
            // //     memset(callback, 0, sizeof(event<target, generator>::callback));
            // // }
            // //
            // // template <class target, class generator>
            // // bool event<target, generator>::subscription::cancel(void) {
            // //     if (this->container != nullptr) {
            // //         clear();
            // //
            // //         if (this->container != nullptr) this->container->del(this);
            // //
            // //         return true;
            // //     }
            // //
            // //     return false;
            // // }
            // //
            // // template <class target, class generator>
            // // const target * event<target, generator>::subscription::objectGet(void) const {
            // //     return object;
            // // }
            // //
            // //
            // // template <class target, class generator>
            // // void event<target, generator>::subscription::add(subscription::node * node) {
            // //     if (node == nullptr || node->container != nullptr) throw pokemonism::exception();
            // //
            // //     collector::add(this, node);
            // // }
            // //
            // // template <class target, class generator>
            // // void event<target, generator>::subscription::del(subscription::node * node) {
            // //     if (node == nullptr || node->container != this) throw pokemonism::exception();
            // //
            // //     collector::del(this, node);
            // // }
            // //
            // // template <class target, class generator>
            // // void event<target, generator>::subscription::clear(void) {
            // //     collector::clear(this);
            // // }
            // //
            // // template <class target, class generator>
            // // int event<target, generator>::subscription::on(uint32 type, event<target, generator> * event, primitivable::object * result, pokemonism::exception * e) {
            // //     if (object == nullptr || internal::event<target, generator>::max <= type) throw pokemonism::exception();
            // //
            // //     internal::event<target, generator>::callback func = callback[type];
            // //
            // //     if (func) return func(*object, type, event, result, e);
            // //
            // //     return declaration::success;
            // // }
            // //
            // // template <class target, class generator>
            // // event<target, generator>::subscription::node::node(subscription * container) : container(nullptr), prev(nullptr), next(nullptr), event(nullptr) {
            // //     collector::add(container, this);
            // // }
            // //
            // // template <class target, class generator>
            // // event<target, generator>::subscription::node::~node(void) {
            // //     if (event != nullptr) {
            // //         if (event->container != nullptr) {
            // //             event->container->del(event);
            // //             if (container != nullptr) {
            // //                 event->on();
            // //             }
            // //         }
            // //         event->node = nullptr;
            // //         event = allocator::del(event);
            // //     }
            // //     if (container != nullptr) container->del(this);
            // // }

        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_EVENTABLE__HH__
