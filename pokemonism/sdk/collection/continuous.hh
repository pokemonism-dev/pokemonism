/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_COLLECTION_CONTINUOUS_HH__
#define   __POKEMONISM_SDK_COLLECTION_CONTINUOUS_HH__

#include <pokemonism/sdk/allocator.hh>
#include <pokemonism/sdk/memorizer.hh>
#include <pokemonism/sdk/collection/continuable.hh>

namespace pokemonism::sdk::collection {

    template <typename element, class interfaceable = collection::continuable<element>>
    class continuous : public interfaceable {
    protected:  unsigned long size;
    protected:  unsigned long capacity;
    protected:  element * storage;
    public:     inline unsigned long set(void) override;
    public:     inline unsigned long set(const element & item, unsigned long n) override;
    public:     inline unsigned long set(const element * source, unsigned long sourceLen) override;
    public:     inline virtual unsigned long set(const continuous<element, interfaceable> & source);
    public:     inline virtual unsigned long set(continuous<element, interfaceable> && source) noexcept;
    public:     inline unsigned long cat(const element & item, unsigned long n) override;
    public:     inline unsigned long cat(const element * source, unsigned long sourceLen) override;
    public:     inline virtual unsigned long cat(const continuous<element, interfaceable> & source);
    public:     inline unsigned long cut(unsigned long offset) override;
    public:     inline unsigned long pop(unsigned long length) override;
    public:     inline const element & at(unsigned long index) const override;
    public:     inline element & at(unsigned long index) override;
    public:     inline const element & operator[](unsigned long index) const override;
    public:     inline element & operator[](unsigned long index) override;
    public:     inline element * add(const element & item) override;
    public:     inline element * add(element && item) override;
    public:     inline element & del(element & item) override;
    public:     inline unsigned long sizeGet(void) override;
    public:     inline unsigned long capacityGet(void) override;
    public:     inline void clear(void) override;
    public:     inline void clean(void) override;
    public:     inline void reset(void) override;
    public:     inline continuous(const element & item, unsigned long n);
    public:     inline continuous(const element * source, unsigned long sourceLen);
    public:     inline continuous(void);
    public:     inline ~continuous(void) override;
    public:     inline continuous(const continuous<element, interfaceable> & o);
    public:     inline continuous(continuous<element, interfaceable> && o) noexcept;
    public:     inline virtual continuous<element, interfaceable> & operator=(const continuous<element, interfaceable> & o);
    public:     inline virtual continuous<element, interfaceable> & operator=(continuous<element, interfaceable> && o) noexcept;
    };

    template <typename element, class interfaceable>
    inline unsigned long continuous<element, interfaceable>::set(void) {
        memorizer<element>::del(storage, size);
        size = declaration::zero;

        return declaration::zero;
    }

    template <typename element, class interfaceable>
    inline unsigned long continuous<element, interfaceable>::set(const element & item, unsigned long n) {
        memorizer<element>::del(storage, size);
        if (capacity < n) storage = static_cast<element *>(allocator::reset(storage, capacity = continuous<element, interfaceable>::capacityCal(n, continuous<element, interfaceable>::page)));
        memorizer<element>::set(storage, item, size = n);

        return n;
    }

    template <typename element, class interfaceable>
    inline unsigned long continuous<element, interfaceable>::set(const element * source, unsigned long sourceLen) {
        memorizer<element>::del(storage, size);
        if (capacity < sourceLen) storage = static_cast<element *>(allocator::reset(storage, capacity = continuous<element, interfaceable>::capacityCal(sourceLen, continuous<element, interfaceable>::page)));
        memorizer<element>::set(storage, source, size = sourceLen);

        return sourceLen;
    }

    template <typename element, class interfaceable>
    inline unsigned long continuous<element, interfaceable>::set(const continuous<element, interfaceable> & source) {
        memorizer<element>::del(storage, size);
        if (capacity < source.size) storage = static_cast<element *>(allocator::reset(storage, capacity = continuous<element, interfaceable>::capacityCal(source.size, continuous<element, interfaceable>::page)));
        memorizer<element>::set(storage, source.storage, size = source.size);

        return size;
    }

    template <typename element, class interfaceable>
    inline unsigned long continuous<element, interfaceable>::set(continuous<element, interfaceable> && source) noexcept {
        memorizer<element>::del(storage, size);
        allocator::del(storage);

        storage = source.storage;
        capacity = source.capacity;
        size = source.size;

        return size;
    }

    template <typename element, class interfaceable>
    inline unsigned long continuous<element, interfaceable>::cat(const element & item, unsigned long n) {
        if (capacity < size + n) storage = static_cast<element *>(allocator::regen(storage, capacity = continuous<element, interfaceable>::capacityCal(size + n, continuous<element, interfaceable>::page)));
        memorizer<element>::set(storage + size, item, n);
        size = size + n;

        return n;
    }

    template <typename element, class interfaceable>
    inline unsigned long continuous<element, interfaceable>::cat(const element * source, unsigned long sourceLen) {
        if (capacity < size + sourceLen) storage = static_cast<element *>(allocator::regen(storage, capacity = continuous<element, interfaceable>::capacityCal(size + sourceLen, continuous<element, interfaceable>::page)));
        memorizer<element>::set(storage + size, source, sourceLen);
        size = size + sourceLen;

        return sourceLen;
    }

    template <typename element, class interfaceable>
    inline unsigned long continuous<element, interfaceable>::cat(const continuous<element, interfaceable> & source) {
        if (capacity < size + source.size) storage = static_cast<element *>(allocator::regen(storage, capacity = continuous<element, interfaceable>::capacityCal(size + source.size, continuous<element, interfaceable>::page)));
        memorizer<element>::set(storage + size, source.storage, source.size);
        size = size + source.size;

        return source.size;
    }

    template <typename element, class interfaceable>
    inline unsigned long continuous<element, interfaceable>::cut(unsigned long offset) {
        if (offset <= size) return declaration::zero;

        const unsigned long deleted = size - offset;
        memorizer<element>::del(storage + offset, deleted);
        size = offset;

        return deleted;
    }

    template <typename element, class interfaceable>
    inline unsigned long continuous<element, interfaceable>::pop(unsigned long length) {
        if (size < length) length = size;

        const unsigned long remain = size - length;
        memorizer<element>::del(storage, length);
        if (remain > 0) memcpy(storage, storage + length, remain * sizeof(element));
        size = remain;

        return length;
    }

    template <typename element, class interfaceable>
    inline const element & continuous<element, interfaceable>::at(unsigned long index) const {
        pokemon_develop_check(size <= index, exit(declaration::zero));

        return storage[index];
    }

    template <typename element, class interfaceable>
    inline element & continuous<element, interfaceable>::at(unsigned long index) {
        pokemon_develop_check(size <= index, exit(declaration::zero));

        return storage[index];
    }

    template <typename element, class interfaceable>
    inline const element & continuous<element, interfaceable>::operator[](unsigned long index) const {
        pokemon_develop_check(size <= index, exit(declaration::zero));

        return storage[index];
    }

    template <typename element, class interfaceable>
    inline element & continuous<element, interfaceable>::operator[](unsigned long index) {
        pokemon_develop_check(size <= index, exit(declaration::zero));

        return storage[index];
    }

    template <typename element, class interfaceable>
    inline element * continuous<element, interfaceable>::add(const element & item) {
        if (capacity < size + 1) storage = static_cast<element *>(allocator::regen(storage, capacity = continuous<element, interfaceable>::capacityCal(size + 1, continuous<element, interfaceable>::page)));
        memorizer<element>::set(storage + size, item);
        size = size + 1;

        return storage + size - 1;
    }

    template <typename element, class interfaceable>
    inline element * continuous<element, interfaceable>::add(element && item) {
        if (capacity < size + 1) storage = static_cast<element *>(allocator::regen(storage, capacity = continuous<element, interfaceable>::capacityCal(size + 1, continuous<element, interfaceable>::page)));
        memorizer<element>::set(storage + size, std::move(item));
        size = size + 1;

        return storage + size - 1;
    }

    template <typename element, class interfaceable>
    inline element & continuous<element, interfaceable>::del(element & item) {
        for (unsigned long i = 0; i < size; i = i + 1) {
            if (item == storage[i]) {
                memorizer<element>::del(storage + i);
                if (i + 1 < size) memcpy(storage + i, storage + i + 1, size - i - 1);
                size = size - 1;
                return item;
            }
        }
        return item;
    }

    template <typename element, class interfaceable>
    inline unsigned long continuous<element, interfaceable>::sizeGet(void) {
        return size;
    }

    template <typename element, class interfaceable>
    inline unsigned long continuous<element, interfaceable>::capacityGet(void) {
        return capacity;
    }

    template <typename element, class interfaceable>
    inline void continuous<element, interfaceable>::clear(void) {
        memorizer<element>::del(storage, size);
        storage = static_cast<element *>(allocator::rel(storage));
        capacity = size = 0;
    }

    template <typename element, class interfaceable>
    inline void continuous<element, interfaceable>::clean(void) {
        memorizer<element>::del(storage, size);
        size = 0;
    }

    template <typename element, class interfaceable>
    inline void continuous<element, interfaceable>::reset(void) {
        memorizer<element>::del(storage, size);
        size = 0;
    }

    template <typename element, class interfaceable>
    inline continuous<element, interfaceable>::continuous(const element & item, unsigned long n) : size(n), capacity(continuous<element, interfaceable>::capacityCal(n, continuous<element, interfaceable>::page)) {
        storage = static_cast<element *>(allocator::gen(capacity));
        memorizer<element>::set(item, n);
    }

    template <typename element, class interfaceable>
    inline continuous<element, interfaceable>::continuous(const element * source, unsigned long sourceLen) : size(sourceLen), capacity(continuous<element, interfaceable>::capacityCal(sourceLen, continuous<element, interfaceable>::page)) {
        storage = static_cast<element *>(allocator::gen(capacity));
        memorizer<element>::set(source, sourceLen);
    }

    template <typename element, class interfaceable>
    inline continuous<element, interfaceable>::continuous(void) : size(declaration::zero), capacity(declaration::zero), storage(nullptr) {

    }

    template <typename element, class interfaceable>
    inline continuous<element, interfaceable>::~continuous(void) {
        memorizer<element>::del(storage, size);
        storage = static_cast<element *>(allocator::rel(storage));
        size = declaration::zero;
        capacity = declaration::zero;
    }

    template <typename element, class interfaceable>
    inline continuous<element, interfaceable>::continuous(const continuous<element, interfaceable> & o) : size(declaration::zero), capacity(o.capacity), storage(allocator::gen(o.capacity)) {
        memorizer<element>::set(storage, o.storage, size = o.size);
    }

    template <typename element, class interfaceable>
    inline continuous<element, interfaceable>::continuous(continuous<element, interfaceable> && o) noexcept : size(o.size), capacity(o.capacity), storage(o.storage) {
        o.size = declaration::zero;
        o.capacity = declaration::zero;
        o.storage = nullptr;
    }

    template <typename element, class interfaceable>
    inline continuous<element, interfaceable> & continuous<element, interfaceable>::operator=(const continuous<element, interfaceable> & o) {
        if (pointof(o) != this) {
            memorizer<element>::del(storage, size);
            if (capacity < o.size) storage = static_cast<element *>(allocator::reset(storage, capacity = continuous<element, interfaceable>::capacityCal(o.size, continuous<element, interfaceable>::page)));
            memorizer<element>::set(storage, o.storage, size = o.size);
        }
        return *this;
    }

    template <typename element, class interfaceable>
    inline continuous<element, interfaceable> & continuous<element, interfaceable>::operator=(continuous<element, interfaceable> && o) noexcept {
        if (pointof(o) != this) {
            memorizer<element>::del(storage, size);
            allocator::rel(storage);

            capacity = o.capacity;
            size = o.size;
            storage = o.storage;

            o.size = declaration::zero;
            o.capacity = declaration::zero;
            o.storage = nullptr;
        }
        return *this;
    }

}

#endif // __POKEMONISM_SDK_COLLECTION_CONTINUOUS_HH__