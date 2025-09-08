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
    public:     virtual unsigned long positionGet(void) const = 0;
    protected:  streamable(void) {}
    protected:  ~streamable(void) override {}
    public:     streamable(const collection::streamable<elementable> & o) = delete;
    public:     streamable(collection::streamable<elementable> && o) noexcept = delete;
    public:     collection::streamable<elementable> & operator=(const collection::streamable<elementable> & o) = delete;
    public:     collection::streamable<elementable> & operator=(collection::streamable<elementable> && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_CONTAINER_STREAMABLE_HH__