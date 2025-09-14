/**
 * @file
 * @brief
 * @details
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_SDK_STREAM_HH__
#define   __POKEMONISM_SDK_STREAM_HH__

#include <pokemonism.hh>

namespace pokemonism {

    namespace sdk {

        class stream {
        public:     stream(void) {}
        public:     virtual ~stream(void) {}
        public:     stream(const stream & o) {}
        public:     stream(stream && o) noexcept {}
        public:     stream & operator=(const stream & o) { return *this; }
        public:     stream & operator=(stream && o) noexcept { return *this; }
        };

    }

    using stream = pokemonism::sdk::stream;

}

#endif // __POKEMONISM_SDK_STREAM_HH__
