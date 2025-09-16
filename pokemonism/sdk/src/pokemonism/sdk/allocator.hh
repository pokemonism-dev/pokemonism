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

#include <type_traits>
#include <cstring>

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
        public:     template <typename element> static inline element * clear(element * destination, unsigned long n);
        public:     template <typename element> static inline element * clear(element * destination);
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

        /**
         * @brief       객체 또는 배열의 메모를 0으로 빠르게 초기화합니다.
         * @details     C++의 `{}` 초기화보다 특정 컴파일러/라이브러리 환경(예를들어, gcc + glibc) 에서
         *              프로파일링 결과 더 빠른 성능을 보이는 `memset`을 의도적으로 사용합니다.
         *              이 함수는 POD(Plain Old Data) 또는 Trivial 타입에만 사용해야 합니다.
         *              컴파일러의 최적화가 발전하면, 이 함수의 내부 구현은 향후 C++ 스타일로 변경될 수 있습니다.
         *
         */
        template <typename element>
        inline element * allocator::clear(element * destination, unsigned long n) {
            static_assert(std::is_trivial_v<element>, "allocator::clear can only be used on trivial types.");

            if (destination != nullptr) memset(destination, declaration::zero, n * sizeof(element));

            return destination;
        }

        template <typename element>
        inline element * allocator::clear(element * destination) {
            static_assert(std::is_trivial_v<element>, "allocator::clear can only be used on trivial types.");

            if (destination != nullptr) memset(destination, declaration::zero, sizeof(element));

            return destination;
        }

        inline allocator::allocator(void) {

        }

        inline allocator::~allocator(void) {

        }
    }

    using allocator = pokemonism::sdk::allocator;

}

#endif // __POKEMONISM_SDK_ALLOCATOR_HH__