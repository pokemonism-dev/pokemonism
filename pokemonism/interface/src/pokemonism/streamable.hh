/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_STREAMABLE_HH__
#define   __POKEMONISM_STREAMABLE_HH__

#include <pokemonism/containable.hh>

namespace pokemonism {

    template <class Elementable, class Super = Containable>
    class Streamable : public Super {
    public:     inline Streamable(void);
    public:     inline ~Streamable(void) override;
    public:     inline Streamable(const Streamable<Elementable, Super> & o);
    public:     inline Streamable(Streamable<Elementable, Super> && o) noexcept;
    public:     inline Streamable<Elementable, Super> & operator=(const Streamable<Elementable, Super> & o);
    public:     inline Streamable<Elementable, Super> & operator=(Streamable<Elementable, Super> && o) noexcept;
    };

    template <class Elementable, class Super>
    inline Streamable<Elementable, Super>::Streamable(void) {

    }

    template <class Elementable, class Super>
    inline Streamable<Elementable, Super>::~Streamable(void) {

    }

    template <class Elementable, class Super>
    inline Streamable<Elementable, Super>::Streamable(const Streamable<Elementable, Super> & o) : Super(o) {

    }

    template <class Elementable, class Super>
    inline Streamable<Elementable, Super>::Streamable(Streamable<Elementable, Super> && o) noexcept : Super(std::move(o)) {

    }

    template <class Elementable, class Super>
    inline Streamable<Elementable, Super> & Streamable<Elementable, Super>::operator=(const Streamable<Elementable, Super> & o) {
        if (pointof(o) != this) Super::operator=(o);

        return *this;
    }

    template <class Elementable, class Super>
    inline Streamable<Elementable, Super> & Streamable<Elementable, Super>::operator=(Streamable<Elementable, Super> && o) noexcept {
        if (pointof(o) != this) Super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_STREAMABLE_HH__