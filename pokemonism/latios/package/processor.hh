/**
 * @file        pokemonism/latios/package/processor.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_PACKAGE_PROCESSOR__HH__
#define   __POKEMONISM_LATIOS_PACKAGE_PROCESSOR__HH__

#include <pokemonism/latios/general/processor.hh>

namespace pokemonism {
    namespace latios {
        namespace package {

            template <class subscription, class event>
            class processor : public general::processor {
            public:     static int on(subscription * o, uint32 type, event * e) { return declaration::fail; }
            };

        }
    }
}

#endif // __POKEMONISM_LATIOS_PACKAGE_PROCESSOR__HH__
