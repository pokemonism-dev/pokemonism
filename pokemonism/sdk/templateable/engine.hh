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
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> inline static templateable::command::subscription<outputable, commandable> * commandReg(pokemonism::sdk::templateable::engine * engine, commandable * object, unsigned int properties, const templateable::command::event::callback<outputable, commandable>::set & eventSet, templateable::command::subscription<outputable, commandable>::state::callback::function subscriptionOn);
    protected:  struct set {
                public:     pokemonism::sdk::command::event::generator * command;
                public:     inline set(void) : command(nullptr) {}
                };
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
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> inline templateable::command::subscription<outputable, commandable> * reg(commandable * object, unsigned int properties, const templateable::command::event::callback<outputable, commandable>::set & eventSet) const;
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> inline templateable::command::subscription<outputable, commandable> * reg(commandable * object, unsigned int properties, const templateable::command::event::callback<outputable, commandable>::set & eventSet, typename templateable::command::subscription<outputable, commandable>::state::callback::function subscriptionOn) const;
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> inline templateable::command::subscription<outputable, commandable> * reg(commandable * object, unsigned int properties, const templateable::command::event::callback<outputable, commandable>::set & eventSet, typename templateable::command::subscription<outputable, commandable>::state::callback::modifier subscriptionReleaseOn) const;
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> inline templateable::command::subscription<outputable, commandable> * reg(commandable * object, unsigned int properties, const templateable::command::event::callback<outputable, commandable>::set & eventSet, typename templateable::command::subscription<outputable, commandable>::state::callback::function subscriptionOn, typename templateable::command::subscription<outputable, commandable>::state::callback::modifier subscriptionReleaseOn) const;
    public:     inline engine(void) {}
    public:     inline ~engine(void) override {}
    public:     engine(const engine & o) = delete;
    public:     engine(engine && o) noexcept = delete;
    public:     engine & operator=(const engine & o) = delete;
    public:     engine & operator=(engine && o) noexcept = delete;
    public:     friend command::event::generator;
    };

    template <typename outputable, class commandable>
    inline templateable::command::subscription<outputable, commandable> * engine::reg(commandable * object, unsigned int properties, const typename templateable::command::event::callback<outputable, commandable>::set & eventSet) const {
        pokemon_develop_check(generator.command == nullptr, return nullptr);

        return static_cast<templateable::command::event::generator *>(reinterpret_cast<void *>(generator.command))->reg<outputable, commandable>(object, properties, eventSet);
    }

    template <typename outputable, class commandable>
    inline templateable::command::subscription<outputable, commandable> * engine::commandReg(pokemonism::sdk::templateable::engine * engine, commandable * object, unsigned int properties, const typename templateable::command::event::callback<outputable, commandable>::set & eventSet, typename templateable::command::subscription<outputable, commandable>::state::callback::function subscriptionOn) {
        return engine->reg(object, properties, eventSet, subscriptionOn);
    }

    template <typename outputable, class commandable>
    inline templateable::command::subscription<outputable, commandable> * engine::reg(commandable * object, unsigned int properties, const typename templateable::command::event::callback<outputable, commandable>::set & eventSet, typename templateable::command::subscription<outputable, commandable>::state::callback::function subscriptionOn) const {
        pokemon_develop_check(generator.command == nullptr, return nullptr);

        return static_cast<templateable::command::event::generator *>(reinterpret_cast<void *>(generator.command))->reg<outputable, commandable>(object, properties, eventSet, subscriptionOn);
    }

    template <typename outputable, class commandable>
    inline templateable::command::subscription<outputable, commandable> * engine::reg(commandable * object, unsigned int properties, const typename templateable::command::event::callback<outputable, commandable>::set & eventSet, typename templateable::command::subscription<outputable, commandable>::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_develop_check(generator.command == nullptr, return nullptr);

        return static_cast<templateable::command::event::generator *>(reinterpret_cast<void *>(generator.command))->reg<outputable, commandable>(object, properties, eventSet, subscriptionReleaseOn);
    }

    template <typename outputable, class commandable>
    inline templateable::command::subscription<outputable, commandable> * engine::reg(commandable * object, unsigned int properties, const typename templateable::command::event::callback<outputable, commandable>::set & eventSet, typename templateable::command::subscription<outputable, commandable>::state::callback::function subscriptionOn, typename templateable::command::subscription<outputable, commandable>::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_develop_check(generator.command == nullptr, return nullptr);

        return static_cast<templateable::command::event::generator *>(reinterpret_cast<void *>(generator.command))->reg<outputable, commandable>(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn);
    }

}

#endif // __POKEMONISM_SDK_TEMPLATEABLE_ENGINE_HH__