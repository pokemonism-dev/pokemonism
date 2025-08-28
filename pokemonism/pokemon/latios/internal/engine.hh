/**
 * @file        pokemon/latios/internal/engine.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_ENGINE__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_ENGINE__HH__

#include <pokemon/latios/command.hh>
#include <pokemon/latios/external/engine.hh>

#include <pokemon/latios/internal/queue.hh>
#include <pokemon/latios/internal/command/subscription.hh>

namespace pokemon { namespace latios { namespace internal {

    namespace command {
        class generator;
    }

    class engine : public external::engine {
    /** PROTECTED MEMBER VARIABLE */
    protected:  queue * queue;
    protected:  struct {
                    command::generator * command;
                } generator;
    /** OVERRIDE METHOD IN EXTERNAL::ENGINE */
    public:     const char * tag(void) const override { return "internal"; }
    public:     external::command::subscription * reg(latios::command * command, latios::command::event::handler (*on)[latios::command::event::max]) override;
    public:     external::command::subscription * mod(latios::command * command, uint32 type, latios::command::event::handler on) override;
    public:     void cancel(void (*func)(external::engine &)) override;
    public:     engine & on(void) override;
    public:     int run(void) override;
    /** DEFAULT CLASS METHOD */
    public:     engine(void);
    public:     ~engine(void) override;
    public:     engine(engine & o) = delete;
    public:     engine(engine && o) noexcept = delete;
    public:     engine & operator=(engine & o) = delete;
    public:     engine & operator=(engine && o) noexcept = delete;
    };

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_ENGINE__HH__
