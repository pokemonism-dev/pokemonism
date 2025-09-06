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
        protected:  pokemonism::sdk::engine * engine;
        public:     const char * name(void) const noexcept override { return "togepi"; }
        public:     const char * cry(void) const noexcept override { return "togepriii"; }
        public:     togepi<trainerizable> * ready(void) override;
        public:     togepi<trainerizable> * go(void) override;
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
            pokemon_training_check(engine != nullptr, return this);

            engine = new pokemonism::sdk::engine();

            engine->on();

            return this;
        }

        template <trainername trainerizable>
        togepi<trainerizable>  * togepi<trainerizable>::go(void) {
            pokemon_training_check(engine == nullptr, return this);

            result = engine->run();

            engine = pokemonism::sdk::allocator::del(engine);

            return this;
        }

        template<typename trainerizable>
        togepi<trainerizable>::togepi(void) : engine(nullptr) {

        }

        template<typename trainerizable>
        togepi<trainerizable>::~togepi(void) {
            engine = pokemonism::sdk::allocator::del(engine);
        }


    }
}

#endif // __POKEMONISM_TOGEPI_HH__