/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 07, 2025
 */

#ifndef   __POKEMONISM_SDK_POKEMONS_TOGEPI_TOGETIC_TEMPLATEABLE_HH__
#define   __POKEMONISM_SDK_POKEMONS_TOGEPI_TOGETIC_TEMPLATEABLE_HH__

#include <pokemonism/pokemons/togepi/togetic.hh>

namespace pokemonism::pokemons {

    template <trainername trainerizable>
    struct togetic<trainerizable>::templateable {
    public:     struct command;
    };

    template <trainername trainerizable>
    struct togetic<trainerizable>::templateable::command {
    public:     class event;
    };

    template <trainername trainerizable>
    class togetic<trainerizable>::templateable::command::event : public pokemonism::sdk::templateable::command::event {
    public:     struct subscriptions {
                public:     template <class commandable = pokemonism::sdk::command, typename outputable = commandable::output> class repeat;
                };
    protected:  event(void) {}
    public:     inline ~event(void) override {}
    public:     event(const command::event & o) = delete;
    public:     event(command::event && o) noexcept = delete;
    public:     command::event & operator=(const command::event & o) = delete;
    public:     command::event & operator=(command::event && o) noexcept = delete;
    };

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    class togetic<trainerizable>::templateable::command::event::subscriptions::repeat : public pokemonism::sdk::templateable::command::internal::subscription<commandable, outputable> {
    protected:  int total;
    protected:  inline bool executeSet(void) override {
                    this->count = this->count + 1;

                    if (total <= this->count) {
                        this->status = this->status | command::event::subscription::state::complete;

                        return true;
                    }

                    return false;
                }
    protected:  inline repeat(commandable * object, int total, unsigned int properties, const togetic<trainerizable>::templateable::command::event::callback<commandable, outputable>::set & eventSet) : pokemonism::sdk::templateable::command::internal::subscription<commandable, outputable>(object, properties, eventSet), total(total) { pokemon_develop_check(total <= 0, total = 1); }
    protected:  inline repeat(commandable * object, int total, unsigned int properties, const togetic<trainerizable>::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn) : pokemonism::sdk::templateable::command::internal::subscription<commandable, outputable>(object, properties, eventSet, subscriptionOn), total(total) { pokemon_develop_check(total <= 0, total = 1); }
    protected:  inline repeat(commandable * object, int total, unsigned int properties, const togetic<trainerizable>::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) : pokemonism::sdk::templateable::command::internal::subscription<commandable, outputable>(object, properties, eventSet, subscriptionReleaseOn), total(total) { pokemon_develop_check(total <= 0, total = 1); }
    protected:  inline repeat(commandable * object, int total, unsigned int properties, const togetic<trainerizable>::templateable::command::event::callback<commandable, outputable>::set & eventSet, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn, pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) : pokemonism::sdk::templateable::command::internal::subscription<commandable, outputable>(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn), total(total) { pokemon_develop_check(total <= 0, total = 1); }
    protected:  inline repeat(void) = delete;
    protected:  ~repeat(void) override {}
    public:     repeat(const togetic<trainerizable>::templateable::command::event::subscriptions::repeat<commandable, outputable> & o) = delete;
    public:     repeat(togetic<trainerizable>::templateable::command::event::subscriptions::repeat<commandable, outputable> && o) noexcept = delete;
    public:     togetic<trainerizable>::templateable::command::event::subscriptions::repeat<commandable, outputable> & operator=(const togetic<trainerizable>::templateable::command::event::subscriptions::repeat<commandable, outputable> & o) = delete;
    public:     togetic<trainerizable>::templateable::command::event::subscriptions::repeat<commandable, outputable> & operator=(togetic<trainerizable>::templateable::command::event::subscriptions::repeat<commandable, outputable> && o) noexcept = delete;
    public:     friend togetic<trainerizable>;
    };

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::genericRepeatReg(commandable * object, int total, unsigned int properties, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(new typename togetic<trainerizable>::templateable::command::event::subscriptions::template repeat<commandable, outputable>(object, total, properties, eventSet));
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::genericRepeatReg(commandable * object, int total, unsigned int properties, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(new typename togetic<trainerizable>::templateable::command::event::subscriptions::template repeat<commandable, outputable>(object, total, properties, eventSet, subscriptionOn));
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::genericRepeatReg(commandable * object, int total, unsigned int properties, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(new typename togetic<trainerizable>::templateable::command::event::subscriptions::template repeat<commandable, outputable>(object, total, properties, eventSet, subscriptionReleaseOn));
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::genericRepeatReg(commandable * object, int total, unsigned int properties, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(new typename togetic<trainerizable>::templateable::command::event::subscriptions::template repeat<commandable, outputable>(object, total, properties, eventSet, subscriptionOn, subscriptionReleaseOn));
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::genericRepeatReg(commandable * object, int total, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(new typename togetic<trainerizable>::templateable::command::event::subscriptions::template repeat<commandable, outputable>(object, total, togetic<trainerizable>::declaration::properties, eventSet));
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::genericRepeatReg(commandable * object, int total, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(new typename togetic<trainerizable>::templateable::command::event::subscriptions::template repeat<commandable, outputable>(object, total, togetic<trainerizable>::declaration::properties, eventSet, subscriptionOn));
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::genericRepeatReg(commandable * object, int total, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(new typename togetic<trainerizable>::templateable::command::event::subscriptions::template repeat<commandable, outputable>(object, total, togetic<trainerizable>::declaration::properties, eventSet, subscriptionReleaseOn));
    }

    template <trainername trainerizable>
    template <class commandable, typename outputable>
    inline pokemonism::sdk::templateable::command::subscription<commandable, outputable> * togetic<trainerizable>::genericRepeatReg(commandable * object, int total, const typename pokemonism::sdk::templateable::command::event::callback<commandable, outputable>::set & eventSet, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::function subscriptionOn, typename pokemonism::sdk::templateable::command::subscription<commandable, outputable>::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_develop_check(genericCommandGet() == nullptr, return nullptr);

        return genericCommandGet()->genericReg(new typename togetic<trainerizable>::templateable::command::event::subscriptions::template repeat<commandable, outputable>(object, total, togetic<trainerizable>::declaration::properties, eventSet, subscriptionOn, subscriptionReleaseOn));
    }

}

#endif // __POKEMONISM_SDK_POKEMONS_TOGEPI_TOGETIC_TEMPLATEABLE_HH__