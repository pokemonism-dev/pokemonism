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

#include <pokemonism/sdk/memorizer.hh>
#include <pokemonism/sdk/allocator.hh>

#include <pokemonism/continuable.hh>
#include <pokemonism/collection/sequence.hh>

namespace pokemonism::collection {

    template <class Element, class Super = Continuable<Element, Sequence<Element>>, unsigned long unit = sizeof(Element), typename Characterable = void, typename Primitivable = void>
    class Continuous : public Super {
    protected:  using memorizer = Memorizer<Element, Primitivable, unit>;
    protected:  using allocator = Allocator;
    protected:  Element *       storage;
    protected:  unsigned long   size;
    protected:  unsigned long   capacity;
    public:     inline void clear(void) override;
    public:     inline Continuous(void);
    public:     inline ~Continuous(void) override;
    public:     inline Continuous(const Continuous<Element, Super, unit, Characterable, Primitivable> & o);
    public:     inline Continuous(Continuous<Element, Super, unit, Characterable, Primitivable> && o) noexcept;
    public:     inline Continuous<Element, Super, unit, Characterable, Primitivable> & operator=(const Continuous<Element, Super, unit, Characterable, Primitivable> & o);
    public:     inline Continuous<Element, Super, unit, Characterable, Primitivable> & operator=(Continuous<Element, Super, unit, Characterable, Primitivable> && o) noexcept;
    };

    template<class Element, class Super, unsigned long unit, typename Characterable, typename Primitivable>
    void Continuous<Element, Super, unit, Characterable, Primitivable>::clear(void) {
        if (size > declaration::zero) memorizer::del(storage, size);
        storage = allocator::rel(storage);
        size = declaration::zero;
        capacity = declaration::zero;
    }

    template<class Element, class Super, unsigned long unit, typename Characterable, typename Primitivable>
    Continuous<Element, Super, unit, Characterable, Primitivable>::Continuous(void) : storage(nullptr), size(declaration::zero), capacity(declaration::zero) {

    }

    template<class Element, class Super, unsigned long unit, typename Characterable, typename Primitivable>
    Continuous<Element, Super, unit, Characterable, Primitivable>::~Continuous(void) {
        if (size > declaration::zero) memorizer::del(storage, size);
        storage = allocator::rel(storage);
        size = declaration::zero;
        capacity = declaration::zero;
    }

    template<class Element, class Super, unsigned long unit, typename Characterable, typename Primitivable>
    Continuous<Element, Super, unit, Characterable, Primitivable>::Continuous(const Continuous<Element, Super, unit, Characterable, Primitivable> & o) : storage(nullptr), size(declaration::zero), capacity(declaration::zero) {
        if (o.capacity > 0) storage = allocator::gen<Element>(capacity = o.capacity);
        if (o.size > 0) memorizer::set(storage, o.storage, size = o.size);
    }

    template<class Element, class Super, unsigned long unit, typename Characterable, typename Primitivable>
    Continuous<Element, Super, unit, Characterable, Primitivable>::Continuous(Continuous<Element, Super, unit, Characterable, Primitivable> && o) noexcept : storage(o.storage), size(o.size), capacity(o.capacity) {
        o.storage = nullptr;
        o.size = declaration::zero;
        o.capacity = declaration::zero;
    }

    template<class Element, class Super, unsigned long unit, typename Characterable, typename Primitivable>
    Continuous<Element, Super, unit, Characterable, Primitivable> & Continuous<Element, Super, unit, Characterable, Primitivable>::operator=(const Continuous<Element, Super, unit, Characterable, Primitivable> & o) {
        if (pointof(o) != this) {
            memorizer::del(storage, size);
            size = declaration::zero;

            if (capacity < o.capacity) storage = allocator::reset<Element>(storage, capacity = o.capacity);
            if (o.size > 0) memorizer::set(storage, o.storage, size = o.size);
        }

        return *this;
    }

    template<class Element, class Super, unsigned long unit, typename Characterable, typename Primitivable>
    Continuous<Element, Super, unit, Characterable, Primitivable> & Continuous<Element, Super, unit, Characterable, Primitivable>::operator=(Continuous<Element, Super, unit, Characterable, Primitivable> && o) noexcept {
        if (pointof(o) != this) {
            memorizer::del(storage, size);
            allocator::rel(storage);

            storage = o.storage;
            size = o.size;
            capacity = o.capacity;

            o.storage = nullptr;
            o.size = declaration::zero;
            o.capacity = declaration::zero;
        }

        return *this;
    }

}

#endif // __POKEMONISM_COLLECTION_CONTINUOUS_HH__