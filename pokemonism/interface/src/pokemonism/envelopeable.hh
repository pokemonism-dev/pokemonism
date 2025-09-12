/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_ENVELOPEABLE_HH__
#define   __POKEMONISM_ENVELOPEABLE_HH__

#include <pokemonism/virtualable.hh>
#include <pokemonism/primitivable.hh>

namespace pokemonism {

    template <class Super>
    class Envelopeable : public Super {
    public:     virtual Primitivable * messagePop(void) = 0;
    public:     inline Envelopeable(void);
    public:     inline~Envelopeable(void) override;
    public:     Envelopeable(const Envelopeable<Super> & o) = delete;
    public:     Envelopeable(Envelopeable<Super> && o) noexcept = delete;
    public:     Envelopeable<Super> & operator=(const Envelopeable<Super> & o) = delete;
    public:     Envelopeable<Super> & operator=(Envelopeable<Super> && o) noexcept = delete;
    };

    template<class Super>
    inline Envelopeable<Super>::Envelopeable(void) {

    }

    template<class Super>
    inline Envelopeable<Super>::~Envelopeable(void) {

    }

}

#endif // __POKEMONISM_ENVELOPEABLE_HH__