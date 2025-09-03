/**
 * @file            pokemonism/event.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_EVENT_HH__
#define   __POKEMONISM_EVENT_HH__

#include <pokemonism/envelope.hh>

#include <pokemonism/subscription.hh>

namespace pokemonism {

    class event {
    public:     template <typename messageable> class envelope;
    public:     template <typename objectable, typename envelopeable = objectable::envelope> struct callback;
    public:     class subscription;
    public:     constexpr static uint32 max = 0;
    public:     virtual uint32 identifierGet(void) const = 0;
    public:     event(void) {}
    public:     virtual ~event(void) {}
    public:     event(const event & o) = delete;
    public:     event(event && o) noexcept = delete;
    public:     event & operator=(const event & o) = delete;
    public:     event & operator=(event && o) noexcept = delete;
    };

    class event::subscription : public pokemonism::subscription {
    public:     struct event;
    public:     virtual const exception * exceptionGet(void) const = 0;
    public:     virtual bool completeChk(void) const = 0;
    public:     virtual bool finishChk(void) const = 0;
    public:     virtual bool cancelChk(void) const = 0;
    protected:  subscription(void) {}
    protected:  ~subscription(void) override {}
    public:     subscription(const pokemonism::event::subscription & o) = delete;
    public:     subscription(pokemonism::event::subscription && o) noexcept = delete;
    public:     pokemonism::event::subscription & operator=(const pokemonism::event::subscription & o) = delete;
    public:     pokemonism::event::subscription & operator=(pokemonism::event::subscription && o) noexcept = delete;
    };

    struct event::subscription::event {
    public:     constexpr static uint32 gen = 0;
    public:     constexpr static uint32 reg = 1;
    public:     constexpr static uint32 chk = 2;
    public:     constexpr static uint32 del = 3;
    public:     constexpr static uint32 rel = 4;
    public:     constexpr static uint32 max = 5;
    public:     template <typename subscriptable, typename modifiable> struct callback;
    };

    template <typename messageable>
    class event::envelope : public pokemonism::envelope<messageable> {
    public:     virtual const exception * exceptionGet(void) const = 0;
    public:     virtual bool completeChk(void) const = 0;
    public:     virtual bool finishChk(void) const = 0;
    public:     virtual bool cancelChk(void) const = 0;
    public:     virtual event::subscription & subscriptionGet(void) const = 0;
    protected:  envelope(void) {}
    protected:  ~envelope(void) override {}
    public:     envelope(const event::envelope<messageable> & o) = delete;
    public:     envelope(event::envelope<messageable> && o) noexcept = delete;
    public:     event::envelope<messageable> & operator=(const event::envelope<messageable> & o) = delete;
    public:     event::envelope<messageable> & operator=(event::envelope<messageable> && o) noexcept = delete;
    };

    template <typename objectable, typename envelopeable>
    struct event::callback {
    public:     typedef void (*function)(const objectable &, uint32, envelopeable &);
    public:     function func;
    public:     inline callback(void) : func(nullptr) {}
    public:     inline explicit callback(function f) : func(f) {}
    };

    template <typename subscriptable, typename modifiable>
    struct event::subscription::event::callback {
    public:     typedef void (*function)(const subscriptable &, uint32, const exception *);
    public:     typedef void (*modifier)(modifiable &, uint32, const exception *);
    public:     union container {
                public:     pokemonism::event::subscription::event::callback<subscriptable, modifiable>::function func;
                public:     pokemonism::event::subscription::event::callback<subscriptable, modifiable>::modifier modifier;
                public:     inline explicit container(pokemonism::event::subscription::event::callback<subscriptable, modifiable>::function f) : func(f) {}
                public:     inline explicit container(pokemonism::event::subscription::event::callback<subscriptable, modifiable>::modifier f) : modifier(f) {}
                public:     inline container(void) : func(nullptr) {}
                };
    public:     struct set {
                public:     function gen;
                public:     function reg;
                public:     function chk;
                public:     function del;
                public:     modifier rel;
                };
    public:     container func;
    public:     inline callback(void) {}
    public:     inline explicit callback(function f) : func(f) {}
    public:     inline explicit callback(modifier f) : func(f) {}
    };

}

#endif // __POKEMONISM_EVENT_HH__