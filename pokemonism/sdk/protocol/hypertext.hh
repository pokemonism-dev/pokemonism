/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_PROTOCOL_HYPERTEXT_HH__
#define   __POKEMONISM_SDK_PROTOCOL_HYPERTEXT_HH__

#include <pokemonism/sdk/protocol.hh>

namespace pokemonism::sdk {

    struct protocol::hypertext {
    public:     class transfer;
    };

}

#include <pokemonism/sdk/protocol/hypertext/transfer.hh>

#endif // __POKEMONISM_SDK_PROTOCOL_HYPERTEXT_HH__