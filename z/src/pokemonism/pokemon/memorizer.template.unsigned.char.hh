/**
 * @file        pokemon/memorizer.template.unsigned.char.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_MEMORIZER_TEMPLATE_UNSIGNED_CHAR__HH__
#define   __POKEMONISM_POKEMON_MEMORIZER_TEMPLATE_UNSIGNED_CHAR__HH__

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemon/memorizer.hh>

namespace pokemon {

    // ReSharper disable once CppClassCanBeFinal
    template <typename object_type, uint64 unit>
    class memorizer<object_type, unsigned char, unit> {
    public:     typedef object_type                                     element;
    public:     typedef unsigned char                                   primitive;
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

    template <typename element, uint64 unit>
    element * memorizer<element, unsigned char, unit>::gen(const uint64 n) {
        if (n > 0) return static_cast<element *>(malloc(n * width));

        return nullptr;
    }

    template <typename element, uint64 unit>
    element * memorizer<element, unsigned char, unit>::regen(element * o, const uint64 n) {
        if (n == 0) {
            if (o != nullptr) free(o);

            return nullptr;
        }

        return static_cast<element *>(o != nullptr ? realloc(o, n * width) : malloc(n * width));
    }

    template <typename element, uint64 unit>
    element * memorizer<element, unsigned char, unit>::reset(element * o, const uint64 n) {
        if (o != nullptr) free(o);
        if (n == 0) return nullptr;
        return static_cast<element *>(malloc(n * width));
    }

    template <typename element, uint64 unit>
    element * memorizer<element, unsigned char, unit>::mov(element * o, const element * source, const uint64 n) {
        return static_cast<element *>(memmove(o, source, n * width));
    }

    template <typename element, uint64 unit>
    element * memorizer<element, unsigned char, unit>::rel(element * o) {
        if (o != nullptr) free(o);

        return nullptr;
    }

    template <typename element, uint64 unit>
    element * memorizer<element, unsigned char, unit>::rel(element * o, uint64 & n) {
        if (o != nullptr) free(o);
        n = 0;

        return nullptr;
    }

    template <typename element, uint64 unit>
    element * memorizer<element, unsigned char, unit>::set(element * o, const uint64 n) {
        // develop_quick_throw(exceptional::should::notcall, return o + n);
        return o != nullptr ? o + n : o;
    }

    template <typename element, uint64 unit>
    element * memorizer<element, unsigned char, unit>::set(element * o, const element * source, const uint64 n) {
        critical_quick_throw_check(o == nullptr, exceptional::nullpointer, return o);

        return static_cast<element *>(memcpy(o, source, n * width));
    }

    template <typename element, uint64 unit>
    element * memorizer<element, unsigned char, unit>::set(element * o, typename immutable::reference item, const uint64 n) {
        critical_quick_throw_check(o == nullptr, exceptional::nullpointer, return o);

        for (uint64 i = 0; i < n; i = i + 1) referenceof(o + i) = item;

        return o + n;
    }

    template <typename element, uint64 unit>
    element * memorizer<element, unsigned char, unit>::set(element * o, typename right::value::reference item, uint64 n) {
        critical_quick_throw_check(o == nullptr && n > 0, exceptional::nullpointer, return o);

        if (o == nullptr) return nullptr;

        for (uint64 i = 0; i < n; i = i + 1) referenceof(o + i) = item;

        return o + n;
    }

    template <typename element, uint64 unit>
    element * memorizer<element, unsigned char, unit>::rem(element * o) {
        develop_quick_throw(exceptional::should::notcall, return o != nullptr ? o + 1 : o);
    }

    template <typename element, uint64 unit>
    element * memorizer<element, unsigned char, unit>::rem(element * o, uint64 n) {
        develop_quick_throw(exceptional::should::notcall, return o != nullptr ? o + n : o);
    }

}

#endif // __POKEMONISM_POKEMON_MEMORIZER_TEMPLATE_UNSIGNED_CHAR__HH__
