/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 07, 2025
 */

#ifndef   __POKEMONISM_POKEMONS_TOGETIC_HH__
#define   __POKEMONISM_POKEMONS_TOGETIC_HH__

// #include <pokemonism/sdk/generic/>

#include <pokemonism/pokemons/togepi.hh>

namespace pokemonism::pokemons {

    template <trainername trainerizable>
    class togetic : public togepi<trainerizable> {
    // public:     template <typename commandable, typename >
        // subscription<command<message>, message>
    public:     pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * command, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet) const;
    public:     const char * name(void) const noexcept override { return "togetic"; }
    public:     const char * cry(void) const noexcept override { return "togetic, togee!"; }
    protected:  togetic(void) {}
    protected:  ~togetic(void) override {}
    public:     togetic(const togetic<trainerizable> & o) = delete;
    public:     togetic(togetic<trainerizable> && o) noexcept = delete;
    public:     togetic<trainerizable> & operator=(const togetic<trainerizable> & o) = delete;
    public:     togetic<trainerizable> & operator=(togetic<trainerizable> && o) noexcept = delete;
    public:     friend trainerizable;
    };

}

#endif // __POKEMONISM_POKEMONS_TOGETIC_HH__