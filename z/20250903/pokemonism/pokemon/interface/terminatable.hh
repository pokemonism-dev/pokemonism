/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 01, 2025
 */

#ifndef   __POKEMONISM_TERMINATABLE_HH__
#define   __POKEMONISM_TERMINATABLE_HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace pokemon {
        namespace interface {

            template <int max, typename... argumentable>
            struct terminatable {
            public:     typedef void (*type)(argumentable...);
            public:     type func[max];
            public:     type basic;
            };

            template <typename... argumentable>
            struct terminator {
            public:     typedef void (*type)(argumentable...);
            public:     type terminate;
            public:     explicit terminator(type terminate) : terminate(terminate) {}
            public:     terminator<argumentable...> & operator=(const terminator<argumentable...> & o) {
                            terminate = o.terminate;
                            return *this;
                        }
            public:     terminator<argumentable...> & operator=(terminator<argumentable...> && o) noexcept {
                            terminate = o.terminate;
                            return *this;
                        }
            public:     terminator<argumentable...> & operator=(type f) noexcept {
                            terminate = f;
                            return *this;
                        }
            public:     terminator<argumentable...> & operator=(decltype(nullptr)) noexcept {
                            terminate = nullptr;
                            return *this;
                        }
            public:     terminator(const terminator<argumentable...> & o) { terminate = o.terminate; }
            public:     terminator(terminator<argumentable...> && o) noexcept { terminate = o.terminate; }
            public:     terminator(void) : terminate(nullptr) {}
            public:     explicit terminator(decltype(nullptr)) : terminate(nullptr) {}
            };

            template <typename... argumentable> inline bool operator==(terminator<argumentable...> & left, decltype(nullptr)) {
                return left.terminate == nullptr;
            }

            template <typename... argumentable> inline bool operator==(decltype(nullptr), terminator<argumentable...> & right) {
                return right.terminate == nullptr;
            }

            template <typename... argumentable> inline bool operator!=(terminator<argumentable...> & left, decltype(nullptr)) {
                return left.terminate == nullptr;
            }

            template <typename... argumentable> inline bool operator!=(decltype(nullptr), terminator<argumentable...> & right) {
                return right.terminate == nullptr;
            }

            template <int max, typename... argumentable> inline terminator<argumentable...> operator-(terminatable<max, argumentable...> & o, long n) {
                if (n < max) {
                    typename terminatable<max, argumentable...>::type f = o.func[n];

                    if (f != nullptr) return terminator<argumentable...>(f);
                }

                return terminator<argumentable...>(o.basic);
            }

        };
    }
}

#endif // __POKEMONISM_TERMINATABLE_HH__