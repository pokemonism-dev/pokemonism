/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_POKEMON_COMMAND_HH__
#define   __POKEMONISM_POKEMON_COMMAND_HH__

#include <pokemon/interface/primitivable.hh>
#include <pokemon/interface/functionable.hh>

#include <pokemonism/pokemon/event.hh>
#include <pokemonism/pokemon/exception.hh>
#include <pokemonism/pokemon/envelope.hh>

namespace pokemonism {
    namespace pokemon {

        class command {
        public:     typedef primitivable::object output;
        public:     struct event : public virtual pokemon::event {
                    public:     struct type : public pokemon::event::type {
                                public:     constexpr static int gen        = pokemon::event::type::gen;
                                public:     constexpr static int rel        = pokemon::event::type::rel;
                                public:     constexpr static int add        = pokemon::event::type::add;
                                public:     constexpr static int del        = pokemon::event::type::del;
                                public:     constexpr static int exception  = pokemon::event::type::max;
                                public:     constexpr static int execute    = pokemon::event::type::max + 1;
                                public:     constexpr static int max        = pokemon::event::type::max + 2;
                                };
                    public:     typedef pokemon::event::subscription subscription;
                    };
        public:     class envelope : public pokemon::envelope {
                    public:     typedef command::output     message;
                    public:     message * pop(void) override = 0;
                    public:     virtual pokemon::exception * exceptionPop(void) = 0;
                    public:     envelope(void) {}
                    public:     ~envelope(void) override {}
                    public:     envelope(const envelope & o) = delete;
                    public:     envelope(envelope && o) noexcept = delete;
                    public:     envelope & operator=(const envelope & o) = delete;
                    public:     envelope & operator=(envelope && o) noexcept = delete;
                    };
        public:     struct callback : public pokemon::functionable {
                    public:     typedef int (*type)(command &, uint32, command::envelope *);
                    };
        public:     virtual command::output * operator()(void) = 0;
        public:     command(void) {}
        public:     virtual ~command(void) {}
        public:     command(const command & o) = delete;
        public:     command(command && o) noexcept = delete;
        public:     command & operator=(const command & o) = delete;
        public:     command & operator=(command && o) noexcept = delete;
        };
    }

    using command = pokemon::command;

}

#endif // __POKEMONISM_POKEMON_COMMAND_HH__