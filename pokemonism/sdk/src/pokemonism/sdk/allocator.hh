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

        class allocator {
        public:     template <typename element> static inline element * gen(unsigned long n);
        public:     template <typename element> static inline element * gen(element * destination, unsigned long n);
        public:     template <typename element> static inline element * reset(element * destination, unsigned long n);
        public:     template <typename element> static inline element * rel(element * destination);
        public:     template <typename element> static inline element * del(element * o);
        public:     template <typename element> static inline element * del(element * o, unsigned long n);
        public:     inline allocator(void);
        public:     inline virtual ~allocator(void);
        public:     allocator(const allocator & o) = delete;
        public:     allocator(allocator && o) noexcept = delete;
        public:     allocator & operator=(const allocator & o) = delete;
        public:     allocator & operator=(allocator && o) noexcept = delete;
        };

        template <typename element>
        inline element * allocator::gen(unsigned long n) {
            return static_cast<element *>(n > 0 ? malloc(n * sizeof(element)) : nullptr);
        }

        template <typename element>
        inline element * allocator::gen(element * destination, unsigned long n) {
            if (n == 0) {
                if (destination) free(destination);
                return nullptr;
            }

            return static_cast<element *>(destination != nullptr ? realloc(destination, n * sizeof(element)) : malloc(n * sizeof(element)));
        }

        template <typename element>
        inline element * allocator::reset(element * destination, unsigned long n) {
            if (destination) free(destination);

            return static_cast<element *>(n > 0 ? malloc(n * sizeof(element)) : nullptr);
        }

        template <> inline void * allocator::gen<void>(unsigned long n) {
            return n > 0 ? malloc(n) : nullptr;
        }

        template <> inline void * allocator::gen<void>(void * destination, unsigned long n) {
            if (n == 0) {
                if (destination) free(destination);
                return nullptr;
            }

            return destination != nullptr ? realloc(destination, n) : malloc(n);
        }

        template <> inline void * allocator::reset(void * destination, unsigned long n) {
            if (destination) free(destination);

            return n > 0 ? malloc(n) : nullptr;
        }

        template <> inline unsigned char * allocator::gen<unsigned char>(unsigned long n) {
            return static_cast<unsigned char *>(n > 0 ? malloc(n) : nullptr);
        }

        template <> inline unsigned char * allocator::gen(unsigned char * destination, unsigned long n) {
            if (n == 0) {
                if (destination) free(destination);
                return nullptr;
            }

            return static_cast<unsigned char *>(destination != nullptr ? realloc(destination, n) : malloc(n));
        }

        template <> inline unsigned char * allocator::reset(unsigned char * destination, unsigned long n) {
            if (destination) free(destination);

            return static_cast<unsigned char *>(n > 0 ? malloc(n) : nullptr);
        }

        template <> inline char * allocator::gen<char>(unsigned long n) {
            return static_cast<char *>(n > 0 ? malloc(n) : nullptr);
        }

        template <> inline char * allocator::gen(char * destination, unsigned long n) {
            if (n == 0) {
                if (destination) free(destination);
                return nullptr;
            }

            return static_cast<char *>(destination != nullptr ? realloc(destination, n) : malloc(n));
        }

        template <> inline char * allocator::reset(char * destination, unsigned long n) {
            if (destination) free(destination);

            return static_cast<char *>(n > 0 ? malloc(n) : nullptr);
        }

        template <typename element>
        inline element * allocator::rel(element * destination) {
            if (destination) free(destination);

            return nullptr;
        }

        template <typename element>
        inline element * allocator::del(element * o) {
            if (o != nullptr) delete o;
            return nullptr;
        }

        template <typename element>
        inline element * allocator::del(element * o, unsigned long n) {
            if (o != nullptr) delete[] o;
            return nullptr;
        }

        inline allocator::allocator(void) {

        }

        inline allocator::~allocator(void) {

        }
    }

    using allocator = pokemonism::sdk::allocator;

}

#endif // __POKEMONISM_SDK_ALLOCATOR_HH__