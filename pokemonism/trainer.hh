/**
 * @file
 * @brief
 * @details         소프트웨어에서 트레이너의 역할은 진화(기능이나 성능의 업그레이드를 돕는 서포터 역할을 수행한다.)
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep t, 2025
 */

#ifndef   __POKEMONISM_TRAINER_HH__
#define   __POKEMONISM_TRAINER_HH__

#include <pokemonism/sdk/sync.hh>

namespace pokemonism {

    class trainer : public pokemonism::sdk::sync {
    public:     virtual const char * name(void) const noexcept = 0;
    public:     inline trainer(void);
    public:     inline ~trainer(void) override;
    public:     trainer(const trainer & o) = delete;
    public:     trainer(trainer && o) noexcept = delete;
    public:     trainer & operator=(const trainer & o) = delete;
    public:     trainer & operator=(trainer && o) noexcept = delete;
    };

    inline trainer::trainer(void) {

    }

    inline trainer::~trainer(void) {

    }

}

#endif // __POKEMONISM_TRAINER_HH__