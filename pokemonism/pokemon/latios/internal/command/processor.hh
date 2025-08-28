/**
 * @file        pokemon/latios/internal/command/processor.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 28, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_PROCESSOR__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_PROCESSOR__HH__

#include <pokemon/latios/internal/command/event.hh>
#include <pokemon/latios/internal/command/subscription.hh>

namespace pokemon { namespace latios { namespace internal { namespace command {

    class processor {
    public:     static int execute(command::subscription * subscription, uint32 type, command::event * event);
    public:     processor(void) {}
    public:     inline virtual ~processor() {}
    public:     processor(const processor & o) = delete;
    public:     processor(processor && o) noexcept = delete;
    public:     processor & operator=(const processor & o) = delete;
    public:     processor & operator=(processor && o) noexcept = delete;
    };

} } } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_PROCESSOR__HH__
