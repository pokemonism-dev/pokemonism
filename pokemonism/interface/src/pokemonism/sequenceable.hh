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
    public:     inline Sequenceable(const Sequenceable<Elementable, Super> & o);
    public:     inline Sequenceable(Sequenceable<Elementable, Super> && o) noexcept;
    public:     inline Sequenceable<Elementable, Super> & operator=(const Sequenceable<Elementable, Super> & o);
    public:     inline Sequenceable<Elementable, Super> & operator=(Sequenceable<Elementable, Super> && o) noexcept;
    };

    template <class Elementable, class Super>
    inline Sequenceable<Elementable, Super>::Sequenceable(void) {

    }

    template <class Elementable, class Super>
    inline Sequenceable<Elementable, Super>::~Sequenceable(void) {

    }

    template <class Elementable, class Super>
    inline Sequenceable<Elementable, Super>::Sequenceable(const Sequenceable<Elementable, Super> & o) : Super(o) {

    }

    template <class Elementable, class Super>
    inline Sequenceable<Elementable, Super>::Sequenceable(Sequenceable<Elementable, Super> && o) noexcept : Super(std::move(o)) {

    }

    template <class Elementable, class Super>
    inline Sequenceable<Elementable, Super> & Sequenceable<Elementable, Super>::operator=(const Sequenceable<Elementable, Super> & o) {
        if (pointof(o) != this) Super::operator=(o);

        return *this;
    }

    template <class Elementable, class Super>
    inline Sequenceable<Elementable, Super> & Sequenceable<Elementable, Super>::operator=(Sequenceable<Elementable, Super> && o) noexcept {
        if (pointof(o) != this) Super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_SEQUENCEABLE_HH__