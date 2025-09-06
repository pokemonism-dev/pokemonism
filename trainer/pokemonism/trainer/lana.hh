/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_TRAINER_LANA_HH__
#define   __POKEMONISM_TRAINER_LANA_HH__

#include <cstdio>

#include <pokemonism/trainer.hh>

namespace pokemonism {
    namespace trainers {
        class lana final : public trainer {
        protected:  static lana * character;
        public:     inline static lana * on(void);
        public:     inline const char * name(void) const noexcept override { return "lana"; }
        private:    inline lana(void) { }
        private:    inline ~lana(void) override {}
        public:     lana(const lana & o) = delete;
        public:     lana(lana && o) noexcept = delete;
        public:     lana & operator=(const lana & o) = delete;
        public:     lana & operator=(lana && o) noexcept = delete;
        };

        inline lana * lana::on(void) {
            if (character == nullptr) {
                static lana o;
                character = pointof(o);

                // ### IMPLEMENT | 20250905 | 개인 맞춤형 인사를 만들자. 수련(lana) 의 인사는 ?
                printf("%s: Hi, friend!\n", character->name());
            }
            return character;
        }
    }



}

#endif // __POKEMONISM_TRAINER_LANA_HH__