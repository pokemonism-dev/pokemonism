/**
 * @file            pokemonism/pokemon.ixx
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 04, 2025
 */

export import :pokemonism;

export module pokemonism:pokemon;

#include <pokemonism/interface/cloneable.hh>
#include <pokemonism/interface/synchronizable.hh>

export namespace pokemonism {
    class pokemon : public pokemonism::synchronizable, public pokemonism::cloneable {
    public:     pokemon * clone(void) const override { return nullptr; }
    public:     int lock(void) override { return declaration::fail; }
    public:     int unlock(void) override { return declaration::fail; }
    public:     int wait(void) override { return declaration::fail; }
    public:     int wait(int64 second, int64 nano) override { return declaration::fail; }
    public:     int wakeup(void) override { return declaration::fail; }
    public:     int wakeup(bool all) override { return declaration::fail; }
    public:     pokemon(void) {}
    public:     ~pokemon(void) override {}
    public:     pokemon(const pokemon & o) = delete;
    public:     pokemon(pokemon && o) noexcept = delete;
    public:     pokemon & operator=(const pokemon & o) = delete;
    public:     pokemon & operator=(pokemon && o) noexcept = delete;
    };
}

// export class pokemon : public pokemonism::synchronizable {
// public:     pokemon(void) {}
// public:     virtual ~pokemon(void) {}
// };
//
//
//
// #include <pokemonism.hh>
//
// #include <pokemonism/sync.hh>
// #include <pokemonism/exception.hh>
//
// #include <pokemonism/interface/cloneable.hh>
// #include <pokemonism/interface/synchronizable.hh>
//
// export namespace pokemonism {
//
//     class pokemon : public synchronizable, public cloneable {
//     public:     class ball;
//     public:     class faint;
//     public:     template <pokemonname name = pokemon> static int retreat(name * o);
//     public:     virtual const char * name(void) const = 0;
//     public:     pokemon * clone(void) const override { return nullptr; }
//     public:     int lock(void) override { return declaration::fail; }
//     public:     int unlock(void) override { return declaration::fail; }
//     public:     int wait(void) override { return declaration::fail; }
//     public:     int wait(int64 second, int64 nano) override { return declaration::fail; }
//     public:     int wakeup(void) override { return declaration::fail; }
//     public:     int wakeup(bool all) override { return declaration::fail; }
//     public:     pokemon(void) {}
//     public:     ~pokemon(void) override {}
//     public:     pokemon(const pokemon & o) = delete;
//     public:     pokemon(pokemon && o) noexcept = delete;
//     public:     pokemon & operator=(const pokemon & o) = delete;
//     public:     pokemon & operator=(pokemon && o) noexcept = delete;
//     };
//
//     class pokemon::ball : public sync {
//     public:     static int recall(pokemon * monster);
//     public:     ball(void) {}
//     public:     ~ball(void) override {}
//     public:     ball(const pokemon::ball & o) = delete;
//     public:     ball(pokemon::ball && o) noexcept = delete;
//     public:     pokemon::ball & operator=(const pokemon::ball & o) = delete;
//     public:     pokemon::ball & operator=(pokemon::ball && o) noexcept = delete;
//     };
//
//     class pokemon::faint : public exception {
//     public:     struct level {
//                 public:     constexpr static uint32 normal      = 0;
//                 public:     constexpr static uint32 training    = 1;
//                 public:     constexpr static uint32 confusion   = 2;
//                 public:     constexpr static uint32 freeze      = 3;
//                 public:     constexpr static uint32 asleep      = 4;
//                 public:     constexpr static uint32 paralysis   = 5;
//                 public:     constexpr static uint32 burn        = 6;
//                 public:     constexpr static uint32 position    = 7;
//                 };
//     public:     inline const char * what(void) const noexcept override { return "faint"; }
//     public:     inline exception * clone(void) const override { return new pokemon::faint(*this); }
//     public:     inline explicit faint(const char * subject, uint32 level) : exception(subject, level) {}
//     public:     inline faint(const char * subject, uint32 level, const exception & source) : exception(subject, level, source) {}
//     public:     inline faint(const char * subject, uint32 level, const char * path, int line, const char * func) : exception(subject, level, path, line, func) {}
//     public:     inline faint(const char * subject, uint32 level, const exception & source, const char * path, int line, const char * func) : exception(subject, level, path, line, func) {}
//     public:     inline faint(void) {}
//     public:     inline ~faint(void) override {}
//     public:     inline faint(const pokemon::faint & o) : exception(o) {}
//     public:     inline faint(pokemon::faint && o) noexcept : exception(std::move(o)) {}
//     public:     inline pokemon::faint & operator=(const pokemon::faint & o) { return reinterpret_cast<pokemon::faint &>(exception::operator=(o)); }
//     public:     inline pokemon::faint& operator=(pokemon::faint && o) noexcept { return reinterpret_cast<pokemon::faint &>(exception::operator=(std::move(o))); }
//     };
//
// }
//
// #ifndef   pokemon_faint_minimum_level
// #define   pokemon_faint_minimum_level       1
// #endif // pokemon_faint_minimum_level
//
// #define pokemon_faint_throw(subject, level, code) do {                                                                              \
//     if(condition) {                                                                                                                 \
//         if(pokemon_faint_minimum_level <= level) {                                                                                  \
//             throw pokemonism::pokemon::faint(subject, level, __FILE__, __LINE__, __func__);                                         \
//         }                                                                                                                           \
//         pokemonLog("[%s:%d/%s] %s(...) => %s\n", __FILE__, __LINE__, level, __func__, subject);                                     \
//         code;                                                                                                                       \
//     }                                                                                                                               \
// } while (0)
//
// #define pokemon_faint_check(condition, level, code) do {                                                                            \
//     if(condition) {                                                                                                                 \
//         if(pokemon_faint_minimum_level <= level) {                                                                                  \
//             throw pokemonism::pokemon::faint(#condition, level, __FILE__, __LINE__, __func__);                                      \
//         }                                                                                                                           \
//         pokemonLog("[%s:%d/%s] %s(...) => %s\n", __FILE__, __LINE__, level, __func__, #condition);                                  \
//         code;                                                                                                                       \
//     }                                                                                                                               \
// } while (0)
//
// #define pokemon_defeat_check(condition, level, code) do {                                                                           \
//     if(condition) {                                                                                                                 \
//         pokemonLog("[%s:%d/%s] %s(...) => %s\n", __FILE__, __LINE__, pokemonism::pokemon::faint::to(level), __func__, #condition);  \
//         if(pokemon_exception_minimum_level <= level) exit(0);                                                                       \
//         code;                                                                                                                       \
//     }                                                                                                                               \
// } while (0)
//
// #define pokemon_normal_throw(code)                              pokemon_faint_throw("normal", pokemonism::pokemon::faint::level::normal, code);
// #define pokemon_training_throw(code)                            pokemon_faint_throw("training", pokemonism::pokemon::faint::level::training, code);
// #define pokemon_confusion_throw(code)                           pokemon_faint_throw("confusion", pokemonism::pokemon::faint::level::confusion, code);
// #define pokemon_freeze_throw(code)                              pokemon_faint_throw("freeze", pokemonism::pokemon::faint::level::freeze, code);
// #define pokemon_asleep_throw(code)                              pokemon_faint_throw("asleep", pokemonism::pokemon::faint::level::asleep, code);
// #define pokemon_paralysis_throw(code)                           pokemon_faint_throw("paralysis", pokemonism::pokemon::faint::level::paralysis, code);
// #define pokemon_burn_throw(code)                                pokemon_faint_throw("burn", pokemonism::pokemon::faint::level::burn, code);
// #define pokemon_position_throw(code)                            pokemon_faint_throw("position", pokemonism::pokemon::faint::level::position, code);
//
// #define pokemon_normal_check(condition, code)                   pokemon_faint_check(condition,  pokemonism::pokemon::faint::level::normal, code);
// #define pokemon_training_check(condition, code)                 pokemon_faint_check(condition, pokemonism::pokemon::faint::level::training, code);
// #define pokemon_confusion_check(condition, code)                pokemon_faint_check(condition, pokemonism::pokemon::faint::level::confusion, code);
// #define pokemon_freeze_check(condition, code)                   pokemon_faint_check(condition, pokemonism::pokemon::faint::level::freeze, code);
// #define pokemon_asleep_check(condition, code)                   pokemon_faint_check(condition, pokemonism::pokemon::faint::level::asleep, code);
// #define pokemon_paralysis_check(condition, code)                pokemon_faint_check(condition, pokemonism::pokemon::faint::level::paralysis, code);
// #define pokemon_burn_check(condition, code)                     pokemon_faint_check(condition, pokemonism::pokemon::faint::level::burn, code);
// #define pokemon_position_check(condition, code)                 pokemon_faint_check(condition, pokemonism::pokemon::faint::level::position, code);
//
// #define pokemon_normal_defeat_check(condition, code)            pokemon_defeat_check(condition,  pokemonism::pokemon::faint::level::normal, code);
// #define pokemon_training_defeat_check(condition, code)          pokemon_defeat_check(condition, pokemonism::pokemon::faint::level::training, code);
// #define pokemon_confusion_defeat_check(condition, code)         pokemon_defeat_check(condition, pokemonism::pokemon::faint::level::confusion, code);
// #define pokemon_freeze_defeat_check(condition, code)            pokemon_defeat_check(condition, pokemonism::pokemon::faint::level::freeze, code);
// #define pokemon_asleep_defeat_check(condition, code)            pokemon_defeat_check(condition, pokemonism::pokemon::faint::level::asleep, code);
// #define pokemon_paralysis_defeat_check(condition, code)         pokemon_defeat_check(condition, pokemonism::pokemon::faint::level::paralysis, code);
// #define pokemon_burn_defeat_check(condition, code)              pokemon_defeat_check(condition, pokemonism::pokemon::faint::level::burn, code);
// #define pokemon_position_defeat_check(condition, code)          pokemon_defeat_check(condition, pokemonism::pokemon::faint::level::position, code);
//
// namespace pokemonism {
//
//     // ReSharper disable once CppDFAConstantFunctionResult
//     template<typename name>
//     int pokemon::retreat(name * o) {
//         pokemon_training_check(o == nullptr, return declaration::fail);
//
//         pokemonLog("%s retreat\n", o->name());
//
//         return declaration::success;
//     }
//
// }