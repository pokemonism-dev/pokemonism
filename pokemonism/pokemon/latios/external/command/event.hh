/**
 * @file        pokemon/latios/external/command/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 26, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_EXTERNAL_COMMAND_EVENT__HH__
#define   __POKEMONISM_POKEMON_LATIOS_EXTERNAL_COMMAND_EVENT__HH__

#include <pokemonism.hh>

#include <pokemon/latios/event.hh>

namespace pokemon { namespace latios { namespace external { namespace command {

    class event : public virtual latios::event {
    /** CUSTOM CONSTRUCTOR */
    // ReSharper disable once CppParameterMayBeConst
    protected:  inline explicit event(uint32 type) : latios::event(type) {}
    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    protected:  inline event(void) {}
    protected:  inline ~event(void) override {}
    public:     event(const event & o) = delete;
    public:     event(event && o) noexcept = delete;
    public:     event & operator=(const event & o) = delete;
    public:     event & operator=(event && o) noexcept = delete;
    };

} } } }

#endif // __POKEMONISM_POKEMON_LATIOS_EXTERNAL_COMMAND_EVENT__HH__