/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 14, 2025
 */

#ifndef   __POKEMONISM_COLLECTION_STREAM_HH__
#define   __POKEMONISM_COLLECTION_STREAM_HH__

#include <pokemonism/streamable.hh>
#include <pokemonism/collection/continuous.hh>

namespace pokemonism::collection {

    template <class element, class super = streamable<element, continuous<element>>, unsigned long unit = sizeof(element), typename characterable = void, typename primitivable = void>
    class stream : public super {
    protected:  using memorizer = pokemonism::sdk::memorizer<element, primitivable, unit>;
    protected:  using allocator = pokemonism::sdk::allocator;
    protected:  unsigned long position;
    public:     inline void set(const element & item, unsigned long n) override;
    public:     inline void set(const element * source, unsigned long sourceLen) override;
    public:     inline void cat(const element & item, unsigned long n) override;
    public:     inline void cat(const element * source, unsigned long sourceLen) override;
    public:     inline void add(const element & item) override;
    public:     inline void add(element && item) override;
    public:     inline void del(element & item) override;
    public:     inline void clear(void) override;
    public:     inline stream(void);
    public:     inline ~stream(void) override;
    public:     inline stream(const stream<element, super, unit, characterable, primitivable> & o);
    public:     inline stream(stream<element, super, unit, characterable, primitivable> && o) noexcept;
    public:     inline stream<element, super, unit, characterable, primitivable> & operator=(const stream<element, super, unit, characterable, primitivable> & o);
    public:     inline stream<element, super, unit, characterable, primitivable> & operator=(stream<element, super, unit, characterable, primitivable> && o) noexcept;
    };

    template <class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline void stream<element, super, unit, characterable, primitivable>::set(const element & item, unsigned long n) {
        if (this->size - this->position > 0) memorizer::del(this->storage + this->position, this->size - this->position);
        if (this->capacity < n) this->storage = allocator::reset(this->storage, this->capacity = this->capacityCal(n));

        this->position = 0;
        this->size = n;
        if (n > 0) memorizer::set(this->storage, item, n);
    }

    template <class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline void stream<element, super, unit, characterable, primitivable>::set(const element * source, unsigned long sourceLen) {
        if (this->size - this->position > 0) memorizer::del(this->storage + this->position, this->size - this->position);
        if (this->capacity < sourceLen) this->storage = allocator::reset(this->storage, this->capacity = this->capacityCal(sourceLen));

        this->position = 0;
        this->size = sourceLen;
        if (sourceLen > 0) memorizer::set(this->storage, source, sourceLen);
    }

    template <class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline void stream<element, super, unit, characterable, primitivable>::cat(const element & item, unsigned long n) {
        if (this->capacity < this->size + n) this->storage = allocator::gen(this->storage, this->capacity = this->capacityCal(this->size + n));

        memorizer::set(this->storage + this->size, item, n);
        this->size = this->size + n;
    }

    template <class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline void stream<element, super, unit, characterable, primitivable>::cat(const element * source, unsigned long sourceLen) {
        if (this->capacity < this->size + sourceLen) this->storage = allocator::gen(this->storage, this->capacity = this->capacityCal(this->size + sourceLen));

        memorizer::set(this->storage + this->size, source, sourceLen);
        this->size = this->size + sourceLen;
    }

    template <class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline void stream<element, super, unit, characterable, primitivable>::add(const element & item) {
        if (this->capacity <= this->size) this->storage = allocator::gen(this->storage, this->capacity = this->capacityCal(this->size + 1));
        memorizer::set(this->storage + this->size, item);
        this->size = this->size + 1;
    }

    template <class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline void stream<element, super, unit, characterable, primitivable>::add(element && item) {
        if (this->capacity <= this->size) this->storage = allocator::gen(this->storage, this->capacity = this->capacityCal(this->size + 1));
        memorizer::set(this->storage + this->size, std::move(item));
        this->size = this->size + 1;
    }

    template <class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline void stream<element, super, unit, characterable, primitivable>::del(element & item) {
        for (unsigned int i = position; i < this->size; i = i + 1) {
            if (item == this->storage[i]) {
                memorizer::del(this->storage + i);
                if (this->size - i - 1 > 0) ::memmove(this->storage + i, this->storage + i + 1, (this->size - i - 1) * unit);
                this->size = this->size - 1;
                return;
            }
        }
    }

    template <class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline void stream<element, super, unit, characterable, primitivable>::clear(void) {
        if (this->size - this->position > declaration::zero) memorizer::del(this->storage, this->size - this->position);
        this->storage = allocator::rel(this->storage);
        this->capacity = declaration::zero;
        this->size = declaration::zero;
        this->position = declaration::zero;
    }

    template <class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline stream<element, super, unit, characterable, primitivable>::stream(void) : position(declaration::zero) {

    }

    template <class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline stream<element, super, unit, characterable, primitivable>::~stream(void) {
        if (this->size - position > 0) memorizer::del(this->storage + position, this->size - position);
        this->storage = allocator::rel(this->storage);
        this->capacity = declaration::zero;
        this->size = declaration::zero;
        this->position = declaration::zero;
    }

    template <class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline stream<element, super, unit, characterable, primitivable>::stream(const stream<element, super, unit, characterable, primitivable> & o) : position(o.position) {
        this->size = o.size;

        if (o.capacity > 0) this->storage = allocator::gen<element>(this->capacity = o.capacity);
        if (o.size > 0) memorizer::set(this->storage + position, o.storage + position, this->size - position);
    }

    template <class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline stream<element, super, unit, characterable, primitivable>::stream(stream<element, super, unit, characterable, primitivable> && o) noexcept : super(std::move(o)), position(o.position) {
        o.position = declaration::zero;
    }

    template <class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline stream<element, super, unit, characterable, primitivable> & stream<element, super, unit, characterable, primitivable>::operator=(const stream<element, super, unit, characterable, primitivable> & o) {
        if (pointof(o) != this) {
            memorizer::del(this->storage + position, this->size - position);

            this->size = o.size;
            this->position = o.position;

            if (this->capacity < o.capacity) this->storage = allocator::reset<element>(this->storage, this->capacity = o.capacity);
            if (o.size - o.position > 0) memorizer::set(this->storage + this->position, o.size - o.position);
        }

        return *this;
    }

    template <class element, class super, unsigned long unit, typename characterable, typename primitivable>
    inline stream<element, super, unit, characterable, primitivable> & stream<element, super, unit, characterable, primitivable>::operator=(stream<element, super, unit, characterable, primitivable> && o) noexcept {
        if (pointof(o) != this) {
            memorizer::del(this->storage + this->position, this->size - this->position);
            allocator::rel(this->storage);

            this->storage = o.storage;
            this->position = o.position;
            this->capacity = o.capacity;
            this->size = o.size;

            o.storage = nullptr;
            o.position = declaration::zero;
            o.capacity = declaration::zero;
            o.size = declaration::zero;
        }

        return *this;
    }

}

#endif // __POKEMONISM_COLLECTION_STREAM_HH__