/**
 * @file            pokemonism/pokemon/trainer.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 5, 2025
 */

#ifndef   __POKEMONISM_POKEMON_TRAINER_HH__
#define   __POKEMONISM_POKEMON_TRAINER_HH__

#include <pokemonism/pokemon.hh>

namespace pokemonism {

    class pokemon::trainer : public sync {
    public:     template <trainername trainer> static trainer * go(void);
    public:     template <pokemonname monster> static monster * capture(void) {
                    return nullptr;
                }
    public:     template <pokemonname monster> static monster * choose(void);
    // public:     template <trainername name> name & get(void);
    // public:     virtual void capture_(pokemon * mon) = 0;
    // public:     virtual pokemon * evolve_(pokemon * mon) = 0;
    // public:     virtual pokemon * evolve_(pokemon * mon, item * item) = 0;
    protected:  virtual const char * name_(void) const noexcept = 0;
    public:     trainer(void) {}
    public:     ~trainer(void) override {}
    public:     trainer(const pokemon::trainer & o) = delete;
    public:     trainer(pokemon::trainer && o) noexcept = delete;
    public:     pokemon::trainer & operator=(const pokemon::trainer & o) = delete;
    public:     pokemon::trainer & operator=(pokemon::trainer && o) noexcept = delete;
    };

    template <trainername trainer> trainer * pokemon::trainer::go(void) {
        if (trainer::singleton == nullptr) {
            static trainer o;
            trainer::singleton = pointof(o);

            printf("%s: Hi friend.\n", trainer::singleton->name_());
        }

        return trainer::singleton;
    }

    template <pokemonname monster> monster * pokemon::trainer::choose(void) {
        if (monster::singleton == nullptr) {
            static monster o;

            monster::singleton = pointof(o);

            printf("%s: Hi friend.\n", monster::singleton->name_());
        }

        return monster::singleton;
    }
}

#endif // __POKEMONISM_POKEMON_TRAINER_HH__