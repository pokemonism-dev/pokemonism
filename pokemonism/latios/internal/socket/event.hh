/**
 * @file        pokemonism/latios/internal/socket/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_SOCKET_EVENT__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_SOCKET_EVENT__HH__

#include <pokemonism/latios/socket.hh>
#include <pokemonism/latios/internal/event.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {
            namespace socket {

                class event : public internal::event<pokemonism::socket, pokemonism::descriptor> {
                public:     event(void) = delete;
                public:     event(const uint32 tag, package::eventable<pokemonism::socket, pokemonism::descriptor>::node * node) :
                            internal::event<pokemonism::socket, pokemonism::descriptor>(tag, node) {}
                };
            }

        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_SOCKET_EVENT__HH__
