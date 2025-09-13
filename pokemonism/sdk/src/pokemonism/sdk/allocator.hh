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
        public:     template <typename Element> static inline Element * gen(Element * destination, unsigned long n);
        public:     template <typename Element> static inline Element * reset(Element * destination, unsigned long n);
        public:     template <typename Element> static inline Element * rel(Element * destination);
        public:     template <typename Element> static inline Element * del(Element * o);
        public:     template <typename Element> static inline Element * del(Element * o, unsigned long n);
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
        inline Element * Allocator::gen(Element * destination, unsigned long n) {
            if (n == 0) {
                if (destination) free(destination);
                return nullptr;
            }

            return static_cast<Element *>(destination != nullptr ? realloc(destination, n * sizeof(Element)) : malloc(n * sizeof(Element)));
        }

        template <typename Element>
        inline Element * Allocator::reset(Element * destination, unsigned long n) {
            if (destination) free(destination);

            return static_cast<Element *>(n > 0 ? malloc(n * sizeof(Element)) : nullptr);
        }

        template <> inline void * Allocator::gen<void>(unsigned long n) {
            return n > 0 ? malloc(n) : nullptr;
        }

        template <> inline void * Allocator::gen<void>(void * destination, unsigned long n) {
            if (n == 0) {
                if (destination) free(destination);
                return nullptr;
            }

            return destination != nullptr ? realloc(destination, n) : malloc(n);
        }

        template <> inline void * Allocator::reset(void * destination, unsigned long n) {
            if (destination) free(destination);

            return n > 0 ? malloc(n) : nullptr;
        }

        template <> inline unsigned char * Allocator::gen<unsigned char>(unsigned long n) {
            return static_cast<unsigned char *>(n > 0 ? malloc(n) : nullptr);
        }

        template <> inline unsigned char * Allocator::gen(unsigned char * destination, unsigned long n) {
            if (n == 0) {
                if (destination) free(destination);
                return nullptr;
            }

            return static_cast<unsigned char *>(destination != nullptr ? realloc(destination, n) : malloc(n));
        }

        template <> inline unsigned char * Allocator::reset(unsigned char * destination, unsigned long n) {
            if (destination) free(destination);

            return static_cast<unsigned char *>(n > 0 ? malloc(n) : nullptr);
        }

        template <> inline char * Allocator::gen<char>(unsigned long n) {
            return static_cast<char *>(n > 0 ? malloc(n) : nullptr);
        }

        template <> inline char * Allocator::gen(char * destination, unsigned long n) {
            if (n == 0) {
                if (destination) free(destination);
                return nullptr;
            }

            return static_cast<char *>(destination != nullptr ? realloc(destination, n) : malloc(n));
        }

        template <> inline char * Allocator::reset(char * destination, unsigned long n) {
            if (destination) free(destination);

            return static_cast<char *>(n > 0 ? malloc(n) : nullptr);
        }

        template <typename Element>
        inline Element * Allocator::rel(Element * destination) {
            if (destination) free(destination);

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