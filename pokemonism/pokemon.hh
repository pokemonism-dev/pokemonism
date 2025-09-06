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

#include <pokemonism.hh>

namespace pokemonism {

    class pokemon {
    public:     virtual const char * name(void) const = 0;
    public:     virtual const char * cry(void) const = 0;
    public:     virtual pokemon * ready(void) = 0;
    public:     virtual pokemon * go(void) = 0;
    public:     virtual int resultGet(void) = 0;
    public:     pokemon(void) {}
    public:     virtual ~pokemon(void) {}
    public:     pokemon(const pokemon & o) = delete;
    public:     pokemon(pokemon && o) noexcept = delete;
    public:     pokemon & operator=(const pokemon & o) = delete;
    public:     pokemon & operator=(pokemon && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_POKEMON_HH__