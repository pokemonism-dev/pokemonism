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

    class engine : public external::engine, public virtual pokemon::object {
    /** PROTECTED MEMBER VARIABLE */
    protected:  queue * queue;
    protected:  void (*cancel)(external::engine &);
    protected:  struct {
                    command::generator * command;
                } generator;
    public:     virtual void dispatch(internal::event * o);
    /** OVERRIDE METHOD IN EXTERNAL::ENGINE */
    public:     const char * tag(void) const override;
    public:     external::command::subscription * reg(latios::command * command, uint32 properties, latios::command::event::listener (*on)[latios::command::event::max]) override;
    public:     void off(void (*func)(external::engine &)) override;
    public:     external::engine & on(void) override;
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
