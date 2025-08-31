/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 01, 2025
 */

#ifndef   __POKEMONISM_POKEMON_GENERIC_LAMBDA_RUNNABLE_HH__
#define   __POKEMONISM_POKEMON_GENERIC_LAMBDA_RUNNABLE_HH__

#include <pokemonism/pokemon/interface/runnable.hh>
#include <pokemonism/pokemon/exception.hh>

namespace pokemonism {
    namespace pokemon {
        namespace generic {
            namespace lambda {

                class runnable : public pokemon::interface::runnable {
                public:     typedef pokemon::interface::runnable::type type;
                protected:  type func;
                public:     void operator()(void) override {
                                if (func == nullptr) throw pokemon::exception();
                                func();
                            }
                public:     explicit runnable(type f) : func(f) {}
                public:     runnable(void) = delete;
                public:     ~runnable(void) override {}
                public:     runnable(const runnable & o) = delete;
                public:     runnable(runnable && o) noexcept = delete;
                public:     runnable & operator=(const runnable & o) = delete;
                public:     runnable & operator=(runnable && o) noexcept = delete;
                };
            }
        }
    }
}

#endif // __POKEMONISM_POKEMON_GENERIC_LAMBDA_RUNNABLE_HH__