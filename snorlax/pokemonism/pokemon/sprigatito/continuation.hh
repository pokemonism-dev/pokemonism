/**
 * @file        pokemon/sprigatito/continuation.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 26, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SPRIGATITO_CONTINUATION__HH__
#define   __POKEMONISM_POKEMON_SPRIGATITO_CONTINUATION__HH__

#include <pokemon/memorizer.hh>
#include <pokemon/typographer.hh>
#include <pokemon/sprigatito/continuable.hh>

namespace pokemon { namespace sprigatito {

    template <typename element_type, typename primitive_tag = typographer<element_type>::primitive, typename character_tag = typographer<element_type>::character, uint64 unit = typographer<element_type>::width>
    class continuation : public virtual sprigatito::continuable<element_type> {
    public:     typedef element_type        element;
    public:     typedef primitive_tag       primitive;
    public:     typedef character_tag       character;
    public:     constexpr static uint64     width = unit;
    public:     using                       memorizer = memorizer<element>;
    protected:  uint64                      capa;
    protected:  element *                   storage;
    public:     uint64                      len;
    /** sprigatito::capable<element> */
    public:     inline uint64 capacity(void) const override;
    public:     inline uint64 maximum(void) const override;
    /** sprigatito::collectable<element> */
    public:     inline uint64 size(void) const override;
    public:     inline uint64 length(void) const override;
    public:     inline bool empty(void) const override;
    public:     inline bool add(const element & item) override;
    public:     inline bool add(element && item) override;
    public:     inline uint64 add(const element & item, uint64 n) override;
    public:     inline uint64 add(element && item, uint64 n) override;
    public:     inline uint64 add(const element * source, uint64 n) override;
    public:     inline void clear(void) override;
    public:     inline void clean(void) override;
    public:     inline void reset(void) override;
    /** sprigatito::sequenceable<element> */
    public:     inline const element & at(uint64 index) const override;
    public:     inline element & at(uint64 index) override;
    public:     inline const element & operator[](uint64 index) const override;
    public:     inline element & operator[](uint64 index) override;
    /** sprigatito::continuable<element> */
    public:     inline void set(const element & item, uint64 n) override;
    public:     inline void set(element && item, uint64 n) override;
    public:     inline void set(const element * source, uint64 n) override;
    public:     inline virtual void set(const continuation<element, primitive, character, unit> & o);
    public:     inline virtual void set(continuation<element, primitive, character, unit> && o);
    public:     inline void cat(const element & item, uint64 n) override;
    public:     inline void cat(element && item, uint64 n) override;
    public:     inline void cat(const element * source, uint64 n) override;
    public:     inline virtual void cat(const continuation<element, primitive, character, unit> & o);
    public:     inline virtual void cat(continuation<element, primitive, character, unit> && o);
    public:     inline void put(uint64 offset, const element & item, uint64 n) override;
    public:     inline void put(uint64 offset, element && item, uint64 n) override;
    public:     inline void put(uint64 offset, const element * source, uint64 n) override;
    public:     inline virtual void put(uint64 offset, const continuation<element, primitive, character, unit> & o);
    public:     inline virtual void put(uint64 offset, continuation<element, primitive, character, unit> && o);
    public:     inline void cut(uint64 offset) override;
    public:     inline void pop(uint64 length) override;
    public:     inline void rem(uint64 offset, uint64 length) override;
    public:     inline void mod(uint64 offset, uint64 length, const element & item, uint64 n) override;
    public:     inline void mod(uint64 offset, uint64 length, element && item, uint64 n) override;
    public:     inline void mod(uint64 offset, uint64 length, const element * source, uint64 n) override;
    public:     inline virtual void mod(uint64 offset, uint64 length, const continuation<element, primitive, character, unit> & o);
    public:     inline virtual void mod(uint64 offset, uint64 length, continuation<element, primitive, character, unit> && o);
    public:     inline void shrink(void) override;
    /** sprigatito::continuation<element, primitive, character, unit> */
    public:     inline virtual continuation<element, primitive, character, unit> & operator+=(const continuation<element, primitive, character, unit> & o);
    public:     inline virtual continuation<element, primitive, character, unit> & operator+=(continuation<element, primitive, character, unit> && o);
    public:     inline virtual continuation<element, primitive, character, unit> & operator+=(const element & o);
    public:     inline virtual continuation<element, primitive, character, unit> & operator+=(element && o);
    public:     inline explicit continuation(const element & item);
    public:     inline explicit continuation(element && item);
    public:     inline explicit continuation(const element & item, uint64 n);
    public:     inline explicit continuation(element && item, uint64 n);
    public:     inline explicit continuation(const element * source, uint64 n);
    public:     inline continuation(void);
    public:     inline ~continuation(void) override;
    public:     inline continuation(const continuation<element, primitive, character, unit> & o);
    public:     inline continuation(continuation<element, primitive, character, unit> && o) noexcept;
    public:     inline continuation<element, primitive, character, unit> & operator=(const continuation<element, primitive, character, unit> & o);
    public:     inline continuation<element, primitive, character, unit> & operator=(continuation<element, primitive, character, unit> && o) noexcept;
    /** std::iostream */
    public:     inline friend std::ostream & operator<<(std::ostream & stream, const continuation<element, primitive, character, unit> & o) {
                    stream << "address: " << static_cast<void *>(o.storage) << ", "
                   << "size: " << o.len << ", "
                   << "capacity: " << o.capa;
                    return stream;
                }
    };

    template<typename element, typename primitive, typename character, uint64 unit>
    continuation<element, primitive, character, unit>::continuation() : capa(0), storage(nullptr), len(0) {

    }

    template<typename element, typename primitive, typename character, uint64 unit>
    continuation<element, primitive, character, unit>::~continuation() {
        memorizer::rem(storage, len);
        storage = memorizer::rel(storage);
        capa = 0;
        len = 0;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    continuation<element, primitive, character, unit>::continuation(const continuation<element, primitive, character, unit> & o) : capa(o.capa), storage(nullptr), len(o.len) {
        storage = memorizer::gen(capa);
        if (storage != nullptr && o.len > 0) storage = memorizer::set(storage, o.storage, o.len);
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    continuation<element, primitive, character, unit>::continuation(continuation<element, primitive, character, unit> && o) noexcept : capa(o.capa), storage(o.storage), len(o.len) {
        o.capa = 0;
        o.storage = nullptr;
        o.len = 0;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    continuation<element, primitive, character, unit> & continuation<element, primitive, character, unit>::operator=(const continuation<element, primitive, character, unit> & o) {
        if (pointof(o) != this) {
            memorizer::rem(storage, len);
            storage = memorizer::rel(storage);
            capa = o.capa;
            len = o.len;

            storage = memorizer::gen(capa);
            if (storage != nullptr && o.len > 0) storage = memorizer::set(storage, o.storage, o.len);
        }
        return *this;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    continuation<element, primitive, character, unit> & continuation<element, primitive, character, unit>::operator=(continuation<element, primitive, character, unit> && o) noexcept {
        if (pointof(o) != this) {
            memorizer::rem(storage, len);
            storage = memorizer::rel(storage);

            capa = o.capa;
            len = o.len;
            storage = o.storage;

            o.capa = 0;
            o.storage = nullptr;
            o.len = 0;
        }
        return *this;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    continuation<element, primitive, character, unit>::continuation(const element & item) : capa(continuation::capacityCal(1)), storage(nullptr), len(1) {
        storage = memorizer::gen(capa);
        memorizer::set(storage, item);
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    continuation<element, primitive, character, unit>::continuation(element && item) : capa(continuation::capacityCal(1)), storage(nullptr), len(1) {
        storage = memorizer::gen(capa);
        memorizer::set(storage, std::move(item));
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    continuation<element, primitive, character, unit>::continuation(const element & item, const uint64 n) : capa(continuation::capacityCal(n)), storage(nullptr), len(n) {
        storage = memorizer::gen(capa);
        memorizer::set(storage, item);
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    continuation<element, primitive, character, unit>::continuation(element && item, const uint64 n) : capa(continuation::capacityCal(n)), storage(nullptr), len(n) {
        storage = memorizer::gen(capa);
        memorizer::set(storage, std::move(item));
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    continuation<element, primitive, character, unit>::continuation(const element * source, uint64 n) : capa(continuation::capacityCal(n)), storage(nullptr), len(n) {
        storage = memorizer::gen(capa);
        memorizer::set(storage, source, n);
    }

    /** sprigatito::capable<element> */
    template<typename element, typename primitive, typename character, uint64 unit>
    uint64 continuation<element, primitive, character, unit>::capacity(void) const {
        return capa;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    uint64 continuation<element, primitive, character, unit>::maximum(void) const {
        return -1;
    }

    /** sprigatito::continuable<element> */

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::set(const element & item, uint64 n) {
        memorizer::rem(storage, len);
        if (const uint64 capacity = continuation::capacityCal(n); capacity != capa) storage = memorizer::reset(storage, capa = capacity);
        if ((len = n) > 0) memorizer::set(storage, item, len);
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::set(element && item, uint64 n) {
        memorizer::rem(storage, len);
        if (const uint64 capacity = continuation::capacityCal(n); capacity != capa) storage = memorizer::reset(storage, capa = capacity);
        if ((len = n) > 0) memorizer::set(storage, std::move(item), len);
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::set(const element * source, uint64 n) {
        memorizer::rem(storage, len);
        if (const uint64 capacity = continuation::capacityCal(n); capacity != capa) storage = memorizer::reset(storage, capa = capacity);
        if ((len = n) > 0) memorizer::set(storage, source, len);
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::cat(const element & item, uint64 n) {
        if (const uint64 capacity = continuation::capacityCal(len + n); capacity != capa) storage = memorizer::reset(storage, capa = capacity);
        if (n > 0) {
            memorizer::set(storage + len, item, n);
            len = len + n;
        }
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::cat(element && item, uint64 n) {
        if (const uint64 capacity = continuation::capacityCal(len + n); capacity != capa) storage = memorizer::reset(storage, capa = capacity);
        if (n > 0) {
            memorizer::set(storage + len, std::move(item), n);
            len = len + n;
        }
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::cat(const element * source, uint64 n) {
        if (const uint64 capacity = continuation::capacityCal(len + n); capacity != capa) storage = memorizer::reset(storage, capa = capacity);
        if (n > 0) {
            memorizer::set(storage + len, source, n);
            len = len + n;
        }
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::put(uint64 offset, const element & item, uint64 n) {
        critical_quick_throw_check(len < offset, exceptional::overflow::index, return);
        if (n > 0) {
            if (const uint64 capacity = continuation::capacityCal(len + n); capacity != capa) storage = memorizer::regen(storage, capa = capacity);
            if (const uint64 remain = len - offset; remain > 0) memorizer::mov(storage + offset + n, storage + offset, remain);
            memorizer::set(storage + offset, item, n);
            len = len + n;
        }
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::put(uint64 offset, element && item, uint64 n) {
        critical_quick_throw_check(len < offset, exceptional::overflow::index, return);
        if (n > 0) {
            if (const uint64 capacity = continuation::capacityCal(len + n); capacity != capa) storage = memorizer::regen(storage, capa = capacity);
            if (const uint64 remain = len - offset; remain > 0) memorizer::mov(storage + offset + n, storage + offset, remain);
            memorizer::set(storage + offset, std::move(item), n);
            len = len + n;
        }
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::put(uint64 offset, const element * source, uint64 n) {
        critical_quick_throw_check(len < offset, exceptional::overflow::index, return);
        if (n > 0) {
            if (const uint64 capacity = continuation::capacityCal(len + n); capacity != capa) storage = memorizer::regen(storage, capa = capacity);
            if (const uint64 remain = len - offset; remain > 0) memorizer::mov(storage + offset + n, storage + offset, remain);
            memorizer::set(storage + offset, source, n);
            len = len + n;
        }
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::cut(uint64 offset) {
        if (offset < len) offset = len;

        if (const uint64 length = len - offset; length > 0) {
            memorizer::rem(storage + offset, length);

            len = offset;

            if (const uint64 capacity = continuation::capacityCal(len); capacity != capa) storage = memorizer::regen(storage, capa = capacity);
        }
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::pop(uint64 length) {
        if (len < length) length = len;

        if (length > 0) {
            memorizer::rem(storage, length);
            len = len - length;

            if (len > 0) memorizer::mov(storage, storage + length, len);

            if (const uint64 capacity = continuation::capacityCal(len); capacity != capa) storage = memorizer::regen(storage, capa = capacity);
        }
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::rem(const uint64 offset, uint64 length) {
        critical_quick_throw_check(len < offset, exceptional::overflow::index, return);

        if (uint64 remain = len - offset; remain > 0) {
            if (remain < length) length = remain;
            remain = remain - length;

            if (length > 0) memorizer::rem(storage + offset, length);
            if (remain > 0) memorizer::mov(storage + offset, storage + offset + length, remain);

            len = len - length;

            if (const uint64 capacity = continuation::capacityCal(len); capacity != capa) storage = memorizer::regen(storage, capa = capacity);
        }
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::mod(uint64 offset, uint64 length, const element & item, uint64 n) {
        critical_quick_throw_check(len < offset, exceptional::overflow::index, return);

        if (uint64 remain = len - offset; remain > 0) {
            if (remain < length) length = remain;
            remain = remain - length;

            len = len + n - length;

            if (length > 0) memorizer::rem(storage + offset, length);
            if (length < n) if (const uint64 capacity = continuation::capacityCal(len); capacity != capa) storage = memorizer::regen(storage, capa = capacity);

            if (remain > 0) memorizer::mov(storage + offset + n, storage + offset + length, remain);
            if (n > 0) memorizer::set(storage + offset, item, n);

            if (length >= n) if (const uint64 capacity = continuation::capacityCal(len); capacity != capa) storage = memorizer::regen(storage, capa = capacity);
        }
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::mod(uint64 offset, uint64 length, element && item, uint64 n) {
        critical_quick_throw_check(len < offset, exceptional::overflow::index, return);

        if (uint64 remain = len - offset; remain > 0) {
            if (remain < length) length = remain;
            remain = remain - length;

            len = len + n - length;

            if (length > 0) memorizer::rem(storage + offset, length);
            if (length < n) if (const uint64 capacity = continuation::capacityCal(len); capacity != capa) storage = memorizer::regen(storage, capa = capacity);

            if (remain > 0) memorizer::mov(storage + offset + n, storage + offset + length, remain);
            if (n > 0) memorizer::set(storage + offset, std::move(item), n);

            if (length >= n) if (const uint64 capacity = continuation::capacityCal(len); capacity != capa) storage = memorizer::regen(storage, capa = capacity);
        }
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::mod(uint64 offset, uint64 length, const element * source, uint64 n) {
        critical_quick_throw_check(len < offset, exceptional::overflow::index, return);

        if (uint64 remain = len - offset; remain > 0) {
            if (remain < length) length = remain;
            remain = remain - length;

            len = len + n - length;

            if (length > 0) memorizer::rem(storage + offset, length);
            if (length < n) if (const uint64 capacity = continuation::capacityCal(len); capacity != capa) storage = memorizer::regen(storage, capa = capacity);

            if (remain > 0) memorizer::mov(storage + offset + n, storage + offset + length, remain);
            if (n > 0) memorizer::set(storage + offset, source, n);

            if (length >= n) if (const uint64 capacity = continuation::capacityCal(len); capacity != capa) storage = memorizer::regen(storage, capa = capacity);
        }
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::shrink(void) {
        if (capa != len) storage = memorizer::regen(storage, capa = len);
    }

    /** sprigatito::collectable<element> */

    template<typename element, typename primitive, typename character, uint64 unit>
    uint64 continuation<element, primitive, character, unit>::size(void) const {
        return len;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    uint64 continuation<element, primitive, character, unit>::length(void) const {
        return len;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    bool continuation<element, primitive, character, unit>::empty(void) const {
        return len == 0;
    }


    template<typename element, typename primitive, typename character, uint64 unit>
    bool continuation<element, primitive, character, unit>::add(const element & item) {
        cat(item, 1);
        return true;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    bool continuation<element, primitive, character, unit>::add(element && item) {
        cat(std::move(item), 1);
        return true;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    uint64 continuation<element, primitive, character, unit>::add(const element & item, const uint64 n) {
        cat(item, n);
        return n;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    uint64 continuation<element, primitive, character, unit>::add(element && item, uint64 n) {
        cat(std::move(item), n);
        return n;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    uint64 continuation<element, primitive, character, unit>::add(const element * source, const uint64 n) {
        cat(source, n);
        return n;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::clear(void) {
        memorizer::rem(storage, len);
        storage = memorizer::rel(storage, capa);
        capa = 0;
        len = 0;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::clean(void) {
        memorizer::rem(storage, len);
        len = 0;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::reset(void) {

    }

    /** sprigatito::sequenceable<element> */

    template<typename element, typename primitive, typename character, uint64 unit>
    const element & continuation<element, primitive, character, unit>::at(uint64 index) const {
        critical_quick_throw_check(len <= index, exceptional::overflow::index, (void)(0));

        return storage[index];
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    element & continuation<element, primitive, character, unit>::at(uint64 index) {
        critical_quick_throw_check(len <= index, exceptional::overflow::index, (void)(0));

        return storage[index];
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    const element & continuation<element, primitive, character, unit>::operator[](uint64 index) const {
        critical_quick_throw_check(len <= index, exceptional::overflow::index, (void)(0));

        return storage[index];
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    element & continuation<element, primitive, character, unit>::operator[](uint64 index) {
        critical_quick_throw_check(len <= index, exceptional::overflow::index, (void)(0));

        return storage[index];
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    continuation<element, primitive, character, unit> & continuation<element, primitive, character, unit>::operator+=(const continuation<element, primitive, character, unit> & o) {
        cat(o);
        return *this;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    continuation<element, primitive, character, unit> & continuation<element, primitive, character, unit>::operator+=(continuation<element, primitive, character, unit> && o) {
        cat(std::move(o));
        return *this;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    continuation<element, primitive, character, unit> & continuation<element, primitive, character, unit>::operator+=(const element & o) {
        cat(o, 1);
        return *this;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    continuation<element, primitive, character, unit> & continuation<element, primitive, character, unit>::operator+=(element && o) {
        cat(o, 1);
        return *this;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::set(const continuation<element, primitive, character, unit> & o) {
        clear();
        set(o.storage, o.len);
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::set(continuation<element, primitive, character, unit> && o) {
        clear();

        storage = o.storage;
        len = o.len;
        capa = o.capa;

        o.storage = nullptr;
        o.len = 0;
        o.capa = 0;
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::cat(const continuation<element, primitive, character, unit> & o) {
        cat(o.storage, o.len);
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::cat(continuation<element, primitive, character, unit> && o) {
        if (len == 0) {
            set(std::move(o));
        } else {
            cat(o.storage, o.len);
        }
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::put(const uint64 offset, const continuation<element, primitive, character, unit> & o) {
        put(offset, o.storage, o.len);
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::put(const uint64 offset, continuation<element, primitive, character, unit> && o) {
        if (len == 0 && offset == 0) {
            set(std::move(o));
        } else {
            put(offset, o.storage, o.len);
        }
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::mod(const uint64 offset, const uint64 length, const continuation<element, primitive, character, unit> & o) {
        mod(offset, length, o.storage, o.len);
    }

    template<typename element, typename primitive, typename character, uint64 unit>
    void continuation<element, primitive, character, unit>::mod(const uint64 offset, const uint64 length, continuation<element, primitive, character, unit> && o) {
        if (len == 0 && offset == 0) {
            set(std::move(o));
        } else if (offset == 0 && length == len) {
            set(std::move(o));
        } else {
            mod(offset, length, o.storage, o.len);
        }
    }

} }

#include <pokemon/sprigatito/continuation.template.unsigned.char.hh>

#endif // __POKEMONISM_POKEMON_SPRIGATITO_CONTINUATION__HH__
