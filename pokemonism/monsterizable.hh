/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_MONSTERIZABLE_HH__
#define   __POKEMONISM_MONSTERIZABLE_HH__

#include <pokemonism/pokemon.hh>
#include <pokemonism/trainer.hh>

namespace pokemonism {

    template <trainername characterizable = trainer>
    class monsterizable : public pokemon {
    public:     monsterizable(void) {}
    public:     ~monsterizable(void) override {}
    public:     monsterizable(const monsterizable<characterizable> & o) = delete;
    public:     monsterizable(monsterizable<characterizable> && o) noexcept = delete;
    public:     monsterizable<characterizable> & operator=(const monsterizable<characterizable> & o) = delete;
    public:     monsterizable<characterizable> & operator=(monsterizable<characterizable> && o) noexcept = delete;
    public:     friend trainer;
    };

}

#endif // __POKEMONISM_MONSTERIZABLE_HH__