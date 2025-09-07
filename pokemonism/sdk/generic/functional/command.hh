/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 07, 2025
 */

#ifndef   __POKEMONISM_SDK_GENERIC_FUNCTIONAL_COMMAND_HH__
#define   __POKEMONISM_SDK_GENERIC_FUNCTIONAL_COMMAND_HH__

#include <pokemonism/sdk/generic/command.hh>

namespace pokemonism::sdk::generic::functional {

    template <typename outputable = primitivable>
    class command : public pokemonism::sdk::generic::command<outputable> {
    public:     typedef outputable output;
    public:     outputable * (*func)(void);
    public:     output * operator()(void) override { return func(); }
    public:     explicit command(outputable * (*func)(void)) : func(func) { pokemon_develop_check(func == nullptr, return); }
    public:     command(void) = delete;
    public:     ~command(void) override { func = nullptr; }
    public:     command(const command & o) = delete;
    public:     command(command && o) noexcept = delete;
    public:     command & operator=(const command & o) = delete;
    public:     command & operator=(command && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_GENERIC_FUNCTIONAL_COMMAND_HH__