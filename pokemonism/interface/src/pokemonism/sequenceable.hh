/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_SEQUENCEABLE_HH__
#define   __POKEMONISM_SEQUENCEABLE_HH__

#include <pokemonism/containable.hh>

namespace pokemonism {

    template <class Elementable, class Super = Containable>
    class Sequenceable : public Super {
    public:     inline Sequenceable(void);
    public:     inline ~Sequenceable(void) override;
    public:     Sequenceable(const Sequenceable<Elementable, Super> & o) = delete;
    public:     Sequenceable(Sequenceable<Elementable, Super> && o) noexcept = delete;
    public:     Sequenceable<Elementable, Super> & operator=(const Sequenceable<Elementable, Super> & o) = delete;
    public:     Sequenceable<Elementable, Super> & operator=(Sequenceable<Elementable, Super> && o) noexcept = delete;
    };

    template <class Elementable, class Super>
    inline Sequenceable<Elementable, Super>::Sequenceable(void) {

    }

    template <class Elementable, class Super>
    inline Sequenceable<Elementable, Super>::~Sequenceable(void) {

    }

}

#endif // __POKEMONISM_SEQUENCEABLE_HH__