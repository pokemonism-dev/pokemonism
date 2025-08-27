/**
 * @file        pokemon/memorizer.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_MEMORIZER__HH__
#define   __POKEMONISM_POKEMON_MEMORIZER__HH__

#include <pokemonism.hh>

#include <pokemon/exception.hh>
#include <pokemon/typographer.hh>

namespace pokemon {

    // ReSharper disable once CppClassCanBeFinal
    template <typename object_type, typename primitive_type = typographer<object_type>::primitive, uint64 unit = typographer<object_type>::width>
    class memorizer {
    public:     typedef object_type                                     element;
    public:     typedef primitive_type                                  primitive;
    public:     typedef element *                                       pointer;
    public:     typedef element &                                       reference;
    public:     struct immutable { typedef const element &              reference; };
    public:     struct right { struct value { typedef const element &&  reference; }; };
    public:     constexpr static uint64                                 width = unit;
    public:     static inline element * gen(uint64 n);
    public:     static inline element * regen(element * o, uint64 n);
    public:     static inline element * reset(element * o, uint64 n);
    public:     static inline element * mov(element * o, const element * source, uint64 n);
    public:     static inline element * rel(element * o);
    public:     static inline element * rel(element * o, uint64 & n);
    public:     static inline element * set(element * o, uint64 n);
    public:     static inline element * set(element * o, const element * source, uint64 n);
    public:     static inline element * set(element * o, immutable::reference item, uint64 n);
    public:     static inline element * set(element * o, right::value::reference item, uint64 n);
    public:     static inline element * rem(element * o);
    public:     static inline element * rem(element * o, uint64 n);
    public:     memorizer(void) {}
    public:     virtual ~memorizer(void) {}
    public:     memorizer(const memorizer<element, primitive, unit> & o) = delete;
    public:     memorizer(memorizer<element, primitive, unit> && o) noexcept = delete;
    public:     memorizer<element, primitive, unit> & operator=(const memorizer<element, primitive, unit> & o) = delete;
    public:     memorizer<element, primitive, unit> & operator=(memorizer<element, primitive, unit> && o) noexcept = delete;
    };

    template <typename element, typename primitive, uint64 unit>
    element * memorizer<element, primitive, unit>::gen(const uint64 n) {
        if (n > 0) return static_cast<element *>(malloc(n * width));

        return nullptr;
    }

    template <typename element, typename primitive, uint64 unit>
    element * memorizer<element, primitive, unit>::regen(element * o, const uint64 n) {
        if (n == 0) {
            if (o != nullptr) free(o);

            return nullptr;
        }

        return static_cast<element *>(o != nullptr ? realloc(o, n * width) : malloc(n * width));
    }

    template <typename element, typename primitive, uint64 unit>
    element * memorizer<element, primitive, unit>::reset(element * o, const uint64 n) {
        if (o != nullptr) free(o);
        if (n == 0) return nullptr;
        return static_cast<element *>(malloc(n * width));
    }

    template <typename element, typename primitive, uint64 unit>
    element * memorizer<element, primitive, unit>::mov(element * o, const element * source, const uint64 n) {
        return static_cast<element *>(memmove(static_cast<void *>(o), static_cast<const void *>(source), n * width));
    }

    template <typename element, typename primitive, uint64 unit>
    element * memorizer<element, primitive, unit>::rel(element * o) {
        if (o != nullptr) free(o);

        return nullptr;
    }

    template <typename element, typename primitive, uint64 unit>
    element * memorizer<element, primitive, unit>::rel(element * o, uint64 & n) {
        if (o != nullptr) free(o);
        n = 0;

        return nullptr;
    }

    template <typename element, typename primitive, uint64 unit>
    element * memorizer<element, primitive, unit>::set(element * o, const uint64 n) {
        critical_quick_throw_check(o == nullptr, exceptional::nullpointer, return o);

        for (uint64 i = 0; i < n; i = i + 1) new (o + i) element();

        return o + n;
    }

    template <typename element, typename primitive, uint64 unit>
    element * memorizer<element, primitive, unit>::set(element * o, const element * source, uint64 n) {
        critical_quick_throw_check(o == nullptr, exceptional::nullpointer, return o);

        for (uint64 i = 0; i < n; i = i + 1) new (o + i) element(referenceof(source + i));

        return o + n;
    }

    template <typename element, typename primitive, uint64 unit>
    element * memorizer<element, primitive, unit>::set(element * o, typename immutable::reference item, const uint64 n) {
        critical_quick_throw_check(o == nullptr, exceptional::nullpointer, return o);

        for (uint64 i = 0; i < n; i = i + 1) new (o + i) element(item);

        return o + n;
    }

    template <typename element, typename primitive, uint64 unit>
    element * memorizer<element, primitive, unit>::set(element * o, typename right::value::reference item, uint64 n) {
        critical_quick_throw_check(o == nullptr, exceptional::nullpointer, return o);

        if (n > 0) {
            for (uint64 i = 0; i < n - 1; i = i + 1) new (o + i) element(item);
            new (o + n - 1) element(std::move(item));
        }

        return o + n;
    }

    template <typename element, typename primitive, uint64 unit>
    element * memorizer<element, primitive, unit>::rem(element * o) {
        critical_quick_throw_check(o == nullptr, exceptional::nullpointer, return o);

        o->~element();

        return o + 1;
    }

    template <typename element, typename primitive, uint64 unit>
    element * memorizer<element, primitive, unit>::rem(element * o, uint64 n) {
        critical_quick_throw_check(o == nullptr && n > 0, exceptional::nullpointer, return o);

        if (o != nullptr) {
            for (uint64 i = 0; i < n; i = i + 1) (o + i)->~element();
            return o + n;
        }

        return nullptr;
    }
}

#include <pokemon/memorizer.template.unsigned.char.hh>
#include <pokemon/memorizer.template.unsigned.char.one.hh>

#endif // __POKEMONISM_POKEMON_MEMORIZER__HH__
