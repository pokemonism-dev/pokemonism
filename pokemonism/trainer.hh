/**
 * @file
 * @brief
 * @details         소프트웨어에서 트레이너의 역할은 진화(기능이나 성능의 업그레이드를 돕는 서포터 역할을 수행한다.)
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep t, 2025
 */

#ifndef   __POKEMONISM_TRAINER_HH__
#define   __POKEMONISM_TRAINER_HH__

#include <pokemonism/trainerizable.hh>

#include <pokemonism/faint.hh>

namespace pokemonism {

    class pokemon;

    class trainer : public trainerizable {
    public:     template <pokemonname monster = pokemon> monster * capture(void);
    protected:  inline trainer(void) {}
    protected:  inline ~trainer(void) override {}
    public:     trainer(const trainer & o) = delete;
    public:     trainer(trainer && o) noexcept = delete;
    public:     trainer & operator=(const trainer & o) = delete;
    public:     trainer & operator=(trainer && o) noexcept = delete;
    public:     friend pokemon;
    };

    template <pokemonname monster>
    monster * trainer::capture(void) {
        if (monster::singleton == nullptr) {
            static monster o;

            monster::singleton = pointof(o);

            printf("%s: Hi, %s!\n", name(), monster::singleton->name());
        }

        return monster::singleton;
    }

}

#include <pokemonism/pokemon.hh>

#endif // __POKEMONISM_TRAINER_HH__