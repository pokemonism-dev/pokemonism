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
    public:     inline Collection(void);
    public:     inline ~Collection(void) override;
    public:     inline Collection(const Collection<Element, Super> & o);
    public:     inline Collection(Collection<Element, Super> && o) noexcept;
    public:     inline Collection<Element, Super> & operator=(const Collection<Element, Super> & o);
    public:     inline Collection<Element, Super> & operator=(Collection<Element, Super> && o) noexcept;
    };

    template<class Element, class Super>
    inline Collection<Element, Super>::Collection(void) {

    }

    template<class Element, class Super>
    inline Collection<Element, Super>::~Collection(void) {

    }

    template<class Element, class Super>
    inline Collection<Element, Super>::Collection(const Collection<Element, Super> & o) : Super(o) {

    }

    template<class Element, class Super>
    inline Collection<Element, Super>::Collection(Collection<Element, Super> && o) noexcept : Super(std::move(o)) {

    }

    template<class Element, class Super>
    inline Collection<Element, Super> & Collection<Element, Super>::operator=(const Collection<Element, Super> & o) {
        if (pointof(o) != this) Super::operator=(o);
        return *this;
    }

    template<class Element, class Super>
    inline Collection<Element, Super> & Collection<Element, Super>::operator=(Collection<Element, Super> && o) noexcept {
        if (pointof(o) != this) Super::operator=(std::move(o));
        return *this;
    }

}

#endif // __POKEMONISM_COLLECTION_COLLECTION_HH__