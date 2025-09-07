/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 07, 2025
 */

#ifndef   __POKEMONISM_POKEMONS_TOGEPI_COMMAND_EVENT_HH__
#define   __POKEMONISM_POKEMONS_TOGEPI_COMMAND_EVENT_HH__

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/pokemons/togepi/command.hh>

namespace pokemonism::pokemons {

    template <trainername trainerizable>
    class togepi<trainerizable>::command::event : public pokemonism::sdk::command::event {
    public:     struct subscriptions {
                public:     class repeat;
                };
    public:     event(void) {}
    public:     ~event(void) override {}
    public:     event(const togepi<trainerizable>::command::event & o) = delete;
    public:     event(togepi<trainerizable>::command::event && o) noexcept = delete;
    public:     togepi<trainerizable>::command::event & operator=(const togepi<trainerizable>::command::event & o) = delete;
    public:     togepi<trainerizable>::command::event & operator=(togepi<trainerizable>::command::event && o) noexcept = delete;
    };

    template <trainername trainerizable>
    class togepi<trainerizable>::command::event::subscriptions::repeat : public pokemonism::sdk::command::event::internal::subscription {
    protected:  int total;
    protected:  inline bool executeSet(void) override {
                    count = count + 1;

                    if (total <= count) {
                        status = status | command::event::subscription::state::complete;

                        return true;
                    }

                    return false;
                }
    protected:  inline repeat(pokemonism::sdk::command * object, int total, unsigned int properties, const command::event::callback::set & eventSet) : pokemonism::sdk::command::event::internal::subscription(object, properties, eventSet), total(total) { pokemon_develop_check(total <= 0, total = 1); }
    protected:  inline repeat(pokemonism::sdk::command * object, int total, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn) : pokemonism::sdk::command::event::internal::subscription(object, properties, eventSet, subscriptionOn), total(total) { pokemon_develop_check(total <= 0, total = 1); }
    protected:  inline repeat(pokemonism::sdk::command * object, int total, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::modifier subscriptionReleaseOn) : pokemonism::sdk::command::event::internal::subscription(object, properties, eventSet, subscriptionReleaseOn), total(total) { pokemon_develop_check(total <= 0, total = 1); }
    protected:  inline repeat(pokemonism::sdk::command * object, int total, unsigned int properties, const command::event::callback::set & eventSet, command::event::subscription::state::callback::function subscriptionOn, command::event::subscription::state::callback::modifier subscriptionReleaseOn) : pokemonism::sdk::command::event::internal::subscription(object, properties, eventSet, subscriptionOn, subscriptionReleaseOn), total(total) { pokemon_develop_check(total <= 0, total = 1); }
    protected:  inline repeat(void) = delete;
    protected:  ~repeat(void) override {}
    public:     repeat(const togepi<trainerizable>::command::event::subscriptions::repeat & o) = delete;
    public:     repeat(togepi<trainerizable>::command::event::subscriptions::repeat && o) noexcept = delete;
    public:     togepi<trainerizable>::command::event::subscriptions::repeat & operator=(const togepi<trainerizable>::command::event::subscriptions::repeat & o) = delete;
    public:     togepi<trainerizable>::command::event::subscriptions::repeat & operator=(togepi<trainerizable>::command::event::subscriptions::repeat && o) noexcept = delete;
    public:     friend togepi<trainerizable>;
    };

    template <trainername trainerizable>
    pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, int repeat, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet) const {
        pokemon_training_check(internal == nullptr, return nullptr);

        typename togepi<trainerizable>::command::event::subscriptions::repeat * subscription = new togepi<trainerizable>::command::event::subscriptions::repeat(command, repeat, properties, eventSet);

        return reinterpret_cast<togepi<trainerizable>::engine *>(internal)->reg(subscription);
    }

    template <trainername trainerizable>
    pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, int repeat, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn) const {
        pokemon_training_check(internal == nullptr, return nullptr);

        typename togepi<trainerizable>::command::event::subscriptions::repeat * subscription = new togepi<trainerizable>::command::event::subscriptions::repeat(command, repeat, properties, eventSet, subscriptionOn);

        return reinterpret_cast<togepi<trainerizable>::engine *>(internal)->reg(subscription);
    }

    template <trainername trainerizable>
    pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, int repeat, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_training_check(internal == nullptr, return nullptr);

        typename togepi<trainerizable>::command::event::subscriptions::repeat * subscription = new togepi<trainerizable>::command::event::subscriptions::repeat(command, repeat, properties, eventSet, subscriptionReleaseOn);

        return reinterpret_cast<togepi<trainerizable>::engine *>(internal)->reg(subscription);
    }

    template <trainername trainerizable>
    pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, int repeat, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_training_check(internal == nullptr, return nullptr);

        typename togepi<trainerizable>::command::event::subscriptions::repeat * subscription = new togepi<trainerizable>::command::event::subscriptions::repeat(command, repeat, properties, eventSet, subscriptionOn, subscriptionReleaseOn);

        return reinterpret_cast<togepi<trainerizable>::engine *>(internal)->reg(subscription);

    }

    template <trainername trainerizable>
    pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, int repeat, const pokemonism::sdk::command::event::callback::set & eventSet) const {
        pokemon_training_check(internal == nullptr, return nullptr);

        constexpr unsigned int properties = pokemonism::sdk::command::event::subscription::property::release_on_del | pokemonism::sdk::command::event::subscription::property::release_object_on_rel;

        typename togepi<trainerizable>::command::event::subscriptions::repeat * subscription = new togepi<trainerizable>::command::event::subscriptions::repeat(command, repeat, properties, eventSet);

        return reinterpret_cast<togepi<trainerizable>::engine *>(internal)->reg(subscription);
    }

    template <trainername trainerizable>
    pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, int repeat, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn) const {
        pokemon_training_check(internal == nullptr, return nullptr);

        constexpr unsigned int properties = pokemonism::sdk::command::event::subscription::property::release_on_del | pokemonism::sdk::command::event::subscription::property::release_object_on_rel;

        typename togepi<trainerizable>::command::event::subscriptions::repeat * subscription = new togepi<trainerizable>::command::event::subscriptions::repeat(command, repeat, properties, eventSet, subscriptionOn);

        return reinterpret_cast<togepi<trainerizable>::engine *>(internal)->reg(subscription);
    }

    template <trainername trainerizable>
    pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, int repeat, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_training_check(internal == nullptr, return nullptr);

        constexpr unsigned int properties = pokemonism::sdk::command::event::subscription::property::release_on_del | pokemonism::sdk::command::event::subscription::property::release_object_on_rel;

        typename togepi<trainerizable>::command::event::subscriptions::repeat * subscription = new togepi<trainerizable>::command::event::subscriptions::repeat(command, repeat, properties, eventSet, subscriptionReleaseOn);

        return reinterpret_cast<togepi<trainerizable>::engine *>(internal)->reg(subscription);
    }

    template <trainername trainerizable>
    pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, int repeat, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const {
        pokemon_training_check(internal == nullptr, return nullptr);

        constexpr unsigned int properties = pokemonism::sdk::command::event::subscription::property::release_on_del | pokemonism::sdk::command::event::subscription::property::release_object_on_rel;

        typename togepi<trainerizable>::command::event::subscriptions::repeat * subscription = new togepi<trainerizable>::command::event::subscriptions::repeat(command, repeat, properties, eventSet, subscriptionOn, subscriptionReleaseOn);

        return reinterpret_cast<togepi<trainerizable>::engine *>(internal)->reg(subscription);
    }


}

#endif // __POKEMONISM_POKEMONS_TOGEPI_COMMAND_EVENT_HH__