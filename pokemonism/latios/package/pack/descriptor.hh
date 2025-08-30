/**
 * @file        pokemonism/latios/package/pack/descriptor.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_PACKAGE_PACK_DESCRIPTOR__HH__
#define   __POKEMONISM_LATIOS_PACKAGE_PACK_DESCRIPTOR__HH__

#include <pokemonism/latios/package/pack.hh>

namespace pokemonism {
    namespace latios {
        namespace package {

            template <class object, class generatable>
            class pack<object, pokemonism::descriptor, generatable> {
            public:     class node;
            public:     class event;
            public:     class subscription;
            public:     typedef eventable<object, pokemonism::descriptor, generatable>::generator   generator;
            public:     class event : public eventable<object, pokemonism::descriptor, generatable>::event {
                        public:     typedef typename eventable<object, pokemonism::descriptor, pokemonism::descriptor>::event::type     type;
                        public:     event(const uint32 tag, eventable<object, pokemonism::descriptor, generatable>::node * node) : eventable<object, pokemonism::descriptor, generatable>::event(tag, node) {}
                        public:     event(void) = delete;
                        public:     ~event(void) override {}
                        public:     event(const event & o) = delete;
                        public:     event(event && o) noexcept = delete;
                        public:     event & operator=(const event & o) = delete;
                        public:     event & operator=(event && o) noexcept = delete;
                        };
            public:     class subscription : public eventable<object, pokemonism::descriptor, generatable>::subscription {
                        public:     typedef int (*callback)(subscription *, uint32, event *, primitivable::object *, pokemonism::exception *, int);
                        public:     subscription(object * target, uint32 properties, const callback * callbacks, uint32 n)
                                    : eventable<object, pokemonism::descriptor, generatable>::subscription(target, properties, static_cast<typename eventable<object, pokemonism::descriptor, generatable>::subscription::callback>(callbacks), n) {

                                    }
                        };
            public:     class node : public eventable<object, pokemonism::descriptor, generatable>::node {
                        };
            };



        }
    }
}

#endif // __POKEMONISM_LATIOS_PACKAGE_PACK_DESCRIPTOR__HH__
