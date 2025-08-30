/**
 * @file        pokemon/exception.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_EXCEPTION__HH__
#define   __POKEMONISM_POKEMON_EXCEPTION__HH__

#include <pokemonism.hh>

namespace pokemon {
    // ReSharper disable once CppClassCanBeFinal
    class exception : public declaration::type::exception {
    public:     constexpr static const char * tag = "exception";
    public:     class level {
                public:     constexpr static uint32 none            = 0;
                public:     constexpr static uint32 develop         = 1;
                public:     constexpr static uint32 verbose         = 2;
                public:     constexpr static uint32 debug           = 3;
                public:     constexpr static uint32 information     = 4;
                public:     constexpr static uint32 notice          = 5;
                public:     constexpr static uint32 caution         = 6;
                public:     constexpr static uint32 warning         = 7;
                public:     constexpr static uint32 critical        = 8;
    };
    protected:  static inline char * dup(const char * s);
    protected:  static inline exception * dup(const exception * o);
    protected:  static inline char * rel(char * s);
    protected:  static inline exception * rel(exception * o);
    protected:  static inline const char * to(int level);
    protected:  exception * source;
    protected:  char * message;
    protected:  char * subject;
    protected:  int level;
    public:     inline const char * what(void) const noexcept override { return tag; }
    public:     inline virtual const char * msg(void) const noexcept;
    public:     inline virtual const char * reason(void) const noexcept;
    public:     inline virtual const exception * origin(void) const noexcept;
    public:     inline virtual exception * clone(void) const { return new exception(*this); }
    public:     inline explicit exception(const char * subject, int level);
    public:     inline exception(const char * subject, int level, const exception & source);
    public:     inline exception(const char * subject, int level, const char * path, int line, const char * func);
    public:     inline exception(const char * subject, int level, const exception & source, const char * path, int line, const char * func);
    public:     inline exception(void) : source(nullptr), message(dup(tag)), subject(nullptr), level(level::warning) {}
    public:     inline ~exception(void) override;
    public:     inline exception(const exception & o);
    public:     inline exception(exception && o) noexcept;
    public:     inline exception & operator=(const exception & o);
    public:     inline exception& operator=(exception && o) noexcept;
    };

    char * exception::dup(const char * s) {
        if (s != nullptr) return strdup(s);
        return nullptr;
    }

    exception * exception::dup(const exception * o) {
        return o->clone();
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

    exception::exception(const char * subject, const int level) : source(nullptr), message(nullptr), subject(dup(subject)), level(level) {
        if (subject != nullptr) {
            asprintf(pointof(message), "[%s/%s] %s", tag, to(level), subject);
        } else {
            asprintf(pointof(message), "[%s/%s]", tag, to(level));
        }
    }

    exception::exception(const char * subject, const int level, const exception & source) : source(dup(pointof(source))), message(nullptr), subject(dup(subject)), level(level) {
        if (subject != nullptr) {
            asprintf(pointof(message), "[%s/%s] %s", tag, to(level), subject);
        } else {
            asprintf(pointof(message), "[%s/%s]", tag, to(level));
        }
    }

    exception::exception(const char * subject, const int level, const char * path, const int line, const char * func) : source(nullptr), message(nullptr), subject(dup(subject)), level(level) {
        if (subject != nullptr) {
            asprintf(pointof(message), "[%s/%s] [%s:%d] %s(...) => %s", tag, to(level), path, line, func, subject);
        } else {
            asprintf(pointof(message), "[%s/%s] [%s:%d] %s(...)", tag, to(level), path, line, func);
        }
    }

    exception::exception(const char * subject, const int level, const exception & source, const char * path, const int line, const char * func) : source(dup(pointof(source))), message(nullptr), subject(dup(subject)), level(level) {
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

#define exception_class_quick_declare(first, second)                                                \
namespace pokemon { namespace exceptional { namespace first {                                       \
using second = pokemon::exception;                                                                  \
} } }

#define single_namespace_exception_class_quick_declare(first)                                       \
namespace pokemon { namespace exceptional {                                                         \
using first = pokemon::exception;                                                                   \
} }

#ifndef   minimum_exception_throw_level
#define   minimum_exception_throw_level             0
#endif // minimum_exception_throw_level

#define implement_check(func, ...)                                                                  pokemon::exception::check(#func, ##__VA_ARGS__)
#define exception_throw_check(func)                                                                 pokemon::exception::check(func)

#define exception_throw(exception_type, level, reason, cause, code) do {                            \
    if(minimum_exception_throw_level <= static_cast<pokemon::uint32>(level)) {                      \
        throw exception_type(reason " (" #code ")", level, cause, __FILE__, __LINE__, __func__);    \
    } else {                                                                                        \
        code;                                                                                       \
    }                                                                                               \
} while (0)

#define exception_quick_throw(exception_type, level, code) do {                                     \
    if(minimum_exception_throw_level <= static_cast<pokemon::uint32>(level)) {                      \
        throw exception_type(#exception_type, level, __FILE__, __LINE__, __func__);                 \
    } else {                                                                                        \
        code;                                                                                       \
    }                                                                                               \
} while (0)

#define exception_reason_throw(exception_type, level, reason, code) do {                            \
    if(minimum_exception_throw_level <= static_cast<pokemon::uint32>(level)) {                      \
        throw exception_type(reason, " (" #code ")" level, __FILE__, __LINE__, __func__);           \
    } else {                                                                                        \
        code;                                                                                       \
    }                                                                                               \
} while (0)

#define exception_conditional_throw(condition, exception_type, level, description, code) do {       \
    if(condition) {                                                                                 \
        if(minimum_exception_throw_level <= static_cast<pokemon::uint32>(level)) {                  \
            throw exception_type(#condition " (" #code ")", level, __FILE__, __LINE__, __func__);   \
        } else {                                                                                    \
            code;                                                                                   \
        }                                                                                           \
    }                                                                                               \
} while (0)

#define exception_conditional_quick_throw(condition, exception_type, level, code) do {              \
    if(condition) {                                                                                 \
        if(minimum_exception_throw_level <= static_cast<pokemon::uint32>(level)) {                  \
            throw exception_type(#condition " (" #code ")", level, __FILE__, __LINE__, __func__);   \
        } else {                                                                                    \
            code;                                                                                   \
        }                                                                                           \
    }                                                                                               \
} while (0)

#define fatal_quick_throw(exception_type)                                                           exception_quick_throw(exception_type, pokemon::declaration::infinite, (void)(0))
#define critical_quick_throw(exception_type, code)                                                  exception_quick_throw(exception_type, pokemon::exception::level::critical, code)
#define warning_quick_throw(exception_type, code)                                                   exception_quick_throw(exception_type, pokemon::exception::level::warning, code)
#define caution_quick_throw(exception_type, code)                                                   exception_quick_throw(exception_type, pokemon::exception::level::caution, code)
#define notice_quick_throw(exception_type, code)                                                    exception_quick_throw(exception_type, pokemon::exception::level::notice, code)
#define information_quick_throw(exception_type, code)                                               exception_quick_throw(exception_type, pokemon::exception::level::information, code)
#define debug_quick_throw(exception_type, code)                                                     exception_quick_throw(exception_type, pokemon::exception::level::debug, code)
#define verbose_quick_throw(exception_type, code)                                                   exception_quick_throw(exception_type, pokemon::exception::level::verbose, code)
#define develop_quick_throw(exception_type, code)                                                   exception_quick_throw(exception_type, pokemon::exception::level::develop, code)

#define fatal_quick_throw_check(condition, exception_type, code)                                    exception_conditional_quick_throw(condition, exception_type, pokemon::declaration::infinite, code)
#define critical_quick_throw_check(condition, exception_type, code)                                 exception_conditional_quick_throw(condition, exception_type, pokemon::exception::level::critical, code)
#define warning_quick_throw_check(condition, exception_type, code)                                  exception_conditional_quick_throw(condition, exception_type, pokemon::exception::level::warning, code)
#define caution_quick_throw_check(condition, exception_type, code)                                  exception_conditional_quick_throw(condition, exception_type, pokemon::exception::level::caution, code)
#define notice_quick_throw_check(condition, exception_type, code)                                   exception_conditional_quick_throw(condition, exception_type, pokemon::exception::level::notice, code)
#define information_quick_throw_check(condition, exception_type, code)                              exception_conditional_quick_throw(condition, exception_type, pokemon::exception::level::information, code)
#define debug_quick_throw_check(condition, exception_type, code)                                    exception_conditional_quick_throw(condition, exception_type, pokemon::exception::level::debug, code)
#define verbose_quick_throw_check(condition, exception_type, code)                                  exception_conditional_quick_throw(condition, exception_type, pokemon::exception::level::verbose, code)
#define develop_quick_throw_check(condition, exception_type, code)                                  exception_conditional_quick_throw(condition, exception_type, pokemon::exception::level::develop, code)

single_namespace_exception_class_quick_declare(nullpointer)
exception_class_quick_declare(unimplemented, method)
exception_class_quick_declare(should, notcall)
exception_class_quick_declare(overflow, index)
exception_class_quick_declare(unclean, node)
exception_class_quick_declare(unmatched, container)
exception_class_quick_declare(invalid, operation)

single_namespace_exception_class_quick_declare(critical)
single_namespace_exception_class_quick_declare(warning)
single_namespace_exception_class_quick_declare(caution)
single_namespace_exception_class_quick_declare(notice)
single_namespace_exception_class_quick_declare(information)
single_namespace_exception_class_quick_declare(debug)
single_namespace_exception_class_quick_declare(verbose)
single_namespace_exception_class_quick_declare(develop)

#endif // __POKEMONISM_POKEMON_EXCEPTION__HH__