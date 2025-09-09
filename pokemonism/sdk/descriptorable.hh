/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 09, 2025
 */

#ifndef   __POKEMONISM_SDK_DESCRIPTORABLE_HH__
#define   __POKEMONISM_SDK_DESCRIPTORABLE_HH__

#include <pokemonism.hh>

namespace pokemonism::sdk {

    struct descriptorable {
    public:     class unix;
    public:     using def = descriptorable::unix;
    };

}

#include <pokemonism/sdk/descriptorable/unix.hh>

#endif // __POKEMONISM_SDK_DESCRIPTORABLE_HH__