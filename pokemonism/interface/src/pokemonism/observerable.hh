/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 11, 2025
 */

#ifndef   __POKEMONISM_OBSERVERABLE_HH__
#define   __POKEMONISM_OBSERVERABLE_HH__

#include <pokemonism.hh>
#include <pokemonism/virtualable.hh>

namespace pokemonism {

    // namespace tag {
    //     struct DisposableTag {};
    //     struct NondisposableTag : public DisposableTag {};
    // }

    template <class element, class super = virtualable, typename disposable = tag::nondisposable>
    class observerable : public super {
    public:     virtual void on(element && item) = 0;
    public:     inline observerable(void);
    public:     inline ~observerable(void) override;
    public:     inline observerable(const observerable<element, super, disposable> & o);
    public:     inline observerable(observerable<element, super, disposable> && o) noexcept;
    public:     inline observerable<element, super, disposable> & operator=(const observerable<element, super, disposable> & o);
    public:     inline observerable<element, super, disposable> & operator=(observerable<element, super, disposable> && o) noexcept;
    };

    template <class element, class super, typename disposable>
    inline observerable<element, super, disposable>::observerable(void) {

    }

    template <class element, class super, typename disposable>
    inline observerable<element, super, disposable>::~observerable(void) {

    }

    template <class element, class super, typename disposable>
    inline observerable<element, super, disposable>::observerable(const observerable<element, super, disposable> & o) : super(o) {

    }

    template <class element, class super, typename disposable>
    inline observerable<element, super, disposable>::observerable(observerable<element, super, disposable> && o) noexcept : super(std::move(o)) {

    }

    template <class element, class super, typename disposable>
    inline observerable<element, super, disposable> & observerable<element, super, disposable>::operator=(const observerable<element, super, disposable> & o) {
        if (pointof(o) != this) super::operator=(o);

        return *this;
    }

    template <class element, class super, typename disposable>
    inline observerable<element, super, disposable> & observerable<element, super, disposable>::operator=(observerable<element, super, disposable> && o) noexcept {
        if (pointof(o) != this) super::operator=(std::move(o));

        return *this;
    }

    template <class element, class super>
    class observerable<element, super, tag::nondisposable> : public super {
    public:     virtual void on(const element & item) = 0;
    public:     inline observerable(void);
    public:     inline ~observerable(void) override;
    public:     inline observerable(const observerable<element, super, tag::nondisposable> & o);
    public:     inline observerable(observerable<element, super, tag::nondisposable> && o) noexcept;
    public:     inline observerable<element, super, tag::nondisposable> & operator=(const observerable<element, super, tag::nondisposable> & o);
    public:     inline observerable<element, super, tag::nondisposable> & operator=(observerable<element, super, tag::nondisposable> && o) noexcept;
    };

    template <class element, class super>
    inline observerable<element, super, tag::nondisposable>::observerable(void) {

    }

    template <class element, class super>
    inline observerable<element, super, tag::nondisposable>::~observerable(void) {

    }

    template <class element, class super>
    inline observerable<element, super, tag::nondisposable>::observerable(const observerable<element, super, tag::nondisposable> & o) : super(o) {

    }

    template <class element, class super>
    inline observerable<element, super, tag::nondisposable>::observerable(observerable<element, super, tag::nondisposable> && o) noexcept : super(std::move(o)) {

    }

    template <class element, class super>
    inline observerable<element, super, tag::nondisposable> & observerable<element, super, tag::nondisposable>::operator=(const observerable<element, super, tag::nondisposable> & o) {
        if (pointof(o) != this) super::operator=(o);
        return *this;
    }

    template <class element, class super>
    inline observerable<element, super, tag::nondisposable> & observerable<element, super, tag::nondisposable>::operator=(observerable<element, super, tag::nondisposable> && o) noexcept {
        if (pointof(o) != this) super::operator=(std::move(o));
        return *this;
    }

}

#endif // __POKEMONISM_OBSERVERABLE_HH__