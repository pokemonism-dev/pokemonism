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
        class Exception : public Cloneable<std::exception> {
        public:     struct Level;
        protected:  char *          file;
        protected:  char *          func;
        protected:  int             line;
        protected:  unsigned int    level;
        protected:  char *          message;
        protected:  char *          subject;
        public:     inline const char * what(void) const noexcept override { return subject; }
        public:     inline virtual const char * msg(void) const noexcept { return message; }
        public:     inline Exception * clone(void) const override { return new Exception(*this); }
        public:     Exception(const char * subject, unsigned int level);
        public:     Exception(const char * subject, unsigned int level, const char * file, int line, const char * func);
        public:     Exception(void);
        public:     ~Exception(void) override;
        public:     Exception(const Exception & o);
        public:     Exception(Exception && o) noexcept;
        public:     Exception & operator=(const Exception & o);
        public:     Exception & operator=(Exception && o) noexcept;
        };

        struct Exception::Level {
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

        const char * Exception::Level::to(unsigned int level) {
            switch (level) {
                case Exception::Level::none:            return "none";
                case Exception::Level::develop:         return "develop";
                case Exception::Level::verbose:         return "verbose";
                case Exception::Level::debug:           return "debug";
                case Exception::Level::information:     return "information";
                case Exception::Level::notice:          return "notice";
                case Exception::Level::caution:         return "caution";
                case Exception::Level::warning:         return "warning";
                case Exception::Level::critical:        return "critical";
                default:                                return "exception";
            }
        }
    }

    using Exception = pokemonism::sdk::Exception;

}


#ifndef   pokemon_exception_minimum_level
#define   pokemon_exception_minimum_level       1
#endif // pokemon_exception_minimum_level


#define pokemon_exception_throw(subject, level, code) do {                                                                                  \
    if(pokemon_exception_minimum_level <= level) {                                                                                          \
        throw pokemonism::sdk::Exception(subject, level, __FILE__, __LINE__, __func__);                                                     \
    }                                                                                                                                       \
    pokemonLog("[%s:%d/%s] %s(...) => %s\n", __FILE__, __LINE__, pokemonism::sdk::Exception::Level::to(level), __func__, subject);          \
    code;                                                                                                                                   \
} while (0)

#define pokemon_exception_check(condition, level, code) do {                                                                                \
    if(condition) {                                                                                                                         \
        if(pokemon_exception_minimum_level <= level) {                                                                                      \
            throw pokemonism::sdk::Exception(#condition, level, __FILE__, __LINE__, __func__);                                              \
        }                                                                                                                                   \
        pokemonLog("[%s:%d/%s] %s(...) => %s\n", __FILE__, __LINE__, pokemonism::sdk::Exception::Level::to(level), __func__, #condition);   \
        code;                                                                                                                               \
    }                                                                                                                                       \
} while (0)

#define pokemon_exit_check(condition, level, code) do {                                                                                     \
    if(condition) {                                                                                                                         \
        pokemonLog("[%s:%d/%s] %s(...) => %s\n", __FILE__, __LINE__, pokemonism::sdk::Exception::Level::to(level), __func__, #condition);   \
        if(pokemon_exception_minimum_level <= level) exit(0);                                                                               \
        code;                                                                                                                               \
    }                                                                                                                                       \
} while (0)

#define pokemon_critical_check(condition, code)             pokemon_exception_check(condition, pokemonism::sdk::Exception::Level::critical, code)
#define pokemon_warning_check(condition, code)              pokemon_exception_check(condition, pokemonism::sdk::Exception::Level::warning, code)
#define pokemon_caution_check(condition, code)              pokemon_exception_check(condition, pokemonism::sdk::Exception::Level::caution, code)
#define pokemon_notice_check(condition, code)               pokemon_exception_check(condition, pokemonism::sdk::Exception::Level::notice, code)
#define pokemon_information_check(condition, code)          pokemon_exception_check(condition, pokemonism::sdk::Exception::Level::information, code)
#define pokemon_debug_check(condition, code)                pokemon_exception_check(condition, pokemonism::sdk::Exception::Level::debug, code)
#define pokemon_verbose_check(condition, code)              pokemon_exception_check(condition, pokemonism::sdk::Exception::Level::verbose, code)
#define pokemon_develop_check(condition, code)              pokemon_exception_check(condition, pokemonism::sdk::Exception::Level::develop, code)

#define pokemon_critical_quick_check(condition)             pokemon_exception_check(condition, pokemonism::sdk::Exception::Level::critical, (void)(0))
#define pokemon_warning_quick_check(condition)              pokemon_exception_check(condition, pokemonism::sdk::Exception::Level::warning, (void)(0))
#define pokemon_caution_quick_check(condition)              pokemon_exception_check(condition, pokemonism::sdk::Exception::Level::caution, (void)(0))
#define pokemon_notice_quick_check(condition)               pokemon_exception_check(condition, pokemonism::sdk::Exception::Level::notice, (void)(0))
#define pokemon_information_quick_check(condition)          pokemon_exception_check(condition, pokemonism::sdk::Exception::Level::information, (void)(0))
#define pokemon_debug_quick_check(condition)                pokemon_exception_check(condition, pokemonism::sdk::Exception::Level::debug, (void)(0))
#define pokemon_verbose_quick_check(condition)              pokemon_exception_check(condition, pokemonism::sdk::Exception::Level::verbose, (void)(0))
#define pokemon_develop_quick_check(condition)              pokemon_exception_check(condition, pokemonism::sdk::Exception::Level::develop, (void)(0))

#define pokemon_critical_throw(code)                        pokemon_exception_throw("critical", pokemonism::sdk::Exception::Level::critical, code)
#define pokemon_warning_throw(code)                         pokemon_exception_throw("warning", pokemonism::sdk::Exception::Level::warning, code)
#define pokemon_caution_throw(code)                         pokemon_exception_throw("caution", pokemonism::sdk::Exception::Level::caution, code)
#define pokemon_notice_throw(code)                          pokemon_exception_throw("notice", pokemonism::sdk::Exception::Level::notice, code)
#define pokemon_information_throw(code)                     pokemon_exception_throw("information", pokemonism::sdk::Exception::Level::information, code)
#define pokemon_debug_throw(code)                           pokemon_exception_throw("debug", pokemonism::sdk::Exception::Level::debug, code)
#define pokemon_verbose_throw(code)                         pokemon_exception_throw("verbose", pokemonism::sdk::Exception::Level::verbose, code)
#define pokemon_develop_throw(code)                         pokemon_exception_throw("develop", pokemonism::sdk::Exception::Level::develop, code)

#define pokemon_critical_quick_throw()                      pokemon_exception_throw("critical", pokemonism::sdk::Exception::Level::critical, (void)(0))
#define pokemon_warning_quick_throw()                       pokemon_exception_throw("warning", pokemonism::sdk::Exception::Level::warning, (void)(0))
#define pokemon_caution_quick_throw()                       pokemon_exception_throw("caution", pokemonism::sdk::Exception::Level::caution, (void)(0))
#define pokemon_notice_quick_throw()                        pokemon_exception_throw("notice", pokemonism::sdk::Exception::Level::notice, (void)(0))
#define pokemon_information_quick_throw()                   pokemon_exception_throw("information", pokemonism::sdk::Exception::Level::information, (void)(0))
#define pokemon_debug_quick_throw()                         pokemon_exception_throw("debug", pokemonism::sdk::Exception::Level::debug, (void)(0))
#define pokemon_verbose_quick_throw()                       pokemon_exception_throw("verbose", pokemonism::sdk::Exception::Level::verbose, (void)(0))
#define pokemon_develop_quick_throw()                       pokemon_exception_throw("develop", pokemonism::sdk::Exception::Level::develop, (void)(0))

#define pokemon_critical_exit_check(condition, code)        pokemon_exit_check(condition, pokemonism::sdk::Exception::Level::critical, code)
#define pokemon_warning_exit_check(condition, code)         pokemon_exit_check(condition, pokemonism::sdk::Exception::Level::warning, code)
#define pokemon_caution_exit_check(condition, code)         pokemon_exit_check(condition, pokemonism::sdk::Exception::Level::caution, code)
#define pokemon_notice_exit_check(condition, code)          pokemon_exit_check(condition, pokemonism::sdk::Exception::Level::notice, code)
#define pokemon_information_exit_check(condition, code)     pokemon_exit_check(condition, pokemonism::sdk::Exception::Level::information, code)
#define pokemon_debug_exit_check(condition, code)           pokemon_exit_check(condition, pokemonism::sdk::Exception::Level::debug, code)
#define pokemon_verbose_exit_check(condition, code)         pokemon_exit_check(condition, pokemonism::sdk::Exception::Level::verbose, code)
#define pokemon_develop_exit_check(condition, code)         pokemon_exit_check(condition, pokemonism::sdk::Exception::Level::develop, code)


#endif // __POKEMONISM_SDK_EXCEPTION_HH__