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

#include <pokemonism.hh>
#include <pokemonism/virtualable.hh>

namespace pokemonism {

    template <class super = virtualable>
    class synchronizable : public super {
    public:     virtual int lock(void) = 0;
    public:     virtual int unlock(void) = 0;
    public:     virtual int wait(void) = 0;
    public:     virtual int wakeup(void) = 0;
    public:     virtual int wait(long second, long nano) = 0;
    public:     virtual int wakeup(bool all) = 0;
    public:     inline synchronizable(void);
    public:     inline ~synchronizable(void) override;
    public:     inline synchronizable(const synchronizable<super> & o);
    public:     inline synchronizable(synchronizable<super> && o) noexcept;
    public:     inline synchronizable<super> & operator=(const synchronizable<super> & o);
    public:     inline synchronizable<super> & operator=(synchronizable<super> && o) noexcept;
    };

    template<class super>
    inline synchronizable<super>::synchronizable(void) {

    }

    template<class super>
    inline synchronizable<super>::~synchronizable(void) {

    }

    template<class super>
    inline synchronizable<super>::synchronizable(const synchronizable<super> & o) : super(o) {

    }

    template<class super>
    inline synchronizable<super>::synchronizable(synchronizable<super> && o) noexcept : super(std::move(o)) {

    }

    template<class super>
    inline synchronizable<super> & synchronizable<super>::operator=(const synchronizable<super> & o) {
        if (pointof(o) != this) super::operator=(o);

        return *this;
    }

    template<class super>
    inline synchronizable<super> & synchronizable<super>::operator=(synchronizable<super> && o) noexcept {
        if (pointof(o) != this) super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_SYNCHRONIZABLE_HH__