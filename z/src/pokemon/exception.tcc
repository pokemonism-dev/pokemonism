/**
 * @file        pokemon/exception.tcc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 18, 2025
 *
 */

#ifndef   __POKEMONISM_POKEMON_EXCEPTION_TCC__
#define   __POKEMONISM_POKEMON_EXCEPTION_TCC__

#include <pokemon/exception.hh>

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

#define exception_throw(exception_type, level, reason, detail, cause, code) do {                    \
    if(minimum_exception_throw_level <= static_cast<pokemon::uint32>(level)) {                      \
        throw exception_type(reason " (" #code ")", detail, cause, __FILE__, __LINE__, __func__);   \
    } else {                                                                                        \
        code;                                                                                       \
    }                                                                                               \
} while (0)

#define exception_quick_throw(exception_type, level, code) do {                                     \
    if(minimum_exception_throw_level <= static_cast<pokemon::uint32>(level)) {                      \
        throw exception_type(__FILE__, __LINE__, __func__);                                         \
    } else {                                                                                        \
        code;                                                                                       \
    }                                                                                               \
} while (0)

#define exception_reason_throw(exception_type, level, reason, code) do {                            \
    if(minimum_exception_throw_level <= static_cast<pokemon::uint32>(level)) {                      \
        throw exception_type(reason, " (" #code ")" __FILE__, __LINE__, __func__);                  \
    } else {                                                                                        \
        code;                                                                                       \
    }                                                                                               \
} while (0)

#define exception_conditional_throw(condition, exception_type, level, description, code) do {       \
    if(condition) {                                                                                 \
        if(minimum_exception_throw_level <= static_cast<pokemon::uint32>(level)) {                  \
            throw exception_type(#condition " (" #code ")", __FILE__, __LINE__, __func__);          \
        } else {                                                                                    \
            code;                                                                                   \
        }                                                                                           \
    } else {                                                                                        \
        code;                                                                                       \
    }                                                                                               \
} while (0)

#define exception_conditional_quick_throw(condition, exception_type, level, code) do {              \
    if(condition) {                                                                                 \
        if(minimum_exception_throw_level <= static_cast<pokemon::uint32>(level)) {                  \
            throw exception_type(#condition " (" #code ")", __FILE__, __LINE__, __func__);          \
        } else {                                                                                    \
            code;                                                                                   \
        }                                                                                           \
    } else {                                                                                        \
        code;                                                                                       \
    }                                                                                               \
} while (0)

#define fatal_quick_throw(exception_type)                                                           exception_quick_throw(exception_type, pokemon::declaration::infinite, (void)(0))
#define critical_quick_throw(exception_type, code)                                                  exception_quick_throw(exception_type, pokemon::exception::Level::critical, code)
#define warning_quick_throw(exception_type, code)                                                   exception_quick_throw(exception_type, pokemon::exception::Level::warning, code)
#define caution_quick_throw(exception_type, code)                                                   exception_quick_throw(exception_type, pokemon::exception::Level::caution, code)
#define notice_quick_throw(exception_type, code)                                                    exception_quick_throw(exception_type, pokemon::exception::Level::notice, code)
#define information_quick_throw(exception_type, code)                                               exception_quick_throw(exception_type, pokemon::exception::Level::information, code)
#define debug_quick_throw(exception_type, code)                                                     exception_quick_throw(exception_type, pokemon::exception::Level::debug, code)
#define verbose_quick_throw(exception_type, code)                                                   exception_quick_throw(exception_type, pokemon::exception::Level::verbose, code)
#define develop_quick_throw(exception_type, code)                                                   exception_quick_throw(exception_type, pokemon::exception::Level::develop, code)

#define fatal_quick_throw_check(condition, exception_type, code)                                    exception_conditional_quick_throw(condition, exception_type, pokemon::declaration::infinite, code)
#define critical_quick_throw_check(condition, exception_type, code)                                 exception_conditional_quick_throw(condition, exception_type, pokemon::exception::Level::critical, code)
#define warning_quick_throw_check(condition, exception_type, code)                                  exception_conditional_quick_throw(condition, exception_type, pokemon::exception::Level::warning, code)
#define caution_quick_throw_check(condition, exception_type, code)                                  exception_conditional_quick_throw(condition, exception_type, pokemon::exception::Level::caution, code)
#define notice_quick_throw_check(condition, exception_type, code)                                   exception_conditional_quick_throw(condition, exception_type, pokemon::exception::Level::notice, code)
#define information_quick_throw_check(condition, exception_type, code)                              exception_conditional_quick_throw(condition, exception_type, pokemon::exception::Level::information, code)
#define debug_quick_throw_check(condition, exception_type, code)                                    exception_conditional_quick_throw(condition, exception_type, pokemon::exception::Level::debug, code)
#define verbose_quick_throw_check(condition, exception_type, code)                                  exception_conditional_quick_throw(condition, exception_type, pokemon::exception::Level::verbose, code)
#define develop_quick_throw_check(condition, exception_type, code)                                  exception_conditional_quick_throw(condition, exception_type, pokemon::exception::Level::develop, code)

#endif // __POKEMONISM_POKEMON_EXCEPTION_TCC__