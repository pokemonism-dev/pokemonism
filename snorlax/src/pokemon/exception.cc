/**
 * @file        pokemon/exception.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 18, 2025
 */

#include "log.hh"

#include "exception.hh"

namespace pokemon {
    int exception::check(void (*func)(void)) {
        try {
            if (func != nullptr) func();
            return -1;
        } catch (const throwable & e) {
            diagnosticLog("%s\n", e.msg());
            return 0;
        }
    }

    int exception::check(const std::function<void (void)> & func) {
        try {
            if (func != nullptr) func();
            return -1;
        } catch (const throwable & e) {
            diagnosticLog("%s\n", e.msg());
            return 0;
        }
    }

    int exception::check(const std::function<void (void)> && func) {
        try {
            if (func != nullptr) func();
            return -1;
        } catch (const throwable & e) {
            diagnosticLog("%s\n", e.msg());
            return 0;
        }
    }

    throwable * exception::rel(throwable * o) {
        delete o;
        return nullptr;
    }

    exception::exception(void) : throwable(), cause(nullptr) {}

    exception::exception(const char * where, const int line, const char * func) : throwable(where, line, func), cause(nullptr) {}

    exception::exception(const throwable & cause, const char * where, const int line, const char * func) : throwable(where, line, func), cause(cause.clone()) {}

    exception::exception(throwable && cause, const char * where, const int line, const char * func) : throwable(where, line, func), cause(cause.move()) {}

    exception::exception(const char * reason, const char * where, const int line, const char * func) : throwable(reason, where, line, func), cause(nullptr) {}

    exception::exception(const char * reason, const throwable & cause, const char * where, const int line, const char * func) : throwable(reason, where, line, func), cause(cause.clone()) {}

    exception::exception(const char * reason, throwable && cause, const char * where, const int line, const char * func) : throwable(reason, where, line, func), cause(cause.move()) {}

    exception::exception(const char * reason, const char * detail, const char * where, const int line, const char * func) : throwable(reason, detail, where, line, func), cause(nullptr) {}

    exception::exception(const char * reason, const char * detail, const throwable & cause, const char * where, const int line, const char * func) : throwable(reason, detail, where, line, func), cause(cause.clone()) {}

    exception::exception(const char * reason, const char * detail, throwable && cause, const char * where, const int line, const char * func) : throwable(reason, detail, where, line, func), cause(cause.move()) {}

    exception::exception(const exception & o) : throwable(o), cause(o.cause ? o.cause->clone() : nullptr) {}

    exception::exception(exception && o) noexcept : throwable(std::move(o)), cause(o.cause) {
        o.cause = nullptr;
    }

    exception::~exception(void) {
        cause = rel(cause);
    }

    exception & exception::operator=(const exception & o) {
        if (addressof(o) != this) {
            throwable::operator=(o);

            cause = rel(cause);
            cause = o.clone();
        }
        return *this;
    }

    exception & exception::operator=(exception && o) noexcept {
        if (addressof(o) != this) {
            throwable::operator=(std::move(o));

            cause = rel(cause);
            cause = o.move();
        }
        return *this;
    }
} 
