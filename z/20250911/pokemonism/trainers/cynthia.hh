/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_TRAINERS_CYNTHIA_HH__
#define   __POKEMONISM_TRAINERS_CYNTHIA_HH__

#include <pokemonism/faint.hh>
#include <pokemonism/trainer.hh>
#include <pokemonism/pokemon.hh>

namespace pokemonism {
    namespace trainers {

        class cynthia : public trainer {
        public:     constexpr static const char * name = "cynthia";
        public:     template <typename monsterizable = pokemon> static monsterizable * gotcha(void) { return new monsterizable(); }
        public:     template <typename monsterizable = pokemon> static int recall(monsterizable * monster) {
                        pokemon_training_check(monster == nullptr, return battle::result::unknown);
                        const int ret = monster->resultGet();
                        delete monster;
                        return ret;
                    }
        public:     cynthia(void) {}
        public:     ~cynthia(void) override {}
        public:     cynthia(const cynthia & o) = delete;
        public:     cynthia(cynthia && o) noexcept = delete;
        public:     cynthia & operator=(const cynthia & o) = delete;
        public:     cynthia & operator=(cynthia && o) noexcept = delete;
        };

    }
}

#endif // __POKEMONISM_TRAINERS_CYNTHIA_HH__