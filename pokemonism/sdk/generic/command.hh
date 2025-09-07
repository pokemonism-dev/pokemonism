/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 07, 2025
 */

#ifndef   __POKEMONISM_SDK_GENERIC_COMMAND_HH__
#define   __POKEMONISM_SDK_GENERIC_COMMAND_HH__

#include <pokemonism/sdk/command.hh>

namespace pokemonism::sdk::generic {

    template <typename outputable = primitivable>
    class command : public pokemonism::sdk::command {
    public:     typedef outputable output;
    public:     output * operator()(void) override = 0;
    public:     command(void) {}
    public:     ~command(void) override {}
    public:     command(const command & o) = delete;
    public:     command(command && o) noexcept = delete;
    public:     command & operator=(const command & o) = delete;
    public:     command & operator=(command && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_GENERIC_COMMAND_HH__