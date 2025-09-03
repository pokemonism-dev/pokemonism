/**
 * @file            pokemonism/meowth/petilil.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_PETILIL_HH__
#define   __POKEMONISM_PETILIL_HH__

#include <pokemonism/command.hh>

namespace pokemonism {
    namespace meowth {
        class randomizer : public pokemonism::command<primitivable> {
        protected:  uint64 value;
        public:     virtual primitivable * operator()(void) override { return reinterpret_cast<primitivable *>(value != 0 ? value : random()); }
        public:     explicit randomizer(uint64 v) : value(v) {}
        public:     randomizer(void) : value(declaration::zero) {}
        public:     ~randomizer(void) override {}
        public:     randomizer(const randomizer & o) = delete;
        public:     randomizer(randomizer && o) noexcept = delete;
        public:     randomizer & operator=(const randomizer & o) = delete;
        public:     randomizer & operator=(randomizer && o) noexcept = delete;
        };
    }
}

#endif // __POKEMONISM_PETILIL_HH__