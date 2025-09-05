/**
 * @file        pokemonism/latios/package/messageable/command.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 30, 2025
 */

#ifndef   __POKEMONISM_LATIOS_PACKAGE_MESSAGEABLE_COMMAND__HH__
#define   __POKEMONISM_LATIOS_PACKAGE_MESSAGEABLE_COMMAND__HH__

#include <pokemonism/pokemon/general/command.hh>

namespace pokemonism {
    namespace latios {
        namespace package {
            namespace messageable {

                template <class output, class message>
                class command : public pokemon::general::command<> {

                };
            }
        }
    }
}

#endif // __POKEMONISM_LATIOS_PACKAGE_MESSAGEABLE_COMMAND__HH__