/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 01, 2025
 */

#ifndef   __POKEMONISM_POKEMON_GENERIC_LAMBDA_COMMAND_HH__
#define   __POKEMONISM_POKEMON_GENERIC_LAMBDA_COMMAND_HH__

#include <pokemonism/pokemon/generic/command.hh>

namespace pokemonism {
    namespace pokemon {
        namespace generic {
            namespace lambda {

                template <class outputable = pokemon::command::output>
                class command : public virtual pokemon::generic::command<outputable> {
                public:     typedef outputable output;
                public:     typedef command<outputable>::output * (*type)(void);
                public:     typedef pokemon::generic::command<outputable>::event event;
                public:     typedef pokemon::generic::command<outputable>::envelope envelope;
                public:     struct callback : public pokemon::generic::command<outputable>::callback {
                            public:     typedef int (*type)(command<outputable> &, uint32, command<outputable>::envelope *);
                            };
                protected:  type func;
                public:     command<outputable>::output * operator()(void) override {
                                if (func == nullptr) throw pokemon::exception();
                                return func();
                            }
                public:     explicit command(type f) : func(f) {}
                public:     command(void) : func(nullptr) {}
                public:     ~command(void) override {}
                public:     command(const command & o) = delete;
                public:     command(command && o) noexcept = delete;
                public:     command & operator=(const command & o) = delete;
                public:     command & operator=(command && o) noexcept = delete;
                };

            }
        }
    }
}

#endif // __POKEMONISM_POKEMON_GENERIC_LAMBDA_COMMAND_HH__