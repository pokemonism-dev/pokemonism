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

#include <pokemonism/virtualable.hh>
#include <pokemonism/primitivable.hh>

namespace pokemonism {

    template <class Output = Primitivable, class Super = Virtualable>
    class Callable : public Super {
    public:     virtual Output * call(void) = 0;
    public:     inline Callable(void);
    public:     inline ~Callable(void) override;
    public:     inline Callable(const Callable<Output, Super> & o);
    public:     inline Callable(Callable<Output, Super> && o) noexcept;
    public:     inline Callable<Output, Super> & operator=(const Callable<Output, Super> & o);
    public:     inline Callable<Output, Super> & operator=(Callable<Output, Super> && o) noexcept;
    };

    template<class Output, class Super>
    inline Callable<Output, Super>::Callable(void) {

    }

    template<class Output, class Super>
    inline Callable<Output, Super>::~Callable(void) {

    }

    template<class Output, class Super>
    inline Callable<Output, Super>::Callable(const Callable<Output, Super> & o) : Super(o) {

    }

    template<class Output, class Super>
    inline Callable<Output, Super>::Callable(Callable<Output, Super> && o) noexcept : Super(std::move(o)) {

    }

    template<class Output, class Super>
    inline Callable<Output, Super> & Callable<Output, Super>::operator=(const Callable<Output, Super> & o) {
        if (pointof(o) != this) Super::operator=(o);

        return *this;
    }

    template<class Output, class Super>
    inline Callable<Output, Super> & Callable<Output, Super>::operator=(Callable<Output, Super> && o) noexcept {
        if (pointof(o) != this) Super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_CALLABLE_HH__