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

#include <pokemonism/trainer.hh>
#include <pokemonism/monsterizable.hh>

namespace pokemonism {
    namespace pokemons {

        template <trainername trainerizable = trainer>
        class petilil : public monsterizable<trainerizable> {
        protected:  static petilil<trainerizable> * singleton;
        public:     const char * name(void) const noexcept override { return "petilil"; }
        public:     const char * cry(void) const noexcept override { return "chiri~ chiri~"; }
        public:     void heal(void) override {}
        public:     petilil<trainerizable> * fight(void) override { return this; }
        public:     int ready(void) override { return declaration::success; }
        public:     petilil<trainerizable> * go(void) override { return this; }
        protected:  petilil(void) {}
        protected:  ~petilil(void) override {}
        public:     petilil(const petilil<trainerizable> & o) = delete;
        public:     petilil(petilil<trainerizable> && o) noexcept = delete;
        public:     petilil<trainerizable> & operator=(const petilil<trainerizable> & o) = delete;
        public:     petilil<trainerizable> & operator=(petilil<trainerizable> && o) noexcept = delete;
        public:     friend trainerizable;
        public:     friend trainer;
        };

        template <trainername trainerizable>
        petilil<trainerizable> * petilil<trainerizable>::singleton = nullptr;

    }
}

#endif // __POKEMONISM_PETILIL_HH__