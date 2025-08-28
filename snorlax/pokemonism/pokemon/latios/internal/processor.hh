/**
 * @file        pokemon/latios/internal/processor.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 28, 2025
 */

#ifndef   __POKEMONISM_POKEMON_LATIOS_INTERNAL_PROCESSOR__HH__
#define   __POKEMONISM_POKEMON_LATIOS_INTERNAL_PROCESSOR__HH__

namespace pokemon { namespace latios { namespace internal {

    class processor {
    public:     processor(void) {}
    public:     virtual ~processor(void) {}
    public:     processor(const processor & o) = delete;
    public:     processor(processor && o) = delete;
    public:     processor & operator=(const processor & o) = delete;
    public:     processor & operator=(processor && o) = delete;
    };

} } }

#endif // __POKEMONISM_POKEMON_LATIOS_INTERNAL_PROCESSOR__HH__