/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 01, 2025
 */

#ifndef   __POKEMONISM_POKEMON_GENERIC_LAMBDA_FUNCTION_HH__
#define   __POKEMONISM_POKEMON_GENERIC_LAMBDA_FUNCTION_HH__

#include <pokemonism/pokemon/generic/function.hh>
#include <pokemonism/pokemon/exception.hh>

namespace pokemonism {
    namespace pokemon {
        namespace generic {
            namespace lambda {

                template <typename returnable, typename... argumentable>
                class function : public pokemon::generic::function<returnable, argumentable...> {
                public:     typedef pokemon::generic::function<returnable, argumentable...>::type type;
                protected:  type func;
                public:     returnable & operator()(argumentable... args) const override {
                                if (func == nullptr) throw pokemon::exception();
                                return func(args...);
                            }
                public:     explicit function(type f) : func(f) {}
                public:     function(void) : func(nullptr) {}
                public:     ~function(void) override {}
                public:     function(const function & o) = delete;
                public:     function(function && o) noexcept = delete;
                public:     function & operator=(const function & o) = delete;
                public:     function & operator=(function && o) noexcept = delete;
                };

            }
        }
    }
}

#endif // __POKEMONISM_POKEMON_GENERIC_LAMBDA_FUNCTION_HH__