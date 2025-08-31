/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_POKEMON_DESCRIPTOR_HH__
#define   __POKEMONISM_POKEMON_DESCRIPTOR_HH__

#include <pokemonism.hh>

namespace pokemonism {
    namespace pokemon {

        class descriptor {
        public:     descriptor(void) {}
        public:     virtual ~descriptor(void) {}
        public:     descriptor(const descriptor & o) = delete;
        public:     descriptor(descriptor && o) noexcept = delete;
        public:     descriptor & operator=(const descriptor & o) = delete;
        public:     descriptor & operator=(descriptor && o) noexcept = delete;
        };

    }

    using descriptor = pokemon::descriptor;
}

#endif // __POKEMONISM_POKEMON_DESCRIPTOR_HH__