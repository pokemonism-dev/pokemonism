/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_PETILIL_COMMAND_HH__
#define   __POKEMONISM_PETILIL_COMMAND_HH__

#include <pokemonism/petilil.hh>
#include <pokemonism/petilil/command.hh>

namespace pokemonism {

    struct petilil::command {
    public:     template <class objectable = commandable, typename outputable = primitivable> class link;
    public:     template <class objectable = commandable, typename outputable = primitivable> class event;
    public:     template <class objectable = commandable, typename outputable = primitivable> class envelope;
    public:     template <class objectable = commandable, typename outputable = primitivable> struct callback;
    public:     template <class objectable = commandable, typename outputable = primitivable> class subscription;
    public:     struct modifiable;
    };

    template <class objectable, typename outputable>
    class petilil::command::event : public petilil::commandable::event {
    public:     constexpr static unsigned int execute   = 0;
    public:     constexpr static unsigned int max       = 1;
    public:     using link          = petilil::command::link<objectable, outputable>;
    public:     using queue         = petilil::event::queue;
    public:     using engine        = petilil::event::engine;
    public:     using envelope      = petilil::command::envelope<objectable, outputable>;
    public:     using callback      = petilil::command::callback<objectable, outputable>;
    public:     using generator     = petilil::commandable::generator;
    public:     using processor     = petilil::commandable::processor;
    public:     using subscription  = petilil::command::subscription<objectable, outputable>;
    public:     using modifiable    = petilil::command::modifiable;
    public:     inline event(unsigned int identifier, petilil::command::link<objectable, outputable> * node) : petilil::commandable::event(identifier, node) {}
    public:     inline event(void) {}
    public:     inline ~event(void) override {}
    public:     event(const petilil::command::event<objectable, outputable> & o) = delete;
    public:     event(petilil::command::event<objectable, outputable> && o) noexcept = delete;
    public:     petilil::command::event<objectable, outputable> & operator=(const petilil::command::event<objectable, outputable> & o) = delete;
    public:     petilil::command::event<objectable, outputable> & operator=(petilil::command::event<objectable, outputable> && o) noexcept = delete;
    };

    struct petilil::command::modifiable {
    public:     template <class objectable = commandable, typename outputable = primitivable> class subscription;
    };

    template <class objectable, typename outputable>
    class petilil::command::subscription : public virtual petilil::commandable::subscription {
    public:     using property = petilil::commandable::subscription::property;
    public:     using state = petilil::commandable::subscription::state;
    public:     struct callback : public petilil::commandable::subscription::callback {
                public:     typedef void (*function)(const petilil::command::subscription<objectable, outputable> &, unsigned int, const pokemon::faint * e);
                public:     typedef void (*modifier)(const petilil::command::modifiable::subscription<objectable, outputable> &, unsigned int, const pokemon::faint * e);
                public:     struct set {
                            public:     petilil::command::subscription<objectable, outputable>::callback::function on;
                            public:     petilil::command::subscription<objectable, outputable>::callback::modifier rel;
                            public:     inline set(void) : on(nullptr), rel(nullptr) {}
                            public:     inline explicit set(petilil::command::subscription<objectable, outputable>::callback::function on) : on(on), rel(nullptr) {}
                            public:     inline explicit set(petilil::command::subscription<objectable, outputable>::callback::modifier rel) : on(nullptr), rel(rel) {}
                            public:     inline set(petilil::command::subscription<objectable, outputable>::callback::function on, petilil::command::subscription<objectable, outputable>::callback::modifier rel) : on(on), rel(rel) {}
                            public:     inline ~set(void) {
                                            on = nullptr;
                                            rel = nullptr;
                                        }
                            };
                };
    public:     using releaser = petilil::commandable::subscription::releaser;
    public:     using command = objectable;
    protected:  inline explicit subscription(objectable * object, unsigned int properties, const petilil::command::callback<objectable, outputable>::set & callbackSet) : petilil::commandable::subscription(object, properties, callbackSet) {}
    protected:  inline subscription(objectable * object, unsigned int properties, const petilil::command::callback<objectable, outputable>::set & callbackSet, petilil::command::subscription<objectable, outputable>::callback::function on) : petilil::commandable::subscription(object, properties, callbackSet, on) {}
    protected:  inline subscription(objectable * object, unsigned int properties, const petilil::command::callback<objectable, outputable>::set & callbackSet, petilil::command::subscription<objectable, outputable>::callback::modifier modifiableOn) : petilil::commandable::subscription(object, properties, callbackSet, modifiableOn) {}
    protected:  inline subscription(objectable * object, unsigned int properties, const petilil::command::callback<objectable, outputable>::set & callbackSet, petilil::command::subscription<objectable, outputable>::callback::function on, petilil::command::subscription<objectable, outputable>::callback::modifier modifiableOn) : petilil::commandable::subscription(object, properties, callbackSet, on, modifiableOn) {}
    protected:  inline subscription(void) {}
    protected:  inline ~subscription(void) override {}
    public:     subscription(const petilil::command::subscription<objectable, outputable> & o) = delete;
    public:     subscription(petilil::command::subscription<objectable, outputable> && o) noexcept = delete;
    public:     petilil::command::subscription<objectable, outputable> & operator=(const petilil::command::subscription<objectable, outputable> & o) = delete;
    public:     petilil::command::subscription<objectable, outputable> & operator=(petilil::command::subscription<objectable, outputable> && o) noexcept = delete;
    };

    template <class objectable, typename outputable>
    class petilil::command::modifiable::subscription : public petilil::command::subscription<objectable, outputable>, public petilil::commandable::modifiable::subscription {
    public:     using property = petilil::command::subscription<objectable, outputable>::property;
    public:     using state = petilil::command::subscription<objectable, outputable>::state;
    public:     using callback = petilil::command::subscription<objectable, outputable>::callback;
    public:     using releaser = petilil::command::subscription<objectable, outputable>::releaser;
    public:     using command = objectable;
    public:     inline objectable * objectPop(void) override { return pokemon::cast<objectable *>(object); }
    protected:  inline explicit subscription(objectable * object, unsigned int properties, const petilil::command::callback<objectable, outputable>::set & callbackSet) : petilil::command::subscription<objectable, outputable>(object, properties, callbackSet) {}
    protected:  inline subscription(objectable * object, unsigned int properties, const petilil::command::callback<objectable, outputable>::set & callbackSet, petilil::command::modifiable::subscription<objectable, outputable>::callback::function on) : petilil::command::subscription<objectable, outputable>(object, properties, callbackSet, on) {}
    protected:  inline subscription(objectable * object, unsigned int properties, const petilil::command::callback<objectable, outputable>::set & callbackSet, petilil::command::modifiable::subscription<objectable, outputable>::callback::modifier modifiableOn) : petilil::command::subscription<objectable, outputable>(object, properties, callbackSet, modifiableOn) {}
    protected:  inline subscription(objectable * object, unsigned int properties, const petilil::command::callback<objectable, outputable>::set & callbackSet, petilil::command::modifiable::subscription<objectable, outputable>::callback::function on, petilil::command::modifiable::subscription<objectable, outputable>::callback::modifier modifiableOn) : petilil::command::subscription<objectable, outputable>(object, properties, callbackSet, on, modifiableOn) {}
    protected:  inline subscription(void) {}
    protected:  inline ~subscription(void) override {}
    public:     subscription(const petilil::command::modifiable::subscription<objectable, outputable> & o) = delete;
    public:     subscription(petilil::command::modifiable::subscription<objectable, outputable> && o) noexcept = delete;
    public:     petilil::command::modifiable::subscription<objectable, outputable> & operator=(const petilil::command::modifiable::subscription<objectable, outputable> & o) = delete;
    public:     petilil::command::modifiable::subscription<objectable, outputable> & operator=(petilil::command::modifiable::subscription<objectable, outputable> && o) noexcept = delete;
    };

    template <class objectable, typename outputable>
    class petilil::command::envelope : public pokemonism::generic::envelope<outputable>, public virtual petilil::event::envelope {
    public:     inline petilil::command::subscription<objectable, outputable> * subscriptionGet(void) const override { return pokemon::cast<petilil::command::subscription<objectable, outputable> *>(container); }
    public:     inline explicit envelope(petilil::command::subscription<objectable, outputable> * subscription) : petilil::event::envelope(subscription) {}
    public:     inline envelope(petilil::command::subscription<objectable, outputable> * subscription, pokemon::faint * exception) : petilil::event::envelope(subscription, exception) {}
    public:     inline envelope(void) {}
    public:     inline ~envelope(void) override {}
    public:     envelope(const petilil::command::envelope<objectable, outputable> & o) = delete;
    public:     envelope(petilil::command::envelope<objectable, outputable> && o) noexcept = delete;
    public:     petilil::command::envelope<objectable, outputable> & operator=(const petilil::command::envelope<objectable, outputable> & o) = delete;
    public:     petilil::command::envelope<objectable, outputable> & operator=(petilil::command::envelope<objectable, outputable> && o) noexcept = delete;
    };

    template <class objectable, typename outputable>
    class petilil::command::link : public petilil::event::link, public command::envelope<objectable, outputable> {
    public:     inline explicit link(petilil::command::subscription<objectable, outputable> * subscription) : petilil::event::link(subscription) {}
    public:     inline link(void) {}
    public:     inline ~link(void) override {}
    public:     link(const petilil::command::link<objectable, outputable> & o) = delete;
    public:     link(petilil::command::link<objectable, outputable> && o) noexcept = delete;
    public:     petilil::command::link<objectable, outputable> & operator=(const petilil::command::link<objectable, outputable> & o) = delete;
    public:     petilil::command::link<objectable, outputable> & operator=(petilil::command::link<objectable, outputable> && o) noexcept = delete;
    };

    template <class objectable, typename outputable>
    struct petilil::command::callback : public petilil::event::callback {
    public:     struct set;
    public:     typedef void (*function)(objectable &, unsigned int, petilil::command::envelope<outputable> &, pokemon::faint *);
    public:     inline petilil::command::callback<objectable, outputable>::function get(void) { return reinterpret_cast<petilil::command::callback<objectable, outputable>::function>(func); }
    public:     callback(void) {}
    public:     explicit callback(petilil::command::callback<objectable, outputable>::function f) : petilil::event::callback(reinterpret_cast<petilil::event::callback::function>(f)) {}
    };

    template <class objectable, typename outputable>
    struct petilil::command::callback<objectable, outputable>::set {
    public:     petilil::command::callback<objectable, outputable>::function functions[petilil::command::event<objectable, outputable>::max];
    public:     set(void) { functions[petilil::command::event<objectable, outputable>::execute] = nullptr; }
    public:     explicit set(petilil::command::callback<objectable, outputable>::function execute) { functions[petilil::command::event<objectable, outputable>::execute] = execute; }
    };

}

#endif // __POKEMONISM_PETILIL_COMMAND_HH__