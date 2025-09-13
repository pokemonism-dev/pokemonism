/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_COLLECTION_SEQUENCE_HH__
#define   __POKEMONISM_COLLECTION_SEQUENCE_HH__

#include <pokemonism/collection/collection.hh>
#include <pokemonism/sequenceable.hh>

namespace pokemonism::collection {

    template <class Element, class Super = Sequenceable<Element, Collection<Element>>>
    class Sequence : public Super {
    public:     inline Sequence(void);
    public:     inline ~Sequence(void) override;
    public:     inline Sequence(const Sequence<Element, Super> & o);
    public:     inline Sequence(Sequence<Element, Super> && o) noexcept;
    public:     inline Sequence<Element, Super> & operator=(const Sequence<Element, Super> & o);
    public:     inline Sequence<Element, Super> & operator=(Sequence<Element, Super> && o) noexcept;
    };

    template <class Element, class Super>
    inline Sequence<Element, Super>::Sequence(void) {

    }

    template <class Element, class Super>
    inline Sequence<Element, Super>::~Sequence(void) {

    }

    template <class Element, class Super>
    inline Sequence<Element, Super>::Sequence(const Sequence<Element, Super> & o) : Super(o) {

    }

    template <class Element, class Super>
    inline Sequence<Element, Super>::Sequence(Sequence<Element, Super> && o) noexcept : Super(std::move(o)) {

    }

    template <class Element, class Super>
    inline Sequence<Element, Super> & Sequence<Element, Super>::operator=(const Sequence<Element, Super> & o) {
        if (pointof(o) != this) Super::operator=(o);
        return *this;
    }

    template <class Element, class Super>
    inline Sequence<Element, Super> & Sequence<Element, Super>::operator=(Sequence<Element, Super> && o) noexcept {
        if (pointof(o) != this) Super::operator=(std::move(o));
        return *this;
    }

}

#endif // __POKEMONISM_COLLECTION_SEQUENCE_HH__