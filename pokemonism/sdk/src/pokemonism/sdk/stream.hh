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

        class Stream {
        public:     Stream(void) {}
        public:     virtual ~Stream(void) {}
        public:     Stream(const Stream & o) {}
        public:     Stream(Stream && o) noexcept {}
        public:     Stream & operator=(const Stream & o) { return *this; }
        public:     Stream & operator=(Stream && o) noexcept { return *this; }
        };

    }

    using Stream = pokemonism::sdk::Stream;

}

#endif // __POKEMONISM_SDK_STREAM_HH__
