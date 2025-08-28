/**
 * @file        pokemon/allocator.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 24, 2025
 */

#ifndef   __POKEMONISM_POKEMON_ALLOCATOR__HH__
#define   __POKEMONISM_POKEMON_ALLOCATOR__HH__

#include <pokemonism.hh>

#include <pokemon/typographer.hh>

namespace pokemon {
    template <typename element_type>
    class allocator {
    public:     typedef element_type        declaration_type;
    public:     typedef declaration_type *  pointer_type;
    public:     constexpr static uint64     width = sizeof(declaration_type);
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
}

#include <pokemon/allocator.tcc>
#include <pokemon/allocator.void.tcc>

#endif // __POKEMONISM_POKEMON_ALLOCATOR__HH__
