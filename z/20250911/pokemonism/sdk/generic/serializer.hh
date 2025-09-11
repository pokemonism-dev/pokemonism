/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_GENERIC_SERIALIZER_HH__
#define   __POKEMONISM_SDK_GENERIC_SERIALIZER_HH__

#include <pokemonism/sdk/context.hh>

namespace pokemonism::sdk::generic {

    template <class outputable = stream, class inputable = stream>
    class serializer {
    public:     virtual outputable * serialize(inputable * input, outputable * output = nullptr) = 0;
    public:     serializer(void) {}
    public:     virtual ~serializer(void) {}
    public:     serializer(const serializer & o) = delete;
    public:     serializer(serializer && o) noexcept = delete;
    public:     serializer & operator=(const serializer & o) = delete;
    public:     serializer & operator=(serializer && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_GENERIC_SERIALIZER_HH__