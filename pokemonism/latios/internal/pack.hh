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
            public:     class event : protected package::pack<object, objectable, generatable>::event {
                        public:     typedef typename package::pack<object, objectable, generatable>::event::type    type;
                        protected:  int on(void) override;
                        public:     event(uint32 tag, package::eventable<object, objectable, generatable>::node * node);
                        public:     event(void) = delete;
                        public:     ~event(void) override;
                        public:     event(const pack<object, objectable, generatable>::event & o) = delete;
                        public:     event(pack<object, objectable, generatable>::event && o) noexcept = delete;
                        public:     pack<object, objectable, generatable>::event & operator=(const pack<object, objectable, generatable>::event & o) = delete;
                        public:     pack<object, objectable, generatable>::event & operator=(pack<object, objectable, generatable>::event && o) noexcept = delete;
                        };
            public:     class subscription : public package::pack<object, objectable, generatable>::subscription {
                        public:     typedef int (*callback)(subscription *, uint32, event *, primitivable::object *, pokemonism::exception *);
                        public:     const object * objectGet(void) const override { return this->target; }
                        public:     bool cancel(void) override { return false; }
                        public:     subscription(object * target, uint32 type, const callback * callbacks, uint32 n) :
                                    package::pack<object, objectable, generatable>::subscription(target, type, reinterpret_cast<const typename package::pack<object, objectable, generatable>::subscription::callback *>(callbacks), n) {

                                    }
                        public:     subscription(void) = delete;
                        };
            public:     class node : public package::pack<object, objectable, generatable>::node {
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
                        // ReSharper disable once CppVirtualFunctionCallInsideCtor
                        if (this->on() > declaration::success) {
                            this->exception = this->exception ? this->exception : new pokemonism::exception();
                            general::subscription::eventOn(this->node->container, this->tag, this, nullptr, this->exception);
                        }
                        this->node->event = nullptr;
                        this->node = allocator::del(this->node);
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

                try {
                    return package::processor::on(this->node->container, this->tag, pointof(result), this);
                } catch (const pokemonism::exception & e) {
                    this->exception = allocator::del(this->exception);
                    general::subscription::eventOn(this->node->container, this->tag, this, result, this->exception = e.clone());
                } catch (...) {
                    this->exception = allocator::del(this->exception);
                    general::subscription::eventOn(this->node->container, this->tag, this, result, this->exception = new pokemonism::exception());
                }
                return declaration::fail;
            }

        }
    }
}

#include <pokemonism/latios/package/pack/command.hh>
#include <pokemonism/latios/package/pack/descriptor.hh>

#endif // __POKEMONISM_LATIOS_INTERNAL_PACK__HH__
