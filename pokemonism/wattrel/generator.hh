/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_WATTREL_GENERATOR_HH__
#define   __POKEMONISM_WATTREL_GENERATOR_HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace wattrel {
        class generator {
        public:     generator(void) {}
        public:     virtual ~generator(void) {}
        public:     generator(const generator & o) = delete;
        public:     generator(generator && o) noexcept = delete;
        public:     generator & operator=(const generator & o) = delete;
        public:     generator & operator=(generator && o) noexcept = delete;
        };
    }
}

#endif // __POKEMONISM_WATTREL_GENERATOR_HH__