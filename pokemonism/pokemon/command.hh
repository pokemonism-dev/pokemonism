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

#include <pokemonism/pokemon/generic/envelope.hh>

namespace pokemonism {
    namespace pokemon {

        class command {
        public:     typedef primitivable::object output;
        public:     struct type {
                    public:     constexpr static int exception  = 0;
                    public:     constexpr static int execute    = 1;
                    };
        public:     class envelope : public pokemon::envelope {
                    public:     typedef command::output     message;
                    public:     message * pop(void) const override = 0;
                    public:     envelope(void) {}
                    public:     ~envelope(void) override {}
                    public:     envelope(const envelope & o) = delete;
                    public:     envelope(envelope && o) noexcept = delete;
                    public:     envelope & operator=(const envelope & o) = delete;
                    public:     envelope & operator=(envelope && o) noexcept = delete;
                    };
        public:     struct callback : public virtual pokemon::functionable {
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