/**
 * @file            pokemonism/petilil.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_PETILIL_HH__
#define   __POKEMONISM_PETILIL_HH__

#include <pokemonism/pokemon.hh>

namespace pokemonism {
    class petilil : public pokemon {
    public:     petilil(void) {}
    public:     ~petilil(void) override {}
    public:     petilil(const petilil & o) = delete;
    public:     petilil(petilil && o) noexcept = delete;
    public:     petilil & operator=(const petilil & o) = delete;
    public:     petilil & operator=(petilil && o) noexcept = delete;
    };
}

#endif // __POKEMONISM_PETILIL_HH__