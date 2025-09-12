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

        Exception::Exception(const char * subject, unsigned int level) : file(nullptr), func(nullptr), line(declaration::zero), level(level), message(nullptr), subject(subject != nullptr ? strdup(subject) : nullptr) {
            asprintf(pointof(message), "[%s] %s", Exception::Level::to(level), subject);
        }

        Exception::Exception(const char * subject, unsigned int level, const char * file, int line, const char * func) : file(file != nullptr ? strdup(file) : nullptr), func(func != nullptr ? strdup(func) : nullptr), line(line), level(level), subject(subject != nullptr ? strdup(subject) : nullptr) {
            asprintf(pointof(message), "[%s/%s:%d] %s(...) => %s", Exception::Level::to(level), file, line, func, subject);
        }

        Exception::Exception(void) : file(nullptr), func(nullptr), line(declaration::zero), level(Exception::Level::none), message(nullptr), subject(nullptr) {

        }

        Exception::~Exception(void) {
            file = static_cast<char *>(Allocator::rel(file));
            func = static_cast<char *>(Allocator::rel(func));
            line = declaration::zero;
            level = Exception::Level::none;
            message = static_cast<char *>(Allocator::rel(message));
            subject = static_cast<char *>(Allocator::rel(subject));
        }

        Exception::Exception(const Exception & o) {
            file = o.file != nullptr ? strdup(o.file) : nullptr;
            func = o.func != nullptr ? strdup(o.func) : nullptr;
            message = o.message != nullptr ? strdup(o.message) : nullptr;
            subject = o.subject != nullptr ? strdup(o.subject) : nullptr;
            line = o.line;
            level = o.level;
        }

        Exception::Exception(Exception && o) noexcept : file(o.file), func(o.func), line(o.line), level(o.level), message(o.message), subject(o.subject) {
            o.file = nullptr;
            o.func = nullptr;
            o.level = Exception::Level::none;
            o.line = declaration::zero;
            o.message = nullptr;
            o.subject = nullptr;
        }

        Exception & Exception::operator=(const Exception & o) {
            if (pointof(o) != this) {
                file = static_cast<char *>(Allocator::rel(file));
                func = static_cast<char *>(Allocator::rel(func));
                message = static_cast<char *>(Allocator::rel(message));
                subject = static_cast<char *>(Allocator::rel(subject));

                file = o.file != nullptr ? strdup(o.file) : nullptr;
                func = o.func != nullptr ? strdup(o.func) : nullptr;
                message = o.message != nullptr ? strdup(o.message) : nullptr;
                subject = o.subject != nullptr ? strdup(o.subject) : nullptr;
                line = o.line;
                level = o.level;
            }
            return *this;
        }

        Exception & Exception::operator=(Exception && o) noexcept {
            if (pointof(o) != this) {
                file = static_cast<char *>(Allocator::rel(file));
                func = static_cast<char *>(Allocator::rel(func));
                message = static_cast<char *>(Allocator::rel(message));
                subject = static_cast<char *>(Allocator::rel(subject));

                file = o.file;
                func = o.func;
                message = o.message;
                subject = o.subject;
                line = o.line;
                level = o.level;

                o.file = nullptr;
                o.func = nullptr;
                o.level = Exception::Level::none;
                o.line = declaration::zero;
                o.message = nullptr;
                o.subject = nullptr;
            }

            return *this;
        }
    }
}

