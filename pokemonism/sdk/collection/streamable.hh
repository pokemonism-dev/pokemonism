/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_CONTAINER_STREAMABLE_HH__
#define   __POKEMONISM_SDK_CONTAINER_STREAMABLE_HH__

#include <pokemonism/sdk/collection/continuable.hh>

namespace pokemonism::sdk::collection {

    template <typename elementable>
    class streamable : public continuable<elementable> {

    };

}

#endif // __POKEMONISM_SDK_CONTAINER_STREAMABLE_HH__