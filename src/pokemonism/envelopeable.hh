/**
 * @file            pokemonism/envelopeable.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 4, 2025
 */

#ifndef   __POKEMONISM_ENVELOPEABLE_HH__
#define   __POKEMONISM_ENVELOPEABLE_HH__

#include <pokemonism/primitivable.hh>

namespace pokemonism {

    class envelopeable {
    public:     typedef primitivable message;
    public:     virtual primitivable * messagePop(void) = 0;
    public:     envelopeable(void) {}
    public:     virtual ~envelopeable(void) {}
    public:     envelopeable(const envelopeable & o) = delete;
    public:     envelopeable(envelopeable && o) noexcept = delete;
    public:     envelopeable & operator=(const envelopeable & o) = delete;
    public:     envelopeable & operator=(envelopeable && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_ENVELOPEABLE_HH__