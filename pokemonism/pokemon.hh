/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_POKEMON_HH__
#define   __POKEMONISM_POKEMON_HH__

#include <cstdio>

#include <pokemonism/sdk/sync.hh>

namespace pokemonism {

    class pokemon : public pokemonism::sdk::sync {
    public:     class center;
    protected:  static pokemon * singleton;
    public:     virtual const char * name(void) const noexcept = 0;
    public:     virtual void heal(void) = 0;
    public:     virtual int fight(void) = 0;
    protected:  pokemon(void) {}
    protected:  ~pokemon(void) override {}
    public:     pokemon(const pokemon & o) = delete;
    public:     pokemon(pokemon && o) noexcept = delete;
    public:     pokemon & operator=(const pokemon & o) = delete;
    public:     pokemon & operator=(pokemon && o) noexcept = delete;
    };

    class pokemon::center : public pokemonism::sdk::sync {
    public:     static pokemon * heal(pokemon * monster);
    public:     inline center(void) {}
    public:     inline ~center(void) override {}
    public:     center(const pokemon::center & o) = delete;
    public:     center(pokemon::center && o) noexcept = delete;
    public:     pokemon::center & operator=(const pokemon::center & o) = delete;
    public:     pokemon::center & operator=(pokemon::center && o) noexcept = delete;
    };

}

#include <pokemonism/pokemon/center.hh>

#endif // __POKEMONISM_POKEMON_HH__