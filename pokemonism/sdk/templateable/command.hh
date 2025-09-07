/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 07, 2025
 */

#ifndef   __POKEMONISM_SDK_TEMPLATEABLE_COMMAND_HH__
#define   __POKEMONISM_SDK_TEMPLATEABLE_COMMAND_HH__

#include <pokemonism/sdk/generic/command.hh>

#include "command.hh"

namespace pokemonism::sdk::templateable {

    struct command {
    public:     using exception = pokemonism::sdk::command::event::exception;
    public:     class event;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> class link;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> class envelope;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> class subscription;
    public:     class generator;
    public:     struct modifiable;
    public:     struct releasable;
    public:     struct internal;
    public:     struct subscriptionable;
    };

    class command::event : public pokemonism::sdk::command::event {
    public:     class generator;
    public:     using type = pokemonism::sdk::command::event::type;
    public:     using exception = pokemonism::sdk::command::event::exception;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> struct callback;
    public:     inline event(unsigned int identifier, pokemonism::sdk::command::event::link * node) : pokemonism::sdk::command::event(identifier, node) {}
    protected:  event(void) {}
    public:     inline ~event(void) override {}
    public:     event(const command::event & o) = delete;
    public:     event(command::event && o) noexcept = delete;
    public:     command::event & operator=(const command::event & o) = delete;
    public:     command::event & operator=(command::event && o) noexcept = delete;
    };

    template <class commandable, typename outputable>
    struct command::event::callback : public pokemonism::sdk::command::event::callback {
    public:     typedef void (*function)(commandable &, unsigned int, command::envelope<commandable, outputable> &, const command::exception *);
    public:     inline callback(void) {}
    public:     inline explicit callback(command::event::callback<commandable, outputable>::function f) : pokemonism::sdk::command::event::callback(reinterpret_cast<pokemonism::sdk::command::event::callback::function>(f)) {}
    public:     inline ~callback(void) {}
    public:     struct set;
    };

    template <class commandable, typename outputable>
    struct command::event::callback<commandable, outputable>::set : public pokemonism::sdk::command::event::callback::set {
    public:     inline set(void) {}
    public:     inline explicit set(command::event::callback<commandable, outputable>::function execute) : pokemonism::sdk::command::event::callback::set(reinterpret_cast<pokemonism::sdk::command::event::callback::function>(execute)) {}
    public:     inline ~set(void) {}
    public:     inline set(const command::event::callback<commandable, outputable>::set & o) : pokemonism::sdk::command::event::callback::set(o) {}
    public:     inline set(command::event::callback<commandable, outputable>::set && o) noexcept : pokemonism::sdk::command::event::callback::set(std::move(o)) {}
    public:     inline command::event::callback<commandable, outputable>::set & operator=(const command::event::callback<commandable, outputable>::set & o) { return pokemonism::sdk::command::event::callback::set::operator=(o); }
    public:     inline command::event::callback<commandable, outputable>::set & operator=(command::event::callback<commandable, outputable>::set && o) noexcept { return pokemonism::sdk::command::event::callback::set::operator=(std::move(o)); }
    };

    struct command::modifiable {
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> class subscription;
    };

    struct command::releasable {
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> class subscription;
    };

    struct command::internal {
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> class subscription;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> class event;
    };

    template <class commandable, typename outputable>
    class command::internal::event : public command::event {
    public:     using type = pokemonism::sdk::command::event::type;
    public:     using exception = pokemonism::sdk::command::event::exception;
    public:     using callback = command::event::callback<commandable, outputable>;
    public:     inline event(unsigned int identifier, command::link<commandable, outputable> * node) : command::event(identifier, node) {}
    protected:  event(void) {}
    public:     inline ~event(void) override {}
    public:     event(const command::internal::event<commandable, outputable> & o) = delete;
    public:     event(command::internal::event<commandable, outputable> && o) noexcept = delete;
    public:     command::internal::event<commandable, outputable> & operator=(const command::internal::event<commandable, outputable> & o) = delete;
    public:     command::internal::event<commandable, outputable> & operator=(command::internal::event<commandable, outputable> && o) noexcept = delete;
    };

    template <class commandable, typename outputable>
    class command::envelope : public pokemonism::sdk::command::event::link {
    public:     inline outputable * messagePop(void) override { return reinterpret_cast<outputable *>(output); }
    public:     inline command::subscription<commandable, outputable> * subscriptionGet(void) const override { return reinterpret_cast<command::subscription<commandable, outputable> *>(container); }
    public:     inline explicit envelope(pokemonism::sdk::event::exception * exception) : pokemonism::sdk::command::event::link(exception) {}
    public:     inline explicit envelope(command::subscription<commandable, outputable> * container, pokemonism::sdk::event::exception * exception = nullptr) : pokemonism::sdk::command::event::link(exception) { this->container = container; }
    protected:  inline envelope(void) {}
    protected:  inline ~envelope(void) override {}
    public:     envelope(const command::envelope<commandable, outputable> & o) = delete;
    public:     envelope(command::envelope<commandable, outputable> && o) noexcept = delete;
    public:     command::envelope<commandable, outputable> & operator=(const command::envelope<commandable, outputable> & o) = delete;
    public:     command::envelope<commandable, outputable> & operator=(command::envelope<commandable, outputable> && o) noexcept = delete;
    public:     friend command::subscription<commandable, outputable>;
    };

    template <class commandable, typename outputable>
    class command::link : public command::envelope<commandable, outputable> {
    public:     inline explicit link(command::subscription<commandable, outputable> * container) { subscriptionReg(container); }
    public:     inline explicit link(command::exception * exception) : command::envelope<commandable, outputable>(exception) {}
    public:     inline link(void) {}
    public:     inline ~link(void) override {}
    public:     link(const command::link<commandable, outputable> & o) = delete;
    public:     link(command::link<commandable, outputable> && o) noexcept = delete;
    public:     command::link<commandable, outputable> & operator=(const command::link<commandable, outputable> & o) = delete;
    public:     command::link<commandable, outputable> & operator=(command::link<commandable, outputable> && o) noexcept = delete;
    };

    template <class commandable, typename outputable>
    class command::subscription : public pokemonism::sdk::command::event::internal::subscription {
    public:     struct state : public pokemonism::sdk::command::event::internal::subscription::state {
                public:     struct callback : public pokemonism::sdk::command::event::internal::subscription::state::callback {
                            public:     typedef void (*function)(command::modifiable::subscription<commandable, outputable> &, unsigned int, const command::exception *);
                            public:     typedef void (*modifier)(command::releasable::subscription<commandable, outputable> &, unsigned int, const command::exception *);
                            public:     inline callback(void) {}
                            public:     inline explicit callback(command::subscription<commandable, outputable>::state::callback::function f) : pokemonism::sdk::command::event::internal::subscription::state::callback(reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::function>(f)) {}
                            public:     inline ~callback(void) { func = nullptr; }
                            public:     struct set : public pokemonism::sdk::command::event::internal::subscription::state::callback::set {
                                        public:     inline set(void) {}
                                        public:     inline explicit set(command::subscription<commandable, outputable>::state::callback::function on) : pokemonism::sdk::command::event::internal::subscription::state::callback::set(reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::function>(on)) {}
                                        public:     inline explicit set(command::subscription<commandable, outputable>::state::callback::modifier rel) : pokemonism::sdk::command::event::internal::subscription::state::callback::set(reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::modifier>(rel)) {}
                                        public:     inline explicit set(command::subscription<commandable, outputable>::state::callback::function on, command::subscription<commandable, outputable>::state::callback::modifier rel) : pokemonism::sdk::command::event::internal::subscription::state::callback::set(reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::function>(on), reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::modifier>(rel)) {}
                                        };
                            };
                };
    protected:  void callbackOn(unsigned int type, pokemonism::sdk::event::envelope & envelope, const pokemonism::sdk::event::exception * problem = nullptr) override { return pokemonism::sdk::command::event::subscription::callbackOn(type, envelope, problem); }
    protected:  void callbackOn(unsigned int type, const pokemonism::sdk::event::exception * problem = nullptr) override;
    protected:  inline explicit subscription(commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet) : pokemonism::sdk::command::event::internal::subscription(reinterpret_cast<pokemonism::sdk::command *>(object), properties, reinterpret_cast<const pokemonism::sdk::command::event::callback::set &>(eventSet)) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet, command::subscription<commandable, outputable>::state::callback::function subscriptionOn) : pokemonism::sdk::command::event::internal::subscription(reinterpret_cast<pokemonism::sdk::command *>(object), properties, reinterpret_cast<const pokemonism::sdk::command::event::callback::set &>(eventSet), reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::function>(subscriptionOn)) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet, command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) : pokemonism::sdk::command::event::internal::subscription(reinterpret_cast<pokemonism::sdk::command *>(object), properties, reinterpret_cast<const pokemonism::sdk::command::event::callback::set &>(eventSet), reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::modifier>(subscriptionReleaseOn)) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet, command::subscription<commandable, outputable>::state::callback::function subscriptionOn, command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) : pokemonism::sdk::command::event::internal::subscription(reinterpret_cast<pokemonism::sdk::command *>(object), properties, reinterpret_cast<const pokemonism::sdk::command::event::callback::set &>(eventSet), reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::function>(subscriptionOn), reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::modifier>(subscriptionReleaseOn)) {}
    protected:  inline subscription(void) = delete;
    protected:  ~subscription(void) override {}
    public:     subscription(const command::subscription<commandable, outputable> & o) = delete;
    public:     subscription(command::subscription<commandable, outputable> && o) noexcept = delete;
    public:     command::subscription<commandable, outputable> & operator=(const command::subscription<commandable, outputable> & o) = delete;
    public:     command::subscription<commandable, outputable> & operator=(command::subscription<commandable, outputable> && o) noexcept = delete;
    };

    template <class commandable, typename outputable>
    class command::modifiable::subscription : public command::subscription<commandable, outputable> {
    protected:  inline explicit subscription(commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet) : command::subscription<commandable, outputable>(object, properties, eventSet) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet, command::subscription<commandable, outputable>::state::callback::function subscriptionOn) : command::subscription<commandable, outputable>(object, properties, eventSet, subscriptionOn) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet, command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) : command::subscription<commandable, outputable>(object, properties, eventSet, subscriptionReleaseOn) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet, command::subscription<commandable, outputable>::state::callback::function subscriptionOn, command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) : command::subscription<commandable, outputable>(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn) {}
    protected:  inline subscription(void) = delete;
    protected:  ~subscription(void) override {}
    public:     subscription(const command::modifiable::subscription<commandable, outputable> & o) = delete;
    public:     subscription(command::modifiable::subscription<commandable, outputable> && o) noexcept = delete;
    public:     command::modifiable::subscription<commandable, outputable> & operator=(const command::modifiable::subscription<commandable, outputable> & o) = delete;
    public:     command::modifiable::subscription<commandable, outputable> & operator=(command::modifiable::subscription<commandable, outputable> && o) noexcept = delete;
    };

    template <class commandable, typename outputable>
    class command::releasable::subscription : public command::modifiable::subscription<commandable, outputable> {
    public:     inline commandable * objectPop(void) override {
                    commandable * o = reinterpret_cast<commandable *>(this->object);
                    this->object = nullptr;
                    return o;
                }
    protected:  inline explicit subscription(commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet) : command::modifiable::subscription<commandable, outputable>(object, properties, eventSet) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet, command::subscription<commandable, outputable>::state::callback::function subscriptionOn) : command::modifiable::subscription<commandable, outputable>(object, properties, eventSet, subscriptionOn) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet, command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) : command::modifiable::subscription<commandable, outputable>(object, properties, eventSet, subscriptionReleaseOn) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet, command::subscription<commandable, outputable>::state::callback::function subscriptionOn, command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) : command::modifiable::subscription<commandable, outputable>(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn) {}
    protected:  inline subscription(void) = delete;
    protected:  ~subscription(void) override {}
    public:     subscription(const command::releasable::subscription<commandable, outputable> & o) = delete;
    public:     subscription(command::releasable::subscription<commandable, outputable> && o) noexcept = delete;
    public:     command::releasable::subscription<commandable, outputable> & operator=(const command::releasable::subscription<commandable, outputable> & o) = delete;
    public:     command::releasable::subscription<commandable, outputable> & operator=(command::releasable::subscription<commandable, outputable> && o) noexcept = delete;
    };

    template <class commandable, typename outputable>
    class command::internal::subscription : public command::releasable::subscription<commandable, outputable> {
    protected:  inline commandable * objectPop(void) override {
                    commandable * o = reinterpret_cast<commandable *>(this->object);
                    this->object = nullptr;
                    return o;
                }
    protected:  inline explicit subscription(commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet) : command::releasable::subscription<commandable, outputable>(object, properties, eventSet) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet, command::subscription<commandable, outputable>::state::callback::function subscriptionOn) : command::releasable::subscription<commandable, outputable>(object, properties, eventSet, subscriptionOn) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet, command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) : command::releasable::subscription<commandable, outputable>(object, properties, eventSet, subscriptionReleaseOn) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet, command::subscription<commandable, outputable>::state::callback::function subscriptionOn, command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) : command::releasable::subscription<commandable, outputable>(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn) {}
    protected:  inline subscription(void) = delete;
    protected:  ~subscription(void) override {}
    public:     subscription(const command::internal::subscription<commandable, outputable> & o) = delete;
    public:     subscription(command::internal::subscription<commandable, outputable> && o) noexcept = delete;
    public:     command::internal::subscription<commandable, outputable> & operator=(const command::internal::subscription<commandable, outputable> & o) = delete;
    public:     command::internal::subscription<commandable, outputable> & operator=(command::internal::subscription<commandable, outputable> && o) noexcept = delete;
    public:     friend command::event::generator;
    };

    class command::event::generator : public pokemonism::sdk::command::event::generator {
    // public:     inline pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command::event::subscription * subscription) override { return pokemonism::sdk::command::event::generator::reg(subscription); }
    // public:     inline pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * object, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet) override { return pokemonism::sdk::command::event::generator::reg(object, properties, eventSet); }
    // public:     inline pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * object, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn) override { return pokemonism::sdk::command::event::generator::reg(object, properties, eventSet, subscriptionOn); }
    // public:     inline pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * object, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) override { return pokemonism::sdk::command::event::generator::reg(object, properties, eventSet, subscriptionReleaseOn); }
    // public:     inline pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * object, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) override { return pokemonism::sdk::command::event::generator::reg(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn); }
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline static command::subscription<commandable, outputable> * commandReg(command::event::generator * o, command::subscription<commandable, outputable> * subscription);
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline static command::subscription<commandable, outputable> * commandReg(command::event::generator * o, commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet);
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline static command::subscription<commandable, outputable> * commandReg(command::event::generator * o, commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet, command::subscription<commandable, outputable>::state::callback::function subscriptionOn);
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline static command::subscription<commandable, outputable> * commandReg(command::event::generator * o, commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet, command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn);
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline static command::subscription<commandable, outputable> * commandReg(command::event::generator * o, commandable * object, unsigned int properties, const command::event::callback<commandable, outputable>::set & eventSet, command::subscription<commandable, outputable>::state::callback::function subscriptionOn, command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn);
    public:     inline explicit generator(pokemonism::sdk::engine * engine);
    public:     generator(void) = delete;
    public:     inline ~generator(void) override;
    public:     generator(const command::event::generator & o) = delete;
    public:     generator(command::event::generator && o) noexcept = delete;
    public:     command::event::generator & operator=(const command::event::generator & o) = delete;
    public:     command::event::generator & operator=(command::event::generator && o) noexcept = delete;
    };

}

// ReSharper disable CppUnusedIncludeDirective
#include <pokemonism/sdk/templateable/command/subscription.hh>
#include <pokemonism/sdk/templateable/command/event/generator.hh>
// ReSharper restore CppUnusedIncludeDirective

#endif // __POKEMONISM_SDK_TEMPLATEABLE_COMMAND_HH__