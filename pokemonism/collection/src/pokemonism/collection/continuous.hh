/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_COLLECTION_CONTINUOUS_HH__
#define   __POKEMONISM_COLLECTION_CONTINUOUS_HH__

#include <pokemonism/sdk/exception.hh>

#include <pokemonism/continuable.hh>
#include <pokemonism/collection/sequence.hh>

namespace pokemonism::collection {

    template <class Element, class Super = Continuable<Element, Sequence<Element>>, unsigned long Unit = sizeof(Element), typename Characterable = void, typename Primitivable = void>
    class Continuous : public Super {
    protected:  Element *       storage;
    protected:  unsigned long   size;
    protected:  unsigned long   capacity;
    public:     inline Continuous(void);
    public:     inline ~Continuous(void) override;
    public:     inline Continuous(const Continuous<Element, Super, Unit, Characterable, Primitivable> & o);
    public:     inline Continuous(Continuous<Element, Super, Unit, Characterable, Primitivable> && o) noexcept;
    public:     inline Continuous<Element, Super, Unit, Characterable, Primitivable> & operator=(const Continuous<Element, Super, Unit, Characterable, Primitivable> & o);
    public:     inline Continuous<Element, Super, Unit, Characterable, Primitivable> & operator=(Continuous<Element, Super, Unit, Characterable, Primitivable> && o) noexcept;
    };

    template<class Element, class Super, unsigned long Unit, typename Characterable, typename Primitivable>
    Continuous<Element, Super, Unit, Characterable, Primitivable>::Continuous(void) : storage(nullptr), size(declaration::zero), capacity(declaration::zero) {

    }

    template<class Element, class Super, unsigned long Unit, typename Characterable, typename Primitivable>
    Continuous<Element, Super, Unit, Characterable, Primitivable>::~Continuous(void) {
        pokemon_develop_exit_check(true, return);
    }

    template<class Element, class Super, unsigned long Unit, typename Characterable, typename Primitivable>
    Continuous<Element, Super, Unit, Characterable, Primitivable>::Continuous(const Continuous<Element, Super, Unit, Characterable, Primitivable> & o) : storage(nullptr), size(declaration::zero), capacity(declaration::zero) {
        pokemon_develop_throw(return);
    }

    template<class Element, class Super, unsigned long Unit, typename Characterable, typename Primitivable>
    Continuous<Element, Super, Unit, Characterable, Primitivable>::Continuous(Continuous<Element, Super, Unit, Characterable, Primitivable> && o) noexcept : storage(o.storage), size(o.size), capacity(o.capacity) {
        o.storage = nullptr;
        o.size = declaration::zero;
        o.capacity = declaration::zero;
    }

    template<class Element, class Super, unsigned long Unit, typename Characterable, typename Primitivable>
    Continuous<Element, Super, Unit, Characterable, Primitivable> & Continuous<Element, Super, Unit, Characterable, Primitivable>::operator=(const Continuous<Element, Super, Unit, Characterable, Primitivable> & o) {
        pokemon_develop_throw(return *this);
        return *this;
    }

    template<class Element, class Super, unsigned long Unit, typename Characterable, typename Primitivable>
    Continuous<Element, Super, Unit, Characterable, Primitivable> & Continuous<Element, Super, Unit, Characterable, Primitivable>::operator=(Continuous<Element, Super, Unit, Characterable, Primitivable> && o) noexcept {
        pokemon_develop_throw(return *this);
        return *this;
    }

}

#endif // __POKEMONISM_COLLECTION_CONTINUOUS_HH__