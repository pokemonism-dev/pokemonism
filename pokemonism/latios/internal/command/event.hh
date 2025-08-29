/**
 * @file        pokemonism/latios/internal/command/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_INTERNAL_COMMAND_EVENT__HH__
#define   __POKEMONISM_LATIOS_INTERNAL_COMMAND_EVENT__HH__

#include <pokemonism/latios/command.hh>
#include <pokemonism/latios/internal/event.hh>

namespace pokemonism {
    namespace latios {
        namespace internal {
            namespace command {

                class event : public internal::event<pokemonism::command, pokemonism::command, pokemonism::command> {
                public:     event(void) = delete;
                public:     event(const uint32 tag, package::eventable<pokemonism::command, pokemonism::command, pokemonism::command>::node * node) :
                            internal::event<pokemonism::command, pokemonism::command, pokemonism::command>(tag, node) {}
                };
            }





        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_COMMAND_EVENT__HH__
