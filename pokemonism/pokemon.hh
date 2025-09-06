/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_POKEMON_HH__
#define   __POKEMONISM_POKEMON_HH__

#include <pokemonism/battle.hh>

namespace pokemonism {

    class pokemon {
    protected:  int result;
    public:     virtual const char * name(void) const noexcept = 0;
    public:     virtual const char * cry(void) const noexcept = 0;
    public:     virtual pokemon * ready(void) = 0;
    public:     virtual pokemon * go(void) = 0;
    public:     virtual pokemon * goodjob(void) = 0;
    public:     inline virtual int resultGet(void) { return result; }
    protected:  pokemon(void) : result(battle::result::unknown) {}
    protected:  virtual ~pokemon(void) {}
    public:     pokemon(const pokemon & o) = delete;
    public:     pokemon(pokemon && o) noexcept = delete;
    public:     pokemon & operator=(const pokemon & o) = delete;
    public:     pokemon & operator=(pokemon && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_POKEMON_HH__