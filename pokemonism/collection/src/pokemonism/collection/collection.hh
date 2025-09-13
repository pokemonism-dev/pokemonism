/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 13, 2025
 */

#ifndef   __POKEMONISM_COLLECTION_COLLECTION_HH__
#define   __POKEMONISM_COLLECTION_COLLECTION_HH__

#include <pokemonism/collectable.hh>
#include <pokemonism/collection/container.hh>

namespace pokemonism::collection {

    template <class Element, class Super = Collectable<Container>>
    class Collection : public Super {
    public:     Collection(void);
    public:     ~Collection(void) override;
    public:     Collection(const Collection<Element, Super> & o) = delete;
    public:     Collection(Collection<Element, Super> && o) noexcept = delete;
    public:     Collection<Element, Super> & operator=(const Collection<Element, Super> & o) = delete;
    public:     Collection<Element, Super> & operator=(Collection<Element, Super> && o) noexcept = delete;
    };

    template<class Element, class Super>
    Collection<Element, Super>::Collection(void) {

    }

    template<class Element, class Super>
    Collection<Element, Super>::~Collection(void) {

    }

}

#endif // __POKEMONISM_COLLECTION_COLLECTION_HH__