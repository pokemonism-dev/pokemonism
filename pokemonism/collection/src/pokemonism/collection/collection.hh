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

    template <class element, class Super = collectable<element, container>>
    class collection : public Super {
    public:     inline collection(void);
    public:     inline ~collection(void) override;
    public:     inline collection(const collection<element, Super> & o);
    public:     inline collection(collection<element, Super> && o) noexcept;
    public:     inline collection<element, Super> & operator=(const collection<element, Super> & o);
    public:     inline collection<element, Super> & operator=(collection<element, Super> && o) noexcept;
    };

    template<class element, class Super>
    inline collection<element, Super>::collection(void) {

    }

    template<class element, class Super>
    inline collection<element, Super>::~collection(void) {

    }

    template<class element, class Super>
    inline collection<element, Super>::collection(const collection<element, Super> & o) : Super(o) {

    }

    template<class element, class Super>
    inline collection<element, Super>::collection(collection<element, Super> && o) noexcept : Super(std::move(o)) {

    }

    template<class element, class Super>
    inline collection<element, Super> & collection<element, Super>::operator=(const collection<element, Super> & o) {
        if (pointof(o) != this) Super::operator=(o);
        return *this;
    }

    template<class element, class Super>
    inline collection<element, Super> & collection<element, Super>::operator=(collection<element, Super> && o) noexcept {
        if (pointof(o) != this) Super::operator=(std::move(o));
        return *this;
    }

}

#endif // __POKEMONISM_COLLECTION_COLLECTION_HH__