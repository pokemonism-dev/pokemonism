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
                        public:     constexpr static uint32 gen     = external::event<object>::gen;
                        public:     constexpr static uint32 rel     = external::event<object>::rel;
                        public:     constexpr static uint32 add     = external::event<object>::add;
                        public:     constexpr static uint32 del     = external::event<object>::del;
                        public:     constexpr static uint32 open    = external::event<object>::max;
                        public:     constexpr static uint32 read    = external::event<object>::max + 1;
                        public:     constexpr static uint32 write   = external::event<object>::max + 2;
                        public:     constexpr static uint32 close   = external::event<object>::max + 3;
                        public:     constexpr static uint32 max     = external::event<object>::max + 4;
                        public:     event(const uint32 tag, eventable<object, pokemonism::descriptor, generatable>::node * node) : eventable<object, pokemonism::descriptor, generatable>::event(tag, node) {}
                        public:     event(void) = delete;
                        public:     ~event(void) override {}
                        public:     event(const event & o) = delete;
                        public:     event(event && o) noexcept = delete;
                        public:     event & operator=(const event & o) = delete;
                        public:     event & operator=(event && o) noexcept = delete;
                        };
            public:     class subscription : public eventable<object, pokemonism::descriptor, generatable>::subscription {
            // public:     const object * objectGet(void) const override { return this->target; }
            };
            public:     class node : public eventable<object, pokemonism::descriptor, generatable>::node {

            };
            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_PACKAGE_PACK_DESCRIPTOR__HH__
