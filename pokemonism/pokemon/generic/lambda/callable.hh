/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 01, 2025
 */

#ifndef   __POKEMONISM_POKEMON_GENERIC_LAMBDA_CALLABLE_HH__
#define   __POKEMONISM_POKEMON_GENERIC_LAMBDA_CALLABLE_HH__

#include <pokemonism/pokemon/interface/callable.hh>
#include <pokemonism/pokemon/exception.hh>

namespace pokemonism {
    namespace pokemon {
        namespace generic {
            namespace lambda {

                template <typename returnable>
                class callable : public pokemon::interface::callable<returnable> {
                public:     typedef returnable (*type)(void);
                protected:  type func;
                public:     returnable operator()(void) override {
                                if (func == nullptr) throw pokemon::exception();
                                return func();
                            }
                public:     callable(type f) : func(f) {}
                public:     callable(void) : func(nullptr) {}
                public:     ~callable(void) override {}
                public:     callable(const callable & o) = delete;
                public:     callable(callable && o) noexcept = delete;
                public:     callable & operator=(const callable & o) = delete;
                public:     callable & operator=(callable && o) noexcept = delete;
                };

            }
        }
    }
}

#endif // __POKEMONISM_POKEMON_GENERIC_LAMBDA_CALLABLE_HH__