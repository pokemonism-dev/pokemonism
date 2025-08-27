/**
 * @file        pokemon/allocator.void.tcc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 24, 2025
 */

#ifndef   __POKEMONISM_POKEMON_ALLOCATOR__VOID_TCC__
#define   __POKEMONISM_POKEMON_ALLOCATOR__VOID_TCC__

#include <pokemon/allocator.hh>
#include <pokemon/typographer.hh>
#include <pokemon/exception.hh>

namespace pokemon {
    template <> class allocator<void> {
    public:     typedef void                declaration_type;
    public:     typedef declaration_type *  pointer_type;
    public:     constexpr static uint64     width = sizeof(typographer<void>::width);
    public:     static inline declaration_type * gen(uint64 n);
    public:     static inline declaration_type * regen(pointer_type & original, uint64 n);
    public:     static inline declaration_type * regen(pointer_type & original, uint64 & original_capacity, uint64 n);
    public:     static inline declaration_type * reset(pointer_type & original, uint64 n);
    public:     static inline declaration_type * reset(pointer_type & original, uint64 & original_capacity, uint64 n);
    public:     static inline declaration_type * reset(pointer_type & original, uint64 n, pointer_type & place);
    public:     static inline declaration_type * reset(pointer_type & original, uint64 & original_capacity, uint64 n, pointer_type & place, uint64 & place_capacity);
    public:     static inline declaration_type * rel(pointer_type & o);
    public:     static inline declaration_type * rel(pointer_type & o, uint64 & original_capacity);
    public:     static inline declaration_type * rel(pointer_type & o, pointer_type & place);
    public:     static inline declaration_type * rel(pointer_type & o, uint64 & original_capacity, pointer_type & place, uint64 & place_capacity);
    public:     allocator(void) {}
    public:     virtual ~allocator(void) {}
    public:     allocator(const allocator<declaration_type> & o) = delete;
    public:     allocator(allocator<declaration_type> && o) noexcept = delete;
    public:     allocator<declaration_type> & operator=(const allocator<declaration_type> & o) = delete;
    public:     allocator<declaration_type> & operator=(allocator<declaration_type> && o) noexcept = delete;
    };

    allocator<void>::declaration_type * allocator<void>::gen(const uint64 n) {
        if (n == 0) return nil;

        declaration_type * o = static_cast<declaration_type *>(malloc(n * width));

        critical_quick_throw_check(o == nil, exceptional::nullpointer, return nil);

        return o;
    }

    allocator<void>::declaration_type * allocator<void>::regen(pointer_type & original, const uint64 n) {
        if (n == 0) {
            free(original);
            original = nil;
            return nil;
        }

        original = static_cast<declaration_type *>(original != nil ? realloc(original, n * width) : malloc(n * width));

        critical_quick_throw_check(original == nil, exceptional::nullpointer, return nil);

        return original;
    }

    allocator<void>::declaration_type * allocator<void>::regen(pointer_type & original, uint64 & original_capacity, const uint64 n) {
        if (n == 0) {
            free(original);
            original = nil;
            original_capacity = 0;
            return nil;
        }

        original = static_cast<declaration_type *>(original != nil ? realloc(original, n * width) : malloc(n * width));
        original_capacity = n;

        critical_quick_throw_check(original == nil, exceptional::nullpointer, original_capacity = 0; return nil);

        return original;
    }

    allocator<void>::declaration_type * allocator<void>::reset(pointer_type & original, const uint64 n) {
        if (original != nil) free(original);

        if (n > 0) {
            original = static_cast<declaration_type *>(malloc(n * width));

            critical_quick_throw_check(original == nil, exceptional::nullpointer, return nil);

            return original;
        }

        return original;
    }

    allocator<void>::declaration_type * allocator<void>::reset(pointer_type & original, uint64 & original_capacity, const uint64 n) {
        if (original != nil) free(original);

        if (n > 0) {
            original = static_cast<declaration_type *>(malloc(n * width));
            original_capacity = n;

            critical_quick_throw_check(original == nil, exceptional::nullpointer, original_capacity = 0; return nil);

            return original;
        }

        return original;
    }

    allocator<void>::declaration_type * allocator<void>::reset(pointer_type & original, const uint64 n, pointer_type & place) {
        if (place != nil) free(place);

        place = original;

        original = static_cast<declaration_type *>(n > 0 ? malloc(n * width) : nil);

        critical_quick_throw_check(n > 0 && original == nil, exceptional::nullpointer, (void)(0));

        return original;
    }

    allocator<void>::declaration_type * allocator<void>::reset(pointer_type & original, uint64 & original_capacity, const uint64 n, pointer_type & place, uint64 & place_capacity) {
        if (place != nil) free(place);

        place = original;
        place_capacity = original_capacity;

        original = static_cast<declaration_type *>(n > 0 ? malloc(n * width) : nil);
        original_capacity = n;

        critical_quick_throw_check(n > 0 && original == nil, exceptional::nullpointer, original_capacity = 0);

        return original;
    }

    allocator<void>::declaration_type * allocator<void>::rel(pointer_type & o) {
        if (o != nil) {
            free(o);
            o = nil;
        }

        return nil;
    }

    allocator<void>::declaration_type * allocator<void>::rel(pointer_type & o, uint64 & original_capacity) {
        if (o != nil) {
            free(o);
            o = nil;
        }
        original_capacity = 0;

        return nil;
    }

    allocator<void>::declaration_type * allocator<void>::rel(pointer_type & o, pointer_type & place) {
        if (place != nil) free(place);

        place = o;
        o = nil;

        return nil;
    }

    allocator<void>::declaration_type * allocator<void>::rel(pointer_type & o, uint64 & original_capacity, pointer_type & place, uint64 & place_capacity) {
        if (place != nil) free(place);

        place = o;
        place_capacity = original_capacity;

        o = nil;
        original_capacity = 0;

        return nil;
    }
}

#endif // __POKEMONISM_POKEMON_ALLOCATOR__VOID_TCC__
