/**
 * @file        pokemonism/latios/internal/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_EVENT__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_EVENT__HH__

#include <pokemonism/latios/command.hh>
#include <pokemonism/latios/package/event.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {

            template <class object, class objectable, class generatable = void>
            class event : public package::event<object, objectable, generatable> {
            public:     int on(void) override;
            public:     event(uint32 tag, package::eventable<object, objectable, generatable>::node * node);
            public:     event(void) = delete;
            public:     ~event(void) override;
            public:     event(const event<object, objectable, generatable> & o) = delete;
            public:     event(event<object, objectable, generatable> && o) noexcept = delete;
            public:     event<object, objectable, generatable> & operator=(const event<object, objectable, generatable> & o) = delete;
            public:     event<object, objectable, generatable> & operator=(event<object, objectable, generatable> && o) noexcept = delete;
            };

            template <class object, class objectable, class generatable>
            event<object, objectable, generatable>::event(uint32 tag, typename package::eventable<object, objectable, generatable>::node * node) :
            package::event<object, objectable, generatable>(tag, node) {
                if (node == nullptr) throw pokemonism::exception();

                node->event = nullptr;
            }

            template <class object, class objectable, class generatable>
            event<object, objectable, generatable>::~event(void) {
                if (this->container != nullptr) {
                    this->container->del(this);

                    // TODO: REMOVE CANCEL FUNC WHEN PROCESSOR IMPLEMENTED
                    if (this->node != nullptr) this->node->cancel();

                    this->node->event = nullptr;
                    this->node = allocator::del(this->node);
                } else if (this->node != nullptr) {
                    this->node->event = nullptr;
                    this->node = allocator::del(this->node);
                }
            }

            template <class object, class objectable, class generatable>
            int event<object, objectable, generatable>::on(void) {
                if (this->container != nullptr || this->node == nullptr) throw pokemonism::exception();

                // TODO: REMOVE CANCEL FUNC WHEN PROCESSOR IMPLEMENTED
                return this->node->on();
            }

        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_EVENT__HH__
