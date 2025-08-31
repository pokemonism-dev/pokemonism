/**
 * @file        pokemonism/pokemon/allocator.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_ALLOCATOR__HH__
#define   __POKEMONISM_POKEMON_ALLOCATOR__HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace pokemon {

        class allocator {
        public:     static inline void * gen(uint64 n);
        public:     static inline void * rel(void * o);
        public:     static inline void * regen(void * o, uint64 n);
        public:     static inline void * reset(void * o, uint64 n);
        public:     template <typename type> static inline type * del(type * o);
        public:     template <typename type> static inline type * del(type * o, uint64 & n);
        public:     allocator(void) {}
        public:     virtual ~allocator(void) {}
        public:     allocator(const allocator & o) = delete;
        public:     allocator(allocator && o) noexcept = delete;
        public:     allocator & operator=(const allocator & o) = delete;
        public:     allocator & operator=(allocator && o) noexcept = delete;
        };

        inline void * allocator::gen(const uint64 n) {
            return n > 0 ? malloc(n) : nullptr;
        }

        inline void * allocator::rel(void * o) {
            if (o != nullptr) free(o);
            return nullptr;
        }

        inline void * allocator::regen(void * o, const uint64 n) {
            if (n == 0) {
                free(o);
                return nullptr;
            }
            return o != nullptr ? realloc(o, n) : malloc(n);
        }

        inline void * allocator::reset(void * o, const uint64 n) {
            if (o != nullptr) free(o);
            return n > 0 ? malloc(n) : nullptr;
        }

        template <typename type> inline type * allocator::del(type * o) {
            if (o != nullptr) delete o;
            return nullptr;
        }

        template <typename type> inline type * allocator::del(type * o, uint64 & n) {
            if (o != nullptr) delete[] o;
            n = 0;
            return nullptr;
        }
    }

    using allocator = pokemon::allocator;
}

#endif // __POKEMONISM_POKEMON_ALLOCATOR__HH__
