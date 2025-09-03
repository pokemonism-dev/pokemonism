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

#include <pokemonism.hh>

namespace pokemonism {
    namespace petilil {

        class engine {
        public:     virtual petilil::engine * run(void) { return this; }
        public:     engine(void) {}
        public:     virtual ~engine(void) {}
        public:     engine(const petilil::engine & o) = delete;
        public:     engine(petilil::engine && o) noexcept = delete;
        public:     petilil::engine & operator=(const petilil::engine & o) = delete;
        public:     petilil::engine & operator=(petilil::engine && o) noexcept = delete;
        };

        template <itemname item = void>
        petilil::engine * evolve(void) {
            return new petilil::engine();
        }
    }
}

#endif // __POKEMONISM_PETILIL_HH__