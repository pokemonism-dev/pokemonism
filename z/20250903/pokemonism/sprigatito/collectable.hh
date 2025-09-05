/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_SPRIGATITO_COLLECTABLE_HH__
#define   __POKEMONISM_SPRIGATITO_COLLECTABLE_HH__

namespace pokemonism {
    namespace sprigatito {

        class collectable {
        public:     collectable(void) {}
        public:     virtual ~collectable(void) {}
        public:     collectable(const collectable & o) = delete;
        public:     collectable(collectable && o) noexcept = delete;
        public:     collectable & operator=(const collectable & o) = delete;
        public:     collectable & operator=(collectable && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_SPRIGATITO_COLLECTABLE_HH__
