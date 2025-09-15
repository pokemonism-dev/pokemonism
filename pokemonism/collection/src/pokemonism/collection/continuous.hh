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

#include <cstring>

#include <pokemonism/sdk/memorizer.hh>
#include <pokemonism/sdk/allocator.hh>
#include <pokemonism/sdk/continuous.hh>

#include <pokemonism/continuable.hh>
#include <pokemonism/collection/sequence.hh>

namespace pokemonism::collection {

    template <class element, class super = continuable<element, sequence<element>>, unsigned long unit = sizeof(element), typename characterable = void, typename primitivable = void>
    class continuous : public super {
    public:     static continuous<element, super, unit, characterable, primitivable> capacityGen(unsigned long capacity);
    public:     static continuous<element, super, unit, characterable, primitivable> sizeGen(unsigned long n);
    protected:  using memorizer = pokemonism::sdk::memorizer<element, primitivable, unit>;
    protected:  using allocator = pokemonism::sdk::allocator;
    protected:  constexpr static unsigned long page = 8;
    protected:  element *       storage;
    protected:  unsigned long   size;
    protected:  unsigned long   capacity;
    public:     inline virtual element * storageGet(void);
    public:     inline virtual unsigned long sizeGet(void) const;
    public:     inline virtual element & at(unsigned long index);
    public:     inline virtual const element & at(unsigned long index) const;
    public:     inline void set(const element & item, unsigned long n) override;
    public:     inline void set(const element * source, unsigned long sourceLen) override;
    public:     inline void cat(const element & item, unsigned long n) override;
    public:     inline void cat(const element * source, unsigned long sourceLen) override;
    public:     inline unsigned long capacityCal(unsigned long n) override;
    public:     inline void add(const element & item) override;
    public:     inline void add(element && item) override;
    // public:     inline void del(element & item) override;
    public:     inline void clear(void) override;
    public:     inline virtual void clean(void);
    public:     inline virtual void grow(unsigned long n);
    public:     inline virtual element & operator[](unsigned long index);
    public:     inline virtual const element & operator[](unsigned long index) const;
    public:     inline continuous(const element * source, unsigned long sourceLen);
    public:     inline continuous(void);
    public:     inline ~continuous(void) override;
    public:     inline continuous(const continuous<element, super, unit, characterable, primitivable> & o);
    public:     inline continuous(continuous<element, super, unit, characterable, primitivable> && o) noexcept;
    public:     inline continuous<element, super, unit, characterable, primitivable> & operator=(const continuous<element, super, unit, characterable, primitivable> & o);
    public:     inline continuous<element, super, unit, characterable, primitivable> & operator=(continuous<element, super, unit, characterable, primitivable> && o) noexcept;
    public:     template <typename elementable, class continuable> friend class pokemonism::sdk::continuous;
    };

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    continuous<element, super, unit, characterable, primitivable> continuous<element, super, unit, characterable, primitivable>::sizeGen(unsigned long n) {
        continuous<element, super, unit, characterable, primitivable> o;

        o.capacity = o.size = n;
        o.storage = allocator::gen<element>(o.capacity);
        for (unsigned long i = 0; i < o.size; i = i + 1) new (o.storage + i) element();

        return o;
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    continuous<element, super, unit, characterable, primitivable> continuous<element, super, unit, characterable, primitivable>::capacityGen(unsigned long capacity) {
        continuous<element, super, unit, characterable, primitivable> o;

        o.capacity = capacity;
        o.storage = allocator::gen<element>(o.capacity);

        return o;
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline element * continuous<element, super, unit, characterable, primitivable>::storageGet(void) {
        return size > 0 ? storage : nullptr;
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline unsigned long continuous<element, super, unit, characterable, primitivable>::sizeGet(void) const {
        return size;
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline element & continuous<element, super, unit, characterable, primitivable>::at(unsigned long index) {
        pokemon_develop_check(size <= index, exit(0));
        return storage[index];
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline const element & continuous<element, super, unit, characterable, primitivable>::at(unsigned long index) const {
        pokemon_develop_check(size <= index, exit(0));
        return storage[index];
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline void continuous<element, super, unit, characterable, primitivable>::set(const element & item, unsigned long n) {
        if (size > 0) memorizer::del(storage, size);
        if (capacity < n) storage = allocator::reset(storage, capacity = capacityCal(n));
        memorizer::set(storage, item, size = n);
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline void continuous<element, super, unit, characterable, primitivable>::set(const element * source, unsigned long sourceLen) {
        if (size > 0) memorizer::del(storage, size);
        if (capacity < sourceLen) storage = allocator::reset(storage, capacity = capacityCal(sourceLen));
        memorizer::set(storage, source, size = sourceLen);
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline void continuous<element, super, unit, characterable, primitivable>::cat(const element & item, unsigned long n) {
        if (capacity < size + n) storage = allocator::gen(storage, capacity = capacityCal(size + n));
        memorizer::set(storage + size, item, n);
        size = size + n;
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline void continuous<element, super, unit, characterable, primitivable>::cat(const element * source, unsigned long sourceLen) {
        if (capacity < size + sourceLen) storage = allocator::gen(storage, capacity = capacityCal(size + sourceLen));
        memorizer::set(storage + size, source, sourceLen);
        size = size + sourceLen;
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline unsigned long continuous<element, super, unit, characterable, primitivable>::capacityCal(unsigned long n) {
        return (n / page + (n % page > 0 ? 1 : 0)) * page;
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline void continuous<element, super, unit, characterable, primitivable>::add(const element & item) {
        if (capacity <= size) storage = allocator::gen(storage, capacity = capacityCal(size + 1));
        new (storage + size) element(item);
        size = size + 1;
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline void continuous<element, super, unit, characterable, primitivable>::add(element && item) {
        if (capacity <= size) storage = allocator::gen(storage, capacity = capacityCal(size + 1));
        new (storage + size) element(std::move(item));
        size = size + 1;
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    void continuous<element, super, unit, characterable, primitivable>::clear(void) {
        if (size > declaration::zero) memorizer::del(storage, size);
        storage = allocator::rel(storage);
        size = declaration::zero;
        capacity = declaration::zero;
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    void continuous<element, super, unit, characterable, primitivable>::clean(void) {
        if (size > declaration::zero) memorizer::del(storage, size);
        size = declaration::zero;
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline element & continuous<element, super, unit, characterable, primitivable>::operator[](unsigned long index) {
        pokemon_develop_check(size <= index, exit(0));
        return storage[index];
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline const element & continuous<element, super, unit, characterable, primitivable>::operator[](unsigned long index) const {
        pokemon_develop_check(size <= index, exit(0));
        return storage[index];
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline void continuous<element, super, unit, characterable, primitivable>::grow(unsigned long n) {
        if (capacity < size + n) storage = allocator::gen(storage, capacity = capacityCal(size + n));
        for (unsigned long i = 0; i < n; i = i + 1) new (storage + size + i) element();
        size = size + n;
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline continuous<element, super, unit, characterable, primitivable>::continuous(const element * source, unsigned long sourceLen) : storage(nullptr), size(sourceLen), capacity(capacityCal(sourceLen)) {
        if (capacity > 0) storage = allocator::gen<element>(capacity);
        if (size > 0) memorizer::set(storage, source, sourceLen);
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    continuous<element, super, unit, characterable, primitivable>::continuous(void) : storage(nullptr), size(declaration::zero), capacity(declaration::zero) {
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    continuous<element, super, unit, characterable, primitivable>::~continuous(void) {
        if (size > declaration::zero) memorizer::del(storage, size);
        storage = allocator::rel(storage);
        size = declaration::zero;
        capacity = declaration::zero;
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    continuous<element, super, unit, characterable, primitivable>::continuous(const continuous<element, super, unit, characterable, primitivable> & o) : storage(nullptr), size(declaration::zero), capacity(declaration::zero) {
        if (o.capacity > 0) storage = allocator::gen<element>(capacity = o.capacity);
        if (o.size > 0) memorizer::set(storage, o.storage, size = o.size);
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    continuous<element, super, unit, characterable, primitivable>::continuous(continuous<element, super, unit, characterable, primitivable> && o) noexcept : storage(o.storage), size(o.size), capacity(o.capacity) {
        o.storage = nullptr;
        o.size = declaration::zero;
        o.capacity = declaration::zero;
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    continuous<element, super, unit, characterable, primitivable> & continuous<element, super, unit, characterable, primitivable>::operator=(const continuous<element, super, unit, characterable, primitivable> & o) {
        if (pointof(o) != this) {
            memorizer::del(storage, size);
            size = declaration::zero;

            if (capacity < o.capacity) storage = allocator::reset<element>(storage, capacity = o.capacity);
            if (o.size > 0) memorizer::set(storage, o.storage, size = o.size);
        }

        return *this;
    }

    template<class element, class super, unsigned long unit, typename characterable, typename primitivable>
    continuous<element, super, unit, characterable, primitivable> & continuous<element, super, unit, characterable, primitivable>::operator=(continuous<element, super, unit, characterable, primitivable> && o) noexcept {
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