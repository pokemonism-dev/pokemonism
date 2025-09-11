/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 07, 2025
 */

#ifndef   __POKEMONISM_POKEMONS_TOGEPI_COMMAND_HH__
#define   __POKEMONISM_POKEMONS_TOGEPI_COMMAND_HH__

#include <pokemonism/pokemons/togepi.hh>

namespace pokemonism::pokemons {

    template <trainername trainerizable>
    class togepi<trainerizable>::command : public pokemonism::sdk::command {
    public:     class event;
    public:     command(void) {}
    public:     ~command(void) override {}
    public:     command(const togepi<trainerizable>::command & o) = delete;
    public:     command(togepi<trainerizable>::command && o) noexcept = delete;
    public:     togepi<trainerizable>::command & operator=(const togepi<trainerizable>::command & o) = delete;
    public:     togepi<trainerizable>::command & operator=(togepi<trainerizable>::command && o) noexcept = delete;
    };

}

#include <pokemonism/pokemons/togepi/command/event.hh>

#endif // __POKEMONISM_POKEMONS_TOGEPI_COMMAND_HH__