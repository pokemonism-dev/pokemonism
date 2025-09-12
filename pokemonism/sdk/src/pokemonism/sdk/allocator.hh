/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_SDK_ALLOCATOR_HH__
#define   __POKEMONISM_SDK_ALLOCATOR_HH__

#include <pokemonism.hh>

namespace pokemonism {

    namespace sdk {

        class Allocator {
        public:     static inline void * gen(unsigned long n);
        public:     static inline void * gen(void * origin, unsigned long n);
        public:     static inline void * reset(void * origin, unsigned long n);
        public:     static inline void * rel(void * n);
        public:     template <typename Type> static inline Type * del(Type * o);
        public:     template <typename Type> static inline Type * del(Type * o, unsigned long n);
        public:     inline Allocator(void);
        public:     inline virtual ~Allocator(void);
        public:     Allocator(const Allocator & o) = delete;
        public:     Allocator(Allocator && o) noexcept = delete;
        public:     Allocator & operator=(const Allocator & o) = delete;
        public:     Allocator & operator=(Allocator && o) noexcept = delete;
        };

        inline void * Allocator::gen(unsigned long n) {
            return n > 0 ? malloc(n) : nullptr;
        }

        inline void * Allocator::gen(void * origin, unsigned long n) {
            if (n == 0) {
                if (origin) free(origin);
                return nullptr;
            }

            return origin != nullptr ? realloc(origin, n) : malloc(n);
        }

        inline void * Allocator::reset(void * origin, unsigned long n) {
            if (origin) free(origin);

            return n > 0 ? malloc(n) : nullptr;
        }

        inline void * Allocator::rel(void * origin) {
            if (origin) free(origin);

            return nullptr;
        }

        template <typename Type>
        inline Type * Allocator::del(Type * o) {
            if (o != nullptr) delete o;
            return nullptr;
        }

        template <typename Type>
        inline Type * Allocator::del(Type * o, unsigned long n) {
            if (o != nullptr) delete[] o;
            return nullptr;
        }

        inline Allocator::Allocator(void) {

        }

        inline Allocator::~Allocator(void) {

        }
    }

    using Allocator = pokemonism::sdk::Allocator;

}

#endif // __POKEMONISM_SDK_ALLOCATOR_HH__