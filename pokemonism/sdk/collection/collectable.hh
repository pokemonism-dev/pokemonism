/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_COLLECTION_COLLECTABLE_HH__
#define   __POKEMONISM_SDK_COLLECTION_COLLECTABLE_HH__

#include <pokemonism/sdk/collection/interface.hh>

namespace pokemonism::sdk::collection {

    template <typename elementable>
    class collectable : public collection::interface {
    public:     typedef elementable     element;
    public:     typedef elementable &   reference;
    public:     virtual element * add(const element & item) = 0;
    public:     virtual element * add(element && item) = 0;
    public:     virtual element & del(element & item) = 0;
    public:     collectable(void) {}
    public:     ~collectable(void) override {}
    public:     collectable(const collection::collectable<elementable> & o) = delete;
    public:     collectable(collection::collectable<elementable> && o) noexcept = delete;
    public:     collection::collectable<elementable> & operator=(const collection::collectable<elementable> & o) = delete;
    public:     collection::collectable<elementable> & operator=(collection::collectable<elementable> && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_COLLECTION_COLLECTABLE_HH__