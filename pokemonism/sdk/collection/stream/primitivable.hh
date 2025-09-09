/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_COLLECTION_STREAM_PRIMITIVABLE_HH__
#define   __POKEMONISM_SDK_COLLECTION_STREAM_PRIMITIVABLE_HH__

#include <pokemonism/sdk/collection/stream.hh>

namespace pokemonism::sdk::collection  {

    template <typename element, typename characterizable, unsigned long unit>
    class stream<element, unsigned char, characterizable, unit> : public collection::streamable<element> {
    protected:  unsigned long   size;
    protected:  unsigned long   capacity;
    protected:  element *       storage;
    protected:  unsigned long   position;
    public:     inline unsigned long positionGet(void) const override;
    public:     inline unsigned long lengthGet(void) const override;
    public:     inline unsigned long remainGet(void) const override;
    public:     inline unsigned long set(void) override;
    public:     inline unsigned long set(const element & item, unsigned long n) override;
    public:     inline unsigned long set(const element * source, unsigned long sourceLen) override;
    public:     inline virtual unsigned long set(const stream<element, unsigned char, characterizable, unit> & source);
    public:     inline virtual unsigned long set(stream<element, unsigned char, characterizable, unit> && source) noexcept;
    public:     inline unsigned long cat(const element & item, unsigned long n) override;
    public:     inline unsigned long cat(const element * source, unsigned long sourceLen) override;
    public:     inline virtual unsigned long cat(const stream<element, unsigned char, characterizable, unit> & source);
    public:     inline virtual unsigned long cat(stream<element, unsigned char, characterizable, unit> && source);
    public:     inline unsigned long cut(unsigned long offset) override;
    public:     inline unsigned long pop(unsigned long length) override;
    public:     inline void grow(unsigned long n) override;
    public:     inline void shrink(void) override;
    public:     inline void fit(void) override;
    public:     inline void trash(void) override;
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
    public:     inline stream(const element & item, unsigned long n);
    public:     inline stream(const element * source, unsigned long sourceLen);
    public:     inline stream(void);
    public:     inline ~stream(void) override;
    public:     inline stream(const stream<element, unsigned char, characterizable, unit> & o);
    public:     inline stream(stream<element, unsigned char, characterizable, unit> && o) noexcept;
    public:     inline virtual stream<element, unsigned char, characterizable, unit> & operator=(const stream<element, unsigned char, characterizable, unit> & o);
    public:     inline virtual stream<element, unsigned char, characterizable, unit> & operator=(stream<element, unsigned char, characterizable, unit> && o) noexcept;
    };

    template <typename element, typename characterizable, unsigned long unit>
    inline unsigned long stream<element, unsigned char, characterizable, unit>::lengthGet(void) const {
        return size - position;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline unsigned long stream<element, unsigned char, characterizable, unit>::remainGet(void) const {
        return capacity - size;
    }

    template <typename element, typename characterizable, unsigned long unit>
    unsigned long stream<element, unsigned char, characterizable, unit>::positionGet(void) const {
        return position;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline unsigned long stream<element, unsigned char, characterizable, unit>::set(void) {
        position = declaration::zero;
        size = declaration::zero;

        return declaration::zero;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline unsigned long stream<element, unsigned char, characterizable, unit>::set(const element & item, unsigned long n) {
        if (capacity < n) storage = static_cast<element *>(allocator::reset(storage, capacity = stream<element, unsigned char, characterizable, unit>::capacityCal(n, stream<element, unsigned char, characterizable, unit>::page)));

        memorizer<element>::set(storage, item, size = n);
        position = declaration::zero;

        return n;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline unsigned long stream<element, unsigned char, characterizable, unit>::set(const element * source, unsigned long sourceLen) {
        if (capacity < sourceLen) storage = static_cast<element *>(allocator::reset(storage, capacity = stream<element, unsigned char, characterizable, unit>::capacityCal(sourceLen, stream<element, unsigned char, characterizable, unit>::page)));

        memorizer<element>::set(storage, source, size = sourceLen);
        position = declaration::zero;

        return sourceLen;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline unsigned long stream<element, unsigned char, characterizable, unit>::set(const stream<element, unsigned char, characterizable, unit> & source) {
        const unsigned long length = source.size - source.position;

        if (capacity < length) storage = static_cast<element *>(allocator::reset(storage, capacity = stream<element, unsigned char, characterizable, unit>::capacityCal(length, stream<element, unsigned char, characterizable, unit>::page)));

        memorizer<element>::set(storage, source.storage, size = length);
        position = declaration::zero;

        return source.size;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline unsigned long stream<element, unsigned char, characterizable, unit>::set(stream<element, unsigned char, characterizable, unit> && source) noexcept {
        allocator::rel(storage);

        storage = source.storage;
        capacity = source.capacity;
        size = source.size;
        position = source.position;

        source.storage = nullptr;
        source.capacity = declaration::zero;
        source.size = declaration::zero;
        source.position = declaration::zero;

        return size;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline unsigned long stream<element, unsigned char, characterizable, unit>::cat(const element & item, unsigned long n) {
        if (position == size && position != 0) position = size = 0;
        if (capacity < size + n) storage = static_cast<element *>(allocator::regen(storage, capacity = stream<element, unsigned char, characterizable, unit>::capacityCal(size + n, pageGet())));
        memorizer<element>::set(storage + size, item, n);
        size = size + n;

        return n;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline unsigned long stream<element, unsigned char, characterizable, unit>::cat(const element * source, unsigned long sourceLen) {
        if (position == size && position != 0) position = size = 0;
        if (capacity < size + sourceLen) storage = static_cast<element *>(allocator::regen(storage, capacity = stream<element, unsigned char, characterizable, unit>::capacityCal(size + sourceLen, pageGet())));
        memorizer<element>::set(storage + size, source, sourceLen);
        size = size + sourceLen;

        return sourceLen;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline unsigned long stream<element, unsigned char, characterizable, unit>::cat(const stream<element, unsigned char, characterizable, unit> & source) {
        if (position == size && position != 0) position = size = 0;
        const unsigned long length = source.size - source.position;
        if (capacity < size + length) storage = static_cast<element *>(allocator::regen(storage, capacity = stream<element, unsigned char, characterizable, unit>::capacityCal(size + length, pageGet())));
        memorizer<element>::set(storage + size, source.storage, length);
        size = size + length;

        return length;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline unsigned long stream<element, unsigned char, characterizable, unit>::cat(stream<element, unsigned char, characterizable, unit> && source) {
        if (capacity < size + (source.size - source.position)) storage = static_cast<element *>(allocator::regen(storage, (capacity = stream<element, unsigned char, characterizable, unit>::capacityCal(size + (source.size - source.position), pageGet())) * sizeof(element)));
        const unsigned long n = source.size - source.position;
        if (n > 0) {
            memcpy(storage + size, source.storage, n * sizeof(element));
            size = size + n;
        }
        source.storage = static_cast<element *>(allocator::rel(source.storage));
        source.size = 0;
        source.capacity = 0;
        return n;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline unsigned long stream<element, unsigned char, characterizable, unit>::cut(unsigned long offset) {
        if (position + offset <= size) return declaration::zero;

        const unsigned long deleted = size - (offset + position);
        size = position + offset;

        return deleted;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline unsigned long stream<element, unsigned char, characterizable, unit>::pop(unsigned long length) {
        if ((size - position) < length) length = (size - position);

        const unsigned long remain = size - position - length;
        if (remain > 0) memmove(storage + position, storage + position + length, remain * sizeof(element));
        size = position + remain;

        return length;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline void stream<element, unsigned char, characterizable, unit>::grow(unsigned long n) {
        if (capacity < size + n) storage = static_cast<element *>(allocator::regen(storage, (capacity = stream<element, unsigned char, characterizable, unit>::capacityCal(size + n, pageGet())) * sizeof(element)));
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline void stream<element, unsigned char, characterizable, unit>::shrink(void) {
        if (size != capacity) storage = static_cast<element *>(allocator::reset(storage, (capacity = size) * sizeof(element)));
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline void stream<element, unsigned char, characterizable, unit>::fit(void) {
        trash();
        shrink();
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline void stream<element, unsigned char, characterizable, unit>::trash(void) {
        if (position != 0) {
            if (position != size) {
                memmove(storage, storage + position, (size - position) * sizeof(element));
                size = size - position;
            } else {
                size = 0;
            }
            position = 0;
        }
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline const element & stream<element, unsigned char, characterizable, unit>::at(unsigned long index) const {
        pokemon_develop_check(size <= position + index, exit(declaration::fail));

        return storage[position + index];
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline element & stream<element, unsigned char, characterizable, unit>::at(unsigned long index) {
        pokemon_develop_check(size <= position + index, exit(declaration::fail));

        return storage[position + index];
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline const element & stream<element, unsigned char, characterizable, unit>::operator[](unsigned long index) const {
        pokemon_develop_check(size <= position + index, exit(declaration::fail));

        return storage[position + index];
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline element & stream<element, unsigned char, characterizable, unit>::operator[](unsigned long index) {
        pokemon_develop_check(size <= position + index, exit(declaration::fail));

        return storage[position + index];
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline element * stream<element, unsigned char, characterizable, unit>::add(const element & item) {
        if (capacity < size + 1) storage = static_cast<element *>(allocator::regen(storage, capacity = stream<element, unsigned char, characterizable, unit>::capacityCal(size + 1, pageGet())));
        memorizer<element>::set(storage + size, item);
        size = size + 1;

        return storage + size - 1;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline element * stream<element, unsigned char, characterizable, unit>::add(element && item) {
        if (capacity < size + 1) storage = static_cast<element *>(allocator::regen(storage, capacity = stream<element, unsigned char, characterizable, unit>::capacityCal(size + 1, pageGet())));
        memorizer<element>::set(storage + size, std::move(item));
        size = size + 1;

        return storage + size - 1;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline element & stream<element, unsigned char, characterizable, unit>::del(element & item) {
        element * front = storage + position;
        for (unsigned long i = 0; i < size; i = i + 1) {
            if (item == front[i]) {
                if (position + i + 1 < size) memmove(front + i, front + i + 1, size - position - i - 1);
                size = size - 1;
                return item;
            }
        }
        return item;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline unsigned long stream<element, unsigned char, characterizable, unit>::pageGet(void) const {
        return declaration::eight;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline unsigned long stream<element, unsigned char, characterizable, unit>::sizeGet(void) const {
        return size;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline unsigned long stream<element, unsigned char, characterizable, unit>::capacityGet(void) const {
        return capacity;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline void stream<element, unsigned char, characterizable, unit>::clear(void) {
        storage = static_cast<element *>(allocator::rel(storage));
        position = declaration::zero;
        size = declaration::zero;
        capacity = declaration::zero;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline void stream<element, unsigned char, characterizable, unit>::clean(void) {
        position = declaration::zero;
        size = declaration::zero;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline void stream<element, unsigned char, characterizable, unit>::reset(void) {
        position = declaration::zero;
        size = declaration::zero;
    }

    // ReSharper disable once CppVirtualFunctionCallInsideCtor
    template <typename element, typename characterizable, unsigned long unit>
    inline stream<element, unsigned char, characterizable, unit>::stream(const element & item, unsigned long n) : size(n), capacity(stream<element, unsigned char, characterizable, unit>::capacityCal(n, pageGet())), position(declaration::zero) {
        storage = static_cast<element *>(allocator::gen(capacity * sizeof(element)));
        memorizer<element>::set(storage, item, n);
    }

    // ReSharper disable once CppVirtualFunctionCallInsideCtor
    template <typename element, typename characterizable, unsigned long unit>
    inline stream<element, unsigned char, characterizable, unit>::stream(const element * source, unsigned long sourceLen) : size(sourceLen), capacity(stream<element, unsigned char, characterizable, unit>::capacityCal(sourceLen, pageGet())), position(declaration::zero) {
        storage = static_cast<element *>(allocator::gen(capacity * sizeof(element)));
        memorizer<element>::set(storage, source, sourceLen);
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline stream<element, unsigned char, characterizable, unit>::stream(void) : size(declaration::zero), capacity(declaration::zero), storage(nullptr), position(declaration::zero) {

    }

    template <typename element, typename characterizable, unsigned long unit>
    inline stream<element, unsigned char, characterizable, unit>::~stream(void) {
        storage = static_cast<element *>(allocator::rel(storage));
        position = declaration::zero;
        size = declaration::zero;
        capacity = declaration::zero;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline stream<element, unsigned char, characterizable, unit>::stream(const stream<element, unsigned char, characterizable, unit> & o) : size(o.size - o.position), capacity(o.capacity), position(declaration::zero) {
        storage = static_cast<element *>(allocator::gen(capacity * sizeof(element)));
        memorizer<element>::set(storage, o.storage + o.position, size);
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline stream<element, unsigned char, characterizable, unit>::stream(stream<element, unsigned char, characterizable, unit> && o) noexcept : size(o.size), capacity(o.capacity), storage(o.storage), position(o.position) {
        o.position = declaration::zero;
        o.size = declaration::zero;
        o.capacity = declaration::zero;
        o.storage = nullptr;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline stream<element, unsigned char, characterizable, unit> & stream<element, unsigned char, characterizable, unit>::operator=(const stream<element, unsigned char, characterizable, unit> & o) {
        if (pointof(o) != this) {
            size = o.size - o.position;

            if (capacity < size) storage = static_cast<element *>(allocator::reset(storage, capacity = stream<element, unsigned char, characterizable, unit>::capacityCal(size, pageGet())));

            memorizer<element>::set(storage, o.storage + o.position, size);
            position = declaration::zero;
        }
        return *this;
    }

    template <typename element, typename characterizable, unsigned long unit>
    inline stream<element, unsigned char, characterizable, unit> & stream<element, unsigned char, characterizable, unit>::operator=(stream<element, unsigned char, characterizable, unit> && o) noexcept {
        if (pointof(o) != this) {
            storage = static_cast<element *>(allocator::rel(storage));

            storage = o.storage;
            size = o.size;
            position = o.position;
            capacity = o.capacity;

            o.position = declaration::zero;
            o.size = declaration::zero;
            o.capacity = declaration::zero;
            o.storage = nullptr;
        }
        return *this;
    }

}

#endif // __POKEMONISM_SDK_COLLECTION_STREAM_PRIMITIVABLE_HH__