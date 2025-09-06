/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 07, 2025
 */

#ifndef   __POKEMONISM_POKEMONS_TOGEPI_POUND_COMMAND_HH__
#define   __POKEMONISM_POKEMONS_TOGEPI_POUND_COMMAND_HH__

#include <pokemonism/pokemons/togepi.hh>

namespace pokemonism {
    namespace pokemons {

        template <trainername trainerizable>
        class togepi<trainerizable>::pound::command : public pokemonism::sdk::command {
        protected:  pokemonism::sdk::primitivable * (*func)(void);
        public:     pokemonism::sdk::primitivable * operator()(void) override { return func(); }
        public:     explicit command(pokemonism::sdk::primitivable * (*func)(void)) : func(func) {
                        pokemon_training_check(func == nullptr, return);
                    }
        public:     command(void) = delete;
        public:     ~command(void) override { func = nullptr; }
        public:     command(const togepi<trainerizable>::pound::command & o) = delete;
        public:     command(togepi<trainerizable>::pound::command && o) noexcept = delete;
        public:     togepi<trainerizable>::pound::command & operator=(const togepi<trainerizable>::pound::command & o) = delete;
        public:     togepi<trainerizable>::pound::command & operator=(togepi<trainerizable>::pound::command && o) noexcept = delete;
        };
    }
}

#endif // __POKEMONISM_POKEMONS_TOGEPI_POUND_COMMAND_HH__