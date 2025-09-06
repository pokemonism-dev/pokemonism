/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_TOGEPI_HH__
#define   __POKEMONISM_TOGEPI_HH__

#include <pokemonism/faint.hh>
#include <pokemonism/pokemon.hh>
#include <pokemonism/trainer.hh>

#include <pokemonism/sdk/engine.hh>
#include <pokemonism/sdk/allocator.hh>
#include <pokemonism/sdk/functional/command.hh>

namespace pokemonism {
    namespace pokemons {

        template <trainername trainerizable = trainer>
        class togepi : public pokemon {
        // public:     using command = pokemonism::sdk::command;
        public:     class command : public pokemonism::sdk::command {

                    };
        public:     class engine;
        protected:  pokemonism::sdk::engine * internal;
        public:     const char * name(void) const noexcept override { return "togepi"; }
        public:     const char * cry(void) const noexcept override { return "togepriii"; }
        public:     togepi<trainerizable> * ready(void) override;
        public:     togepi<trainerizable> * go(void) override;
        public:     togepi<trainerizable> * goodjob(void) override;
        public:     pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * command, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet) const;
        public:     pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * command, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, const pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn) const;
        public:     pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * command, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const;
        public:     pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * command, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const;
        public:     pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * command, const pokemonism::sdk::command::event::callback::set & eventSet) const;
        public:     pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * command, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn) const;
        public:     pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * command, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const;
        public:     pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * command, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const;

        public:     pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * command, int repeat, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet) const;
        public:     pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * command, int repeat, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn) const;
        public:     pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * command, int repeat, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const;
        public:     pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * command, int repeat, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const;
        public:     pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * command, int repeat, const pokemonism::sdk::command::event::callback::set & eventSet) const;
        public:     pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * command, int repeat, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn) const;
        public:     pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * command, int repeat, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const;
        public:     pokemonism::sdk::command::event::subscription * reg(pokemonism::sdk::command * command, int repeat, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const;
        protected:  togepi(void);
        protected:  ~togepi(void) override;
        public:     togepi(const togepi & o) = delete;
        public:     togepi(togepi && o) noexcept = delete;
        public:     togepi & operator=(const togepi & o) = delete;
        public:     togepi & operator=(togepi && o) noexcept = delete;
        public:     friend trainerizable;
        };

        template <trainername trainerizable>
        class togepi<trainerizable>::engine : public pokemonism::sdk::engine {
        protected:  engine(void) {}
        protected:  ~engine(void) override {}
        public:     engine(const engine & o) = delete;
        public:     engine(engine && o) noexcept = delete;
        public:     engine & operator=(const engine & o) = delete;
        public:     engine & operator=(engine && o) noexcept = delete;
        public:     friend pokemonism::sdk::command::event::generator;
        public:     friend togepi<trainerizable>;
        };

        template <trainername trainerizable>
        togepi<trainerizable> * togepi<trainerizable>::ready(void) {
            pokemon_training_check(internal != nullptr, return this);

            internal = new togepi<trainerizable>::engine();

            internal->on();

            return this;
        }

        template <trainername trainerizable>
        togepi<trainerizable>  * togepi<trainerizable>::go(void) {
            pokemon_training_check(internal == nullptr, return this);

            result = internal->run();

            internal = pokemonism::sdk::allocator::del(internal);

            return this;
        }

        template <trainername trainerizable>
        togepi<trainerizable> * togepi<trainerizable>::goodjob(void) {
            pokemon_training_check(internal == nullptr, return this);

            internal->off(nullptr);

            return this;
        }

        template <trainername trainerizable>
        pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet) const {
            pokemon_training_check(internal == nullptr, return nullptr);

            return internal->reg(command, properties, eventSet);
        }

        template <trainername trainerizable>
        pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn) const {
            pokemon_training_check(internal == nullptr, return nullptr);

            return internal->reg(command, properties, eventSet, subscriptionOn);
        }

        template <trainername trainerizable>
        pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const {
            pokemon_training_check(internal == nullptr, return nullptr);

            return internal->reg(command, properties, eventSet, subscriptionReleaseOn);
        }

        template <trainername trainerizable>
        pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const {
            pokemon_training_check(internal == nullptr, return nullptr);

            return internal->reg(command, properties, eventSet, subscriptionOn, subscriptionReleaseOn);

        }

        template <trainername trainerizable>
        pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, const pokemonism::sdk::command::event::callback::set & eventSet) const {
            pokemon_training_check(internal == nullptr, return nullptr);

            constexpr unsigned int properties = pokemonism::sdk::command::event::subscription::property::release_on_del | pokemonism::sdk::command::event::subscription::property::release_object_on_rel;

            return internal->reg(command, properties, eventSet);
        }

        template <trainername trainerizable>
        pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn) const {
            pokemon_training_check(internal == nullptr, return nullptr);

            constexpr unsigned int properties = pokemonism::sdk::command::event::subscription::property::release_on_del | pokemonism::sdk::command::event::subscription::property::release_object_on_rel;

            return internal->reg(command, properties, eventSet, subscriptionOn);
        }

        template <trainername trainerizable>
        pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const {
            pokemon_training_check(internal == nullptr, return nullptr);

            constexpr unsigned int properties = pokemonism::sdk::command::event::subscription::property::release_on_del | pokemonism::sdk::command::event::subscription::property::release_object_on_rel;

            return internal->reg(command, properties, eventSet, subscriptionReleaseOn);
        }

        template <trainername trainerizable>
        pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const {
            pokemon_training_check(internal == nullptr, return nullptr);

            constexpr unsigned int properties = pokemonism::sdk::command::event::subscription::property::release_on_del |
                                      pokemonism::sdk::command::event::subscription::property::release_object_on_rel;

            return internal->reg(command, properties, eventSet, subscriptionOn, subscriptionReleaseOn);
        }

        template <trainername trainerizable>
        pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, int repeat, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet) const {
            pokemon_training_check(internal == nullptr, return nullptr);

            return internal->reg(command, properties, eventSet);
        }

        template <trainername trainerizable>
        pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, int repeat, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn) const {
            pokemon_training_check(internal == nullptr, return nullptr);

            return internal->reg(command, properties, eventSet, subscriptionOn);
        }

        template <trainername trainerizable>
        pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, int repeat, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const {
            pokemon_training_check(internal == nullptr, return nullptr);

            return internal->reg(command, properties, eventSet, subscriptionReleaseOn);
        }

        template <trainername trainerizable>
        pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, int repeat, unsigned int properties, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const {
            pokemon_training_check(internal == nullptr, return nullptr);

            return internal->reg(command, properties, eventSet, subscriptionOn, subscriptionReleaseOn);

        }

        template <trainername trainerizable>
        pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, int repeat, const pokemonism::sdk::command::event::callback::set & eventSet) const {
            pokemon_training_check(internal == nullptr, return nullptr);

            constexpr unsigned int properties = pokemonism::sdk::command::event::subscription::property::release_on_del | pokemonism::sdk::command::event::subscription::property::release_object_on_rel;

            return internal->reg(command, properties, eventSet);
        }

        template <trainername trainerizable>
        pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, int repeat, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn) const {
            pokemon_training_check(internal == nullptr, return nullptr);

            constexpr unsigned int properties = pokemonism::sdk::command::event::subscription::property::release_on_del | pokemonism::sdk::command::event::subscription::property::release_object_on_rel;

            return internal->reg(command, properties, eventSet, subscriptionOn);
        }

        template <trainername trainerizable>
        pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, int repeat, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const {
            pokemon_training_check(internal == nullptr, return nullptr);

            constexpr unsigned int properties = pokemonism::sdk::command::event::subscription::property::release_on_del | pokemonism::sdk::command::event::subscription::property::release_object_on_rel;

            return internal->reg(command, properties, eventSet, subscriptionReleaseOn);
        }

        template <trainername trainerizable>
        pokemonism::sdk::command::event::subscription * togepi<trainerizable>::reg(pokemonism::sdk::command * command, int repeat, const pokemonism::sdk::command::event::callback::set & eventSet, pokemonism::sdk::command::event::subscription::state::callback::function subscriptionOn, pokemonism::sdk::command::event::subscription::state::callback::modifier subscriptionReleaseOn) const {
            pokemon_training_check(internal == nullptr, return nullptr);

            constexpr unsigned int properties = pokemonism::sdk::command::event::subscription::property::release_on_del | pokemonism::sdk::command::event::subscription::property::release_object_on_rel;

            return internal->reg(command, properties, eventSet, subscriptionOn, subscriptionReleaseOn);
        }

        template<typename trainerizable>
        togepi<trainerizable>::togepi(void) : internal(nullptr) {

        }

        template<typename trainerizable>
        togepi<trainerizable>::~togepi(void) {
            internal = pokemonism::sdk::allocator::del(internal);
        }


    }
}

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/pokemons/togepi/pound/command.hh>

#endif // __POKEMONISM_TOGEPI_HH__