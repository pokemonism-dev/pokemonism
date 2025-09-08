/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_COLLECTION_SEQUENCEABLE_HH__
#define   __POKEMONISM_SDK_COLLECTION_SEQUENCEABLE_HH__

#include <pokemonism/sdk/collection/collectable.hh>

namespace pokemonism::sdk::collection {

    template <typename elementable>
    class sequenceable : public collection::collectable<elementable> {
    public:     virtual const elementable & at(unsigned long index) const = 0;
    public:     virtual elementable & at(unsigned long index) = 0;
    public:     virtual const elementable & operator[](unsigned long index) const = 0;
    public:     virtual elementable & operator[](unsigned long index) = 0;
    protected:  sequenceable(void) {}
    protected:  ~sequenceable(void) override {}
    public:     sequenceable(const collection::sequenceable<elementable> & o) = delete;
    public:     sequenceable(collection::sequenceable<elementable> && o) noexcept = delete;
    public:     collection::sequenceable<elementable> & operator=(const collection::sequenceable<elementable> & o) = delete;
    public:     collection::sequenceable<elementable> & operator=(collection::sequenceable<elementable> && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_COLLECTION_SEQUENCEABLE_HH__