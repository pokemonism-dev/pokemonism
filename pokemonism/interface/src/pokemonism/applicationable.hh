/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 13, 2025
 */

#ifndef   __POKEMONISM_APPLICATIONABLE_HH__
#define   __POKEMONISM_APPLICATIONABLE_HH__

#include <pokemonism/virtualable.hh>
#include <pokemonism/runnable.hh>

namespace pokemonism {

    class applicationable : public runnable<virtualable> {
    protected:  static applicationable * singleton;
    public:     virtual const char * platformNameGet(void) const noexcept = 0;
    protected:  int run(void) override = 0;
    public:     inline applicationable(void);
    public:     inline ~applicationable(void) override;
    public:     inline applicationable(const applicationable & o);
    public:     inline applicationable(applicationable && o) noexcept;
    public:     inline applicationable & operator=(const applicationable & o);
    public:     inline applicationable & operator=(applicationable && o) noexcept;
    };

    applicationable::applicationable(void) {

    }

    applicationable::~applicationable(void) {

    }

    inline applicationable::applicationable(const applicationable & o) : runnable<virtualable>(o) {

    }

    inline applicationable::applicationable(applicationable && o) noexcept : runnable<virtualable>(std::move(o)) {

    }

    inline applicationable & applicationable::operator=(const applicationable & o) {
        if (pointof(o) != this) runnable<virtualable>::operator=(o);
        return *this;
    }

    inline applicationable & applicationable::operator=(applicationable && o) noexcept {
        if (pointof(o) != this) runnable<virtualable>::operator=(std::move(o));
        return *this;
    }

}

#endif // __POKEMONISM_APPLICATIONABLE_HH__