/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_TRAINER_HH__
#define   __POKEMONISM_TRAINER_HH__

#include <cstdio>

#include <pokemonism.hh>

namespace pokemonism::sdk {

    class trainer {
    protected:  static trainer * singleton;
    public:     template <trainername character = trainer> static character * go(void);
    protected:  virtual const char * name(void) const = 0;
    protected:  trainer(void) {}
    protected:  virtual ~trainer(void) {}
    public:     trainer(const trainer & o) = delete;
    public:     trainer(trainer && o) noexcept = delete;
    public:     trainer & operator=(const trainer & o) = delete;
    public:     trainer & operator=(trainer && o) noexcept = delete;
    };

    template <trainername character>
    character * trainer::go(void) {
        if (character::singleton == nullptr) {
            static character o;
            character::singleton = pointof(o);

            printf("%s: Hi, friend!\n", character::singleton->name());
        }
        return reinterpret_cast<character *>(character::singleton);
    }

}

#endif // __POKEMONISM_TRAINER_HH__