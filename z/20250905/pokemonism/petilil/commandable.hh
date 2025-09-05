/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_PETILIL_COMMANDABLE_HH__
#define   __POKEMONISM_PETILIL_COMMANDABLE_HH__

#include <pokemonism/petilil.hh>
#include <pokemonism/commandable.hh>

namespace pokemonism {
    class petilil::commandable::event : public petilil::event {
    public:     constexpr static unsigned int execute   = 0;
    public:     constexpr static unsigned int max       = 1;
    public:     using link          = petilil::commandable::link;
    public:     using queue         = petilil::event::queue;
    public:     using engine        = petilil::event::engine;
    public:     using envelope      = petilil::commandable::envelope;
    public:     using callback      = petilil::commandable::callback;
    public:     using generator     = petilil::commandable::generator;
    public:     using processor     = petilil::commandable::processor;
    public:     using subscription  = petilil::commandable::subscription;
    public:     using modifiable    = petilil::commandable::modifiable;
    public:     inline event(unsigned int identifier, petilil::commandable::link * node);
    public:     inline event(void);
    public:     inline ~event(void) override;
    public:     event(const petilil::commandable::event & o) = delete;
    public:     event(petilil::commandable::event && o) noexcept = delete;
    public:     petilil::commandable::event & operator=(const petilil::commandable::event & o) = delete;
    public:     petilil::commandable::event & operator=(petilil::commandable::event && o) noexcept = delete;
    };

    struct petilil::commandable::callback : public petilil::event::callback {
    public:     struct set;
    public:     typedef void (*function)(pokemonism::commandable &, unsigned int, petilil::commandable::envelope &, const pokemon::faint *);
    public:     inline petilil::commandable::callback::function get(void) const { return reinterpret_cast<petilil::commandable::callback::function>(func); }
    public:     callback(void) {}
    public:     explicit callback(petilil::commandable::callback::function f) : petilil::event::callback(reinterpret_cast<petilil::event::callback::function>(f)) {}
    };

    struct petilil::commandable::callback::set {
    public:     petilil::commandable::callback::function functions[petilil::commandable::event::max];
    public:     set(void) { functions[petilil::commandable::event::execute] = nullptr; }
    public:     explicit set(petilil::commandable::callback::function execute) { functions[petilil::commandable::event::execute] = execute; }
    };

    struct petilil::commandable::modifiable {
    public:     class subscription;
    };

    class petilil::commandable::subscription : public virtual petilil::event::subscription {
    public:     using property = petilil::event::subscription::property;
    public:     using state = petilil::event::subscription::state;
    public:     struct callback : public petilil::event::subscription::callback {
                public:     typedef void (*function)(const petilil::commandable::subscription &, unsigned int, const pokemon::faint * e);
                public:     typedef void (*modifier)(const petilil::commandable::modifiable::subscription &, unsigned int, const pokemon::faint * e);
                public:     struct set {
                            public:     petilil::commandable::subscription::callback::function on;
                            public:     petilil::commandable::subscription::callback::modifier rel;
                            public:     inline set(void) : on(nullptr), rel(nullptr) {}
                            public:     inline explicit set(petilil::commandable::subscription::callback::function on) : on(on), rel(nullptr) {}
                            public:     inline explicit set(petilil::commandable::subscription::callback::modifier rel) : on(nullptr), rel(rel) {}
                            public:     inline set(petilil::commandable::subscription::callback::function on, petilil::commandable::subscription::callback::modifier rel) : on(on), rel(rel) {}
                            public:     inline ~set(void) {
                                            on = nullptr;
                                            rel = nullptr;
                                        }
                            };
                };
    public:     using releaser = petilil::event::subscription::releaser;
    public:     using command = commandable;
    protected:  int count;
    protected:  pokemonism::commandable * object;
    protected:  petilil::commandable::callback::set callbackSet;
    public:     inline virtual void callbackOn(petilil::commandable::link * o, unsigned int type, pokemon::faint * e = nullptr);
    public:     inline virtual const pokemonism::commandable * objectGet(void) const;
    protected:  inline virtual pokemonism::commandable * objectGet(void);
    public:     inline int executeCnt(void) const;
    public:     inline virtual void executeSet(void);
    protected:  inline void raise(petilil::event::link * o, pokemon::faint * e) override;
    protected:  int processOn(petilil::event::link * o) noexcept override;
    protected:  inline subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet);
    protected:  inline subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::subscription::callback::function on);
    protected:  inline subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::subscription::callback::modifier modifiableOn);
    protected:  inline subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::subscription::callback::function on, petilil::commandable::subscription::callback::modifier modifiableOn);
    protected:  inline subscription(void);
    protected:  inline ~subscription(void) override;
    public:     subscription(const petilil::commandable::subscription & o) = delete;
    public:     subscription(petilil::commandable::subscription && o) noexcept = delete;
    public:     petilil::commandable::subscription & operator=(const petilil::commandable::subscription & o) = delete;
    public:     petilil::commandable::subscription & operator=(petilil::commandable::subscription && o) noexcept = delete;
    public:     friend petilil::commandable::processor;
    };

    class petilil::commandable::modifiable::subscription : public virtual petilil::commandable::subscription, public petilil::event::modifiable::subscription {
    public:     using property = petilil::commandable::subscription::property;
    public:     using state = petilil::commandable::subscription::state;
    public:     using callback = petilil::commandable::subscription::callback;
    public:     using releaser = petilil::event::subscription::releaser;
    public:     using command = commandable;
    public:     inline virtual pokemonism::commandable * objectPop(void);
    protected:  inline subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet);
    protected:  inline subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::function on);
    protected:  inline subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::modifier modifiableOn);
    protected:  inline subscription(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::function on, petilil::commandable::modifiable::subscription::callback::modifier modifiableOn);
    protected:  inline subscription(void);
    protected:  inline ~subscription(void) override;
    public:     subscription(const petilil::commandable::modifiable::subscription & o) = delete;
    public:     subscription(petilil::commandable::modifiable::subscription && o) noexcept = delete;
    public:     petilil::commandable::modifiable::subscription & operator=(const petilil::commandable::modifiable::subscription & o) = delete;
    public:     petilil::commandable::modifiable::subscription & operator=(petilil::commandable::modifiable::subscription && o) noexcept = delete;
    public:     friend petilil::commandable::generator;
    };

    class petilil::commandable::envelope : public virtual petilil::event::envelope {
    protected:  primitivable * output;
    public:     inline petilil::commandable::subscription * subscriptionGet(void) const override {
                    return pokemon::cast<petilil::commandable::subscription *>(container);
                }
    public:     inline explicit envelope(petilil::commandable::subscription * subscription, int ret) : petilil::event::envelope(subscription, ret), output(nullptr) {}
    public:     inline envelope(petilil::commandable::subscription * subscription, int ret, pokemon::faint * exception) : petilil::event::envelope(subscription, ret, exception), output(nullptr) {}
    public:     inline envelope(void) : output(nullptr) {}
    public:     inline ~envelope(void) override {
                    pokemon_training_exit_check(output != nullptr, return);
                }
    public:     envelope(const petilil::commandable::envelope & o) = delete;
    public:     envelope(petilil::commandable::envelope && o) noexcept = delete;
    public:     petilil::commandable::envelope & operator=(const petilil::commandable::envelope & o) = delete;
    public:     petilil::commandable::envelope & operator=(petilil::commandable::envelope && o) noexcept = delete;
    };

    class petilil::commandable::link : public petilil::event::link, public virtual commandable::envelope {
    public:     inline void outputSet(primitivable * o) { output = o; }
    public:     inline explicit link(petilil::commandable::subscription * subscription) : petilil::event::link(subscription) {}
    public:     inline link(void) {}
    public:     inline ~link(void) override {}
    public:     link(const petilil::commandable::link & o) = delete;
    public:     link(petilil::commandable::link && o) noexcept = delete;
    public:     petilil::commandable::link & operator=(const petilil::commandable::link & o) = delete;
    public:     petilil::commandable::link & operator=(petilil::commandable::link && o) noexcept = delete;
    };

    class petilil::commandable::generator : public petilil::event::generator {
    public:     inline petilil::commandable::subscription * reg(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet);
    public:     inline petilil::commandable::subscription * reg(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::function on);
    public:     inline petilil::commandable::subscription * reg(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::modifier modifiableOn);
    public:     inline petilil::commandable::subscription * reg(pokemonism::commandable * object, unsigned int properties, const petilil::commandable::callback::set & callbackSet, petilil::commandable::modifiable::subscription::callback::function on, petilil::commandable::modifiable::subscription::callback::modifier modifiableOn);
    protected:  inline explicit generator(petilil::event::engine * engine);
    protected:  inline generator(void);
    protected:  inline ~generator(void) override;
    public:     generator(const petilil::commandable::generator & o) = delete;
    public:     generator(petilil::commandable::generator && o) noexcept = delete;
    public:     petilil::commandable::generator & operator=(const petilil::commandable::generator & o) = delete;
    public:     petilil::commandable::generator & operator=(petilil::commandable::generator && o) noexcept = delete;
    public:     friend petilil::commandable::generator::collection;
    public:     friend petilil::event::engine;
    };

    class petilil::commandable::processor : public petilil::event::processor {
    public:     static int on(petilil::commandable::subscription & o, unsigned int type, petilil::commandable::link & node);
    public:     processor(void) {}
    public:     ~processor(void) override {}
    public:     processor(const petilil::commandable::processor & o) = delete;
    public:     processor(petilil::commandable::processor && o) noexcept = delete;
    public:     petilil::commandable::processor & operator=(const petilil::commandable::processor & o) = delete;
    public:     petilil::commandable::processor & operator=(petilil::commandable::processor && o) noexcept = delete;
    };



}

// ReSharper disable CppUnusedIncludeDirective
#include <pokemonism/petilil/commandable/event.hh>
#include <pokemonism/petilil/commandable/generator.hh>
#include <pokemonism/petilil/commandable/processor.hh>
#include <pokemonism/petilil/commandable/subscription.hh>
#include <pokemonism/petilil/commandable/modifiable/subscription.hh>

#include <pokemonism/petilil/command.hh>
// ReSharper restore CppUnusedIncludeDirective

#endif // __POKEMONISM_PETILIL_COMMANDABLE_HH__