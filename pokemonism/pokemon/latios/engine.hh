/**
 * @file        pokemon/latios/engine.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_ENGINE__HH__
#define   __POKEMONISM_POKEMON_LATIOS_ENGINE__HH__

#include <pokemon/latios/command.hh>
#include <pokemon/latios/external/command/subscription.hh>

namespace pokemon { namespace latios {

    namespace external {
        class engine;
    }

    class engine {
    public:     static const char * tag(void);
    public:     static external::command::subscription * reg(command * command,uint32 properties, command::event::listener (*on)[command::event::max]);
    public:     static external::engine & on(void (*bootstrap)(external::engine &));
    public:     static void off(void (*func)(external::engine &));
    public:     static int run(void);
    protected:  engine(void) {}
    public:     virtual ~engine(void) {}
    public:     engine(engine & o) = delete;
    public:     engine(engine && o) noexcept = delete;
    public:     engine & operator=(engine & o) = delete;
    public:     engine & operator=(engine && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_LATIOS_ENGINE__HH__
