/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_CONTINUABLE_HH__
#define   __POKEMONISM_CONTINUABLE_HH__

#include <pokemonism/virtualable.hh>

namespace pokemonism {

    template <class Elementable, class Super = Virtualable>
    class Continuable : public Super {
    public:     inline Continuable(void);
    public:     inline ~Continuable(void) override;
    public:     Continuable(const Continuable<Elementable, Super> & o) = delete;
    public:     Continuable(Continuable<Elementable, Super> && o) noexcept = delete;
    public:     Continuable<Elementable, Super> & operator=(const Continuable<Elementable, Super> & o) = delete;
    public:     Continuable<Elementable, Super> & operator=(Continuable<Elementable, Super> && o) noexcept = delete;
    };

    template <class Elementable, class Super>
    inline Continuable<Elementable, Super>::Continuable(void) {

    }

    template <class Elementable, class Super>
    inline Continuable<Elementable, Super>::~Continuable(void) {

    }

}

#endif // __POKEMONISM_CONTINUABLE_HH__