/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_TRAINERIZABLE_HH__
#define   __POKEMONISM_TRAINERIZABLE_HH__

#include <pokemonism/sdk/sync.hh>

namespace pokemonism {

    class trainerizable : public pokemonism::sdk::sync {
    protected:  static trainerizable * singleton;
    public:     virtual const char * name(void) const noexcept = 0;
    protected:  trainerizable(void) {}
    protected:  ~trainerizable(void) override {}
    public:     trainerizable(const trainerizable & o) = delete;
    public:     trainerizable(trainerizable && o) noexcept = delete;
    public:     trainerizable & operator=(const trainerizable & o) = delete;
    public:     trainerizable & operator=(trainerizable && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_TRAINERIZABLE_HH__