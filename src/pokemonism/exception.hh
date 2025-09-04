/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_EXCEPTION_HH__
#define   __POKEMONISM_EXCEPTION_HH__

#include <cstdio>
#include <cstdarg>
#include <cstring>

#include <pokemonism.hh>
#include <pokemonism/log.hh>
#include <pokemonism/cloneable.hh>

namespace pokemonism {
    class exception : public declaration::exception, public cloneable {
    public:     constexpr static const char * tag = "exception";
    public:     struct level {
                public:     constexpr static unsigned int none          = 0;
                public:     constexpr static unsigned int develop       = 1;
                public:     constexpr static unsigned int verbose       = 2;
                public:     constexpr static unsigned int debug         = 3;
                public:     constexpr static unsigned int information   = 4;
                public:     constexpr static unsigned int notice        = 5;
                public:     constexpr static unsigned int caution       = 6;
                public:     constexpr static unsigned int warning       = 7;
                public:     constexpr static unsigned int critical      = 8;
                };
    public:     static inline void exit(const char * format, ...);
    protected:  static inline char * dup(const char * s);
    protected:  static inline exception * dup(const exception * o);
    protected:  static inline char * rel(char * s);
    protected:  static inline exception * rel(exception * o);
    public:     static inline const char * to(int level);
    protected:  exception * source;
    protected:  char * message;
    protected:  char * subject;
    protected:  int level;
    public:     inline const char * what(void) const noexcept override { return tag; }
    public:     inline virtual const char * msg(void) const noexcept;
    public:     inline virtual const char * reason(void) const noexcept;
    public:     inline virtual const exception * origin(void) const noexcept;
    public:     inline exception * clone(void) const override { return new exception(*this); }
    public:     inline explicit exception(const char * subject, unsigned int level);
    public:     inline exception(const char * subject, unsigned int level, const exception & source);
    public:     inline exception(const char * subject, unsigned int level, const char * path, int line, const char * func);
    public:     inline exception(const char * subject, unsigned int level, const exception & source, const char * path, int line, const char * func);
    public:     inline exception(void) : source(nullptr), message(dup(tag)), subject(nullptr), level(level::warning) {}
    public:     inline ~exception(void) override;
    public:     inline exception(const exception & o);
    public:     inline exception(exception && o) noexcept;
    public:     inline exception & operator=(const exception & o);
    public:     inline exception& operator=(exception && o) noexcept;
    };

    void exception::exit(const char * format, ...) {
        if (strnlen(format, 8) > 0) {
            va_list ap;
            va_start(ap, format);
            vfprintf(stdout, format, ap);
            va_end(ap);
            fprintf(stdout, "\n");
        }
    }

    char * exception::dup(const char * s) {
        if (s != nullptr) return strdup(s);
        return nullptr;
    }

    exception * exception::dup(const exception * o) {
        return o != nullptr ? o->clone() : nullptr;
    }

    char * exception::rel(char * s) {
        if (s != nullptr) free(s);
        return nullptr;
    }

    // ReSharper disable once CppParameterMayBeConstPtrOrRef
    exception * exception::rel(exception * o) {
        if (o != nullptr) delete o;
        return nullptr;
    }

    const char * exception::to(const int level) {
        switch (level) {
            case level::none:           return "none";
            case level::develop:        return "develop";
            case level::verbose:        return "verbose";
            case level::debug:          return "debug";
            case level::information:    return "information";
            case level::notice:         return "notice";
            case level::caution:        return "caution";
            case level::warning:        return "warning";
            case level::critical:       return "critical";
            default:                    return "exception";
        }
    }

    exception::~exception(void) {
        source = rel(source);
        message = rel(message);
        subject = rel(subject);
    }

    exception::exception(const exception & o) : source(dup(o.source)), message(dup(o.message)), subject(dup(o.subject)), level(o.level) {

    }

    exception::exception(exception && o) noexcept : source(o.source), message(o.message), subject(o.subject), level(o.level) {
        o.source = nullptr;
        o.message = nullptr;
        o.subject = nullptr;
        o.level = level::none;
    }

    exception & exception::operator=(const exception & o) {
        if (pointof(o) != this) {
            source = rel(source);
            message = rel(message);
            subject = rel(subject);

            source = dup(o.source);
            message = dup(o.message);
            subject = dup(o.subject);
            level = o.level;
        }
        return *this;
    }

    exception& exception::operator=(exception && o) noexcept {
        if (pointof(o) != this) {
            source = rel(source);
            message = rel(message);
            subject = rel(subject);

            source = o.source;
            message = o.message;
            subject = o.subject;
            level = o.level;

            o.source = nullptr;
            o.message = nullptr;
            o.subject = nullptr;
            o.level = level::none;
        }
        return *this;
    }

    exception::exception(const char * subject, const unsigned int level) : source(nullptr), message(nullptr), subject(dup(subject)), level(level) {
        if (subject != nullptr) {
            asprintf(pointof(message), "[%s/%s] %s", tag, to(level), subject);
        } else {
            asprintf(pointof(message), "[%s/%s]", tag, to(level));
        }
    }

    exception::exception(const char * subject, const unsigned int level, const exception & source) : source(dup(pointof(source))), message(nullptr), subject(dup(subject)), level(level) {
        if (subject != nullptr) {
            asprintf(pointof(message), "[%s/%s] %s", tag, to(level), subject);
        } else {
            asprintf(pointof(message), "[%s/%s]", tag, to(level));
        }
    }

    exception::exception(const char * subject, const unsigned int level, const char * path, const int line, const char * func) : source(nullptr), message(nullptr), subject(dup(subject)), level(level) {
        if (subject != nullptr) {
            asprintf(pointof(message), "[%s/%s] [%s:%d] %s(...) => %s", tag, to(level), path, line, func, subject);
        } else {
            asprintf(pointof(message), "[%s/%s] [%s:%d] %s(...)", tag, to(level), path, line, func);
        }
    }

    exception::exception(const char * subject, const unsigned int level, const exception & source, const char * path, const int line, const char * func) : source(dup(pointof(source))), message(nullptr), subject(dup(subject)), level(level) {
        if (subject != nullptr) {
            asprintf(pointof(message), "[%s/%s] [%s:%d] %s(...) => %s", tag, to(level), path, line, func, subject);
        } else {
            asprintf(pointof(message), "[%s/%s] [%s:%d] %s(...)", tag, to(level),path, line, func);
        }
    }

    const char * exception::msg(void) const noexcept { return message; }
    const char * exception::reason(void) const noexcept { return subject; }
    const exception * exception::origin(void) const noexcept {return source; }
}


#ifndef   pokemon_exception_minimum_level
#define   pokemon_exception_minimum_level       1
#endif // pokemon_exception_minimum_level


#define pokemon_exception_throw(subject, level, code) do {                                                                      \
    if(pokemon_exception_minimum_level <= level) {                                                                              \
        throw pokemonism::exception(subject, level, __FILE__, __LINE__, __func__);                                              \
    }                                                                                                                           \
    pokemonLog("[%s:%d/%s] %s(...) => %s\n", __FILE__, __LINE__, level, __func__, subject);                                     \
    code;                                                                                                                       \
} while (0)

#define pokemon_exception_check(condition, level, code) do {                                                                    \
    if(condition) {                                                                                                             \
        if(pokemon_exception_minimum_level <= level) {                                                                          \
            throw pokemonism::exception(#condition, level, __FILE__, __LINE__, __func__);                                       \
        }                                                                                                                       \
        pokemonLog("[%s:%d/%s] %s(...) => %s\n", __FILE__, __LINE__, pokemonism::exception::to(level), __func__, #condition);   \
        code;                                                                                                                   \
    }                                                                                                                           \
} while (0)

#define pokemon_exit_check(condition, level, code) do {                                                                         \
    if(condition) {                                                                                                             \
        pokemonLog("[%s:%d/%s] %s(...) => %s\n", __FILE__, __LINE__, pokemonism::exception::to(level), __func__, #condition);   \
        if(pokemon_exception_minimum_level <= level) exit(0);                                                                   \
        code;                                                                                                                   \
    }                                                                                                                           \
} while (0)

#define pokemon_critical_check(condition, code)             pokemon_exception_check(condition, pokemonism::exception::level::critical, code)
#define pokemon_warning_check(condition, code)              pokemon_exception_check(condition, pokemonism::exception::level::warning, code)
#define pokemon_caution_check(condition, code)              pokemon_exception_check(condition, pokemonism::exception::level::caution, code)
#define pokemon_notice_check(condition, code)               pokemon_exception_check(condition, pokemonism::exception::level::notice, code)
#define pokemon_information_check(condition, code)          pokemon_exception_check(condition, pokemonism::exception::level::information, code)
#define pokemon_debug_check(condition, code)                pokemon_exception_check(condition, pokemonism::exception::level::debug, code)
#define pokemon_verbose_check(condition, code)              pokemon_exception_check(condition, pokemonism::exception::level::verbose, code)
#define pokemon_develop_check(condition, code)              pokemon_exception_check(condition, pokemonism::exception::level::develop, code)

#define pokemon_critical_quick_check(condition)             pokemon_exception_check(condition, pokemonism::exception::level::critical, (void)(0))
#define pokemon_warning_quick_check(condition)              pokemon_exception_check(condition, pokemonism::exception::level::warning, (void)(0))
#define pokemon_caution_quick_check(condition)              pokemon_exception_check(condition, pokemonism::exception::level::caution, (void)(0))
#define pokemon_notice_quick_check(condition)               pokemon_exception_check(condition, pokemonism::exception::level::notice, (void)(0))
#define pokemon_information_quick_check(condition)          pokemon_exception_check(condition, pokemonism::exception::level::information, (void)(0))
#define pokemon_debug_quick_check(condition)                pokemon_exception_check(condition, pokemonism::exception::level::debug, (void)(0))
#define pokemon_verbose_quick_check(condition)              pokemon_exception_check(condition, pokemonism::exception::level::verbose, (void)(0))
#define pokemon_develop_quick_check(condition)              pokemon_exception_check(condition, pokemonism::exception::level::develop, (void)(0))

#define pokemon_critical_throw(condition, code)             pokemon_exception_throw("critical", pokemonism::exception::level::critical, code)
#define pokemon_warning_throw(condition, code)              pokemon_exception_throw("warning", pokemonism::exception::level::warning, code)
#define pokemon_caution_throw(condition, code)              pokemon_exception_throw("caution", pokemonism::exception::level::caution, code)
#define pokemon_notice_throw(condition, code)               pokemon_exception_throw("notice", pokemonism::exception::level::notice, code)
#define pokemon_information_throw(condition, code)          pokemon_exception_throw("information", pokemonism::exception::level::information, code)
#define pokemon_debug_throw(condition, code)                pokemon_exception_throw("debug", pokemonism::exception::level::debug, code)
#define pokemon_verbose_throw(condition, code)              pokemon_exception_throw("verbose", pokemonism::exception::level::verbose, code)
#define pokemon_develop_throw(condition, code)              pokemon_exception_throw("develop", pokemonism::exception::level::develop, code)

#define pokemon_critical_quick_throw(condition)             pokemon_exception_throw("critical", pokemonism::exception::level::critical, (void)(0))
#define pokemon_warning_quick_throw(condition)              pokemon_exception_throw("warning", pokemonism::exception::level::warning, (void)(0))
#define pokemon_caution_quick_throw(condition)              pokemon_exception_throw("caution", pokemonism::exception::level::caution, (void)(0))
#define pokemon_notice_quick_throw(condition)               pokemon_exception_throw("notice", pokemonism::exception::level::notice, (void)(0))
#define pokemon_information_quick_throw(condition)          pokemon_exception_throw("information", pokemonism::exception::level::information, (void)(0))
#define pokemon_debug_quick_throw(condition)                pokemon_exception_throw("debug", pokemonism::exception::level::debug, (void)(0))
#define pokemon_verbose_quick_throw(condition)              pokemon_exception_throw("verbose", pokemonism::exception::level::verbose, (void)(0))
#define pokemon_develop_quick_throw(condition)              pokemon_exception_throw("develop", pokemonism::exception::level::develop, (void)(0))

#define pokemon_critical_exit_check(condition, code)        pokemon_exit_check(condition, pokemonism::exception::level::critical, code)
#define pokemon_warning_exit_check(condition, code)         pokemon_exit_check(condition, pokemonism::exception::level::warning, code)
#define pokemon_caution_exit_check(condition, code)         pokemon_exit_check(condition, pokemonism::exception::level::caution, code)
#define pokemon_notice_exit_check(condition, code)          pokemon_exit_check(condition, pokemonism::exception::level::notice, code)
#define pokemon_information_exit_check(condition, code)     pokemon_exit_check(condition, pokemonism::exception::level::information, code)
#define pokemon_debug_exit_check(condition, code)           pokemon_exit_check(condition, pokemonism::exception::level::debug, code)
#define pokemon_verbose_exit_check(condition, code)         pokemon_exit_check(condition, pokemonism::exception::level::verbose, code)
#define pokemon_develop_exit_check(condition, code)         pokemon_exit_check(condition, pokemonism::exception::level::develop, code)

#endif // __POKEMONISM_EXCEPTION_HH__