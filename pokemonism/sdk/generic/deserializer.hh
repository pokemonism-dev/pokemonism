/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_GENERIC_DESERIALIZER_HH__
#define   __POKEMONISM_SDK_GENERIC_DESERIALIZER_HH__

#include <pokemonism/sdk/context.hh>

namespace pokemonism::sdk::generic {

    template <class outputable = context, class inputable = stream>
    class deserializer {
    public:     virtual outputable * deserialize(inputable * input, outputable * output = nullptr) = 0;
    public:     deserializer(void) {}
    public:     virtual ~deserializer(void) {}
    public:     deserializer(const deserializer & o) = delete;
    public:     deserializer(deserializer && o) noexcept = delete;
    public:     deserializer & operator=(const deserializer & o) = delete;
    public:     deserializer & operator=(deserializer && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_GENERIC_DESERIALIZER_HH__