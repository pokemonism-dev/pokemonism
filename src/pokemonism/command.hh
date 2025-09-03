/**
 * @file            pokemonism/command.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 03, 2025
 */

#ifndef   __POKEMONISM_COMMAND_HH__
#define   __POKEMONISM_COMMAND_HH__

#include <pokemonism/interface/primitivable.hh>
#include <pokemonism/interface/callable.hh>

#include <pokemonism/event.hh>
#include <pokemonism/envelope.hh>
#include <pokemonism/exception.hh>
#include <pokemonism/subscription.hh>

namespace pokemonism {

    class command : public callable<primitivable> {
    public:     command(void) {}
    public:     ~command(void) override {}
    public:     command(const command & o) = delete;
    public:     command(command && o) noexcept = delete;
    public:     command & operator=(const command & o) = delete;
    public:     command & operator=(command && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_COMMAND_HH__