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
    public:     Sequence(const Sequence<Element, Super> & o) = delete;
    public:     Sequence(Sequence<Element, Super> && o) noexcept = delete;
    public:     Sequence<Element, Super> & operator=(const Sequence<Element, Super> & o) = delete;
    public:     Sequence<Element, Super> & operator=(Sequence<Element, Super> && o) noexcept = delete;
    };

    template <class Element, class Super>
    inline Sequence<Element, Super>::Sequence(void) {

    }

    template <class Element, class Super>
    inline Sequence<Element, Super>::~Sequence(void) {

    }

}

#endif // __POKEMONISM_COLLECTION_SEQUENCE_HH__