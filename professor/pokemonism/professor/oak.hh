/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_PROFESSOR_OAK_HH__
#define   __POKEMONISM_PROFESSOR_OAK_HH__

#include <pokemonism/faint.hh>
#include <pokemonism/professor.hh>
#include <pokemonism/toolizable.hh>

namespace pokemonism {
    namespace professors {

        class oak : public professor {
        public:     struct tools;
        public:     template <toolname toolizable = pokemonism::toolizable> static toolizable get(void);
        public:     template <toolname toolizable = pokemonism::toolizable> static toolizable * gen(void);
        public:     static const char * name(void){ return "oak"; }
        public:     oak(void) {}
        public:     ~oak(void) override {}
        public:     oak(const oak & o) = delete;
        public:     oak(oak && o) noexcept = delete;
        public:     oak & operator=(const oak & o) = delete;
        public:     oak & operator=(oak && o) noexcept = delete;
        };

        template <toolname toolizable>
        toolizable oak::get(void) { throw pokemonism::faint(); }

        template <toolname toolizable>
        toolizable * oak::gen(void) { throw pokemonism::faint(); }

        struct oak::tools {
        public:     class randomizer;
        };

        template <> inline oak::tools::randomizer oak::get<oak::tools::randomizer>();
        template <> inline oak::tools::randomizer * oak::gen<oak::tools::randomizer>();


    }
}

#include <pokemonism/professor/oak/tools/randomizer.hh>

#endif // __POKEMONISM_PROFESSOR_OAK_HH__