/**
 * @file            pokemonism/sdk/command/event.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_SDK_COMMAND_EVENT_HH__
#define   __POKEMONISM_SDK_COMMAND_EVENT_HH__

#include <pokemonism/sdk/event.hh>
#include <pokemonism/sdk/command.hh>

#include "event.hh"

namespace pokemonism::sdk {

    class command::event : public pokemonism::sdk::event {
    public:     class link;
    public:     class envelope;
    public:     class processor;
    public:     class generator;
    public:     class subscription;
    public:     struct modifiable;
    public:     struct releasable;
    public:     struct internal;
    public:     struct type : public pokemonism::sdk::event::type {
                public:     constexpr static unsigned int execute = pokemonism::sdk::event::type::max + 0;
                public:     constexpr static unsigned int max     = pokemonism::sdk::event::type::max + 1;
                };
    public:     struct callback : public callbackable {
                public:     typedef void (*function)(command &, unsigned int, command::event::envelope &, const command::event::exception *);
                public:     inline callback(void) {}
                public:     inline explicit callback(command::event::callback::function f) : callbackable(reinterpret_cast<callbackable::function>(f)) {}
                public:     inline ~callback(void) {}
                public:     struct set {
                            public:     command::event::callback::function execute;
                            public:     inline set(void) : execute(nullptr) {}
                            public:     inline explicit set(command::event::callback::function execute) : execute(execute) {}
                            public:     inline ~set(void) { execute = nullptr; }
                            public:     inline set(const command::event::callback::set & o) : execute(o.execute) {}
                            public:     inline set(command::event::callback::set && o) noexcept : execute(o.execute) { o.execute = nullptr;}
                            public:     inline command::event::callback::set & operator=(const command::event::callback::set & o);
                            public:     inline command::event::callback::set & operator=(command::event::callback::set && o) noexcept;
                            };
                };
    public:     inline event(unsigned int identifier, command::event::link * node);
    protected:  event(void) {}
    public:     inline ~event(void) override;
    public:     event(const pokemonism::sdk::command::event & o) = delete;
    public:     event(pokemonism::sdk::command::event && o) noexcept = delete;
    public:     pokemonism::sdk::command::event & operator=(const pokemonism::sdk::command::event & o) = delete;
    public:     pokemonism::sdk::command::event & operator=(pokemonism::sdk::command::event && o) noexcept = delete;
    };

    class command::event::envelope : public pokemonism::sdk::event::link {
    protected:  primitivable * output;
    public:     inline primitivable * messagePop(void) override;
    protected:  void reset(void) override;
    public:     inline explicit envelope(pokemonism::sdk::event::exception * exception);
    public:     inline explicit envelope(command::event::subscription * container, pokemonism::sdk::event::exception * exception = nullptr);
    protected:  inline envelope(void);
    protected:  inline ~envelope(void) override;
    public:     envelope(const command::event::envelope & o) = delete;
    public:     envelope(command::event::envelope && o) noexcept = delete;
    public:     command::event::envelope & operator=(const command::event::envelope & o) = delete;
    public:     command::event::envelope & operator=(command::event::envelope && o) noexcept = delete;
    public:     friend command::event::subscription;
    public:     friend command::event::processor;
    };

    class command::event::link : public command::event::envelope {
    public:     inline explicit link(command::event::subscription * container);
    public:     inline explicit link(pokemonism::sdk::event::exception * exception);
    public:     inline link(void);
    public:     inline ~link(void) override;
    public:     link(const command::event::link & o) = delete;
    public:     link(command::event::link && o) noexcept = delete;
    public:     command::event::link & operator=(const command::event::link & o) = delete;
    public:     command::event::link & operator=(command::event::link && o) noexcept = delete;
    };

    struct command::event::modifiable {
    public:     class subscription;
    };

    struct command::event::releasable {
    public:     class subscription;
    };

    struct command::event::internal {
    public:     class subscription;
    };

    class command::event::subscription : public pokemonism::sdk::event::internal::subscription {
    public:     struct state : public pokemonism::sdk::event::subscription::state {
                public:     struct callback : public pokemonism::sdk::event::subscription::state::callback {
                            public:     typedef void (*function)(command::event::modifiable::subscription &, unsigned int, const command::event::exception *);
                            public:     typedef void (*modifier)(command::event::releasable::subscription &, unsigned int, const command::event::exception *);
                            public:     inline callback(void) {}
                            public:     inline explicit callback(command::event::subscription::state::callback::function f) : pokemonism::sdk::event::subscription::state::callback(reinterpret_cast<pokemonism::sdk::event::subscription::state::callback::function>(f)) {}
                            public:     inline ~callback(void) { func = nullptr; }
                            public:     struct set {
                                        public:     command::event::subscription::state::callback::function on;
                                        public:     command::event::subscription::state::callback::modifier rel;
                                        public:     inline set(void) : on(nullptr), rel(nullptr) {}
                                        public:     inline explicit set(command::event::subscription::state::callback::function on) : on(on), rel(nullptr) {}
                                        public:     inline explicit set(command::event::subscription::state::callback::modifier rel) : on(nullptr), rel(rel) {}
                                        public:     inline explicit set(command::event::subscription::state::callback::function on, command::event::subscription::state::callback::modifier rel) : on(on), rel(rel) {}
                                        };
                            };
                };
    protected:  command * object;
    protected:  command::event::callback::set eventSet;
    protected:  int count;
    protected:  inline virtual bool executeSet(void);
    protected:  int processOn(unsigned int type) override;
    protected:  int processOn(pokemonism::sdk::event::link * link) override;
    protected:  void callbackOn(unsigned int type, const pokemonism::sdk::event::exception * problem = nullptr) override;
    protected:  void callbackOn(unsigned int type, pokemonism::sdk::event::envelope & envelope, const pokemonism::sdk::event::exception * problem = nullptr) override;
    protected:  inline explicit subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet);
    protected:  inline subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn);
    protected:  inline subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::modifier subscriptionReleaseOn);
    protected:  inline subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn, command::event::subscription::state::callback::modifier subscriptionReleaseOn);
    protected:  inline subscription(void) = delete;
    public:     inline ~subscription(void) override;
    public:     subscription(const command::event::subscription & o) = delete;
    public:     subscription(command::event::subscription && o) noexcept = delete;
    public:     command::event::subscription & operator=(const command::event::subscription & o) = delete;
    public:     command::event::subscription & operator=(command::event::subscription && o) noexcept = delete;
    public:     friend command::event::processor;
    };

    class command::event::modifiable::subscription : public command::event::subscription {
    protected:  inline explicit subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet) : command::event::subscription(object, properties, eventSet) {}
    protected:  inline subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn) : command::event::subscription(object, properties, eventSet, subscriptionOn) {}
    protected:  inline subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::modifier subscriptionReleaseOn) : command::event::subscription(object, properties, eventSet, subscriptionReleaseOn) {}
    protected:  inline subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn, command::event::subscription::state::callback::modifier subscriptionReleaseOn) : command::event::subscription(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn) {}
    protected:  inline subscription(void) = delete;
    protected:  inline ~subscription(void) override {}
    public:     subscription(const command::event::modifiable::subscription & o) = delete;
    public:     subscription(command::event::modifiable::subscription && o) noexcept = delete;
    public:     command::event::modifiable::subscription & operator=(const command::event::modifiable::subscription & o) = delete;
    public:     command::event::modifiable::subscription & operator=(command::event::modifiable::subscription && o) noexcept = delete;
    };


    class command::event::releasable::subscription : public command::event::modifiable::subscription {
    public:     inline virtual command * objectPop(void);
    protected:  inline explicit subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet) : command::event::modifiable::subscription(object, properties, eventSet) {}
    protected:  inline subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn) : command::event::modifiable::subscription(object, properties, eventSet, subscriptionOn) {}
    protected:  inline subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::modifier subscriptionReleaseOn) : command::event::modifiable::subscription(object, properties, eventSet, subscriptionReleaseOn) {}
    protected:  inline subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn, command::event::subscription::state::callback::modifier subscriptionReleaseOn) : command::event::modifiable::subscription(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn) {}
    protected:  inline subscription(void) = delete;
    protected:  inline ~subscription(void) override {}
    public:     subscription(const command::event::releasable::subscription & o) = delete;
    public:     subscription(command::event::releasable::subscription && o) noexcept = delete;
    public:     command::event::releasable::subscription & operator=(const command::event::releasable::subscription & o) = delete;
    public:     command::event::releasable::subscription & operator=(command::event::releasable::subscription && o) noexcept = delete;
    };

    class command::event::internal::subscription : public command::event::releasable::subscription {
    protected:  inline command * objectPop(void) override;
    protected:  inline explicit subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet) : command::event::releasable::subscription(object, properties, eventSet) {
                    // ReSharper disable once CppVirtualFunctionCallInsideCtor
                    stateOn(command::event::subscription::state::type::gen);
                }
    protected:  inline subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn) : command::event::releasable::subscription(object, properties, eventSet, subscriptionOn) {
                    // ReSharper disable once CppVirtualFunctionCallInsideCtor
                    stateOn(command::event::subscription::state::type::gen);
                }
    protected:  inline subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::modifier subscriptionReleaseOn) : command::event::releasable::subscription(object, properties, eventSet, subscriptionReleaseOn) {
                    // ReSharper disable once CppVirtualFunctionCallInsideCtor
                    stateOn(command::event::subscription::state::type::gen);
                }
    protected:  inline subscription(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn, command::event::subscription::state::callback::modifier subscriptionReleaseOn) : command::event::releasable::subscription(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn) {
                    // ReSharper disable once CppVirtualFunctionCallInsideCtor
                    stateOn(command::event::subscription::state::type::gen);
                }
    protected:  inline subscription(void) = delete;
    protected:  ~subscription(void) override;
    public:     subscription(const command::event::internal::subscription & o) = delete;
    public:     subscription(command::event::internal::subscription && o) noexcept = delete;
    public:     command::event::internal::subscription & operator=(const command::event::internal::subscription & o) = delete;
    public:     command::event::internal::subscription & operator=(command::event::internal::subscription && o) noexcept = delete;
    public:     friend command::event::generator;
    };

    class command::event::generator : public pokemonism::sdk::event::generator {
    public:     command::event::subscription * reg(command::event::subscription * subscription);
    public:     command::event::subscription * reg(command * object, unsigned int properties, const command::event::callback::set & eventSet);
    public:     command::event::subscription * reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn);
    public:     command::event::subscription * reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::modifier subscriptionReleaseOn);
    public:     command::event::subscription * reg(command * object, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn, command::event::subscription::state::callback::modifier subscriptionReleaseOn);
    public:     inline explicit generator(pokemonism::sdk::engine * engine);
    public:     generator(void) = delete;
    public:     inline ~generator(void) override;
    public:     generator(const command::event::generator & o) = delete;
    public:     generator(command::event::generator && o) noexcept = delete;
    public:     command::event::generator & operator=(const command::event::generator & o) = delete;
    public:     command::event::generator & operator=(command::event::generator && o) noexcept = delete;
    };

    class command::event::processor : public pokemonism::sdk::event::processor {
    public:     inline static int executeOn(command::event::subscription & subscription, unsigned int type, command::event::envelope * envelope = nullptr);
    public:     processor(void) {}
    public:     ~processor(void) override {}
    public:     processor(const command::event::processor & o) = delete;
    public:     processor(command::event::processor && o) noexcept = delete;
    public:     command::event::processor & operator=(const command::event::processor & o) = delete;
    public:     command::event::processor & operator=(command::event::processor && o) noexcept = delete;
    };

    inline command::event::event(unsigned int identifier, command::event::link * node) : pokemonism::sdk::event(identifier, node) {

    }

    inline command::event::~event(void) {

    }

    inline command::event::callback::set & command::event::callback::set::operator=(const command::event::callback::set & o) {
        if (pointof(o) != this) execute = o.execute;
        return *this;
    }

    inline command::event::callback::set & command::event::callback::set::operator=(command::event::callback::set && o) noexcept {
        if (pointof(o) != this) {
            execute = o.execute;
            o.execute = nullptr;
        }

        return *this;
    }

}

// ReSharper disable CppUnusedIncludeDirective
#include <pokemonism/sdk/command/event/link.hh>
#include <pokemonism/sdk/command/event/envelope.hh>
#include <pokemonism/sdk/command/event/processor.hh>
#include <pokemonism/sdk/command/event/generator.hh>
#include <pokemonism/sdk/command/event/subscription.hh>
#include <pokemonism/sdk/command/event/internal/subscription.hh>
// ReSharper restore CppUnusedIncludeDirective

#endif // __POKEMONISM_SDK_COMMAND_EVENT_HH__