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
    // public:     template <trainername name> name & get(void);
    // public:     virtual void capture_(pokemon * mon) = 0;
    // public:     virtual pokemon * evolve_(pokemon * mon) = 0;
    // public:     virtual pokemon * evolve_(pokemon * mon, item * item) = 0;
    protected:  virtual const char * name_(void) const noexcept;
    public:     trainer(void) {}
    public:     ~trainer(void) override {}
    public:     trainer(const pokemon::trainer & o) = delete;
    public:     trainer(pokemon::trainer && o) noexcept = delete;
    public:     pokemon::trainer & operator=(const pokemon::trainer & o) = delete;
    public:     pokemon::trainer & operator=(pokemon::trainer && o) noexcept = delete;
    };
}

#endif // __POKEMONISM_POKEMON_TRAINER_HH__