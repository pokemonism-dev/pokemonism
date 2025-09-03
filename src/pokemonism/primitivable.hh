/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_PRIMITIVABLE_HH__
#define   __POKEMONISM_PRIMITIVABLE_HH__

#include <pokemonism.hh>

namespace pokemonism {

    struct primitivable {
    public:     primitivable(void) {}
    public:     ~primitivable(void) {}
    public:     primitivable(const primitivable & o) = delete;
    public:     primitivable(primitivable && o) noexcept = delete;
    public:     primitivable & operator=(const primitivable & o) = delete;
    public:     primitivable & operator=(primitivable && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_PRIMITIVABLE_HH__