/**
* @file        pokemonism/latios/internal/process/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_PROCESS_EVENT__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_PROCESS_EVENT__HH__

#include <pokemonism/latios/process.hh>
#include <pokemonism/latios/internal/event.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {
            namespace process {

                class event : public internal::event<pokemonism::process> {
                public:     event(void) = delete;
                public:     event(const uint32 tag, package::eventable<pokemonism::process>::node * node) :
                            internal::event<pokemonism::process>(tag, node) {}
                };
            }

        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_PROCESS_EVENT__HH__
