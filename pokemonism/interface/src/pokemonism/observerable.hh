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
    public:     Observerable(const Observerable & o) = delete;
    public:     Observerable(Observerable && o) noexcept = delete;
    public:     Observerable & operator=(const Observerable & o) = delete;
    public:     Observerable & operator=(Observerable && o) noexcept = delete;
    };

    template <class Element, typename Tag, class Super>
    inline Observerable<Element, Tag, Super>::Observerable(void) {

    }

    template <class Element, typename Tag, class Super>
    inline Observerable<Element, Tag, Super>::~Observerable(void) {

    }

    template <class Element, class Super>
    class Observerable<Element, tag::DisposableTag, Super> : public Super {
    public:     virtual void on(const Element & item) = 0;
    public:     inline Observerable(void);
    public:     inline ~Observerable(void) override;
    public:     Observerable(const Observerable & o) = delete;
    public:     Observerable(Observerable && o) noexcept = delete;
    public:     Observerable & operator=(const Observerable & o) = delete;
    public:     Observerable & operator=(Observerable && o) noexcept = delete;
    };

    template <class Element, class Super>
    inline Observerable<Element, tag::DisposableTag, Super>::Observerable(void) {

    }

    template <class Element, class Super>
    inline Observerable<Element, tag::DisposableTag, Super>::~Observerable(void) {

    }

}

#endif // __POKEMONISM_OBSERVERABLE_HH__