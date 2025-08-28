/**
 * @file        pokemon/exception.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 18, 2025
 *
 */

#ifndef   __POKEMONISM_POKEMON_EXCEPTION__HH__
#define   __POKEMONISM_POKEMON_EXCEPTION__HH__

#include <pokemon/throwable.hh>
#include <pokemon/functionable.hh>

namespace pokemon {
    class exception : public throwable {
    public:     static int check(void (*func)(void));
    public:     static int check(const std::function<void (void)> & func);
    public:     static int check(const std::function<void (void)> && func);
    public:     static inline void check(const char * name, ...) {}
    public:     static throwable * rel(throwable * o);
    protected:  throwable * cause;
    public:     exception(const char * where, int line, const char * func);
    public:     exception(const throwable & cause, const char * where, int line, const char * func);
    public:     exception(throwable && cause, const char * where, int line, const char * func);
    public:     exception(const char * reason, const char * where, int line, const char * func);
    public:     exception(const char * reason, const throwable & cause, const char * where, int line, const char * func);
    public:     exception(const char * reason, throwable && cause, const char * where, int line, const char * func);
    public:     exception(const char * reason, const char * detail, const char * where, int line, const char * func);
    public:     exception(const char * reason, const char * detail, const throwable & cause, const char * where, int line, const char * func);
    public:     exception(const char * reason, const char * detail, throwable && cause, const char * where, int line, const char * func);
    public:     exception(void);
    public:     ~exception(void) override;
    public:     exception(const exception & o);
    public:     exception(exception && o) noexcept;
    public:     exception & operator=(const exception & o);
    public:     exception & operator=(exception && o) noexcept;
    };
}

#include <pokemon/exception.tcc>

single_namespace_exception_class_quick_declare(nullpointer);
exception_class_quick_declare(invalid, parameter);
exception_class_quick_declare(invalid, implementation);
exception_class_quick_declare(memory, leak);
exception_class_quick_declare(overflow, index);
exception_class_quick_declare(rejected, operation);
exception_class_quick_declare(failure, operation);
exception_class_quick_declare(no, observable);
exception_class_quick_declare(uninitialized, object);


#endif // __POKEMONISM_POKEMON_EXCEPTION__HH__