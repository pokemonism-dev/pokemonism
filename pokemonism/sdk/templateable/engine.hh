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
    public:     virtual int on(bootstrapper bootstrap = nullptr);
    protected:  void off(pokemonism::sdk::engine::terminator f) override { pokemonism::sdk::engine::off(f); }
    public:     virtual void off(terminator f) { off(reinterpret_cast<pokemonism::sdk::engine::terminator>(f)); }
    protected:  inline pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command::event::subscription * subscription) const override { return pokemonism::sdk::engine::reg(subscription); }
    public:     inline pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * object, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet) const override { return pokemonism::sdk::engine::reg(object, properties, eventSet); }
    public:     inline pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * object, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn) const override { return pokemonism::sdk::engine::reg(object, properties, eventSet, subscriptionOn); }
    public:     inline pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * object, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const override { return pokemonism::sdk::engine::reg(object, properties, eventSet, subscriptionReleaseOn); }
    public:     inline pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * object, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const override { return pokemonism::sdk::engine::reg(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn); }
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> static inline templateable::command::subscription<commandable, outputable> * commandReg(pokemonism::sdk::templateable::engine * engine, commandable * object, unsigned int properties, const templateable::command::event::callback<commandable, outputable>::set & eventSet);
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> static inline templateable::command::subscription<commandable, outputable> * commandReg(pokemonism::sdk::templateable::engine * engine, commandable * object, unsigned int properties, const templateable::command::event::callback<commandable, outputable>::set & eventSet, templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn);
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> static inline templateable::command::subscription<commandable, outputable> * commandReg(pokemonism::sdk::templateable::engine * engine, commandable * object, unsigned int properties, const templateable::command::event::callback<commandable, outputable>::set & eventSet, templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn);
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> static inline templateable::command::subscription<commandable, outputable> * commandReg(pokemonism::sdk::templateable::engine * engine, commandable * object, unsigned int properties, const templateable::command::event::callback<commandable, outputable>::set & eventSet, templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn, templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn);
    public:     inline engine(void) {}
    public:     inline ~engine(void) override {}
    public:     engine(const engine & o) = delete;
    public:     engine(engine && o) noexcept = delete;
    public:     engine & operator=(const engine & o) = delete;
    public:     engine & operator=(engine && o) noexcept = delete;
    public:     friend command::event::generator;
    };

    template <class commandable, typename outputable>
    inline templateable::command::subscription<commandable, outputable> * engine::commandReg(pokemonism::sdk::templateable::engine * engine, commandable * object, unsigned int properties, const typename templateable::command::event::callback<commandable, outputable>::set & eventSet) {
        pokemon_develop_check(engine->generator.command == nullptr, return nullptr);

        // return static_cast<templateable::command::event::generator *>(reinterpret_cast<void *>(engine->generator.command))->reg<commandable, outputable>(object, properties, eventSet);

        return templateable::command::event::generator::commandReg(static_cast<templateable::command::event::generator *>(reinterpret_cast<void *>(engine->generator.command)), object, properties, eventSet);
    }

    template <class commandable, typename outputable>
    inline templateable::command::subscription<commandable, outputable> * engine::commandReg(pokemonism::sdk::templateable::engine * engine, commandable * object, unsigned int properties, const typename templateable::command::event::callback<commandable, outputable>::set & eventSet, typename templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn) {
        pokemon_develop_check(engine->generator.command == nullptr, return nullptr);

        // return static_cast<templateable::command::event::generator *>(reinterpret_cast<void *>(engine->generator.command))->reg<outputable, commandable>(object, properties, eventSet, subscriptionOn);

        return templateable::command::event::generator::commandReg(static_cast<templateable::command::event::generator *>(reinterpret_cast<void *>(engine->generator.command)), object, properties, eventSet, subscriptionOn);
    }

    template <class commandable, typename outputable>
    inline templateable::command::subscription<commandable, outputable> * engine::commandReg(pokemonism::sdk::templateable::engine * engine, commandable * object, unsigned int properties, const typename templateable::command::event::callback<commandable, outputable>::set & eventSet, typename templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) {
        pokemon_develop_check(engine->generator.command == nullptr, return nullptr);

        // return static_cast<templateable::command::event::generator *>(reinterpret_cast<void *>(engine->generator.command))->reg<commandable, outputable>(object, properties, eventSet, subscriptionReleaseOn);

        return templateable::command::event::generator::commandReg(static_cast<templateable::command::event::generator *>(reinterpret_cast<void *>(engine->generator.command)), object, properties, eventSet, subscriptionReleaseOn);
    }

    template <class commandable, typename outputable>
    inline templateable::command::subscription<commandable, outputable> * engine::commandReg(pokemonism::sdk::templateable::engine * engine, commandable * object, unsigned int properties, const typename templateable::command::event::callback<commandable, outputable>::set & eventSet, typename templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn, typename templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) {
        pokemon_develop_check(engine->generator.command == nullptr, return nullptr);

        // return static_cast<templateable::command::event::generator *>(reinterpret_cast<void *>(engine->generator.command))->reg<commandable, outputable>(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn);
        return templateable::command::event::generator::commandReg(static_cast<templateable::command::event::generator *>(reinterpret_cast<void *>(engine->generator.command)), object, properties, eventSet, subscriptionOn, subscriptionReleaseOn);
    }

}

#endif // __POKEMONISM_SDK_TEMPLATEABLE_ENGINE_HH__