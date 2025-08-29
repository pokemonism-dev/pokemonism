/**
* @file        pokemonism/latios/internal/descriptor/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_DESCRIPTOR_EVENT__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_DESCRIPTOR_EVENT__HH__

#include <pokemonism/latios/descriptor.hh>
#include <pokemonism/latios/internal/event.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {
            namespace descriptor {

                class event : public internal::event<pokemonism::descriptor, pokemonism::descriptor, pokemonism::descriptor> {
                public:     event(void) = delete;
                public:     event(const uint32 tag, package::eventable<pokemonism::descriptor, pokemonism::descriptor, pokemonism::descriptor>::node * node) :
                            internal::event<pokemonism::descriptor, pokemonism::descriptor, pokemonism::descriptor>(tag, node) {}
                };
            }

        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_DESCRIPTOR_EVENT__HH__
