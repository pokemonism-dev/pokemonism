/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_CALLABLE_HH__
#define   __POKEMONISM_CALLABLE_HH__

#include <pokemonism.hh>

#include <pokemonism/virtualable.hh>
#include <pokemonism/primitivable.hh>

namespace pokemonism {

    template <class outputable = primitivable, class super = virtualable>
    class callable : public super {
    public:     typedef outputable  output;
    public:     virtual output * call(void) = 0;
    public:     inline callable(void);
    public:     inline ~callable(void) override;
    public:     inline callable(const callable<outputable, super> & o);
    public:     inline callable(callable<outputable, super> && o) noexcept;
    public:     inline callable<outputable, super> & operator=(const callable<outputable, super> & o);
    public:     inline callable<outputable, super> & operator=(callable<outputable, super> && o) noexcept;
    };

    template<class outputable, class super>
    inline callable<outputable, super>::callable(void) {

    }

    template<class outputable, class super>
    inline callable<outputable, super>::~callable(void) {

    }

    template<class outputable, class super>
    inline callable<outputable, super>::callable(const callable<outputable, super> & o) : super(o) {

    }

    template<class outputable, class super>
    inline callable<outputable, super>::callable(callable<outputable, super> && o) noexcept : super(std::move(o)) {

    }

    template<class outputable, class super>
    inline callable<outputable, super> & callable<outputable, super>::operator=(const callable<outputable, super> & o) {
        if (pointof(o) != this) super::operator=(o);

        return *this;
    }

    template<class outputable, class super>
    inline callable<outputable, super> & callable<outputable, super>::operator=(callable<outputable, super> && o) noexcept {
        if (pointof(o) != this) super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_CALLABLE_HH__