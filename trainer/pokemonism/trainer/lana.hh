/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_TRAINER_LANA_HH__
#define   __POKEMONISM_TRAINER_LANA_HH__

#include <cstdio>

#include <pokemonism/trainer.hh>

namespace pokemonism {

    class lana final : public trainer {
    private:    static lana * singleton;
    public:     inline static lana * on(void);
    public:     inline const char * name(void) const noexcept override;
    private:    inline lana(void);
    private:    inline ~lana(void) override;
    public:     lana(const lana & o) = delete;
    public:     lana(lana && o) noexcept = delete;
    public:     lana & operator=(const lana & o) = delete;
    public:     lana & operator=(lana && o) noexcept = delete;
    };

    lana * lana::on(void) {
        if (singleton == nullptr) {
            static lana o;
            singleton = pointof(o);

            printf("%s: Hi, friend\n", singleton->name());
        }
        return singleton;
    }

    const char * lana::name(void) const noexcept { return "lana"; }

    inline lana::lana(void) {

    }

    inline lana::~lana(void) {

    }


}

#endif // __POKEMONISM_TRAINER_LANA_HH__