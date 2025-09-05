/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_PETILIL_HH__
#define   __POKEMONISM_PETILIL_HH__

#include <pokemonism/pokemon.hh>

namespace pokemonism {

    template <trainername trainer>
    class petilil : public pokemon {
    public:     const char * name(void) const noexcept override { return "petilil"; }
    public:     petilil(void) {}
    public:     ~petilil(void) override {}
    public:     petilil(const petilil<trainer> & o) = delete;
    public:     petilil(petilil<trainer> && o) noexcept = delete;
    public:     petilil<trainer> & operator=(const petilil<trainer> & o) = delete;
    public:     petilil<trainer> & operator=(petilil<trainer> && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_PETILIL_HH__