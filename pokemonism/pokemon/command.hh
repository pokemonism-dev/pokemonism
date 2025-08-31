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

#include <pokemonism/pokemon/envelope.hh>

namespace pokemonism {
    namespace pokemon {



        class command {
        public:     struct type {
                    public:     constexpr static int execute        = 0;
                    };
        public:     struct callback : public pokemonism::functionable {
                    public:     typedef int (*type)(command &, uint32, pokemonism::envelope &);
                    };
        public:     virtual pokemonism::primitivable::object * operator()(void) = 0;
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