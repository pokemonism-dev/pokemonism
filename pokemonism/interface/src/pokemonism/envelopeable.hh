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

#include <pokemonism.hh>
#include <pokemonism/primitivable.hh>

namespace pokemonism {

    template <class super>
    class envelopeable : public super {
    public:     virtual primitivable * messagePop(void) = 0;
    public:     inline envelopeable(void);
    public:     inline ~envelopeable(void) override;
    public:     inline envelopeable(const envelopeable<super> & o);
    public:     inline envelopeable(envelopeable<super> && o) noexcept;
    public:     inline envelopeable<super> & operator=(const envelopeable<super> & o);
    public:     inline envelopeable<super> & operator=(envelopeable<super> && o) noexcept;
    };

    template<class super>
    inline envelopeable<super>::envelopeable(void) {

    }

    template<class super>
    inline envelopeable<super>::~envelopeable(void) {

    }

    template<class super>
    inline envelopeable<super>::envelopeable(const envelopeable<super> & o) : super(o) {

    }

    template<class super>
    inline envelopeable<super>::envelopeable(envelopeable<super> && o) noexcept : super(std::move(o)) {

    }

    template<class super>
    inline envelopeable<super> & envelopeable<super>::operator=(const envelopeable<super> & o) {
        if (pointof(o) != this) super::operator=(o);

        return *this;
    }

    template<class super>
    inline envelopeable<super> & envelopeable<super>::operator=(envelopeable<super> && o) noexcept {
        if (pointof(o) != this) super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_ENVELOPEABLE_HH__