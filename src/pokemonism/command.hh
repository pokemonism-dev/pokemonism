/**
 * @file            pokemonism/command.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_COMMAND_HH__
#define   __POKEMONISM_COMMAND_HH__

#include <pokemonism/interface/primitivable.hh>
#include <pokemonism/interface/callable.hh>

#include <pokemonism/event.hh>
#include <pokemonism/exception.hh>
#include <pokemonism/subscription.hh>

#include "command.hh"

namespace pokemonism {

    template <typename outputable>
    class command : public callable<outputable> {
    public:     typedef outputable      output;
    public:     class subscription;
    public:     class envelope;
    public:     struct modifiable;
    public:     class event;
    public:     template <typename observable = command<outputable>> struct callback;

    public:     command(void) {}
    public:     ~command(void) override {}
    public:     command(const command & o) = delete;
    public:     command(command && o) noexcept = delete;
    public:     command & operator=(const command & o) = delete;
    public:     command & operator=(command && o) noexcept = delete;
    };

    template <typename outputable>
    class command<outputable>::event : public pokemonism::event {
    public:     constexpr static uint32 execute = pokemonism::event::max + 0;
    public:     constexpr static uint32 max     = pokemonism::event::max + 1;
    };

    template <typename outputable>
    struct command<outputable>::modifiable {
    public:     class subscription;
    };

    template <typename outputable>
    class command<outputable>::subscription : public event::subscription {
    public:     struct event;
    public:     virtual const command<outputable> * commandGet(void) const = 0;
    public:     virtual int32 executeCnt(void) const = 0;
    public:     virtual uint64 eventCnt(void) const = 0;
    protected:  subscription(void) {}
    protected:  ~subscription(void) override {}
    public:     subscription(const command<outputable>::subscription & o) = delete;
    public:     subscription(command<outputable>::subscription && o) noexcept = delete;
    public:     command<outputable>::subscription & operator=(const command<outputable>::subscription & o) = delete;
    public:     command<outputable>::subscription & operator=(command<outputable>::subscription && o) noexcept = delete;
    };

    template <typename outputable>
    class command<outputable>::modifiable::subscription : public command<outputable>::subscription {
    public:     virtual command<outputable> * commandPop(void) = 0;
    protected:  subscription(void) {}
    protected:  ~subscription(void) override {}
    public:     subscription(const command<outputable>::modifiable::subscription & o) = delete;
    public:     subscription(command<outputable>::modifiable::subscription && o) noexcept = delete;
    public:     command<outputable>::modifiable::subscription & operator=(const command<outputable>::modifiable::subscription & o) = delete;
    public:     command<outputable>::modifiable::subscription & operator=(command<outputable>::modifiable::subscription && o) noexcept = delete;
    };

    template <typename outputable>
    struct command<outputable>::subscription::event : public pokemonism::event::subscription::event {
    public:     template <typename objectable = command<outputable>, typename envelopeable = command<outputable>::envelope> struct callback;
    };

    template <typename outputable>
    template <typename objectable, typename envelopeable>
    struct command<outputable>::subscription::event::callback : public pokemonism::event::subscription::event::callback<command<outputable>::subscription, typename command<outputable>::modifiable::subscription> {
    public:     inline callback(void) {}
    public:     inline explicit callback(pokemonism::event::subscription::event::callback<objectable, envelopeable>::function f) : pokemonism::event::subscription::event::callback<objectable, envelopeable>(f) {}
    public:     inline explicit callback(pokemonism::event::subscription::event::callback<objectable, envelopeable>::modifier f) : pokemonism::event::subscription::event::callback<objectable, envelopeable>(f) {}
    };

    template <typename outputable>
    class command<outputable>::envelope : public pokemonism::event::envelope<outputable> {
    public:     command<outputable>::subscription & subscriptionGet(void) const override = 0;
    public:     virtual int32 executeCnt(void) const = 0;
    public:     envelope(void) {}
    public:     ~envelope(void) override {}
    public:     envelope(const command<outputable>::envelope & o) = delete;
    public:     envelope(command<outputable>::envelope && o) noexcept = delete;
    public:     command<outputable>::envelope & operator=(const command<outputable>::envelope & o) = delete;
    public:     command<outputable>::envelope & operator=(command<outputable>::envelope && o) noexcept = delete;
    };

    template <typename outputable>
    template <typename observable>
    struct command<outputable>::callback : public pokemonism::event::callback<observable, command<outputable>::envelope> {
    public:     inline callback(void) : pokemonism::event::callback<observable, command<outputable>::envelope>(nullptr) {}
    public:     inline explicit callback(pokemonism::event::callback<observable, command<outputable>::envelope>::function f) : pokemonism::event::callback<observable, command<outputable>::envelope>(f) {}
    };

}

#endif // __POKEMONISM_COMMAND_HH__