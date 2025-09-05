/**
 * @file            pokemonism/sdk/callbackable.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_SDK_CALLBACKABLE_HH__
#define   __POKEMONISM_SDK_CALLBACKABLE_HH__

namespace pokemonism::sdk {

    struct callbackable {
    public:     typedef void (*function)(void *);
    protected:  function func;
    public:     template <typename convertable> inline callbackable::function get(void) const { return reinterpret_cast<convertable>(func); }
    public:     inline callbackable(void) : func(nullptr) {}
    public:     inline explicit callbackable(callbackable::function f) : func(f) {}
    };

}

#endif // __POKEMONISM_SDK_CALLBACKABLE_HH__