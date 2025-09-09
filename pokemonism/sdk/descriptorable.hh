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

#include <pokemonism/sdk/interface/descriptor.hh>

namespace pokemonism::sdk {

    struct descriptorable {
    public:     template <class descriptor = interface::descriptor> class unix;
    public:     using def = descriptorable::unix<interface::descriptor>;
    };

}

#include <pokemonism/sdk/descriptorable/unix.hh>

#endif // __POKEMONISM_SDK_DESCRIPTORABLE_HH__