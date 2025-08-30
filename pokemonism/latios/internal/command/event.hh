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
                public:     event(const uint32 tag, package::eventable<pokemonism::command, pokemonism::command, pokemonism::command>::node * node) :
                            internal::event<pokemonism::command, pokemonism::command, pokemonism::command>(tag, node) {}
                public:     event(void) = delete;
                public:     ~event(void) override {}
                public:     event(const event & o) = delete;
                public:     event(event && o) noexcept = delete;
                public:     event & operator=(const event & o) = delete;
                public:     event & operator=(event && o) noexcept = delete;
                };
            }

        }
    }
}

#endif // __POKEMONISM_LATIOS_INTERNAL_COMMAND_EVENT__HH__
