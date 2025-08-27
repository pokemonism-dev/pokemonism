/**
 * @file        pokemon/memorizer.template.unsigned.char.one.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_MEMORIZER_TEMPLATE_UNSIGNED_CHAR_ONE__HH__
#define   __POKEMONISM_POKEMON_MEMORIZER_TEMPLATE_UNSIGNED_CHAR_ONE__HH__

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemon/memorizer.hh>

namespace pokemon {

    // ReSharper disable once CppClassCanBeFinal
    template <typename object_type>
    class memorizer<object_type, unsigned char, 1> {
    public:     typedef object_type                                     element;
    public:     typedef unsigned char                                   primitive;
    public:     typedef element *                                       pointer;
    public:     typedef element &                                       reference;
    public:     struct immutable { typedef const element &              reference; };
    public:     struct right { struct value { typedef const element &&  reference; }; };
    // public:     constexpr static uint64                                 width = 1;       // TODO: UNCOMMENT
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
    public:     memorizer(const memorizer<element, primitive, 1> & o) = delete;
    public:     memorizer(memorizer<element, primitive, 1> && o) noexcept = delete;
    public:     memorizer<element, primitive, 1> & operator=(const memorizer<element, primitive, 1> & o) = delete;
    public:     memorizer<element, primitive, 1> & operator=(memorizer<element, primitive, 1> && o) noexcept = delete;
    };

    template <typename element>
    element * memorizer<element, unsigned char, 1>::gen(const uint64 n) {
        if (n > 0) return static_cast<element *>(malloc(n));

        return nullptr;
    }

    template <typename element>
    element * memorizer<element, unsigned char, 1>::regen(element * o, const uint64 n) {
        if (n == 0) {
            if (o != nullptr) free(o);

            return nullptr;
        }

        return static_cast<element *>(o != nullptr ? realloc(o, n) : malloc(n));
    }

    template <typename element>
    element * memorizer<element, unsigned char, 1>::reset(element * o, const uint64 n) {
        if (o != nullptr) free(o);
        if (n == 0) return nullptr;
        return static_cast<element *>(malloc(n));
    }

    template <typename element>
    element * memorizer<element, unsigned char, 1>::mov(element * o, const element * source, const uint64 n) {
        return static_cast<element *>(memmove(o, source, n));
    }

    template <typename element>
    element * memorizer<element, unsigned char, 1>::rel(element * o) {
        if (o != nullptr) free(o);

        return nullptr;
    }

    template <typename element>
    element * memorizer<element, unsigned char, 1>::rel(element * o, uint64 & n) {
        if (o != nullptr) free(o);
        n = 0;

        return nullptr;
    }

    template <typename element>
    element * memorizer<element, unsigned char, 1>::set(element * o, const uint64 n) {
        // develop_quick_throw(exceptional::should::notcall, return o + n);
        return o != nullptr ? o + n : o;
    }

    template <typename element>
    element * memorizer<element, unsigned char, 1>::set(element * o, const element * source, const uint64 n) {
        critical_quick_throw_check(o == nullptr, exceptional::nullpointer, return o);

        return static_cast<element *>(memcpy(o, source, n));
    }

    template <typename element>
    element * memorizer<element, unsigned char, 1>::set(element * o, typename immutable::reference item, const uint64 n) {
        critical_quick_throw_check(o == nullptr, exceptional::nullpointer, return o);

        if (n > 0) return static_cast<element *>(memset(o, item, n));

        return o;
    }

    template <typename element>
    element * memorizer<element, unsigned char, 1>::set(element * o, typename right::value::reference item, uint64 n) {
        critical_quick_throw_check(o == nullptr, exceptional::nullpointer, return o);

        if (n > 0) return static_cast<element *>(memset(o, item, n));

        return o;
    }

    template <typename element>
    element * memorizer<element, unsigned char, 1>::rem(element * o) {
        return o != nullptr ? o + 1 : o;
    }

    template <typename element>
    element * memorizer<element, unsigned char, 1>::rem(element * o, uint64 n) {
        return o != nullptr ? o + n : o;
    }

}

#endif // __POKEMONISM_POKEMON_MEMORIZER_TEMPLATE_UNSIGNED_CHAR_ONE__HH__
