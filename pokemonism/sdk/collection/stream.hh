/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_CONTAINER_STREAM_HH__
#define   __POKEMONISM_SDK_CONTAINER_STREAM_HH__

#include <pokemonism/sdk/collection/streamable.hh>
#include <pokemonism/sdk/collection/continuous.hh>

namespace pokemonism::sdk::collection {

    template <typename element, class interfaceable = collection::streamable<element>>
    class stream : public collection::continuous<element, interfaceable> {
    protected:  unsigned long position;
    };

}

#endif // __POKEMONISM_SDK_CONTAINER_STREAM_HH__