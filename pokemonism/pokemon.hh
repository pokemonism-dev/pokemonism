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

#include <pokemonism/sync.hh>
#include <pokemonism/exception.hh>

namespace pokemonism {

    class pokemon : public cloneable, public synchronizable {
    public:     class faint;
    public:     class ball;
    public:     class battle;
    public:     template <pokemonname name = pokemon> static void clean(name * monster);
    public:     template <typename convertable, typename original> static convertable cast(original o);
    protected:  int result;
    public:     virtual const char * name(void) const noexcept = 0;
    protected:  virtual pokemon * start(void) = 0;
    protected:  virtual int fight(void) = 0;
    public:     virtual int resultGet(void) { return result; }
    protected:  virtual void resultSet(int ret) { result = ret; }
    public:     pokemon * clone(void) const override { return nullptr; }
    public:     int lock(void) noexcept override { return declaration::fail; }
    public:     int unlock(void) noexcept override { return declaration::fail; }
    public:     int wait(void) noexcept override { return declaration::fail; }
    public:     int wakeup(void) noexcept override { return declaration::fail; }
    public:     int wait(long second, long nano) noexcept override { return declaration::fail; }
    public:     int wakeup(bool all) noexcept override { return declaration::fail; }
    protected:  pokemon(void);
    protected:  ~pokemon(void) override {}
    public:     pokemon(const pokemon & o) = delete;
    public:     pokemon(pokemon && o) noexcept = delete;
    public:     pokemon & operator=(const pokemon & o) = delete;
    public:     pokemon & operator=(pokemon && o) noexcept = delete;
    };



}


namespace pokemonism {



}

// ReSharper disable CppUnusedIncludeDirective
#include <pokemonism/pokemon/faint.hh>
#include <pokemonism/pokemon/ball.hh>
#include <pokemonism/pokemon/battle.hh>
// ReSharper restore CppUnusedIncludeDirective

#endif // __POKEMONISM_POKEMON_HH__