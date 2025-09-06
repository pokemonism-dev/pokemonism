/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_TRAINER_HH__
#define   __POKEMONISM_TRAINER_HH__

#include <pokemonism/sdk/sync.hh>

namespace pokemonism {

    class trainer {
    public:     trainer(void) {}
    public:     virtual ~trainer(void) {}
    public:     trainer(const trainer & o) = delete;
    public:     trainer(trainer && o) noexcept = delete;
    public:     trainer & operator=(const trainer & o) = delete;
    public:     trainer & operator=(trainer && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_TRAINER_HH__