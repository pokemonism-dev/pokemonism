/**
 * @file            pokemonism/pokemon/sync.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 02, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SYNC_HH__
#define   __POKEMONISM_POKEMON_SYNC_HH__

#include <pokemonism/pokemon/object.hh>

namespace pokemonism {
    namespace pokemon {

        class sync : public pokemon::object {
        public:     sync(void) {}
        public:     ~sync(void) override {}
        public:     sync(const pokemon::sync & o) = delete;
        public:     sync(pokemon::sync && o) noexcept = delete;
        public:     pokemon::sync & operator=(const pokemon::sync & o) = delete;
        public:     pokemon::sync & operator=(pokemon::sync && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_POKEMON_SYNC_HH__