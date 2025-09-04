/**
 * @file            pokemonism/callbackable.hh
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 04, 2025
 */

#ifndef   __POKEMONISM_CALLBACKABLE_HH__
#define   __POKEMONISM_CALLBACKABLE_HH__

namespace pokemonism {

    struct callbackable {
    public:     typedef void (*type)(void *);
    protected:  type func;
    public:     template <typename convertable> inline callbackable::type get(void) const { return reinterpret_cast<convertable>(func); }
    public:     inline callbackable(void) : func(nullptr) {}
    public:     inline explicit callbackable(callbackable::type f) : func(f) {}
    };

}

#endif // __POKEMONISM_CALLBACKABLE_HH__