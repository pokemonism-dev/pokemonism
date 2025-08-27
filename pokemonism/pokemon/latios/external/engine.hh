/**
 * @file        pokemon/latios/external/engine.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_EXTERNAL_ENGINE__HH__
#define   __POKEMONISM_POKEMON_LATIOS_EXTERNAL_ENGINE__HH__

#include <pokemon/latios/command.hh>
#include <pokemon/latios/external/command/subscription.hh>

namespace pokemon { namespace latios { namespace external {

    class engine {
    public:     virtual const char * tag(void) const = 0;
    public:     virtual command::subscription * reg(latios::command * command, latios::command::event::handler (*on)[latios::command::event::max]) = 0;
    public:     virtual command::subscription * mod(latios::command * command, uint32 type, latios::command::event::handler on) = 0;
    public:     virtual void cancel(void (*func)(engine &)) = 0;
    public:     virtual engine & on(void) = 0;
    public:     virtual int run(void) = 0;
    protected:  engine(void) {}
    public:     virtual ~engine(void) {}
    public:     engine(engine & o) = delete;
    public:     engine(engine && o) noexcept = delete;
    public:     engine & operator=(engine & o) = delete;
    public:     engine & operator=(engine && o) noexcept = delete;
    };

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_EXTERNAL_ENGINE__HH__
