/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           Sep 13, 2025
 */

#ifndef   __POKEMONISM_CONTAINABLE_HH__
#define   __POKEMONISM_CONTAINABLE_HH__

#include <pokemonism/virtualable.hh>

namespace pokemonism {

    class containable : public virtualable {
    public:     virtual void clear(void) = 0;
    public:     inline containable(void);
    public:     inline ~containable(void) override;
    public:     inline containable(const containable & o);
    public:     inline containable(containable && o) noexcept;
    public:     inline containable & operator=(const containable & o);
    public:     inline containable & operator=(containable && o) noexcept;
    };

    inline containable::containable(void) {

    }

    inline containable::~containable(void) {

    }

    inline containable::containable(const containable & o) {

    }

    inline containable::containable(containable && o) noexcept {

    }

    inline containable & containable::operator=(const containable & o) {
        return *this;
    }

    inline containable & containable::operator=(containable && o) noexcept {
        return *this;
    }


}

#endif // __POKEMONISM_CONTAINABLE_HH__