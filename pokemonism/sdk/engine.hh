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
    public:     typedef void (*terminator)(engine &);
    public:     typedef void (*bootstrapper)(engine &);
    protected:  struct set {
                public:     command::event::generator * command;
                public:     inline set(void) : command(nullptr) {}
                };
    protected:  terminator cancel;
    protected:  event::queue * queue;
    protected:  engine::set generator;
    protected:  inline event * add(event * e) const;
    protected:  inline event * del(event * e) const;
    public:     virtual int on(bootstrapper bootstrap = nullptr);
    public:     virtual void off(terminator f);
    public:     virtual int run(void);
    public:     inline command::event::subscription * reg(command * object, unsigned int properties, const command::event::callback::set & eventSet) const;
    public:     inline command::event::subscription * reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn) const;
    public:     inline command::event::subscription * reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::modifier subscriptionReleaseOn) const;
    public:     inline command::event::subscription * reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn, command::event::subscription::state::callback::modifier subscriptionReleaseOn) const;
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

    inline command::event::subscription * engine::reg(command * object, unsigned int properties, const command::event::callback::set & eventSet) const {
        return queue != nullptr ? generator.command->reg(object, properties, eventSet) : nullptr;
    }

    inline command::event::subscription * engine::reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn) const {
        return queue != nullptr ? generator.command->reg(object, properties, eventSet, subscriptionOn) : nullptr;
    }

    inline command::event::subscription * engine::reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::modifier subscriptionReleaseOn) const {
        return queue != nullptr ? generator.command->reg(object, properties, eventSet, subscriptionReleaseOn) : nullptr;
    }

    inline command::event::subscription * engine::reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn, command::event::subscription::state::callback::modifier subscriptionReleaseOn) const {
        return queue != nullptr ? generator.command->reg(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn) : nullptr;
    }

}

#endif // __POKEMONISM_SDK_ENGINE_HH__