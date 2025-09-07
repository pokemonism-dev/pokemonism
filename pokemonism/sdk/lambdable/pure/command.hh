/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 07, 2025
 */

#ifndef   __POKEMONISM_SDK_LAMBDABLE_PURE_COMMAND_HH__
#define   __POKEMONISM_SDK_LAMBDABLE_PURE_COMMAND_HH__

#include <pokemonism/sdk/generic/command.hh>

namespace pokemonism::sdk::pure::lambdable {

    template <typename outputable = primitivable>
    class command : public generic::command<outputable> {
    protected:  outputable * (*func)(void);
    public:     outputable * operator()(void) override { return func(); }
    public:     explicit command(outputable * (*func)(void)) : func(func) { pokemon_develop_check(func == nullptr, return); }
    public:     command(void) = delete;
    public:     ~command(void) override { func =  nullptr; }
    public:     command(const command<outputable> & o) = delete;
    public:     command(command<outputable> && o) noexcept = delete;
    public:     command<outputable> & operator=(const command<outputable> & o) = delete;
    public:     command<outputable> & operator=(command<outputable> && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_LAMBDABLE_PURE_COMMAND_HH__