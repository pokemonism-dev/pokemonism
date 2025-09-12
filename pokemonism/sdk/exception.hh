/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_SDK_EXCEPTION_HH__
#define   __POKEMONISM_SDK_EXCEPTION_HH__

#include <pokemonism.hh>

namespace pokemonism {

    namespace sdk {
        class Exception : public std::exception {
        public:     const char * what(void) const noexcept override { return "exception"; }
        public:     Exception(void) {}
        public:     ~Exception(void) override {}
        public:     Exception(const Exception & o) {}
        public:     Exception(Exception && o) noexcept {}
        public:     Exception & operator=(const Exception & o) { return *this; }
        public:     Exception & operator=(Exception && o) noexcept { return *this; }
        };
    }

    using Exception = pokemonism::sdk::Exception;

}

#endif // __POKEMONISM_SDK_EXCEPTION_HH__