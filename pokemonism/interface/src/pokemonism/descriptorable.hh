/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 20, 2025
 */

#ifndef   __POKEMONISM_DESCRIPTORABLE_HH__
#define   __POKEMONISM_DESCRIPTORABLE_HH__

#include <pokemonism.hh>
#include <pokemonism/virtualable.hh>

namespace pokemonism {

    template <class super = virtualable>
    class descriptorable : public super {
    protected:  constexpr static int invalid = -1;
    public:     virtual int open(void) = 0;
    public:     virtual int close(void) = 0;
    public:     virtual int read(void) = 0;
    public:     virtual int write(void) = 0;
    public:     virtual bool alive(void) = 0;
    public:     descriptorable(void) {}
    public:     ~descriptorable(void) override {}
    public:     descriptorable(const descriptorable<super> & o) : super(o) {}
    public:     descriptorable(descriptorable<super> && o) noexcept : super(std::move(o))  {}
    public:     descriptorable<super> & operator=(const descriptorable<super> & o) {
                    super::operator=(o);
                    return *this;
                }
    public:     descriptorable<super> & operator=(descriptorable<super> && o) noexcept {
                    super::operator=(std::move(o));
                    return *this;
                }
    };

}

#endif // __POKEMONISM_DESCRIPTORABLE_HH__