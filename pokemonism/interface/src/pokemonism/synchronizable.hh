/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 11, 2025
 */

#ifndef   __POKEMONISM_SYNCHRONIZABLE_HH__
#define   __POKEMONISM_SYNCHRONIZABLE_HH__

#include <pokemonism/virtualable.hh>

namespace pokemonism {

    template <class Super = Virtualable>
    class Synchronizable : public Super {
    public:     virtual int lock(void) = 0;
    public:     virtual int unlock(void) = 0;
    public:     virtual int wait(void) = 0;
    public:     virtual int wakeup(void) = 0;
    public:     virtual int wait(long second, long nano) = 0;
    public:     virtual int wakeup(bool all) = 0;
    public:     inline Synchronizable(void);
    public:     inline ~Synchronizable(void) override;
    public:     inline Synchronizable(const Synchronizable<Super> & o);
    public:     inline Synchronizable(Synchronizable<Super> && o);
    public:     inline Synchronizable<Super> & operator=(const Synchronizable<Super> & o);
    public:     inline Synchronizable<Super> & operator=(Synchronizable<Super> && o);
    };

    template<class Super>
    inline Synchronizable<Super>::Synchronizable(void) {

    }

    template<class Super>
    inline Synchronizable<Super>::~Synchronizable(void) {

    }

    template<class Super>
    inline Synchronizable<Super>::Synchronizable(const Synchronizable<Super> & o) : Super(o) {

    }

    template<class Super>
    inline Synchronizable<Super>::Synchronizable(Synchronizable<Super> && o) : Super(std::move(o)) {

    }

    template<class Super>
    inline Synchronizable<Super> & Synchronizable<Super>::operator=(const Synchronizable<Super> & o) {
        if (pointof(o) != this) Super::operator=(o);

        return *this;
    }

    template<class Super>
    inline Synchronizable<Super> & Synchronizable<Super>::operator=(Synchronizable<Super> && o) {
        if (pointof(o) != this) Super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_SYNCHRONIZABLE_HH__