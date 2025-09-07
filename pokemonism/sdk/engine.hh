/**
 * @file            pokemonism/sdk/engine.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_SDK_ENGINE_HH__
#define   __POKEMONISM_SDK_ENGINE_HH__

#include <pokemonism/sdk/command.hh>

namespace pokemonism::sdk {

    class engine : public sync {
    protected:  struct set {
                public:     pokemonism::sdk::command::event::generator * command;
                public:     inline set(void) : command(nullptr) {}
                };
    public:     typedef void (*terminator)(engine &);
    public:     typedef void (*bootstrapper)(engine &, event::queue **, engine::set &);
    protected:  terminator cancel;
    protected:  event::queue * queue;
    protected:  engine::set generator;
    protected:  inline event * add(event * e) const;
    protected:  inline event * del(event * e) const;
    public:     virtual int on(bootstrapper bootstrap = nullptr);
    public:     virtual void off(terminator f);
    public:     virtual int run(void);
    protected:  virtual inline command::event::subscription * reg(command::event::subscription * subscription) const;
    public:     virtual inline command::event::subscription * reg(command * object, unsigned int properties, const command::event::callback::set & eventSet) const;
    public:     virtual inline command::event::subscription * reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn) const;
    public:     virtual inline command::event::subscription * reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::modifier subscriptionReleaseOn) const;
    public:     virtual inline command::event::subscription * reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn, command::event::subscription::state::callback::modifier subscriptionReleaseOn) const;
    public:     engine(void);
    public:     ~engine(void) override;
    public:     engine(const engine & o) = delete;
    public:     engine(engine && o) noexcept = delete;
    public:     engine & operator=(const engine & o) = delete;
    public:     engine & operator=(engine && o) noexcept = delete;
    public:     friend command::event::generator;
    };

    inline event * engine::add(event * e) const {
        return queue->add(e);
    }

    inline event * engine::del(event * e) const {
        return queue->del(e);
    }

    inline command::event::subscription * engine::reg(command::event::subscription * subscription) const {
        pokemon_develop_check(queue == nullptr || generator.command == nullptr || subscription == nullptr, do {
            if (subscription != nullptr) delete subscription;
            return nullptr;
        } while (0));

        return generator.command->reg(subscription);
    }

    inline command::event::subscription * engine::reg(command * object, unsigned int properties, const command::event::callback::set & eventSet) const {
        pokemon_develop_check(queue == nullptr || generator.command == nullptr, do {
            if (properties & command::event::subscription::property::release_object_on_rel) delete object;
            return nullptr;
        } while (0));

        return generator.command->reg(object, properties, eventSet);
    }

    inline command::event::subscription * engine::reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn) const {
        pokemon_develop_check(queue == nullptr || generator.command == nullptr, do {
            if (properties & command::event::subscription::property::release_object_on_rel) delete object;
            return nullptr;
        } while (0));
        return generator.command->reg(object, properties, eventSet, subscriptionOn);
    }

    inline command::event::subscription * engine::reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_develop_check(queue == nullptr || generator.command == nullptr, do {
            if (properties & command::event::subscription::property::release_object_on_rel) delete object;
            return nullptr;
        } while (0));
        return generator.command->reg(object, properties, eventSet, subscriptionReleaseOn);
    }

    inline command::event::subscription * engine::reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn, command::event::subscription::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_develop_check(queue == nullptr || generator.command == nullptr, do {
            if (properties & command::event::subscription::property::release_object_on_rel) delete object;
            return nullptr;
        } while (0));
        return generator.command->reg(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn);
    }

}

#endif // __POKEMONISM_SDK_ENGINE_HH__