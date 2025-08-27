/**
 * @file        pokemon/latios/internal/command/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 26, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_EVENT__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_EVENT__HH__

#include <pokemonism.hh>

#include <pokemon/latios/event.hh>

#include <pokemon/latios/internal/event.hh>
#include <pokemon/latios/external/command/event.hh>

namespace pokemon { namespace latios { namespace internal { namespace command {

    class link;

    class event : public internal::event<link>, public external::command::event {
    /** CUSTOM CONSTRUCTOR */
    protected:  explicit event(uint32 type);
    /** DEFAULT CONSTRUCTOR & DESTRUCTOR */
    public:     event(void) = delete;
    protected:  ~event(void) override;
    public:     event(const event & o) = delete;
    public:     event(event && o) noexcept = delete;
    public:     event & operator=(const event & o) = delete;
    public:     event & operator=(event && o) noexcept = delete;
    };

} } } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_COMMAND_EVENT__HH__