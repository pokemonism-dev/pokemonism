/**
 * @file        pokemonism/latios/internal/pack.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_PACK__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_PACK__HH__

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/latios/general/queue.hh>
#include <pokemonism/latios/package/pack.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {

            template <class object, class objectable = pokemonism::command, class generatable = void>
            class pack {
            public:     class node;
            public:     class event;
            public:     class subscription;
            public:     typedef package::pack<object, objectable, generatable>::generator   generator;
            public:     class event : public package::pack<object, objectable, generatable>::event {
                        public:     typedef typename package::pack<object, objectable, generatable>::event::type    type;
                        protected:  int on(void) override;
                        public:     event(uint32 tag, package::eventable<object, objectable, generatable>::node * node);
                        public:     event(void) = delete;
                        public:     ~event(void) override;
                        public:     event(const pack<object, objectable, generatable>::event & o) = delete;
                        public:     event(pack<object, objectable, generatable>::event && o) noexcept = delete;
                        public:     pack<object, objectable, generatable>::event & operator=(const pack<object, objectable, generatable>::event & o) = delete;
                        public:     pack<object, objectable, generatable>::event & operator=(pack<object, objectable, generatable>::event && o) noexcept = delete;
                        public:     friend class subscription;
                        };
            public:     class subscription : public package::pack<object, objectable, generatable>::subscription {
                        public:     typedef int (*callback)(subscription *, uint32, event *, primitivable::object *, pokemonism::exception *, int);
                        public:     const object * objectGet(void) const override;
                        public:     bool cancel(void) override;
                        public:     int eventOn(package::eventable<object, objectable, generatable>::node * o) override;
                        public:     pack<object, objectable, generatable>::node * add(package::eventable<object, objectable, generatable>::node * node) override;
                        public:     pack<object, objectable, generatable>::node * del(package::eventable<object, objectable, generatable>::node * node) override;
                        public:     void clear(void) override;
                        public:     virtual int processOn(uint32 type, pack<object, objectable, generatable>::event * event, primitivable::object ** result, pokemonism::exception ** exception);
                        public:     virtual uint32 bootstrapOn(uint32 type, pack<object, objectable, generatable>::event ** event, primitivable::object ** result, pokemonism::exception ** exception, int * ret);
                        public:     virtual int completeOn(uint32 type, pack<object, objectable, generatable>::event * event, primitivable::object * result, pokemonism::exception * exception, int ret);
                        // public:     virtual int eventGen(pack<object, objectable, generatable>::node * node);
                        // public:     virtual int eventRel(pack<object, objectable, generatable>::node * node);
                        private:    inline subscription::callback callbackGet(uint32 type) const;

                        public:     subscription(object * target, uint32 type, const callback * callbacks, uint32 n) :
                                    package::pack<object, objectable, generatable>::subscription(target, type, reinterpret_cast<const typename package::pack<object, objectable, generatable>::subscription::callback *>(callbacks), n) {

                                    }
                        public:     subscription(void) = delete;
                        public:     friend class event;
                        };
            public:     class node : public package::pack<object, objectable, generatable>::node {
                        public:     int eventOn(void) override;
                        public:
                        };
            };


            template <class object, class objectable, class generatable>
            pack<object, objectable, generatable>::event::event(uint32 tag, typename package::eventable<object, objectable, generatable>::node * node) :
            package::pack<object, objectable, generatable>::event(tag, node) {
                if (node == nullptr || node->container == nullptr) throw pokemonism::exception();

                node->event = nullptr;
            }

            template <class object, class objectable, class generatable>
            pack<object, objectable, generatable>::event::~event(void) {
                if (this->container != nullptr) {
                    this->container->del(this);
                    if (this->node != nullptr) {
                        if (this->node->eventOn() > declaration::success) {

                        }
                        // this->node->cancel();
                        // throw pokemonism::exception();
                        // TODO: IMPLEMENT THIS
                        // ReSharper disable once CppVirtualFunctionCallInsideCtor
                        // if (this->on() > declaration::success) {
                        //     this->exception = this->exception ? this->exception : new pokemonism::exception();
                        //     general::subscription::eventOn(this->node->container, this->tag, this, nullptr, this->exception);
                        // }
                        // this->node->event = nullptr;
                        // this->node = allocator::del(this->node);
                    }
                } else if (this->node != nullptr) {
                    this->node->event = nullptr;
                    this->node = allocator::del(this->node);
                }
            }

            template <class object, class objectable, class generatable>
            int pack<object, objectable, generatable>::event::on(void) {
                if (this->container != nullptr || this->node == nullptr || this->node->container == nullptr) throw pokemonism::exception();

                primitivable::object * result = nullptr;

                // TODO: IMPLEMENT THIS


                // try {
                //     return package::processor::on(this->node->container, this->tag, pointof(result), this);
                // } catch (const pokemonism::exception & e) {
                //     ;
                //     general::subscription::eventOn<>(this->node->container, this->tag, this, result, this->exception = (allocator::del(this->exception), e.clone()));
                // } catch (...) {
                //     ;
                //     general::subscription::eventOn<>(this->node->container, this->tag, this, result, this->exception = (allocator::del(this->exception), new pokemonism::exception()));
                // }
                return declaration::fail;
            }

            template <class object, class objectable, class generatable>
            const object * pack<object, objectable, generatable>::subscription::objectGet(void) const {
                return this->target;
            }

            template <class object, class objectable, class generatable>
            bool pack<object, objectable, generatable>::subscription::cancel(void) {
                throw pokemonism::exception();
            }

            template <class object, class objectable, class generatable>
            pack<object, objectable, generatable>::subscription::callback pack<object, objectable, generatable>::subscription::callbackGet(uint32 type) const {
                return type < event::type::max ? reinterpret_cast<pack<object, objectable, generatable>::subscription::callback>(this->callbacks[type]) : nullptr;
            }

            template <class object, class objectable, class generatable>
            uint32 pack<object, objectable, generatable>::subscription::bootstrapOn(uint32 type, pack<object, objectable, generatable>::event ** event, primitivable::object ** result, pokemonism::exception ** exception, int * ret) {
                return type;
            }

            template <class object, class objectable, class generatable>
            int pack<object, objectable, generatable>::subscription::processOn(uint32 type, pack<object, objectable, generatable>::event * event, primitivable::object ** result, pokemonism::exception ** exception) {
                throw pokemonism::exception();
            }

            template <class object, class objectable, class generatable>
            int pack<object, objectable, generatable>::subscription::eventOn(package::eventable<object, objectable, generatable>::node * o) {
                if (o->container != this || o->event == nullptr) throw pokemonism::exception();

                pack<object, objectable, generatable>::node * node = del(o);
                pack<object, objectable, generatable>::event * event = dynamic_cast<pack<object, objectable, generatable>::event *>(o->event);
                primitivable::object * result = nullptr;
                pokemonism::exception * exception = nullptr;

                int ret = processOn(event->typeGet(), event, pointof(result), pointof(exception));

                if (uint32 type = bootstrapOn(event->typeGet(), pointof(event), pointof(result), pointof(exception), pointof(ret)); type < pack<object, objectable, generatable>::event::type::max) {
                    callback func = callbackGet(type);

                    int ret = func != nullptr ? func(this, type, event, result, exception, ret) : declaration::success;

                    return completeOn(type, event, result, exception, ret);
                }

                return declaration::success;
            }

            template <class object, class objectable, class generatable>
            int pack<object, objectable, generatable>::subscription::completeOn(uint32 type, pack<object, objectable, generatable>::event * event, primitivable::object * result, pokemonism::exception * exception, int ret) {
                return  ret;
            }

            template <class object, class objectable, class generatable>
            pack<object, objectable, generatable>::node * pack<object, objectable, generatable>::subscription::add(package::eventable<object, objectable, generatable>::node * node) {
                throw pokemonism::exception();
            }

            template <class object, class objectable, class generatable>
            pack<object, objectable, generatable>::node * pack<object, objectable, generatable>::subscription::del(package::eventable<object, objectable, generatable>::node * node) {
                throw pokemonism::exception();
            }

            template <class object, class objectable, class generatable>
            void pack<object, objectable, generatable>::subscription::clear(void) {
                throw pokemonism::exception();
            }

            template <class object, class objectable, class generatable>
            int pack<object, objectable, generatable>::node::eventOn(void) {
                if (this->container == nullptr) throw pokemonism::exception();

                return this->container->eventOn(this);
            }

        }
    }
}

#include <pokemonism/latios/package/pack/command.hh>
#include <pokemonism/latios/package/pack/descriptor.hh>

#endif // __POKEMONISM_LATIOS_INTERNAL_PACK__HH__
