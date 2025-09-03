/**
 * @file            pokemonism/petilil/command.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_PETILIL_COMMAND_HH__
#define   __POKEMONISM_PETILIL_COMMAND_HH__

#include <pokemonism/event.hh>

namespace pokemonism {
    namespace petilil {
        namespace command {

            class event : public pokemonism::event {
            public:     struct modifiable;
            public:     struct callback;
            };

            struct event::modifiable {
            public:

            };

            struct event::callback : public  {

            };

        }
    }
}

#endif // __POKEMONISM_PETILIL_COMMAND_HH__