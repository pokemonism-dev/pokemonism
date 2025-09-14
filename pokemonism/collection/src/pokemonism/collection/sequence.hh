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

    template <class element, class super = sequenceable<element, collection<element>>>
    class sequence : public super {
    public:     inline sequence(void);
    public:     inline ~sequence(void) override;
    public:     inline sequence(const sequence<element, super> & o);
    public:     inline sequence(sequence<element, super> && o) noexcept;
    public:     inline sequence<element, super> & operator=(const sequence<element, super> & o);
    public:     inline sequence<element, super> & operator=(sequence<element, super> && o) noexcept;
    };

    template <class element, class super>
    inline sequence<element, super>::sequence(void) {

    }

    template <class element, class super>
    inline sequence<element, super>::~sequence(void) {

    }

    template <class element, class super>
    inline sequence<element, super>::sequence(const sequence<element, super> & o) : super(o) {

    }

    template <class element, class super>
    inline sequence<element, super>::sequence(sequence<element, super> && o) noexcept : super(std::move(o)) {

    }

    template <class element, class super>
    inline sequence<element, super> & sequence<element, super>::operator=(const sequence<element, super> & o) {
        if (pointof(o) != this) super::operator=(o);
        return *this;
    }

    template <class element, class super>
    inline sequence<element, super> & sequence<element, super>::operator=(sequence<element, super> && o) noexcept {
        if (pointof(o) != this) super::operator=(std::move(o));
        return *this;
    }

}

#endif // __POKEMONISM_COLLECTION_SEQUENCE_HH__