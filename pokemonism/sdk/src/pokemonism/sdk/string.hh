/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_SDK_STRING_HH__
#define   __POKEMONISM_SDK_STRING_HH__

#include <pokemonism/collection/string.hh>

namespace pokemonism {

    namespace sdk {

        class String : public pokemonism::collection::String {
        public:     String(void) {}
        public:     ~String(void) override {}
        public:     String(const String & o) {}
        public:     String(String && o) noexcept {}
        public:     String & operator=(const String & o) { return *this; }
        public:     String & operator=(String && o) noexcept { return *this; }
        };

    }

    using String = pokemonism::sdk::String;

}

#endif // __POKEMONISM_SDK_STRING_HH__
