/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 09, 2025
 */

#ifndef   __POKEMONISM_SDK_SOCKETABLE_HH__
#define   __POKEMONISM_SDK_SOCKETABLE_HH__

#include <pokemonism/sdk/interface/socket.hh>

namespace pokemonism::sdk {

    struct socketable {
    public:     class unix;
    public:     using def = socketable::unix;
    };

}

#include <pokemonism/sdk/socketable/unix.hh>

#endif // __POKEMONISM_SDK_SOCKETABLE_HH__