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

#include <pokemonism/virtualable.hh>

namespace pokemonism {

    template <class Super = Virtualable>
    class Communicatable : public Super {
    public:     virtual int open(void) = 0;
    public:     virtual long read(void) = 0;
    public:     virtual long write(void) = 0;
    public:     virtual int close(void) = 0;
    public:     inline Communicatable(void);
    public:     inline ~Communicatable(void) override;
    public:     inline Communicatable(const Communicatable<Super> & o);
    public:     inline Communicatable(Communicatable<Super> && o) noexcept;
    public:     inline Communicatable<Super> & operator=(const Communicatable<Super> & o);
    public:     inline Communicatable<Super> & operator=(Communicatable<Super> && o) noexcept;
    };

    template <class Super>
    inline Communicatable<Super>::Communicatable(void) {

    }

    template <class Super>
    inline Communicatable<Super>::~Communicatable(void) {

    }

    template <class Super>
    inline Communicatable<Super>::Communicatable(const Communicatable<Super> & o) : Super(o) {

    }

    template <class Super>
    inline Communicatable<Super>::Communicatable(Communicatable<Super> && o) noexcept : Super(std::move(o)) {

    }

    template <class Super>
    inline Communicatable<Super> & Communicatable<Super>::operator=(const Communicatable<Super> & o) {
        if (pointof(o) != this) Super::operator=(o);

        return *this;
    }

    template <class Super>
    inline Communicatable<Super> & Communicatable<Super>::operator=(Communicatable<Super> && o) noexcept {
        if (pointof(o) != this) Super::operator=(std::move(o));

        return *this;
    }

}

#endif // __POKEMONISM_COMMUNICATABLE_HH__