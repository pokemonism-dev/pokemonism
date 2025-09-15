/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 15, 2025
 */

#ifndef   __POKEMONISM_SDK_CONTINUOUS_HH__
#define   __POKEMONISM_SDK_CONTINUOUS_HH__

#include <pokemonism/collection/continuous.hh>

namespace pokemonism::sdk {
    template <typename elementable, class continuable = collection::continuous<elementable>>
    class continuous {
    public:     template <typename itemable> static bool scan(const continuable & o, const itemable & item, bool (*func)(const elementable &, const itemable &));
    public:     static bool scan(const continuable & o, const char * item, bool (*func)(const elementable &, const char *));
    public:     inline continuous(void);
    public:     inline virtual ~continuous(void);
    public:     continuous(const continuous<elementable, continuable> & o) = delete;
    public:     continuous(continuous<elementable, continuable> && o) noexcept = delete;
    public:     continuous<elementable, continuable> & operator=(const continuous<elementable, continuable> & o) = delete;
    public:     continuous<elementable, continuable> & operator=(continuous<elementable, continuable> && o) noexcept = delete;
    };

    template <typename elementable, class continuable>
    template <typename itemable>
    bool continuous<elementable, continuable>::scan(const continuable & o, const itemable & item, bool (*func)(const elementable &, const itemable &)) {
        for (unsigned long i = 0; i < o.sizeGet(); i = i + 1) {
            if (func(o[i], item)) return true;
        }
        return false;
    }

    template <typename elementable, class continuable>
    bool continuous<elementable, continuable>::scan(const continuable & o, const char * item, bool (*func)(const elementable &, const char *)) {
        for (unsigned long i = 0; i < o.sizeGet(); i = i + 1) {
            if (func(o[i], item)) return true;
        }
        return false;
    }

    template <typename elementable, class continuable>
    inline continuous<elementable, continuable>::continuous(void) {

    }

    template <typename elementable, class continuable>
    inline continuous<elementable, continuable>::~continuous(void) {

    }

}

#endif // __POKEMONISM_SDK_CONTINUOUS_HH__