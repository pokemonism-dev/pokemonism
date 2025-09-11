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

// ReSharper disable CppUnusedIncludeDirective
#include <pokemonism/pokemons/togepi.hh>

#include <pokemonism/sdk/templateable/engine.hh>

namespace pokemonism::pokemons {

    template <trainername trainerizable = trainer>
    class togetic : public togepi<trainerizable> {
    public:     template <typename outputable = pokemonism::sdk::primitivable> class command;
    public:     struct templateable;
    public:     class engine;
    public:     const char * name(void) const noexcept override { return "togetic"; }
    public:     const char * cry(void) const noexcept override { return "togetic, togee!"; }
    public:     togetic<trainerizable> * ready(void) override;
    public:     inline pokemonism::sdk::templateable::command::event::generator * genericCommandGet(void) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericReg(commandable * object, unsigned int properties, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericReg(commandable * object, unsigned int properties, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericReg(commandable * object, unsigned int properties, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericReg(commandable * object, unsigned int properties, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericReg(commandable * object, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericReg(commandable * object, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericReg(commandable * object, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericReg(commandable * object, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericRepeatReg(commandable * object, int total, unsigned int properties, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericRepeatReg(commandable * object, int total, unsigned int properties, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericRepeatReg(commandable * object, int total, unsigned int properties, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericRepeatReg(commandable * object, int total, unsigned int properties, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericRepeatReg(commandable * object, int total, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericRepeatReg(commandable * object, int total, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericRepeatReg(commandable * object, int total, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericRepeatReg(commandable * object, int total, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const;
    protected:  explicit togetic(togepi<trainerizable> * monster);
    protected:  togetic(void) {}
    protected:  ~togetic(void) override {}
    public:     togetic(const togetic<trainerizable> & o) = delete;
    public:     togetic(togetic<trainerizable> && o) noexcept = delete;
    public:     togetic<trainerizable> & operator=(const togetic<trainerizable> & o) = delete;
    public:     togetic<trainerizable> & operator=(togetic<trainerizable> && o) noexcept = delete;
    public:     friend trainerizable;
    public:     friend class togepi<trainerizable>;
    };

    template <trainername trainerizable>
    class togetic<trainerizable>::engine : public togepi<trainerizable>::engine {
    public:     inline pokemonism::sdk::templateable::command::event::generator * genericCommandGet(void) const { return static_cast<pokemonism::sdk::templateable::command::event::generator *>(reinterpret_cast<void *>(this->generator.command)); }
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericReg(commandable * object, unsigned int properties, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericReg(commandable * object, unsigned int properties, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericReg(commandable * object, unsigned int properties, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const;
    public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * genericReg(commandable * object, unsigned int properties, const pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const;
    protected:  engine(void) {}
    protected:  ~engine(void) override {}
    public:     engine(const engine & o) = delete;
    public:     engine(engine && o) noexcept = delete;
    public:     engine & operator=(const engine & o) = delete;
    public:     engine & operator=(engine && o) noexcept = delete;
    public:     friend togetic<trainerizable>;
    };

    template <trainername trainerizable>
    inline pokemonism::sdk::templateable::command::event::generator * togetic<trainerizable>::genericCommandGet(void) const {
        pokemon_training_check(this->internal == nullptr, return nullptr);
        return reinterpret_cast<togetic<trainerizable>::engine *>(this->internal)->genericCommandGet();
    }

    template <trainername trainerizable>
    togetic<trainerizable> * togetic<trainerizable>::ready(void) {
        pokemon_training_check(this->internal != nullptr, return this);

        this->internal = new togetic<trainerizable>::engine();

        this->internal->on();

        return this;
    }

    template <trainername trainerizable>
    togetic<trainerizable> * togepi<trainerizable>::evolve(togepi<trainerizable>::pointer & monster) {
        pokemon_training_check(monster == nullptr, return nullptr);

        togetic<trainerizable> * evolution = new togetic<trainerizable>(monster);

        delete monster;
        monster = nullptr;

        return evolution;
    }

    template <trainername trainerizable>
    template <itemname itemable>
    togetic<trainerizable> * togepi<trainerizable>::evolve(togepi<trainerizable> * monster, itemable * item) {
        pokemon_training_check(monster == nullptr, return nullptr);

        togetic<trainerizable> * evolution = new togetic<trainerizable>(monster);

        delete monster;

        return evolution;
    }

    template <trainername trainerizable>
    togetic<trainerizable>::togetic(togepi<trainerizable> * monster) {
        this->internal = monster->internal;
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::genericReg(commandable * object, unsigned int properties, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(object, properties, eventSet);
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::genericReg(commandable * object, unsigned int properties, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(object, properties, eventSet, subscriptionOn);
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::genericReg(commandable * object, unsigned int properties, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(object, properties, eventSet, subscriptionReleaseOn);
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::genericReg(commandable * object, unsigned int properties, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn);
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::genericReg(commandable * object, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(object, togetic<trainerizable>::declaration::properties, eventSet);
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::genericReg(commandable * object, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(object, togetic<trainerizable>::declaration::properties, eventSet, subscriptionOn);
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::genericReg(commandable * object, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(object, togetic<trainerizable>::declaration::properties, eventSet, subscriptionReleaseOn);
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::genericReg(commandable * object, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(object, togetic<trainerizable>::declaration::properties, eventSet, subscriptionOn, subscriptionReleaseOn);
    }

}

#include <pokemonism/pokemons/togepi/togetic/engine.hh>
#include <pokemonism/pokemons/togepi/togetic/templateable.hh>

#endif // __POKEMONISM_POKEMONS_TOGETIC_HH__