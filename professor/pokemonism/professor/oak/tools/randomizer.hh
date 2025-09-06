/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_PROFESSOR_OAK_TOOLS_RANDOMIZER_RANDOMIZER_HH__
#define   __POKEMONISM_PROFESSOR_OAK_TOOLS_RANDOMIZER_RANDOMIZER_HH__

#include <pokemonism/professor/oak.hh>

#include <pokemonism/sdk/command.hh>

namespace pokemonism {
    namespace professors {

        class oak::tools::randomizer : public pokemonism::sdk::command, public pokemonism::toolizable {
        protected:  long v;
        public:     pokemonism::sdk::primitivable * operator()(void) override { return pokemonism::sdk::primitivable::from(v == 0 ? random() : v); }
        public:     inline void valueSet(long value) { v = value; }
        public:     inline explicit randomizer(long v) : v(v) {}
        public:     inline randomizer(void) : v(declaration::zero) {}
        public:     inline ~randomizer(void) override {}
        public:     randomizer(const oak::tools::randomizer & o) : v(o.v) {}
        public:     randomizer(oak::tools::randomizer && o) noexcept : v(o.v) { o.v = declaration::zero; }
        public:     oak::tools::randomizer & operator=(const oak::tools::randomizer & o) {
                        if (pointof(o) != this) v = o.v;
                        return *this;
                    }
        public:     oak::tools::randomizer & operator=(oak::tools::randomizer && o) noexcept {
                        if (pointof(o) != this) {
                            v = o.v;
                            o.v = declaration::zero;
                        }
                        return *this;
                    }
        };

        template <> inline oak::tools::randomizer oak::get<oak::tools::randomizer>() { return oak::tools::randomizer(); }
        template <> inline oak::tools::randomizer * oak::gen<oak::tools::randomizer>() { return new oak::tools::randomizer(); }

    }
}

#endif // __POKEMONISM_PROFESSOR_OAK_TOOLS_RANDOMIZER_RANDOMIZER_HH__