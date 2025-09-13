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
    public:     Streamable(const Streamable<Elementable, Super> & o) = delete;
    public:     Streamable(Streamable<Elementable, Super> && o) noexcept = delete;
    public:     Streamable<Elementable, Super> & operator=(const Streamable<Elementable, Super> & o) = delete;
    public:     Streamable<Elementable, Super> & operator=(Streamable<Elementable, Super> && o) noexcept = delete;
    };

    template <class Elementable, class Super>
    inline Streamable<Elementable, Super>::Streamable(void) {

    }

    template <class Elementable, class Super>
    inline Streamable<Elementable, Super>::~Streamable(void) {

    }

}

#endif // __POKEMONISM_STREAMABLE_HH__