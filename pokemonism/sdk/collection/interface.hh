/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 8, 2025
 */

#ifndef   __POKEMONISM_SDK_COLLECTION_INTERFACE_HH__
#define   __POKEMONISM_SDK_COLLECTION_INTERFACE_HH__

#include <pokemonism/sdk/synchronizable.hh>

namespace pokemonism::sdk::collection {

    class interface : public synchronizable {
    public:     interface(void) {}
    public:     ~interface(void) override {}
    public:     interface(const collection::interface & o) = delete;
    public:     interface(collection::interface && o) noexcept = delete;
    public:     collection::interface & operator=(const collection::interface & o) = delete;
    public:     collection::interface & operator=(collection::interface && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_COLLECTION_INTERFACE_HH__
