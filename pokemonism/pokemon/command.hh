/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_COMMAND_HH__
#define   __POKEMONISM_COMMAND_HH__

#include <pokemonism/primitivable.hh>

namespace pokemonism {
    namespace pokemon {

        class command {
        public:     virtual primitivable::object * operator()(void) = 0;
        public:     command(void) {}
        public:     virtual ~command(void) {}
        public:     command(const command & o) = delete;
        public:     command(command && o) noexcept = delete;
        public:     command & operator=(const command & o) = delete;
        public:     command & operator=(command && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_COMMAND_HH__