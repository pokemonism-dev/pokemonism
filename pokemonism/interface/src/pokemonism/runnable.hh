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

#include <pokemonism.hh>

#include <pokemonism/virtualable.hh>

namespace pokemonism {

    template <class super = virtualable>
    class runnable : public super {
    public:     virtual int run(void) = 0;
    public:     inline runnable(void);
    public:     inline ~runnable(void) override;
    public:     inline runnable(const runnable<super> & o);
    public:     inline runnable(runnable<super> && o) noexcept;
    public:     inline runnable<super> & operator=(const runnable<super> & o);
    public:     inline runnable<super> & operator=(runnable<super> && o) noexcept;
    };

    template<class super>
    inline runnable<super>::runnable(void) {

    }

    template<class super>
    inline runnable<super>::~runnable(void) {

    }

    template<class super>
    inline runnable<super>::runnable(const runnable<super> & o) : super(o) {

    }

    template<class super>
    inline runnable<super>::runnable(runnable<super> && o) noexcept : super(std::move(o)) {

    }

    template<class super>
    inline runnable<super> & runnable<super>::operator=(const runnable<super> & o) {
        if (pointof(o) != this) runnable<super>::operator=(o);

        return *this;
    }

    template<class super>
    inline runnable<super> & runnable<super>::operator=(runnable<super> && o) noexcept {
        if (pointof(o) != this) runnable<super>::operator=(std::move(o));

        return *this;
    }


}

#endif // __POKEMONISM_RUNNABLE_HH__