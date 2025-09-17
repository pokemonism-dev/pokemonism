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

    template <class element, class super = collectable<element, container>>
    class collection : public super {
    public:     inline collection(void);
    public:     inline ~collection(void) override;
    public:     inline collection(const collection<element, super> & o);
    public:     inline collection(collection<element, super> && o) noexcept;
    public:     inline collection<element, super> & operator=(const collection<element, super> & o);
    public:     inline collection<element, super> & operator=(collection<element, super> && o) noexcept;
    };

    template<class element, class super>
    inline collection<element, super>::collection(void) {

    }

    template<class element, class super>
    inline collection<element, super>::~collection(void) {

    }

    template<class element, class super>
    inline collection<element, super>::collection(const collection<element, super> & o) : super(o) {

    }

    template<class element, class super>
    inline collection<element, super>::collection(collection<element, super> && o) noexcept : super(std::move(o)) {

    }

    template<class element, class super>
    inline collection<element, super> & collection<element, super>::operator=(const collection<element, super> & o) {
        if (pointof(o) != this) super::operator=(o);
        return *this;
    }

    template<class element, class super>
    inline collection<element, super> & collection<element, super>::operator=(collection<element, super> && o) noexcept {
        if (pointof(o) != this) super::operator=(std::move(o));
        return *this;
    }

}

#endif // __POKEMONISM_COLLECTION_COLLECTION_HH__