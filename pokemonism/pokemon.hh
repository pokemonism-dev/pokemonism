/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_POKEMON_HH__
#define   __POKEMONISM_POKEMON_HH__

#include <pokemonism/cloneable.hh>

#include <pokemonism/synchronizable.hh>

namespace pokemonism {

    class pokemon : public cloneable, public synchronizable {
    public:     virtual const char * name(void) const = 0;
    public:     pokemon * clone(void) const override { return nullptr; }
    public:     int lock(void) override { return declaration::fail; }
    public:     int unlock(void) override { return declaration::fail; }
    public:     int wait(void) override { return declaration::fail; }
    public:     int wakeup(void) override { return declaration::fail; }
    public:     int wait(long second, long nano) override { return declaration::fail; }
    public:     int wakeup(bool all) override { return declaration::fail; }
    public:     pokemon(void);
    public:     ~pokemon(void) override;
    public:     pokemon(const pokemon & o) = delete;
    public:     pokemon(pokemon && o) noexcept = delete;
    public:     pokemon & operator=(const pokemon & o) = delete;
    public:     pokemon & operator=(pokemon && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_POKEMON_HH__