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

#include <pokemonism/ralts.hh>

namespace pokemonism {
    namespace pokemon {

        class command {
        public:     typedef primitivable::object output;
        public:     struct tag {};
        public:     class envelope;





        public:     struct event : public virtual ralts::event {
                    public:     struct type : public pokemon::event::type {
                                public:     constexpr static int execute    = 0;
                                public:     constexpr static int max        = 1;
                                };
                    public:     struct handler : public pokemon::functionable {
                                public:     typedef void (*type)(pokemon::command &, uint32, pokemon::command::envelope *);
                                public:     typedef pokemon::command::event::handler set[pokemon::command::event::type::max];
                                };
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