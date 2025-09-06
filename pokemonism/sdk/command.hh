/**
 * @file            pokemonism/sdk/command.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */

#ifndef   __POKEMONISM_SDK_COMMAND_HH__
#define   __POKEMONISM_SDK_COMMAND_HH__

#include <pokemonism/sdk/callable.hh>

namespace pokemonism::sdk {

    class command : callable<primitivable> {
    public:     class event;
    public:     typedef primitivable output;
    public:     output * operator()(void) override = 0;
    public:     command(void);
    public:     ~command(void) override;
    public:     command(const command & o) = delete;
    public:     command(command && o) noexcept = delete;
    public:     command & operator=(const command & o) = delete;
    public:     command & operator=(command && o) noexcept = delete;
    };

}

// ReSharper disable CppUnusedIncludeDirective
#include <pokemonism/sdk/command/event.hh>
// ReSharper restore CppUnusedIncludeDirective

#endif // __POKEMONISM_SDK_COMMAND_HH__
