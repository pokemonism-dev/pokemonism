/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 07, 2025
 */

#ifndef   __POKEMONISM_POKEMONS_TOGEPI_TOGETIC_ENGINE_HH__
#define   __POKEMONISM_POKEMONS_TOGEPI_TOGETIC_ENGINE_HH__

#include <pokemonism/pokemons/togepi/togetic.hh>

namespace pokemonism::pokemons {

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::engine::genericReg(commandable * object, unsigned int properties, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(object, properties, eventSet);
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::engine::genericReg(commandable * object, unsigned int properties, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(object, properties, eventSet, subscriptionOn);
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::engine::genericReg(commandable * object, unsigned int properties, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(object, properties, eventSet, subscriptionReleaseOn);
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::engine::genericReg(commandable * object, unsigned int properties, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn);
    }

}

#endif // __POKEMONISM_POKEMONS_TOGEPI_TOGETIC_ENGINE_HH__