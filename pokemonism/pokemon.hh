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

#include <pokemonism/faint.hh>
#include <pokemonism/trainer.hh>

namespace pokemonism {

    class pokemon : public pokemonism::sdk::sync {
    protected:  static pokemon * singleton;
    public:     virtual const char * name(void) const noexcept = 0;
    public:     pokemon(void) {}
    public:     ~pokemon(void) override {}
    public:     pokemon(const pokemon & o) = delete;
    public:     pokemon(pokemon && o) noexcept = delete;
    public:     pokemon & operator=(const pokemon & o) = delete;
    public:     pokemon & operator=(pokemon && o) noexcept = delete;
    public:     friend trainer;
    };



    template <pokemonname monsterizable>
    inline monsterizable * trainer::capture(void) {
        if (monsterizable::singleton == nullptr) {
            static monsterizable o;
            monsterizable::singleton = pointof(o);

            printf("%s: Hi, %s!\n", name(), monsterizable::singleton->name());
        }
        return reinterpret_cast<monsterizable *>(monsterizable::singleton);
    }

    template <pokemonname monsterizable>
    inline monsterizable * trainer::go(void) {
        pokemon_training_check(monsterizable::singleton == nullptr, return nullptr);

        return reinterpret_cast<monsterizable *>(monsterizable::singleton);
    }



}

#endif // __POKEMONISM_POKEMON_HH__