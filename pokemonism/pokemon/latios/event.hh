/**
 * @file        pokemon/latios/event.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 26, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_EVENT__HH__
#define   __POKEMONISM_POKEMON_LATIOS_EVENT__HH__

namespace pokemon { namespace latios {

    class event {
    public:     inline event(void) {}
    public:     inline virtual ~event(void) {}
    public:     event(const event & o) = delete;
    public:     event(event && o) noexcept = delete;
    public:     event & operator=(const event & o) = delete;
    public:     event & operator=(event && o) noexcept = delete;
    };

} }

#endif // __POKEMONISM_POKEMON_LATIOS_EVENT__HH__