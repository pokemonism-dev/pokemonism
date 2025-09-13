/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_APPLICATIONABLE_HH__
#define   __POKEMONISM_APPLICATIONABLE_HH__

#include <pokemonism/virtualable.hh>
#include <pokemonism/runnable.hh>

namespace pokemonism {

    template <class Super = Virtualable>
    class Applicationable : public Runnable<Super> {
    public:     Applicationable(void);
    public:     ~Applicationable(void) override;
    public:     Applicationable(const Applicationable<Super> & o) = delete;
    public:     Applicationable(Applicationable<Super> && o) noexcept = delete;
    public:     Applicationable<Super> & operator=(const Applicationable<Super> & o) = delete;
    public:     Applicationable<Super> & operator=(Applicationable<Super> && o) noexcept = delete;
    };

    template <class Super>
    Applicationable<Super>::Applicationable(void) {

    }

    template <class Super>
    Applicationable<Super>::~Applicationable(void) {

    }

    /**
     * WindowApp
     * ConsoleApp
     */

}

#endif // __POKEMONISM_APPLICATIONABLE_HH__