/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 11, 2025
 */

#ifndef   __POKEMONISM_RUNNABLE_HH__
#define   __POKEMONISM_RUNNABLE_HH__

#include <pokemonism/virtualable.hh>

namespace pokemonism {

    template <class Super = Virtualable>
    class Runnable : public Super {
    public:     virtual int run(void) = 0;
    public:     inline Runnable(void);
    public:     inline ~Runnable(void) override;
    public:     inline Runnable(const Runnable<Super> & o);
    public:     inline Runnable(Runnable<Super> && o) noexcept;
    public:     inline Runnable<Super> & operator=(const Runnable<Super> & o);
    public:     inline Runnable<Super> & operator=(Runnable<Super> && o) noexcept;
    };

    template<class Super>
    inline Runnable<Super>::Runnable(void) {

    }

    template<class Super>
    inline Runnable<Super>::~Runnable(void) {

    }

    template<class Super>
    inline Runnable<Super>::Runnable(const Runnable<Super> & o) : Super(o) {

    }

    template<class Super>
    inline Runnable<Super>::Runnable(Runnable<Super> && o) noexcept : Super(std::move(o)) {

    }

    template<class Super>
    inline Runnable<Super> & Runnable<Super>::operator=(const Runnable<Super> & o) {
        if (pointof(o) != this) Runnable<Super>::operator=(o);

        return *this;
    }

    template<class Super>
    inline Runnable<Super> & Runnable<Super>::operator=(Runnable<Super> && o) noexcept {
        if (pointof(o) != this) Runnable<Super>::operator=(std::move(o));

        return *this;
    }


}

#endif // __POKEMONISM_RUNNABLE_HH__