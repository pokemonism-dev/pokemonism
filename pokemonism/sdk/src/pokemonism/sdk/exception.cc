/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 12, 2025
 */

#include <cstring>
#include <cstdio>

#include "exception.hh"

#include "allocator.hh"

namespace pokemonism {
    namespace sdk {

        exception::exception(const char * subject, unsigned int level) : file(nullptr), func(nullptr), line(declaration::zero), level(level), message(nullptr), subject(subject != nullptr ? strdup(subject) : nullptr) {
            asprintf(pointof(message), "[%s] %s", exception::level::to(level), subject);
        }

        exception::exception(const char * subject, unsigned int level, const char * file, int line, const char * func) : file(file != nullptr ? strdup(file) : nullptr), func(func != nullptr ? strdup(func) : nullptr), line(line), level(level), subject(subject != nullptr ? strdup(subject) : nullptr) {
            asprintf(pointof(message), "[%s/%s:%d] %s(...) => %s", exception::level::to(level), file, line, func, subject);
        }

        exception::exception(void) : file(nullptr), func(nullptr), line(declaration::zero), level(exception::level::none), message(nullptr), subject(nullptr) {

        }

        exception::~exception(void) {
            file = static_cast<char *>(allocator::rel(file));
            func = static_cast<char *>(allocator::rel(func));
            line = declaration::zero;
            level = exception::level::none;
            message = static_cast<char *>(allocator::rel(message));
            subject = static_cast<char *>(allocator::rel(subject));
        }

        exception::exception(const exception & o) {
            file = o.file != nullptr ? strdup(o.file) : nullptr;
            func = o.func != nullptr ? strdup(o.func) : nullptr;
            message = o.message != nullptr ? strdup(o.message) : nullptr;
            subject = o.subject != nullptr ? strdup(o.subject) : nullptr;
            line = o.line;
            level = o.level;
        }

        exception::exception(exception && o) noexcept : file(o.file), func(o.func), line(o.line), level(o.level), message(o.message), subject(o.subject) {
            o.file = nullptr;
            o.func = nullptr;
            o.level = exception::level::none;
            o.line = declaration::zero;
            o.message = nullptr;
            o.subject = nullptr;
        }

        exception & exception::operator=(const exception & o) {
            if (pointof(o) != this) {
                file = static_cast<char *>(allocator::rel(file));
                func = static_cast<char *>(allocator::rel(func));
                message = static_cast<char *>(allocator::rel(message));
                subject = static_cast<char *>(allocator::rel(subject));

                file = o.file != nullptr ? strdup(o.file) : nullptr;
                func = o.func != nullptr ? strdup(o.func) : nullptr;
                message = o.message != nullptr ? strdup(o.message) : nullptr;
                subject = o.subject != nullptr ? strdup(o.subject) : nullptr;
                line = o.line;
                level = o.level;
            }
            return *this;
        }

        exception & exception::operator=(exception && o) noexcept {
            if (pointof(o) != this) {
                file = static_cast<char *>(allocator::rel(file));
                func = static_cast<char *>(allocator::rel(func));
                message = static_cast<char *>(allocator::rel(message));
                subject = static_cast<char *>(allocator::rel(subject));

                file = o.file;
                func = o.func;
                message = o.message;
                subject = o.subject;
                line = o.line;
                level = o.level;

                o.file = nullptr;
                o.func = nullptr;
                o.level = exception::level::none;
                o.line = declaration::zero;
                o.message = nullptr;
                o.subject = nullptr;
            }

            return *this;
        }
    }
}

