/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_TRANSMISSION_HH__
#define   __POKEMONISM_TRANSMISSION_HH__

#include <pokemonism/sdk/protocol.hh>

namespace pokemonism::sdk {

    struct protocol::transmission {
    public:     class control;
    };

}


#include <pokemonism/sdk/protocol/transmission/control.hh>

#endif // __POKEMONISM_TRANSMISSION_HH__