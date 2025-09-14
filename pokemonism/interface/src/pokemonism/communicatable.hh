/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 12, 2025
 */

#ifndef   __POKEMONISM_COMMUNICATABLE_HH__
#define   __POKEMONISM_COMMUNICATABLE_HH__

#include <pokemonism.hh>
#include <pokemonism/virtualable.hh>

namespace pokemonism {

    template <class super = virtualable>
    class communicatable : public super {
    public:     virtual int open(void) = 0;
    public:     virtual long read(void) = 0;
    public:     virtual long write(void) = 0;
    public:     virtual int close(void) = 0;
    public:     inline communicatable(void);
    public:     inline ~communicatable(void) override;
    public:     inline communicatable(const communicatable<super> & o);
    public:     inline communicatable(communicatable<super> && o) noexcept;
    public:     inline communicatable<super> & operator=(const communicatable<super> & o);
    public:     inline communicatable<super> & operator=(communicatable<super> && o) noexcept;
    };

    template <class super>
    inline communicatable<super>::communicatable(void) {

    }

    template <class super>
    inline communicatable<super>::~communicatable(void) {

    }

    template <class super>
    inline communicatable<super>::communicatable(const communicatable<super> & o) : super(o) {

    }

    template <class super>
    inline communicatable<super>::communicatable(communicatable<super> && o) noexcept : super(std::move(o)) {

    }

    template <class super>
    inline communicatable<super> & communicatable<super>::operator=(const communicatable<super> & o) {
        if (pointof(o) != this) super::operator=(o);

        return *this;
    }

    template <class super>
    inline communicatable<super> & communicatable<super>::operator=(communicatable<super> && o) noexcept {
        if (pointof(o) != this) super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_COMMUNICATABLE_HH__