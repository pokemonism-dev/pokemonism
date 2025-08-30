/**
 * @file        pokemonism/latios/general/generator.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 29, 2025
 */

#ifndef   __POKEMONISM_LATIOS_GENERAL_GENERATOR__HH__
#define   __POKEMONISM_LATIOS_GENERAL_GENERATOR__HH__

#include <pokemon/exception.hh>
#include <pokemonism/latios/general/engine.hh>
#include <pokemonism/latios/general/processor.hh>

namespace pokemonism {
    namespace latios {
        namespace general {

            class generator : public virtual pokemonism::object {
            public:     using                                   processor = general::processor;
            protected:  general::engine *                       engine;

            public:     virtual void clear(void) = 0;
            public:     inline virtual uint64 on(void);
            public:     inline explicit generator(general::engine * engine);
            public:     generator(void) = delete;
            public:     inline ~generator(void) override;
            public:     generator(const generator & o) = delete;
            public:     generator(generator && o) noexcept = delete;
            public:     generator & operator=(const generator & o) = delete;
            public:     generator & operator=(generator && o) noexcept = delete;
            };

            generator::generator(general::engine * engine) : engine(engine) {

            }

            generator::~generator(void) {
                engine = nullptr;
            }

            uint64 generator::on(void) { return declaration::success; }

        }
    }
}

#endif // __POKEMONISM_LATIOS_GENERAL_GENERATOR__HH__
