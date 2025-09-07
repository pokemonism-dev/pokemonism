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
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> class link;
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> class envelope;
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> class subscription;
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
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> struct callback;
    public:     inline event(unsigned int identifier, pokemonism::sdk::command::event::link * node) : pokemonism::sdk::command::event(identifier, node) {}
    protected:  event(void) {}
    public:     inline ~event(void) override {}
    public:     event(const command::event & o) = delete;
    public:     event(command::event && o) noexcept = delete;
    public:     command::event & operator=(const command::event & o) = delete;
    public:     command::event & operator=(command::event && o) noexcept = delete;
    };

    template <typename outputable, class commandable>
    struct command::event::callback : public pokemonism::sdk::command::event::callback {
    public:     typedef void (*function)(commandable &, unsigned int, command::envelope<outputable, commandable> &, const command::exception *);
    public:     inline callback(void) {}
    public:     inline explicit callback(command::event::callback<outputable, commandable>::function f) : pokemonism::sdk::command::event::callback(reinterpret_cast<pokemonism::sdk::command::event::callback::function>(f)) {}
    public:     inline ~callback(void) {}
    public:     struct set;
    };

    template <typename outputable, class commandable>
    struct command::event::callback<outputable, commandable>::set : public pokemonism::sdk::command::event::callback::set {
    public:     inline set(void) {}
    public:     inline explicit set(command::event::callback<outputable, commandable>::function execute) : pokemonism::sdk::command::event::callback::set(reinterpret_cast<pokemonism::sdk::command::event::callback::function>(execute)) {}
    public:     inline ~set(void) {}
    public:     inline set(const command::event::callback<outputable, commandable>::set & o) : pokemonism::sdk::command::event::callback::set(o) {}
    public:     inline set(command::event::callback<outputable, commandable>::set && o) noexcept : pokemonism::sdk::command::event::callback::set(std::move(o)) {}
    public:     inline command::event::callback<outputable, commandable>::set & operator=(const command::event::callback<outputable, commandable>::set & o) { return pokemonism::sdk::command::event::callback::set::operator=(o); }
    public:     inline command::event::callback<outputable, commandable>::set & operator=(command::event::callback<outputable, commandable>::set && o) noexcept { return pokemonism::sdk::command::event::callback::set::operator=(std::move(o)); }
    };

    struct command::modifiable {
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> class subscription;
    };

    struct command::releasable {
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> class subscription;
    };

    struct command::internal {
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> class subscription;
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> class event;
    };

    template <typename outputable, class commandable>
    class command::internal::event : public command::event {
    public:     using type = pokemonism::sdk::command::event::type;
    public:     using exception = pokemonism::sdk::command::event::exception;
    public:     using callback = command::event::callback<outputable, commandable>;
    public:     inline event(unsigned int identifier, command::link<outputable, commandable> * node) : command::event(identifier, node) {}
    protected:  event(void) {}
    public:     inline ~event(void) override {}
    public:     event(const command::internal::event<outputable, commandable> & o) = delete;
    public:     event(command::internal::event<outputable, commandable> && o) noexcept = delete;
    public:     command::internal::event<outputable, commandable> & operator=(const command::internal::event<outputable, commandable> & o) = delete;
    public:     command::internal::event<outputable, commandable> & operator=(command::internal::event<outputable, commandable> && o) noexcept = delete;
    };

    template <typename outputable, class commandable>
    class command::envelope : public pokemonism::sdk::command::event::link {
    public:     inline outputable * messagePop(void) override { return reinterpret_cast<outputable *>(output); }
    public:     inline command::subscription<outputable, commandable> * subscriptionGet(void) const override { return reinterpret_cast<command::subscription<outputable, commandable> *>(container); }
    public:     inline explicit envelope(pokemonism::sdk::event::exception * exception) : pokemonism::sdk::command::event::link(exception) {}
    public:     inline explicit envelope(command::subscription<outputable, commandable> * container, pokemonism::sdk::event::exception * exception = nullptr) : pokemonism::sdk::command::event::link(exception) { this->container = container; }
    protected:  inline envelope(void) {}
    protected:  inline ~envelope(void) override {}
    public:     envelope(const command::envelope<outputable, commandable> & o) = delete;
    public:     envelope(command::envelope<outputable, commandable> && o) noexcept = delete;
    public:     command::envelope<outputable, commandable> & operator=(const command::envelope<outputable, commandable> & o) = delete;
    public:     command::envelope<outputable, commandable> & operator=(command::envelope<outputable, commandable> && o) noexcept = delete;
    public:     friend command::subscription<outputable, commandable>;
    };

    template <typename outputable, class commandable>
    class command::link : public command::envelope<outputable, commandable> {
    public:     inline explicit link(command::subscription<outputable, commandable> * container) { subscriptionReg(container); }
    public:     inline explicit link(command::exception * exception) : command::envelope<outputable, commandable>(exception) {}
    public:     inline link(void) {}
    public:     inline ~link(void) override {}
    public:     link(const command::link<outputable, commandable> & o) = delete;
    public:     link(command::link<outputable, commandable> && o) noexcept = delete;
    public:     command::link<outputable, commandable> & operator=(const command::link<outputable, commandable> & o) = delete;
    public:     command::link<outputable, commandable> & operator=(command::link<outputable, commandable> && o) noexcept = delete;
    };

    template <typename outputable, class commandable>
    class command::subscription : public pokemonism::sdk::command::event::internal::subscription {
    public:     struct state : public pokemonism::sdk::command::event::internal::subscription::state {
                public:     struct callback : public pokemonism::sdk::command::event::internal::subscription::state::callback {
                            public:     typedef void (*function)(command::modifiable::subscription<outputable, commandable> &, unsigned int, const command::exception *);
                            public:     typedef void (*modifier)(command::releasable::subscription<outputable, commandable> &, unsigned int, const command::exception *);
                            public:     inline callback(void) {}
                            public:     inline explicit callback(command::subscription<outputable, commandable>::state::callback::function f) : pokemonism::sdk::command::event::internal::subscription::state::callback(reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::function>(f)) {}
                            public:     inline ~callback(void) { func = nullptr; }
                            public:     struct set : public pokemonism::sdk::command::event::internal::subscription::state::callback::set {
                                        public:     inline set(void) {}
                                        public:     inline explicit set(command::subscription<outputable, commandable>::state::callback::function on) : pokemonism::sdk::command::event::internal::subscription::state::callback::set(reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::function>(on)) {}
                                        public:     inline explicit set(command::subscription<outputable, commandable>::state::callback::modifier rel) : pokemonism::sdk::command::event::internal::subscription::state::callback::set(reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::modifier>(rel)) {}
                                        public:     inline explicit set(command::subscription<outputable, commandable>::state::callback::function on, command::subscription<outputable, commandable>::state::callback::modifier rel) : pokemonism::sdk::command::event::internal::subscription::state::callback::set(reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::function>(on), reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::modifier>(rel)) {}
                                        };
                            };
                };
    protected:  void callbackOn(unsigned int type, pokemonism::sdk::event::envelope & envelope, const pokemonism::sdk::event::exception * problem = nullptr) override { return pokemonism::sdk::command::event::subscription::callbackOn(type, envelope, problem); }
    protected:  void callbackOn(unsigned int type, const pokemonism::sdk::event::exception * problem = nullptr) override;
    protected:  inline explicit subscription(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet) : pokemonism::sdk::command::event::internal::subscription(reinterpret_cast<pokemonism::sdk::command *>(object), properties, reinterpret_cast<const pokemonism::sdk::command::event::callback::set &>(eventSet)) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet, command::subscription<outputable, commandable>::state::callback::function subscriptionOn) : pokemonism::sdk::command::event::internal::subscription(reinterpret_cast<pokemonism::sdk::command *>(object), properties, reinterpret_cast<const pokemonism::sdk::command::event::callback::set &>(eventSet), reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::function>(subscriptionOn)) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet, command::subscription<outputable, commandable>::state::callback::modifier subscriptionReleaseOn) : pokemonism::sdk::command::event::internal::subscription(reinterpret_cast<pokemonism::sdk::command *>(object), properties, reinterpret_cast<const pokemonism::sdk::command::event::callback::set &>(eventSet), reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::modifier>(subscriptionReleaseOn)) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet, command::subscription<outputable, commandable>::state::callback::function subscriptionOn, command::subscription<outputable, commandable>::state::callback::modifier subscriptionReleaseOn) : pokemonism::sdk::command::event::internal::subscription(reinterpret_cast<pokemonism::sdk::command *>(object), properties, reinterpret_cast<const pokemonism::sdk::command::event::callback::set &>(eventSet), reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::function>(subscriptionOn), reinterpret_cast<pokemonism::sdk::command::event::internal::subscription::state::callback::modifier>(subscriptionReleaseOn)) {}
    protected:  inline subscription(void) = delete;
    protected:  ~subscription(void) override {}
    public:     subscription(const command::subscription<outputable, commandable> & o) = delete;
    public:     subscription(command::subscription<outputable, commandable> && o) noexcept = delete;
    public:     command::subscription<outputable, commandable> & operator=(const command::subscription<outputable, commandable> & o) = delete;
    public:     command::subscription<outputable, commandable> & operator=(command::subscription<outputable, commandable> && o) noexcept = delete;
    };

    template <typename outputable, class commandable>
    class command::modifiable::subscription : public command::subscription<outputable, commandable> {
    protected:  inline explicit subscription(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet) : command::subscription<outputable, commandable>(object, properties, eventSet) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet, command::subscription<outputable, commandable>::state::callback::function subscriptionOn) : command::subscription<outputable, commandable>(object, properties, eventSet, subscriptionOn) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet, command::subscription<outputable, commandable>::state::callback::modifier subscriptionReleaseOn) : command::subscription<outputable, commandable>(object, properties, eventSet, subscriptionReleaseOn) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet, command::subscription<outputable, commandable>::state::callback::function subscriptionOn, command::subscription<outputable, commandable>::state::callback::modifier subscriptionReleaseOn) : command::subscription<outputable, commandable>(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn) {}
    protected:  inline subscription(void) = delete;
    protected:  ~subscription(void) override {}
    public:     subscription(const command::modifiable::subscription<outputable, commandable> & o) = delete;
    public:     subscription(command::modifiable::subscription<outputable, commandable> && o) noexcept = delete;
    public:     command::modifiable::subscription<outputable, commandable> & operator=(const command::modifiable::subscription<outputable, commandable> & o) = delete;
    public:     command::modifiable::subscription<outputable, commandable> & operator=(command::modifiable::subscription<outputable, commandable> && o) noexcept = delete;
    };

    template <typename outputable, class commandable>
    class command::releasable::subscription : public command::modifiable::subscription<outputable, commandable> {
    public:     inline commandable * objectPop(void) override {
                    commandable * o = reinterpret_cast<commandable *>(this->object);
                    this->object = nullptr;
                    return o;
                }
    protected:  inline explicit subscription(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet) : command::modifiable::subscription<outputable, commandable>(object, properties, eventSet) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet, command::subscription<outputable, commandable>::state::callback::function subscriptionOn) : command::modifiable::subscription<outputable, commandable>(object, properties, eventSet, subscriptionOn) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet, command::subscription<outputable, commandable>::state::callback::modifier subscriptionReleaseOn) : command::modifiable::subscription<outputable, commandable>(object, properties, eventSet, subscriptionReleaseOn) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet, command::subscription<outputable, commandable>::state::callback::function subscriptionOn, command::subscription<outputable, commandable>::state::callback::modifier subscriptionReleaseOn) : command::modifiable::subscription<outputable, commandable>(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn) {}
    protected:  inline subscription(void) = delete;
    protected:  ~subscription(void) override {}
    public:     subscription(const command::releasable::subscription<outputable, commandable> & o) = delete;
    public:     subscription(command::releasable::subscription<outputable, commandable> && o) noexcept = delete;
    public:     command::releasable::subscription<outputable, commandable> & operator=(const command::releasable::subscription<outputable, commandable> & o) = delete;
    public:     command::releasable::subscription<outputable, commandable> & operator=(command::releasable::subscription<outputable, commandable> && o) noexcept = delete;
    };

    template <typename outputable, class commandable>
    class command::internal::subscription : public command::releasable::subscription<outputable, commandable> {
    protected:  inline commandable * objectPop(void) override {
                    commandable * o = reinterpret_cast<commandable *>(this->object);
                    this->object = nullptr;
                    return o;
                }
    protected:  inline explicit subscription(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet) : command::releasable::subscription<outputable, commandable>(object, properties, eventSet) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet, command::subscription<outputable, commandable>::state::callback::function subscriptionOn) : command::releasable::subscription<outputable, commandable>(object, properties, eventSet, subscriptionOn) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet, command::subscription<outputable, commandable>::state::callback::modifier subscriptionReleaseOn) : command::releasable::subscription<outputable, commandable>(object, properties, eventSet, subscriptionReleaseOn) {}
    protected:  inline subscription(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet, command::subscription<outputable, commandable>::state::callback::function subscriptionOn, command::subscription<outputable, commandable>::state::callback::modifier subscriptionReleaseOn) : command::releasable::subscription<outputable, commandable>(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn) {}
    protected:  inline subscription(void) = delete;
    protected:  ~subscription(void) override {}
    public:     subscription(const command::internal::subscription<outputable, commandable> & o) = delete;
    public:     subscription(command::internal::subscription<outputable, commandable> && o) noexcept = delete;
    public:     command::internal::subscription<outputable, commandable> & operator=(const command::internal::subscription<outputable, commandable> & o) = delete;
    public:     command::internal::subscription<outputable, commandable> & operator=(command::internal::subscription<outputable, commandable> && o) noexcept = delete;
    public:     friend command::event::generator;
    };

    class command::event::generator : public pokemonism::sdk::command::event::generator {
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> command::subscription<outputable, commandable> * reg(command::subscription<outputable, commandable> * subscription);
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> inline command::subscription<outputable, commandable> * reg(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet);
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> inline command::subscription<outputable, commandable> * reg(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet, command::subscription<outputable, commandable>::state::callback::function subscriptionOn);
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> inline command::subscription<outputable, commandable> * reg(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet, command::subscription<outputable, commandable>::state::callback::modifier subscriptionReleaseOn);
    public:     template <typename outputable = primitivable, class commandable = generic::command<outputable>> inline command::subscription<outputable, commandable> * reg(commandable * object, unsigned int properties, const command::event::callback<outputable, commandable>::set & eventSet, command::subscription<outputable, commandable>::state::callback::function subscriptionOn, command::subscription<outputable, commandable>::state::callback::modifier subscriptionReleaseOn);
    public:     inline explicit generator(pokemonism::sdk::engine * engine);
    public:     generator(void) = delete;
    public:     inline ~generator(void) override;
    public:     generator(const command::event::generator & o) = delete;
    public:     generator(command::event::generator && o) noexcept = delete;
    public:     command::event::generator & operator=(const command::event::generator & o) = delete;
    public:     command::event::generator & operator=(command::event::generator && o) noexcept = delete;
    };

}

#include <pokemonism/sdk/templateable/command/subscription.hh>
#include <pokemonism/sdk/templateable/command/event/generator.hh>

#endif // __POKEMONISM_SDK_TEMPLATEABLE_COMMAND_HH__