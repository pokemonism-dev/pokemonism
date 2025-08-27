/**
 * @file        pokemon/latios/internal/command/link.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_POKEMON_INTERNAL_COMMAND_LINK__HH__
#define   __POKEMONISM_POKEMON_INTERNAL_COMMAND_LINK__HH__

#include <pokemon/latios/internal/link.hh>

namespace pokemon { namespace latios { namespace internal { namespace command {

    class subscription;
    class event;

    class link : public internal::link<subscription, event> {
    /** CUSTOM OBJECT CONSTRUCTOR */
    public:     explicit link(subscription * container);
    /** DEFAULT OBJECT METHOD */
    public:     link(void) = delete;
    public:     ~link(void) override;
    public:     link(const link & o) = delete;
    public:     link(link && o) noexcept = delete;
    public:     link & operator=(const link & o) = delete;
    public:     link & operator=(link && o) noexcept = delete;
    };

} } } }

#endif // __POKEMONISM_POKEMON_INTERNAL_COMMAND_LINK__HH__