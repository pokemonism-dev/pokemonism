/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 07, 2025
 */

#ifndef   __POKEMONISM_SDK_TEMPLATEABLE_ENGINE_HH__
#define   __POKEMONISM_SDK_TEMPLATEABLE_ENGINE_HH__

#include <pokemonism/sdk/engine.hh>
// #include <pokemonism/sdk/generic/command.hh>
#include <pokemonism/sdk/templateable/command.hh>

namespace pokemonism::sdk::templateable {

    class engine : public pokemonism::sdk::engine {
    public:     typedef void (*terminator)(engine &);
    public:     typedef void (*bootstrapper)(engine &, pokemonism::sdk::event::queue **, pokemonism::sdk::engine::set &);
    public:     int on(bootstrapper bootstrap = nullptr);
    public:     void off(terminator f = nullptr) { pokemonism::sdk::engine::off(reinterpret_cast<pokemonism::sdk::engine::terminator>(f)); }
    public:     inline templateable::command::event::generator * genericCommandGet(void) const { return static_cast<templateable::command::event::generator *>(reinterpret_cast<void *>(generator.command)); }
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline templateable::command::subscription<commandable, outputable> * genericReg(commandable * object, unsigned int properties, const templateable::command::event::callback<commandable, outputable>::set & eventSet) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline templateable::command::subscription<commandable, outputable> * genericReg(commandable * object, unsigned int properties, const templateable::command::event::callback<commandable, outputable>::set & eventSet, templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline templateable::command::subscription<commandable, outputable> * genericReg(commandable * object, unsigned int properties, const templateable::command::event::callback<commandable, outputable>::set & eventSet, templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline templateable::command::subscription<commandable, outputable> * genericReg(commandable * object, unsigned int properties, const templateable::command::event::callback<commandable, outputable>::set & eventSet, templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn, templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const;
    public:     inline engine(void) {}
    public:     inline ~engine(void) override {}
    public:     engine(const engine & o) = delete;
    public:     engine(engine && o) noexcept = delete;
    public:     engine & operator=(const engine & o) = delete;
    public:     engine & operator=(engine && o) noexcept = delete;
    public:     friend command::event::generator;
    };

    template <class commandable, typename outputable>
    inline templateable::command::subscription<commandable, outputable> * engine::genericReg(commandable * object, unsigned int properties, const typename templateable::command::event::callback<commandable, outputable>::set & eventSet) const {
        pokemon_develop_check(generator.command == nullptr, return nullptr);

        return genericCommandGet()->genericReg(object, properties, eventSet);
    }

    template <class commandable, typename outputable>
    inline templateable::command::subscription<commandable, outputable> * engine::genericReg(commandable * object, unsigned int properties, const typename templateable::command::event::callback<commandable, outputable>::set & eventSet, typename templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn) const {
        pokemon_develop_check(generator.command == nullptr, return nullptr);

        return genericCommandGet()->genericReg(object, properties, eventSet, subscriptionOn);
    }

    template <class commandable, typename outputable>
    inline templateable::command::subscription<commandable, outputable> * engine::genericReg(commandable * object, unsigned int properties, const typename templateable::command::event::callback<commandable, outputable>::set & eventSet, typename templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_develop_check(generator.command == nullptr, return nullptr);

        return genericCommandGet()->genericReg(object, properties, eventSet, subscriptionReleaseOn);
    }

    template <class commandable, typename outputable>
    inline templateable::command::subscription<commandable, outputable> * engine::genericReg(commandable * object, unsigned int properties, const typename templateable::command::event::callback<commandable, outputable>::set & eventSet, typename templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn, typename templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_develop_check(generator.command == nullptr, return nullptr);

        return genericCommandGet()->genericReg(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn);
    }

}

#endif // __POKEMONISM_SDK_TEMPLATEABLE_ENGINE_HH__