/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 07, 2025
 */

#ifndef   __POKEMONISM_POKEMONS_TOGEPI_TOGETIC_COMMAND_HH__
#define   __POKEMONISM_POKEMONS_TOGEPI_TOGETIC_COMMAND_HH__

#include <pokemonism/sdk/generic/command.hh>
#include <pokemonism/pokemons/togepi/togetic.hh>

namespace pokemonism::pokemons {

    template <trainername trainerizable>
    template <typename outputable>
    class togetic<trainerizable>::command : public pokemonism::sdk::generic::command<outputable> {
    public:     class event;
    public:     command(void) {}
    public:     ~command(void) override {}
    public:     command(const togetic<trainerizable>::command<outputable> & o) = delete;
    public:     command(togetic<trainerizable>::command<outputable> && o) noexcept = delete;
    public:     togetic<trainerizable>::command<outputable> & operator=(const togetic<trainerizable>::command<outputable> & o) = delete;
    public:     togetic<trainerizable>::command<outputable> & operator=(togetic<trainerizable>::command<outputable> && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_POKEMONS_TOGEPI_TOGETIC_COMMAND_HH__