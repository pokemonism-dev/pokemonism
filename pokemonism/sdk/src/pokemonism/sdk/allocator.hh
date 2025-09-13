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
        public:     template <typename Element> static inline Element * gen(unsigned long n);
        public:     template <typename Element> static inline Element * gen(void * origin, unsigned long n);
        public:     template <typename Element> static inline Element * reset(void * origin, unsigned long n);
        public:     template <typename Element> static inline Element * rel(void * n);
        public:     template <typename Type> static inline Type * del(Type * o);
        public:     template <typename Type> static inline Type * del(Type * o, unsigned long n);
        public:     inline Allocator(void);
        public:     inline virtual ~Allocator(void);
        public:     Allocator(const Allocator & o) = delete;
        public:     Allocator(Allocator && o) noexcept = delete;
        public:     Allocator & operator=(const Allocator & o) = delete;
        public:     Allocator & operator=(Allocator && o) noexcept = delete;
        };

        template <typename Element>
        inline Element * Allocator::gen(unsigned long n) {
            return static_cast<Element *>(n > 0 ? malloc(n * sizeof(Element)) : nullptr);
        }

        template <typename Element>
        inline Element * Allocator::gen(void * origin, unsigned long n) {
            if (n == 0) {
                if (origin) free(origin);
                return nullptr;
            }

            return static_cast<Element *>(origin != nullptr ? realloc(origin, n * sizeof(Element)) : malloc(n * sizeof(Element)));
        }

        template <typename Element>
        inline Element * Allocator::reset(void * origin, unsigned long n) {
            if (origin) free(origin);

            return static_cast<Element *>(n > 0 ? malloc(n * sizeof(Element)) : nullptr);
        }

        template <typename Element>
        inline Element * Allocator::rel(void * origin) {
            if (origin) free(origin);

            return nullptr;
        }

        template <typename Element>
        inline Element * Allocator::del(Element * o) {
            if (o != nullptr) delete o;
            return nullptr;
        }

        template <typename Element>
        inline Element * Allocator::del(Element * o, unsigned long n) {
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