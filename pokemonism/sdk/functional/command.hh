/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 07, 2025
 */

#ifndef   __POKEMONISM_SDK_FUNCTIONAL_COMMAND_HH__
#define   __POKEMONISM_SDK_FUNCTIONAL_COMMAND_HH__

#include <pokemonism/sdk/command.hh>

namespace pokemonism::sdk::functional {

    class command : public pokemonism::sdk::command {
    public:     primitivable * (*func)(void);
    public:     output * operator()(void) override { return func(); }
    public:     explicit command(primitivable * (*func)(void)) : func(func) {
                    pokemon_develop_check(func == nullptr, return);
                }
    public:     command(void) = delete;
    public:     ~command(void) override {}
    public:     command(const command & o) = delete;
    public:     command(command && o) noexcept = delete;
    public:     command & operator=(const command & o) = delete;
    public:     command & operator=(command && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_FUNCTIONAL_COMMAND_HH__