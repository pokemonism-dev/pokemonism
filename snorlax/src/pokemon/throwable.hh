/**
 * @file        pokemon/throwable.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 18, 2025
 */

#ifndef   __POKEMONISM_POKEMON_THROWABLE__HH__
#define   __POKEMONISM_POKEMON_THROWABLE__HH__

#include <exception>

#include <pokemonism.hh>

namespace pokemon {
    class throwable : public std::exception {
    public:     class Level {
    public:     constexpr static uint32 develop         = 0;
    public:     constexpr static uint32 verbose         = 1;
    public:     constexpr static uint32 debug           = 2;
    public:     constexpr static uint32 information     = 3;
    public:     constexpr static uint32 notice          = 4;
    public:     constexpr static uint32 caution         = 5;
    public:     constexpr static uint32 warning         = 6;
    public:     constexpr static uint32 critical        = 7;
    public:     constexpr static uint32 none            = 8;
    };
    protected:  static char * dup(const char * s);
    protected:  static char * rel(char * s);
    protected:  char * where;
    protected:  char * func;
    protected:  char * reason;
    protected:  char * message;
    protected:  char * detail;
    protected:  int line;
    public:     virtual throwable * clone(void) const;
    public:     virtual throwable * move(void) noexcept;
    public:     const char * what(void) const noexcept override;
    public:     virtual const char * msg(void) const noexcept;
    public:     throwable(const char * where, int line, const char * func);
    public:     throwable(const char * reason, const char * where, int line, const char * func);
    public:     throwable(const char * reason, const char * detail, const char * where, int line, const char * func);
    public:     throwable(void);
    public:     ~throwable(void) override;
    public:     throwable(const throwable & o);
    public:     throwable(throwable && o) noexcept;
    public:     throwable & operator=(const throwable & o);
    public:     throwable & operator=(throwable && o) noexcept;
    };
}

#endif // __POKEMONISM_POKEMON_THROWABLE__HH__
