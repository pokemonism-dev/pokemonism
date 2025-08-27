/**
 * @file        pokemon/throwable.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 18, 2025
 */

// ReSharper disable once CppUnusedIncludeDirective
#include <cstdlib>
#include <cstring>
#include <cstdio>

#include "throwable.hh"

namespace pokemon {
    char * throwable::dup(const char * s) {
        return s != nullptr ? strdup(s) : nullptr;
    }

    char * throwable::rel(char * s) {
        if (s) free(s);

        return nullptr;
    }

    throwable::throwable(void) : where(nullptr), func(nullptr), reason(nullptr), message(nullptr), detail(nullptr), line(0) {
        message = dup("exception");
    }

    throwable::throwable(const char * where, const int line, const char * func) : where(dup(where)), func(dup(func)), reason(nullptr), message(nullptr), detail(nullptr), line(line) {
        asprintf(std::addressof(message), "[%s:%d] %s(...)", where, line, func);
    }

    throwable::throwable(const char * reason, const char * where, const int line, const char * func) : where(dup(where)), func(dup(func)), reason(dup(reason)), message(nullptr), detail(nullptr), line(line) {
        asprintf(std::addressof(message), "[%s:%d] %s(...) => %s", where, line, func, reason);
    }

    throwable::throwable(const char * reason, const char * detail, const char * where, const int line, const char * func) : where(dup(where)), func(dup(func)), reason(dup(reason)), message(nullptr), detail(dup(detail)), line(line) {
        asprintf(std::addressof(message), "[%s:%d] %s(...) => %s (%s)", where, line, func, reason, detail);
    }

    throwable::throwable(const throwable & o) : where(dup(o.where)), func(dup(o.func)), reason(dup(o.reason)), message(dup(o.message)), detail(dup(o.detail)), line(o.line) {}

    throwable::throwable(throwable && o) noexcept {
        where = o.where;
        func = o.func;
        reason = o.reason;
        message = o.message;
        detail = o.detail;
        line = o.line;

        o.where = nullptr;
        o.func = nullptr;
        o.reason = nullptr;
        o.message = nullptr;
        o.detail = nullptr;
        o.line = 0;
    }

    throwable::~throwable(void) {
        where = rel(where);
        func = rel(func);
        reason = rel(reason);
        message = rel(message);
        detail = rel(detail);
        line = 0;
    }

    throwable & throwable::operator=(const throwable & o) {
        if (addressof(o) != this) {
            where = rel(where);
            func = rel(func);
            reason = rel(reason);
            message = rel(message);
            detail = rel(detail);

            where = dup(o.where);
            func = dup(o.func);
            reason = dup(o.reason);
            message = dup(o.message);
            detail = dup(o.detail);

            line = o.line;
        }

        return *this;
    }

    throwable & throwable::operator=(throwable && o) noexcept {
        if (addressof(o) != this) {
            where = rel(where);
            func = rel(func);
            reason = rel(reason);
            message = rel(message);
            detail = rel(detail);

            where = o.where;
            func = o.func;
            reason = o.reason;
            message = o.message;
            detail = o.detail;
            line = o.line;

            o.where = nullptr;
            o.func = nullptr;
            o.reason = nullptr;
            o.message = nullptr;
            o.detail = nullptr;
            o.line = 0;
        }
        return *this;
    }

    const char * throwable::what(void) const noexcept {
        return "exception";
    }

    const char * throwable::msg(void) const noexcept {
        return message;
    }

    throwable * throwable::clone(void) const {
        return new throwable(*this);
    }

    throwable * throwable::move(void) noexcept {
        return new throwable(std::move(*this));
    }
}
