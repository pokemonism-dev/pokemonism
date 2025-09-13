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

#include <pokemonism/virtualable.hh>

namespace pokemonism {

    namespace tag {
        struct DisposableTag {};
        struct NondisposableTag : public DisposableTag {};
    }

    template <class Element, typename Tag = tag::DisposableTag, class Super = Virtualable>
    class Observerable : public Super {
    public:     virtual void on(Element && item) = 0;
    public:     inline Observerable(void);
    public:     inline ~Observerable(void) override;
    public:     inline Observerable(const Observerable<Element, Tag, Super> & o);
    public:     inline Observerable(Observerable<Element, Tag, Super> && o) noexcept;
    public:     inline Observerable<Element, Tag, Super> & operator=(const Observerable<Element, Tag, Super> & o);
    public:     inline Observerable<Element, Tag, Super> & operator=(Observerable<Element, Tag, Super> && o) noexcept;
    };

    template <class Element, typename Tag, class Super>
    inline Observerable<Element, Tag, Super>::Observerable(void) {

    }

    template <class Element, typename Tag, class Super>
    inline Observerable<Element, Tag, Super>::~Observerable(void) {

    }

    template <class Element, typename Tag, class Super>
    inline Observerable<Element, Tag, Super>::Observerable(const Observerable<Element, Tag, Super> & o) : Super(o) {

    }

    template <class Element, typename Tag, class Super>
    inline Observerable<Element, Tag, Super>::Observerable(Observerable<Element, Tag, Super> && o) noexcept : Super(std::move(o)) {

    }

    template <class Element, typename Tag, class Super>
    inline Observerable<Element, Tag, Super> & Observerable<Element, Tag, Super>::operator=(const Observerable<Element, Tag, Super> & o) {
        if (pointof(o) != this) Super::operator=(o);

        return *this;
    }

    template <class Element, typename Tag, class Super>
    inline Observerable<Element, Tag, Super> & Observerable<Element, Tag, Super>::operator=(Observerable<Element, Tag, Super> && o) noexcept {
        if (pointof(o) != this) Super::operator=(std::move(o));

        return *this;
    }

    template <class Element, class Super>
    class Observerable<Element, tag::NondisposableTag, Super> : public Super {
    public:     virtual void on(const Element & item) = 0;
    public:     inline Observerable(void);
    public:     inline ~Observerable(void) override;
    public:     inline Observerable(const Observerable<Element, tag::NondisposableTag, Super> & o);
    public:     inline Observerable(Observerable<Element, tag::NondisposableTag, Super> && o) noexcept;
    public:     inline Observerable<Element, tag::NondisposableTag, Super> & operator=(const Observerable<Element, tag::NondisposableTag, Super> & o);
    public:     inline Observerable<Element, tag::NondisposableTag, Super> & operator=(Observerable<Element, tag::NondisposableTag, Super> && o) noexcept;
    };

    template <class Element, class Super>
    inline Observerable<Element, tag::NondisposableTag, Super>::Observerable(void) {

    }

    template <class Element, class Super>
    inline Observerable<Element, tag::NondisposableTag, Super>::~Observerable(void) {

    }

    template <class Element, class Super>
    inline Observerable<Element, tag::NondisposableTag, Super>::Observerable(const Observerable<Element, tag::NondisposableTag, Super> & o) : Super(o) {

    }

    template <class Element, class Super>
    inline Observerable<Element, tag::NondisposableTag, Super>::Observerable(Observerable<Element, tag::NondisposableTag, Super> && o) noexcept : Super(std::move(o)) {

    }

    template <class Element, class Super>
    inline Observerable<Element, tag::NondisposableTag, Super> & Observerable<Element, tag::NondisposableTag, Super>::operator=(const Observerable<Element, tag::NondisposableTag, Super> & o) {
        if (pointof(o) != this) Super::operator=(o);
        return *this;
    }

    template <class Element, class Super>
    inline Observerable<Element, tag::NondisposableTag, Super> & Observerable<Element, tag::NondisposableTag, Super>::operator=(Observerable<Element, tag::NondisposableTag, Super> && o) noexcept {
        if (pointof(o) != this) Super::operator=(std::move(o));
        return *this;
    }

}

#endif // __POKEMONISM_OBSERVERABLE_HH__