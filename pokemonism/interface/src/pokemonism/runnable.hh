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
    public:     Runnable(void);
    public:     virtual ~Runnable(void) override;
    public:     Runnable(const Runnable<Super> & o) = delete;
    public:     Runnable(Runnable<Super> && o) noexcept = delete;
    public:     Runnable<Super> & operator=(const Runnable<Super> & o) = delete;
    public:     Runnable<Super> & operator=(Runnable<Super> && o) noexcept = delete;
    };

    template<class Super>
    Runnable<Super>::Runnable(void) {

    }

    template<class Super>
    Runnable<Super>::~Runnable(void) {

    }


}

#endif // __POKEMONISM_RUNNABLE_HH__