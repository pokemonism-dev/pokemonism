/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_POKEMON_FAINT_HH__
#define   __POKEMONISM_POKEMON_FAINT_HH__

#include <pokemonism/pokemon.hh>

namespace pokemonism {

    class pokemon::faint : public exception {
    public:     constexpr static const char * tag                       = "faint";
    public:     struct level {
                public:     constexpr static unsigned int normal        = exception::level::none;
                public:     constexpr static unsigned int training      = exception::level::develop;
                public:     constexpr static unsigned int confusion     = exception::level::verbose;
                public:     constexpr static unsigned int freeze        = exception::level::debug;
                public:     constexpr static unsigned int sleep         = exception::level::information;
                public:     constexpr static unsigned int paralysis     = exception::level::notice;
                public:     constexpr static unsigned int burn          = exception::level::caution;
                public:     constexpr static unsigned int poison        = exception::level::warning;
                public:     constexpr static unsigned int retreat       = exception::level::critical;
                };
    public:     static const char * to(unsigned int level) {
                    switch (level) {
                        case pokemon::faint::level::normal:         return "normal";
                        case pokemon::faint::level::training:       return "training";
                        case pokemon::faint::level::confusion:      return "confusion";
                        case pokemon::faint::level::freeze:         return "freeze";
                        case pokemon::faint::level::sleep:          return "sleep";
                        case pokemon::faint::level::paralysis:      return "paralysis";
                        case pokemon::faint::level::burn:           return "burn";
                        case pokemon::faint::level::poison:         return "poison";
                        case pokemon::faint::level::retreat:        return "retreat";
                        default:                                    return "faint";
                    }
                }
    public:     inline pokemon::faint * clone(void) const override { return new pokemon::faint(*this); }
    public:     inline const char * what(void) const noexcept override { return pokemon::faint::tag; }
    public:     inline faint(const char * subject, unsigned int level) : exception(subject, level) {}
    public:     inline faint(const char * subject, unsigned int level, const exception & source) : exception(subject, level, source) {}
    public:     inline faint(const char * subject, unsigned int level, const char * path, int line, const char * func) : exception(subject, level, path, line, func) {}
    public:     inline faint(const char * subject, unsigned int level, const exception & source, const char * path, int line, const char * func) : exception(subject, level, source, path, line, func) {}
    public:     inline faint(void) {}
    public:     inline ~faint(void) override {}
    public:     faint(const pokemon::faint & o) : exception(o) {}
    public:     faint(pokemon::faint && o) noexcept : exception(std::move(o)) {}
    public:     pokemon::faint & operator=(const pokemon::faint & o) { return reinterpret_cast<pokemon::faint &>(exception::operator=(o)); }
    public:     pokemon::faint & operator=(pokemon::faint && o) noexcept  { return reinterpret_cast<pokemon::faint &>(exception::operator=(std::move(o))); }
    };

}

#ifndef   pokemon_faint_minimum_level
#define   pokemon_faint_minimum_level           1
#endif // pokemon_faint_minimum_level


#define pokemon_faint_throw(subject, level, code) do {                                                                              \
    if(pokemon_faint_minimum_level <= level) {                                                                                      \
        throw pokemonism::pokemon::faint(subject, level, __FILE__, __LINE__, __func__);                                             \
    }                                                                                                                               \
    pokemonLog("[%s:%d/%s] %s(...) => %s\n", __FILE__, __LINE__, pokemonism::pokemon::faint::to(level), __func__, subject);         \
    code;                                                                                                                           \
} while (0)

#define pokemon_faint_check(condition, level, code) do {                                                                            \
    if(condition) {                                                                                                                 \
        if(pokemon_faint_minimum_level <= level) {                                                                                  \
            throw pokemonism::pokemon::faint(#condition, level, __FILE__, __LINE__, __func__);                                      \
        }                                                                                                                           \
        pokemonLog("[%s:%d/%s] %s(...) => %s\n", __FILE__, __LINE__, pokemonism::pokemon::faint::to(level), __func__, #condition);  \
        code;                                                                                                                       \
    }                                                                                                                               \
} while (0)

#define pokemon_defeat_check(condition, level, code) do {                                                                           \
    if(condition) {                                                                                                                 \
        pokemonLog("[%s:%d/%s] %s(...) => %s\n", __FILE__, __LINE__, pokemonism::pokemon::faint::to(level), __func__, #condition);  \
        if(pokemon_faint_minimum_level <= level) exit(0);                                                                           \
        code;                                                                                                                       \
    }                                                                                                                               \
} while (0)

#define pokemon_retreat_check(condition, code)              pokemon_faint_check(condition, pokemonism::pokemon::faint::level::retreat, code)
#define pokemon_poison_check(condition, code)               pokemon_faint_check(condition, pokemonism::pokemon::faint::level::poison, code)
#define pokemon_burn_check(condition, code)                 pokemon_faint_check(condition, pokemonism::pokemon::faint::level::burn, code)
#define pokemon_paralysis_check(condition, code)            pokemon_faint_check(condition, pokemonism::pokemon::faint::level::paralysis, code)
#define pokemon_sleep_check(condition, code)                pokemon_faint_check(condition, pokemonism::pokemon::faint::level::sleep, code)
#define pokemon_freeze_check(condition, code)               pokemon_faint_check(condition, pokemonism::pokemon::faint::level::freeze, code)
#define pokemon_confusion_check(condition, code)            pokemon_faint_check(condition, pokemonism::pokemon::faint::level::confusion, code)
#define pokemon_training_check(condition, code)             pokemon_faint_check(condition, pokemonism::pokemon::faint::level::training, code)

#define pokemon_retreat_quick_check(condition)              pokemon_faint_check(condition, pokemonism::pokemon::faint::level::retreat, (void)(0))
#define pokemon_poison_quick_check(condition)               pokemon_faint_check(condition, pokemonism::pokemon::faint::level::poison, (void)(0))
#define pokemon_burn_quick_check(condition)                 pokemon_faint_check(condition, pokemonism::pokemon::faint::level::burn, (void)(0))
#define pokemon_paralysis_quick_check(condition)            pokemon_faint_check(condition, pokemonism::pokemon::faint::level::paralysis, (void)(0))
#define pokemon_sleep_quick_check(condition)                pokemon_faint_check(condition, pokemonism::pokemon::faint::level::sleep, (void)(0))
#define pokemon_freeze_quick_check(condition)               pokemon_faint_check(condition, pokemonism::pokemon::faint::level::freeze, (void)(0))
#define pokemon_confusion_quick_check(condition)            pokemon_faint_check(condition, pokemonism::pokemon::faint::level::confusion, (void)(0))
#define pokemon_training_quick_check(condition)             pokemon_faint_check(condition, pokemonism::pokemon::faint::level::training, (void)(0))

#define pokemon_retreat_throw(condition, code)              pokemon_exception_throw("retreat", pokemonism::pokemon::faint::level::retreat, code)
#define pokemon_poison_throw(condition, code)               pokemon_exception_throw("poison", pokemonism::pokemon::faint::level::poison, code)
#define pokemon_burn_throw(condition, code)                 pokemon_exception_throw("burn", pokemonism::pokemon::faint::level::burn, code)
#define pokemon_paralysis_throw(condition, code)            pokemon_exception_throw("paralysis", pokemonism::pokemon::faint::level::paralysis, code)
#define pokemon_sleep_throw(condition, code)                pokemon_exception_throw("sleep", pokemonism::pokemon::faint::level::sleep, code)
#define pokemon_freeze_throw(condition, code)               pokemon_exception_throw("freeze", pokemonism::pokemon::faint::level::freeze, code)
#define pokemon_confusion_throw(condition, code)            pokemon_exception_throw("confusion", pokemonism::pokemon::faint::level::confusion, code)
#define pokemon_training_throw(condition, code)             pokemon_exception_throw("training", pokemonism::pokemon::faint::level::training, code)

#define pokemon_retreat_quick_throw(code)                   pokemon_exception_throw("retreat", pokemonism::pokemon::faint::level::retreat, code)
#define pokemon_poison_quick_throw(code)                    pokemon_exception_throw("poison", pokemonism::pokemon::faint::level::v, code)
#define pokemon_burn_quick_throw(code)                      pokemon_exception_throw("burn", pokemonism::pokemon::faint::level::burn, code)
#define pokemon_paralysis_quick_throw(code)                 pokemon_exception_throw("paralysis", pokemonism::pokemon::faint::level::paralysis, code)
#define pokemon_sleep_quick_throw(code)                     pokemon_exception_throw("sleep", pokemonism::pokemon::faint::level::sleep, code)
#define pokemon_freeze_quick_throw(code)                    pokemon_exception_throw("freeze", pokemonism::pokemon::faint::level::freeze, code)
#define pokemon_confusion_quick_throw(code)                 pokemon_exception_throw("confusion", pokemonism::pokemon::faint::level::confusion, code)
#define pokemon_training_quick_throw(code)                  pokemon_exception_throw("training", pokemonism::pokemon::faint::level::training, code)

#define pokemon_retreat_exit_check(condition, code)         pokemon_exit_check(condition, pokemonism::pokemon::faint::level::retreat, code)
#define pokemon_poison_exit_check(condition, code)          pokemon_exit_check(condition, pokemonism::pokemon::faint::level::poison, code)
#define pokemon_burn_exit_check(condition, code)            pokemon_exit_check(condition, pokemonism::pokemon::faint::level::burn, code)
#define pokemon_paralysis_exit_check(condition, code)       pokemon_exit_check(condition, pokemonism::pokemon::faint::level::paralysis, code)
#define pokemon_sleep_exit_check(condition, code)           pokemon_exit_check(condition, pokemonism::pokemon::faint::level::sleep, code)
#define pokemon_freeze_exit_check(condition, code)          pokemon_exit_check(condition, pokemonism::pokemon::faint::level::freeze, code)
#define pokemon_confusion_exit_check(condition, code)       pokemon_exit_check(condition, pokemonism::pokemon::faint::level::confusion, code)
#define pokemon_training_exit_check(condition, code)        pokemon_exit_check(condition, pokemonism::pokemon::faint::level::training, code)

namespace pokemonism {

    template <typename convertable, typename original>
    inline convertable pokemon::cast(original o) {
        pokemon_training_check(o != nullptr && dynamic_cast<convertable>(o) == nullptr, return nullptr);

        return static_cast<convertable>(reinterpret_cast<void *>(o));
    }

    template <pokemonname name>
    void pokemon::clean(name * monster) {
        pokemon_training_check(monster == nullptr, return);

        pokemonLog("%s: retreat\n", monster->name());
    }

}

#endif // __POKEMONISM_POKEMON_FAINT_HH__