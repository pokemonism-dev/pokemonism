/**
 * @file            pokemonism/envelopeable.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 4, 2025
 */

#ifndef   __POKEMONISM_SDK_ENVELOPEABLE_HH__
#define   __POKEMONISM_SDK_ENVELOPEABLE_HH__

#include <pokemonism/sdk/primitivable.hh>

namespace pokemonism::sdk {

    class envelopeable {
    public:     using message = primitivable;
    public:     virtual message * messagePop(void) = 0;
    public:     envelopeable(void) {}
    public:     virtual ~envelopeable(void) {}
    public:     envelopeable(const envelopeable & o) = delete;
    public:     envelopeable(envelopeable && o) noexcept = delete;
    public:     envelopeable & operator=(const envelopeable & o) = delete;
    public:     envelopeable & operator=(envelopeable && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_ENVELOPEABLE_HH__