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

#include <pokemonism.hh>
#include <pokemonism/sync.hh>

namespace pokemonism::sdk {

    template <trainername trainer>
    class pokemon : public sync {
    protected:  static pokemon<trainer> * singleton;
    protected:  pokemon(void) {}
    protected:  ~pokemon(void) override {}
    public:     pokemon(const pokemon<trainer> & o) = delete;
    public:     pokemon(pokemon<trainer> && o) noexcept = delete;
    public:     pokemon<trainer> & operator=(const pokemon<trainer> & o) = delete;
    public:     pokemon<trainer> & operator=(pokemon<trainer> && o) noexcept = delete;
    };

    template <trainername trainer>
    pokemon<trainer> * pokemon<trainer>::singleton = nullptr;
}

#endif // __POKEMONISM_POKEMON_HH__