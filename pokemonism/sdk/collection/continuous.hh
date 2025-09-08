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

    template <typename element, typename primitivable = typographer<element>::primitive, typename characterizable = typographer<element>::character, unsigned long unit = typographer<element>::unit>
    class continuous : public collection::continuable<element> {
    protected:  unsigned long   size;
    protected:  unsigned long   capacity;
    protected:  element *       storage;
    public:     inline unsigned long set(void) override;
    public:     inline unsigned long set(const element & item, unsigned long n) override;
    public:     inline unsigned long set(const element * source, unsigned long sourceLen) override;
    public:     inline virtual unsigned long set(const continuous<element, primitivable, characterizable, unit> & source);
    public:     inline virtual unsigned long set(continuous<element, primitivable, characterizable, unit> && source) noexcept;
    public:     inline unsigned long cat(const element & item, unsigned long n) override;
    public:     inline unsigned long cat(const element * source, unsigned long sourceLen) override;
    public:     inline virtual unsigned long cat(const continuous<element, primitivable, characterizable, unit> & source);
    public:     inline unsigned long cut(unsigned long offset) override;
    public:     inline unsigned long pop(unsigned long length) override;
    public:     inline const element & at(unsigned long index) const override;
    public:     inline element & at(unsigned long index) override;
    public:     inline const element & operator[](unsigned long index) const override;
    public:     inline element & operator[](unsigned long index) override;
    public:     inline element * add(const element & item) override;
    public:     inline element * add(element && item) override;
    public:     inline element & del(element & item) override;
    public:     inline unsigned long pageGet(void) const override;
    public:     inline unsigned long sizeGet(void) const override;
    public:     inline unsigned long capacityGet(void) const override;
    public:     inline void clear(void) override;
    public:     inline void clean(void) override;
    public:     inline void reset(void) override;
    public:     inline continuous(const element & item, unsigned long n);
    public:     inline continuous(const element * source, unsigned long sourceLen);
    public:     inline continuous(void);
    public:     inline ~continuous(void) override;
    public:     inline continuous(const continuous<element, primitivable, characterizable, unit> & o);
    public:     inline continuous(continuous<element, primitivable, characterizable, unit> && o) noexcept;
    public:     inline virtual continuous<element, primitivable, characterizable, unit> & operator=(const continuous<element, primitivable, characterizable, unit> & o);
    public:     inline virtual continuous<element, primitivable, characterizable, unit> & operator=(continuous<element, primitivable, characterizable, unit> && o) noexcept;
    };

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline unsigned long continuous<element, primitivable, characterizable, unit>::set(void) {
        memorizer<element>::del(storage, size);
        size = declaration::zero;

        return declaration::zero;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline unsigned long continuous<element, primitivable, characterizable, unit>::set(const element & item, unsigned long n) {
        memorizer<element>::del(storage, size);
        if (capacity < n) storage = static_cast<element *>(allocator::reset(storage, (capacity = continuous<element, primitivable, characterizable, unit>::capacityCal(n, pageGet())) * sizeof(element)));
        memorizer<element>::set(storage, item, size = n);

        return n;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline unsigned long continuous<element, primitivable, characterizable, unit>::set(const element * source, unsigned long sourceLen) {
        memorizer<element>::del(storage, size);
        if (capacity < sourceLen) storage = static_cast<element *>(allocator::reset(storage, (capacity = continuous<element, primitivable, characterizable, unit>::capacityCal(sourceLen, pageGet())) * sizeof(element)));
        memorizer<element>::set(storage, source, size = sourceLen);

        return sourceLen;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline unsigned long continuous<element, primitivable, characterizable, unit>::set(const continuous<element, primitivable, characterizable, unit> & source) {
        memorizer<element>::del(storage, size);
        if (capacity < source.size) storage = static_cast<element *>(allocator::reset(storage, (capacity = continuous<element, primitivable, characterizable, unit>::capacityCal(source.size, pageGet())) * sizeof(element)));
        memorizer<element>::set(storage, source.storage, size = source.size);

        return size;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline unsigned long continuous<element, primitivable, characterizable, unit>::set(continuous<element, primitivable, characterizable, unit> && source) noexcept {
        memorizer<element>::del(storage, size);
        allocator::rel(storage);

        storage = source.storage;
        capacity = source.capacity;
        size = source.size;

        return size;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline unsigned long continuous<element, primitivable, characterizable, unit>::cat(const element & item, unsigned long n) {
        if (capacity < size + n) storage = static_cast<element *>(allocator::regen(storage, (capacity = continuous<element, primitivable, characterizable, unit>::capacityCal(size + n, pageGet())) * sizeof(element)));
        memorizer<element>::set(storage + size, item, n);
        size = size + n;

        return n;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline unsigned long continuous<element, primitivable, characterizable, unit>::cat(const element * source, unsigned long sourceLen) {
        if (capacity < size + sourceLen) storage = static_cast<element *>(allocator::regen(storage, (capacity = continuous<element, primitivable, characterizable, unit>::capacityCal(size + sourceLen, pageGet())) * sizeof(element)));
        memorizer<element>::set(storage + size, source, sourceLen);
        size = size + sourceLen;

        return sourceLen;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline unsigned long continuous<element, primitivable, characterizable, unit>::cat(const continuous<element, primitivable, characterizable, unit> & source) {
        if (capacity < size + source.size) storage = static_cast<element *>(allocator::regen(storage, (capacity = continuous<element, primitivable, characterizable, unit>::capacityCal(size + source.size, pageGet())) * sizeof(element)));
        memorizer<element>::set(storage + size, source.storage, source.size);
        size = size + source.size;

        return source.size;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline unsigned long continuous<element, primitivable, characterizable, unit>::cut(unsigned long offset) {
        if (offset <= size) return declaration::zero;

        const unsigned long deleted = size - offset;
        memorizer<element>::del(storage + offset, deleted);
        size = offset;

        return deleted;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline unsigned long continuous<element, primitivable, characterizable, unit>::pop(unsigned long length) {
        if (size < length) length = size;

        const unsigned long remain = size - length;
        memorizer<element>::del(storage, length);
        if (remain > 0) memcpy(storage, storage + length, remain * sizeof(element));
        size = remain;

        return length;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline const element & continuous<element, primitivable, characterizable, unit>::at(unsigned long index) const {
        pokemon_develop_check(size <= index, exit(declaration::fail));

        return storage[index];
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline element & continuous<element, primitivable, characterizable, unit>::at(unsigned long index) {
        pokemon_develop_check(size <= index, exit(declaration::fail));

        return storage[index];
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline const element & continuous<element, primitivable, characterizable, unit>::operator[](unsigned long index) const {
        pokemon_develop_check(size <= index, exit(declaration::fail));

        return storage[index];
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline element & continuous<element, primitivable, characterizable, unit>::operator[](unsigned long index) {
        pokemon_develop_check(size <= index, exit(declaration::fail));

        return storage[index];
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline element * continuous<element, primitivable, characterizable, unit>::add(const element & item) {
        if (capacity < size + 1) storage = static_cast<element *>(allocator::regen(storage, (capacity = continuous<element, primitivable, characterizable, unit>::capacityCal(size + 1, pageGet())) * sizeof(element)));
        memorizer<element>::set(storage + size, item);
        size = size + 1;

        return storage + size - 1;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline element * continuous<element, primitivable, characterizable, unit>::add(element && item) {
        if (capacity < size + 1) storage = static_cast<element *>(allocator::regen(storage, (capacity = continuous<element, primitivable, characterizable, unit>::capacityCal(size + 1, pageGet())) * sizeof(element)));
        memorizer<element>::set(storage + size, std::move(item));
        size = size + 1;

        return storage + size - 1;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline element & continuous<element, primitivable, characterizable, unit>::del(element & item) {
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

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline unsigned long continuous<element, primitivable, characterizable, unit>::pageGet(void) const {
        return declaration::eight;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline unsigned long continuous<element, primitivable, characterizable, unit>::sizeGet(void) const {
        return size;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline unsigned long continuous<element, primitivable, characterizable, unit>::capacityGet(void) const {
        return capacity;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline void continuous<element, primitivable, characterizable, unit>::clear(void) {
        memorizer<element>::del(storage, size);
        storage = static_cast<element *>(allocator::rel(storage));
        capacity = size = 0;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline void continuous<element, primitivable, characterizable, unit>::clean(void) {
        memorizer<element>::del(storage, size);
        size = 0;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline void continuous<element, primitivable, characterizable, unit>::reset(void) {
        memorizer<element>::del(storage, size);
        size = 0;
    }

    // ReSharper disable once CppVirtualFunctionCallInsideCtor
    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline continuous<element, primitivable, characterizable, unit>::continuous(const element & item, unsigned long n) : size(n), capacity(continuous<element, primitivable, characterizable, unit>::capacityCal(n, pageGet())) {
        storage = static_cast<element *>(allocator::gen(capacity * sizeof(element)));
        memorizer<element>::set(item, n);
    }

    // ReSharper disable once CppVirtualFunctionCallInsideCtor
    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline continuous<element, primitivable, characterizable, unit>::continuous(const element * source, unsigned long sourceLen) : size(sourceLen), capacity(continuous<element, primitivable, characterizable, unit>::capacityCal(sourceLen, pageGet())) {
        storage = static_cast<element *>(allocator::gen(capacity * sizeof(element)));
        memorizer<element>::set(source, sourceLen);
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline continuous<element, primitivable, characterizable, unit>::continuous(void) : size(declaration::zero), capacity(declaration::zero), storage(nullptr) {

    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline continuous<element, primitivable, characterizable, unit>::~continuous(void) {
        memorizer<element>::del(storage, size);
        storage = static_cast<element *>(allocator::rel(storage));
        size = declaration::zero;
        capacity = declaration::zero;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline continuous<element, primitivable, characterizable, unit>::continuous(const continuous<element, primitivable, characterizable, unit> & o) : size(declaration::zero), capacity(o.capacity), storage(allocator::gen(o.capacity  * sizeof(element))) {
        memorizer<element>::set(storage, o.storage, size = o.size);
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline continuous<element, primitivable, characterizable, unit>::continuous(continuous<element, primitivable, characterizable, unit> && o) noexcept : size(o.size), capacity(o.capacity), storage(o.storage) {
        o.size = declaration::zero;
        o.capacity = declaration::zero;
        o.storage = nullptr;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline continuous<element, primitivable, characterizable, unit> & continuous<element, primitivable, characterizable, unit>::operator=(const continuous<element, primitivable, characterizable, unit> & o) {
        if (pointof(o) != this) {
            memorizer<element>::del(storage, size);
            if (capacity < o.size) storage = static_cast<element *>(allocator::reset(storage, (capacity = continuous<element, primitivable, characterizable, unit>::capacityCal(o.size, pageGet())) * sizeof(element)));
            memorizer<element>::set(storage, o.storage, size = o.size);
        }
        return *this;
    }

    template <typename element, typename primitivable, typename characterizable, unsigned long unit>
    inline continuous<element, primitivable, characterizable, unit> & continuous<element, primitivable, characterizable, unit>::operator=(continuous<element, primitivable, characterizable, unit> && o) noexcept {
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