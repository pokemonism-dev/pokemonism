/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_POKEMON_SDK_TRAINER_LANA_HH__
#define   __POKEMONISM_POKEMON_SDK_TRAINER_LANA_HH__

#include <pokemonism/sdk/trainer.hh>

namespace pokemonism::sdk {

    class lana : public trainer {
    // public:     static lana * go(void);
    protected:  inline const char * name(void) const override;
    public:     lana(void) { printf("call\n"); }
    public:     ~lana(void) override {}
    public:     lana(const lana & o) = delete;
    public:     lana(lana && o) noexcept = delete;
    public:     lana & operator=(const lana & o) = delete;
    public:     lana & operator=(lana && o) noexcept = delete;
    };

    const char * lana::name(void) const {
        return "lana";
    }

}

#endif // __POKEMONISM_POKEMON_SDK_TRAINER_LANA_HH__