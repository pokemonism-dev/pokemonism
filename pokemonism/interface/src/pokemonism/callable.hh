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
    public:     Callable(const Callable<Output, Super> & o) = delete;
    public:     Callable(Callable<Output, Super> && o) noexcept = delete;
    public:     Callable<Output, Super> & operator=(const Callable<Output, Super> & o) = delete;
    public:     Callable<Output, Super> & operator=(Callable<Output, Super> && o) noexcept = delete;
    };

    template<class Output, class Super>
    inline Callable<Output, Super>::Callable(void) {

    }

    template<class Output, class Super>
    inline Callable<Output, Super>::~Callable(void) {

    }


}

#endif // __POKEMONISM_CALLABLE_HH__