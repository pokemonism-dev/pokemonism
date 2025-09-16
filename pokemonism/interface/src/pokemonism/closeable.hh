/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 16, 2025
 */

#ifndef   __POKEMONISM_CLOSEABLE_HH__
#define   __POKEMONISM_CLOSEABLE_HH__

#include <pokemonism/virtualable.hh>

namespace pokemonism {

    template <class super = virtualable>
    class closeable : public super {
    public:     virtual int close(void) = 0;
    public:     closeable(void);
    public:     ~closeable(void) override;
    public:     closeable(const closeable<super> & o);
    public:     closeable(closeable<super> && o) noexcept;
    public:     closeable<super> & operator=(const closeable<super> & o);
    public:     closeable<super> & operator=(closeable<super> && o) noexcept;
    };

    template <class super>
    closeable<super>::closeable(void) {

    }

    template <class super>
    closeable<super>::~closeable(void) {

    }

    template <class super>
    closeable<super>::closeable(const closeable<super> & o) {

    }

    template <class super>
    closeable<super>::closeable(closeable<super> && o) noexcept {

    }

    template <class super>
    closeable<super> & closeable<super>::operator=(const closeable<super> & o) {
        return *this;
    }

    template <class super>
    closeable<super> & closeable<super>::operator=(closeable<super> && o) noexcept {
        return *this;
    }

}

#endif // __POKEMONISM_CLOSEABLE_HH__