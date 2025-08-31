/**
 * @file
 * @brief
 * @details
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */

#ifndef   __POKEMONISM_POKEMON_GENERIC_COMMAND_HH__
#define   __POKEMONISM_POKEMON_GENERIC_COMMAND_HH__

#include <pokemonism/pokemon/command.hh>
#include <pokemonism/pokemon/generic/envelope.hh>

namespace pokemonism {
    namespace pokemon {
        namespace generic {

            template <class outputable = pokemon::command::output>
            class command : public virtual pokemon::command {
            public:     typedef outputable output;
            public:     typedef pokemon::command::type type;
            public:     class envelope : public virtual pokemon::generic::envelope<outputable> {
                        public:     typedef pokemon::generic::envelope<outputable>::message  message;
                        public:     pokemon::generic::envelope<output>::message * pop(void) const override = 0;
                        public:     envelope(void) {}
                        public:     ~envelope(void) override {}
                        public:     envelope(const envelope & o) = delete;
                        public:     envelope(envelope && o) noexcept = delete;
                        public:     envelope & operator=(const envelope & o) = delete;
                        public:     envelope & operator=(envelope && o) noexcept = delete;
                        };
                        public:     struct callback : public virtual pokemon::functionable {
                                    public:     typedef int (*type)(command<outputable> &, uint32, command<outputable>::envelope *);
                        };
            public:     command<outputable>::output * operator()(void) override = 0;
            public:     command(void) {}
            public:     ~command(void) override {}
            public:     command(const command & o) = delete;
            public:     command(command && o) noexcept = delete;
            public:     command & operator=(const command & o) = delete;
            public:     command & operator=(command && o) noexcept = delete;
            };

        }
    }

    namespace generic {
        template <class outputable = pokemon::command::output> using command = pokemon::generic::command<outputable>;
    }

}

#endif // __POKEMONISM_POKEMON_GENERIC_COMMAND_HH__