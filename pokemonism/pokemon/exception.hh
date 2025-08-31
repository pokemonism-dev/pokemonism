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

namespace pokemonism {
    namespace pokemon {
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
        public:     static inline void exit(const char * format, ...);
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

    using exception = pokemon::exception;

}



#endif // __POKEMONISM_POKEMON_EXCEPTION__HH__