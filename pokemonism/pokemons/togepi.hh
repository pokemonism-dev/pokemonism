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

namespace pokemonism {
    namespace pokemons {

        template <trainername trainerizable = trainer>
        class togepi : public pokemon {
        public:     class command : public pokemonism::sdk::command {
                    public:     typedef pokemonism::sdk::primitivable * (*internal)(void);
                    protected:  internal func;
                    public:     pokemonism::sdk::primitivable * operator()(void) override { return func(); }
                    public:     explicit command(pokemonism::sdk::primitivable * (*f)(void)) : func(f) {
                                    pokemon_training_check(func == nullptr, return);
                                }
                    public:     command(void) = delete;
                    public:     ~command(void) override { func = nullptr; }
                    public:     command(const togepi<trainerizable>::command & o) = delete;
                    public:     command(togepi<trainerizable>::command && o) noexcept = delete;
                    public:     togepi<trainerizable>::command & operator=(const togepi<trainerizable>::command & o) = delete;
                    public:     togepi<trainerizable>::command & operator=(togepi<trainerizable>::command && o) noexcept = delete;
                    };
        protected:  pokemonism::sdk::engine * internal;
        public:     const char * name(void) const noexcept override { return "togepi"; }
        public:     const char * cry(void) const noexcept override { return "togepriii"; }
        public:     togepi<trainerizable> * ready(void) override;
        public:     togepi<trainerizable> * go(void) override;
        public:     togepi<trainerizable> * goodjob(void) override;
        public:     togepi<trainerizable>::command::event::subscription * pound(togepi<trainerizable>::command * command, unsigned int properties, togepi<trainerizable>::command::event::callback::set & eventSet);
        public:     togepi<trainerizable>::command::event::subscription * pound(togepi<trainerizable>::command * command, unsigned int properties, togepi<trainerizable>::command::event::callback::set & eventSet, togepi<trainerizable>::command::event::subscription::state::callback::function & subscriptionOn);
        public:     togepi<trainerizable>::command::event::subscription * pound(togepi<trainerizable>::command * command, unsigned int properties, togepi<trainerizable>::command::event::callback::set & eventSet, togepi<trainerizable>::command::event::subscription::state::callback::modifier & subscriptionReleaseOn);
        public:     togepi<trainerizable>::command::event::subscription * pound(togepi<trainerizable>::command * command, unsigned int properties, togepi<trainerizable>::command::event::callback::set & eventSet, togepi<trainerizable>::command::event::subscription::state::callback::function & subscriptionOn, togepi<trainerizable>::command::event::subscription::state::callback::modifier & subscriptionReleaseOn);
        public:     togepi<trainerizable>::command::event::subscription * pound(togepi<trainerizable>::command * command, togepi<trainerizable>::command::event::callback::set & eventSet);
        public:     togepi<trainerizable>::command::event::subscription * pound(togepi<trainerizable>::command * command, togepi<trainerizable>::command::event::callback::set & eventSet, togepi<trainerizable>::command::event::subscription::state::callback::function & subscriptionOn);
        public:     togepi<trainerizable>::command::event::subscription * pound(togepi<trainerizable>::command * command, togepi<trainerizable>::command::event::callback::set & eventSet, togepi<trainerizable>::command::event::subscription::state::callback::modifier & subscriptionReleaseOn);
        public:     togepi<trainerizable>::command::event::subscription * pound(togepi<trainerizable>::command * command, togepi<trainerizable>::command::event::callback::set & eventSet, togepi<trainerizable>::command::event::subscription::state::callback::function & subscriptionOn, togepi<trainerizable>::command::event::subscription::state::callback::modifier & subscriptionReleaseOn);

        public:     togepi<trainerizable>::command::event::subscription * pound(togepi<trainerizable>::command * command, int repeat, unsigned int properties, togepi<trainerizable>::command::event::callback::set & eventSet);
        public:     togepi<trainerizable>::command::event::subscription * pound(togepi<trainerizable>::command * command, int repeat, unsigned int properties, togepi<trainerizable>::command::event::callback::set & eventSet, togepi<trainerizable>::command::event::subscription::state::callback::function & subscriptionOn);
        public:     togepi<trainerizable>::command::event::subscription * pound(togepi<trainerizable>::command * command, int repeat, unsigned int properties, togepi<trainerizable>::command::event::callback::set & eventSet, togepi<trainerizable>::command::event::subscription::state::callback::modifier & subscriptionReleaseOn);
        public:     togepi<trainerizable>::command::event::subscription * pound(togepi<trainerizable>::command * command, int repeat, unsigned int properties, togepi<trainerizable>::command::event::callback::set & eventSet, togepi<trainerizable>::command::event::subscription::state::callback::function & subscriptionOn, togepi<trainerizable>::command::event::subscription::state::callback::modifier & subscriptionReleaseOn);
        public:     togepi<trainerizable>::command::event::subscription * pound(togepi<trainerizable>::command * command, int repeat, togepi<trainerizable>::command::event::callback::set & eventSet);
        public:     togepi<trainerizable>::command::event::subscription * pound(togepi<trainerizable>::command * command, int repeat, togepi<trainerizable>::command::event::callback::set & eventSet, togepi<trainerizable>::command::event::subscription::state::callback::function & subscriptionOn);
        public:     togepi<trainerizable>::command::event::subscription * pound(togepi<trainerizable>::command * command, int repeat, togepi<trainerizable>::command::event::callback::set & eventSet, togepi<trainerizable>::command::event::subscription::state::callback::modifier & subscriptionReleaseOn);
        public:     togepi<trainerizable>::command::event::subscription * pound(togepi<trainerizable>::command * command, int repeat, togepi<trainerizable>::command::event::callback::set & eventSet, togepi<trainerizable>::command::event::subscription::state::callback::function & subscriptionOn, togepi<trainerizable>::command::event::subscription::state::callback::modifier & subscriptionReleaseOn);
        protected:  togepi(void);
        protected:  ~togepi(void) override;
        public:     togepi(const togepi & o) = delete;
        public:     togepi(togepi && o) noexcept = delete;
        public:     togepi & operator=(const togepi & o) = delete;
        public:     togepi & operator=(togepi && o) noexcept = delete;
        public:     friend trainerizable;
        };

        template <trainername trainerizable>
        togepi<trainerizable> * togepi<trainerizable>::ready(void) {
            pokemon_training_check(internal != nullptr, return this);

            internal = new pokemonism::sdk::engine();

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

        /**
         * 긴 꼬리나 손 등을 사용하여 상대를 때려서 공격한다.
         *
         */
        // ReSharper disable once CppRedundantTypenameKeyword
        template <trainername trainerizable>
        typename togepi<trainerizable>::command::event::subscription * togepi<trainerizable>::pound(togepi<trainerizable>::command * command, unsigned int properties, typename togepi<trainerizable>::command::event::callback::set & eventSet) {
            pokemon_training_check(internal == nullptr, return nullptr);

            return internal->reg(command, properties, eventSet);
        }

        template <trainername trainerizable>
        // ReSharper disable once CppRedundantTypenameKeyword
        typename togepi<trainerizable>::command::event::subscription * togepi<trainerizable>::pound(togepi<trainerizable>::command * command, unsigned int properties, typename togepi<trainerizable>::command::event::callback::set & eventSet, typename togepi<trainerizable>::command::event::subscription::state::callback::function & subscriptionOn) {
            pokemon_training_check(internal == nullptr, return nullptr);

            return internal->reg(command, properties, eventSet, subscriptionOn);
        }

        // ReSharper disable once CppRedundantTypenameKeyword
        template <trainername trainerizable>
        typename togepi<trainerizable>::command::event::subscription * togepi<trainerizable>::pound(togepi<trainerizable>::command * command, unsigned int properties, typename togepi<trainerizable>::command::event::callback::set & eventSet, typename togepi<trainerizable>::command::event::subscription::state::callback::modifier & subscriptionReleaseOn) {
            pokemon_training_check(internal == nullptr, return nullptr);

            return internal->reg(command, properties, eventSet, subscriptionReleaseOn);
        }

        // ReSharper disable once CppRedundantTypenameKeyword
        template <trainername trainerizable>
        typename togepi<trainerizable>::command::event::subscription * togepi<trainerizable>::pound(togepi<trainerizable>::command * command, unsigned int properties, typename togepi<trainerizable>::command::event::callback::set & eventSet, typename togepi<trainerizable>::command::event::subscription::state::callback::function & subscriptionOn, typename togepi<trainerizable>::command::event::subscription::state::callback::modifier & subscriptionReleaseOn) {
            pokemon_training_check(internal == nullptr, return nullptr);

            return internal->reg(command, properties, eventSet, subscriptionOn, subscriptionReleaseOn);

        }

        // ReSharper disable once CppRedundantTypenameKeyword
        template <trainername trainerizable>
        typename togepi<trainerizable>::command::event::subscription * togepi<trainerizable>::pound(togepi<trainerizable>::command * command, typename togepi<trainerizable>::command::event::callback::set & eventSet) {
            pokemon_training_check(internal == nullptr, return nullptr);

            unsigned int properties = togepi<trainerizable>::command::event::subscription::property::release_on_del | togepi<trainerizable>::command::event::subscription::property::release_object_on_rel;

            return internal->reg(command, properties, eventSet);
        }

        // ReSharper disable once CppRedundantTypenameKeyword
        template <trainername trainerizable>
        typename togepi<trainerizable>::command::event::subscription * togepi<trainerizable>::pound(togepi<trainerizable>::command * command, typename togepi<trainerizable>::command::event::callback::set & eventSet, typename togepi<trainerizable>::command::event::subscription::state::callback::function & subscriptionOn) {
            pokemon_training_check(internal == nullptr, return nullptr);

            unsigned int properties = togepi<trainerizable>::command::event::subscription::property::release_on_del | togepi<trainerizable>::command::event::subscription::property::release_object_on_rel;

            return internal->reg(command, properties, eventSet, subscriptionOn);
        }

        // ReSharper disable once CppRedundantTypenameKeyword
        template <trainername trainerizable>
        typename togepi<trainerizable>::command::event::subscription * togepi<trainerizable>::pound(togepi<trainerizable>::command * command, typename togepi<trainerizable>::command::event::callback::set & eventSet, typename togepi<trainerizable>::command::event::subscription::state::callback::modifier & subscriptionReleaseOn) {
            pokemon_training_check(internal == nullptr, return nullptr);

            unsigned int properties = togepi<trainerizable>::command::event::subscription::property::release_on_del | togepi<trainerizable>::command::event::subscription::property::release_object_on_rel;

            return internal->reg(command, properties, eventSet, subscriptionReleaseOn);
        }

        // ReSharper disable once CppRedundantTypenameKeyword
        template <trainername trainerizable>
        typename togepi<trainerizable>::command::event::subscription * togepi<trainerizable>::pound(togepi<trainerizable>::command * command, typename togepi<trainerizable>::command::event::callback::set & eventSet, typename togepi<trainerizable>::command::event::subscription::state::callback::function & subscriptionOn, typename togepi<trainerizable>::command::event::subscription::state::callback::modifier & subscriptionReleaseOn) {
            pokemon_training_check(internal == nullptr, return nullptr);

            unsigned int properties = togepi<trainerizable>::command::event::subscription::property::release_on_del |
                                      togepi<trainerizable>::command::event::subscription::property::release_object_on_rel;

            return internal->reg(command, properties, eventSet, subscriptionOn, subscriptionReleaseOn);
        }

        // ReSharper disable once CppRedundantTypenameKeyword
        template <trainername trainerizable>
        typename togepi<trainerizable>::command::event::subscription * togepi<trainerizable>::pound(togepi<trainerizable>::command * command, int repeat, unsigned int properties, typename togepi<trainerizable>::command::event::callback::set & eventSet) {
            pokemon_training_check(internal == nullptr, return nullptr);

            return internal->reg(command, properties, eventSet);
        }

        // ReSharper disable once CppRedundantTypenameKeyword
        template <trainername trainerizable>
        typename togepi<trainerizable>::command::event::subscription * togepi<trainerizable>::pound(togepi<trainerizable>::command * command, int repeat, unsigned int properties, typename togepi<trainerizable>::command::event::callback::set & eventSet, typename togepi<trainerizable>::command::event::subscription::state::callback::function & subscriptionOn) {
            pokemon_training_check(internal == nullptr, return nullptr);

            return internal->reg(command, properties, eventSet, subscriptionOn);
        }

        // ReSharper disable once CppRedundantTypenameKeyword
        template <trainername trainerizable>
        typename togepi<trainerizable>::command::event::subscription * togepi<trainerizable>::pound(togepi<trainerizable>::command * command, int repeat, unsigned int properties, typename togepi<trainerizable>::command::event::callback::set & eventSet, typename togepi<trainerizable>::command::event::subscription::state::callback::modifier & subscriptionReleaseOn) {
            pokemon_training_check(internal == nullptr, return nullptr);

            return internal->reg(command, properties, eventSet, subscriptionReleaseOn);
        }

        // ReSharper disable once CppRedundantTypenameKeyword
        template <trainername trainerizable>
        typename togepi<trainerizable>::command::event::subscription * togepi<trainerizable>::pound(togepi<trainerizable>::command * command, int repeat, unsigned int properties, typename togepi<trainerizable>::command::event::callback::set & eventSet, typename togepi<trainerizable>::command::event::subscription::state::callback::function & subscriptionOn, typename togepi<trainerizable>::command::event::subscription::state::callback::modifier & subscriptionReleaseOn) {
            pokemon_training_check(internal == nullptr, return nullptr);

            return internal->reg(command, properties, eventSet, subscriptionOn, subscriptionReleaseOn);

        }

        // ReSharper disable once CppRedundantTypenameKeyword
        template <trainername trainerizable>
        typename togepi<trainerizable>::command::event::subscription * togepi<trainerizable>::pound(togepi<trainerizable>::command * command, int repeat, typename togepi<trainerizable>::command::event::callback::set & eventSet) {
            pokemon_training_check(internal == nullptr, return nullptr);

            unsigned int properties = togepi<trainerizable>::command::event::subscription::property::release_on_del | togepi<trainerizable>::command::event::subscription::property::release_object_on_rel;

            return internal->reg(command, properties, eventSet);
        }

        // ReSharper disable once CppRedundantTypenameKeyword
        template <trainername trainerizable>
        typename togepi<trainerizable>::command::event::subscription * togepi<trainerizable>::pound(togepi<trainerizable>::command * command, int repeat, typename togepi<trainerizable>::command::event::callback::set & eventSet, typename togepi<trainerizable>::command::event::subscription::state::callback::function & subscriptionOn) {
            pokemon_training_check(internal == nullptr, return nullptr);

            unsigned int properties = togepi<trainerizable>::command::event::subscription::property::release_on_del | togepi<trainerizable>::command::event::subscription::property::release_object_on_rel;

            return internal->reg(command, properties, eventSet, subscriptionOn);
        }

        // ReSharper disable once CppRedundantTypenameKeyword
        template <trainername trainerizable>
        typename togepi<trainerizable>::command::event::subscription * togepi<trainerizable>::pound(togepi<trainerizable>::command * command, int repeat, typename togepi<trainerizable>::command::event::callback::set & eventSet, typename togepi<trainerizable>::command::event::subscription::state::callback::modifier & subscriptionReleaseOn) {
            pokemon_training_check(internal == nullptr, return nullptr);

            unsigned int properties = togepi<trainerizable>::command::event::subscription::property::release_on_del | togepi<trainerizable>::command::event::subscription::property::release_object_on_rel;

            return internal->reg(command, properties, eventSet, subscriptionReleaseOn);
        }

        // ReSharper disable once CppRedundantTypenameKeyword
        template <trainername trainerizable>
        typename togepi<trainerizable>::command::event::subscription * togepi<trainerizable>::pound(togepi<trainerizable>::command * command, int repeat, typename togepi<trainerizable>::command::event::callback::set & eventSet, typename togepi<trainerizable>::command::event::subscription::state::callback::function & subscriptionOn, typename togepi<trainerizable>::command::event::subscription::state::callback::modifier & subscriptionReleaseOn) {
            pokemon_training_check(internal == nullptr, return nullptr);

            unsigned int properties = togepi<trainerizable>::command::event::subscription::property::release_on_del |
                                      togepi<trainerizable>::command::event::subscription::property::release_object_on_rel;

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

#endif // __POKEMONISM_TOGEPI_HH__