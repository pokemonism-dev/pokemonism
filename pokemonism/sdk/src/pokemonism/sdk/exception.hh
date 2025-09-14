/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_SDK_EXCEPTION_HH__
#define   __POKEMONISM_SDK_EXCEPTION_HH__

#include <pokemonism/cloneable.hh>

#include <pokemonism/sdk/log.hh>

namespace pokemonism {

    namespace sdk {
        class exception : public cloneable<std::exception> {
        public:     struct level;
        protected:  char *          file;
        protected:  char *          func;
        protected:  int             line;
        protected:  unsigned int    level;
        protected:  char *          message;
        protected:  char *          subject;
        public:     inline const char * what(void) const noexcept override { return subject; }
        public:     inline virtual const char * msg(void) const noexcept { return message; }
        public:     inline exception * clone(void) const override { return new exception(*this); }
        public:     exception(const char * subject, unsigned int level);
        public:     exception(const char * subject, unsigned int level, const char * file, int line, const char * func);
        public:     exception(void);
        public:     ~exception(void) override;
        public:     exception(const exception & o);
        public:     exception(exception && o) noexcept;
        public:     exception & operator=(const exception & o);
        public:     exception & operator=(exception && o) noexcept;
        };

        struct exception::level {
        public:     inline static const char * to(unsigned int level);
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

        const char * exception::level::to(unsigned int level) {
            switch (level) {
                case exception::level::none:            return "none";
                case exception::level::develop:         return "develop";
                case exception::level::verbose:         return "verbose";
                case exception::level::debug:           return "debug";
                case exception::level::information:     return "information";
                case exception::level::notice:          return "notice";
                case exception::level::caution:         return "caution";
                case exception::level::warning:         return "warning";
                case exception::level::critical:        return "critical";
                default:                                return "exception";
            }
        }
    }

    using exception = pokemonism::sdk::exception;

}


#ifndef   pokemon_exception_minimum_level
#define   pokemon_exception_minimum_level       1
#endif // pokemon_exception_minimum_level


#define pokemon_exception_throw(subject, grade, code) do {                                                                                  \
    if(pokemon_exception_minimum_level <= grade) {                                                                                          \
        throw pokemonism::sdk::exception(subject, grade, __FILE__, __LINE__, __func__);                                                     \
    }                                                                                                                                       \
    pokemonLog("[%s:%d/%s] %s(...) => %s\n", __FILE__, __LINE__, pokemonism::sdk::exception::level::to(grade), __func__, subject);          \
    code;                                                                                                                                   \
} while (0)

#define pokemon_exception_check(condition, grade, code) do {                                                                                \
    if(condition) {                                                                                                                         \
        if(pokemon_exception_minimum_level <= grade) {                                                                                      \
            throw pokemonism::sdk::exception(#condition, grade, __FILE__, __LINE__, __func__);                                              \
        }                                                                                                                                   \
        pokemonLog("[%s:%d/%s] %s(...) => %s\n", __FILE__, __LINE__, pokemonism::sdk::exception::level::to(grade), __func__, #condition);   \
        code;                                                                                                                               \
    }                                                                                                                                       \
} while (0)

#define pokemon_exit_check(condition, grade, code) do {                                                                                     \
    if(condition) {                                                                                                                         \
        pokemonLog("[%s:%d/%s] %s(...) => %s\n", __FILE__, __LINE__, pokemonism::sdk::exception::level::to(grade), __func__, #condition);   \
        if(pokemon_exception_minimum_level <= grade) exit(0);                                                                               \
        code;                                                                                                                               \
    }                                                                                                                                       \
} while (0)

#define pokemon_critical_check(condition, code)             pokemon_exception_check(condition, pokemonism::sdk::exception::level::critical, code)
#define pokemon_warning_check(condition, code)              pokemon_exception_check(condition, pokemonism::sdk::exception::level::warning, code)
#define pokemon_caution_check(condition, code)              pokemon_exception_check(condition, pokemonism::sdk::exception::level::caution, code)
#define pokemon_notice_check(condition, code)               pokemon_exception_check(condition, pokemonism::sdk::exception::level::notice, code)
#define pokemon_information_check(condition, code)          pokemon_exception_check(condition, pokemonism::sdk::exception::level::information, code)
#define pokemon_debug_check(condition, code)                pokemon_exception_check(condition, pokemonism::sdk::exception::level::debug, code)
#define pokemon_verbose_check(condition, code)              pokemon_exception_check(condition, pokemonism::sdk::exception::level::verbose, code)
#define pokemon_develop_check(condition, code)              pokemon_exception_check(condition, pokemonism::sdk::exception::level::develop, code)

#define pokemon_critical_quick_check(condition)             pokemon_exception_check(condition, pokemonism::sdk::exception::level::critical, (void)(0))
#define pokemon_warning_quick_check(condition)              pokemon_exception_check(condition, pokemonism::sdk::exception::level::warning, (void)(0))
#define pokemon_caution_quick_check(condition)              pokemon_exception_check(condition, pokemonism::sdk::exception::level::caution, (void)(0))
#define pokemon_notice_quick_check(condition)               pokemon_exception_check(condition, pokemonism::sdk::exception::level::notice, (void)(0))
#define pokemon_information_quick_check(condition)          pokemon_exception_check(condition, pokemonism::sdk::exception::level::information, (void)(0))
#define pokemon_debug_quick_check(condition)                pokemon_exception_check(condition, pokemonism::sdk::exception::level::debug, (void)(0))
#define pokemon_verbose_quick_check(condition)              pokemon_exception_check(condition, pokemonism::sdk::exception::level::verbose, (void)(0))
#define pokemon_develop_quick_check(condition)              pokemon_exception_check(condition, pokemonism::sdk::exception::level::develop, (void)(0))

#define pokemon_critical_throw(code)                        pokemon_exception_throw("critical", pokemonism::sdk::exception::level::critical, code)
#define pokemon_warning_throw(code)                         pokemon_exception_throw("warning", pokemonism::sdk::exception::level::warning, code)
#define pokemon_caution_throw(code)                         pokemon_exception_throw("caution", pokemonism::sdk::exception::level::caution, code)
#define pokemon_notice_throw(code)                          pokemon_exception_throw("notice", pokemonism::sdk::exception::level::notice, code)
#define pokemon_information_throw(code)                     pokemon_exception_throw("information", pokemonism::sdk::exception::level::information, code)
#define pokemon_debug_throw(code)                           pokemon_exception_throw("debug", pokemonism::sdk::exception::level::debug, code)
#define pokemon_verbose_throw(code)                         pokemon_exception_throw("verbose", pokemonism::sdk::exception::level::verbose, code)
#define pokemon_develop_throw(code)                         pokemon_exception_throw("develop", pokemonism::sdk::exception::level::develop, code)

#define pokemon_critical_quick_throw()                      pokemon_exception_throw("critical", pokemonism::sdk::exception::level::critical, (void)(0))
#define pokemon_warning_quick_throw()                       pokemon_exception_throw("warning", pokemonism::sdk::exception::level::warning, (void)(0))
#define pokemon_caution_quick_throw()                       pokemon_exception_throw("caution", pokemonism::sdk::exception::level::caution, (void)(0))
#define pokemon_notice_quick_throw()                        pokemon_exception_throw("notice", pokemonism::sdk::exception::level::notice, (void)(0))
#define pokemon_information_quick_throw()                   pokemon_exception_throw("information", pokemonism::sdk::exception::level::information, (void)(0))
#define pokemon_debug_quick_throw()                         pokemon_exception_throw("debug", pokemonism::sdk::exception::level::debug, (void)(0))
#define pokemon_verbose_quick_throw()                       pokemon_exception_throw("verbose", pokemonism::sdk::exception::level::verbose, (void)(0))
#define pokemon_develop_quick_throw()                       pokemon_exception_throw("develop", pokemonism::sdk::exception::level::develop, (void)(0))

#define pokemon_critical_exit_check(condition, code)        pokemon_exit_check(condition, pokemonism::sdk::exception::level::critical, code)
#define pokemon_warning_exit_check(condition, code)         pokemon_exit_check(condition, pokemonism::sdk::exception::level::warning, code)
#define pokemon_caution_exit_check(condition, code)         pokemon_exit_check(condition, pokemonism::sdk::exception::level::caution, code)
#define pokemon_notice_exit_check(condition, code)          pokemon_exit_check(condition, pokemonism::sdk::exception::level::notice, code)
#define pokemon_information_exit_check(condition, code)     pokemon_exit_check(condition, pokemonism::sdk::exception::level::information, code)
#define pokemon_debug_exit_check(condition, code)           pokemon_exit_check(condition, pokemonism::sdk::exception::level::debug, code)
#define pokemon_verbose_exit_check(condition, code)         pokemon_exit_check(condition, pokemonism::sdk::exception::level::verbose, code)
#define pokemon_develop_exit_check(condition, code)         pokemon_exit_check(condition, pokemonism::sdk::exception::level::develop, code)


#endif // __POKEMONISM_SDK_EXCEPTION_HH__