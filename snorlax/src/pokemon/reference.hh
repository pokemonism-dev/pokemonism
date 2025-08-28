/**
 * @file        pokemon/reference.hh
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#ifndef   __POKEMONISM_POKEMON_REFERENCE__HH__
#define   __POKEMONISM_POKEMON_REFERENCE__HH__

#include <pokemonism.hh>

#include <pokemon/exception.hh>
#include <pokemon/dynamical.hh>

namespace pokemon {
        struct referenceable {
        enum state {
            normal,
            changed,
            abnormal
        };
        /**
         * weak ptr 이어야 할 때 혹은 싱글톤이어야 할때도 도작하도록 가상으로 구현한다.
         *
         * ### 20250825 | UPGRADE | OWNERSHIP
         * ### 20250825 | UPGRADE | ATOMIC INTEGER
         * ### 20250825 | UPGRADE | STATE CHANGED PROCESS | 상태가 변경되어서 더 이상 접근할 수 있지 않다면, 예외를 출력할 수 있도록 하자.
         */
        template <typename element_type>
        // ReSharper disable once CppClassCanBeFinal
        class metadata {
        public:     typedef element_type        declaration_type;
        protected:  declaration_type * origin;
        protected:  int64 count;
        public:     inline virtual declaration_type & at(declaration::type::pointer::distance index) const;
        public:     inline virtual int64 increase(void);
        public:     inline virtual int64 decrease(void);
        public:     inline virtual int64 usage(void);
        public:     inline virtual referenceable::state state(void) { return normal; }
        public:     inline explicit metadata(declaration_type * origin);
        public:     inline metadata(void) = delete;
        public:     inline virtual ~metadata(void);
        public:     inline metadata(const metadata<declaration_type> & o) = delete;
        public:     inline metadata(metadata<declaration_type> && o) noexcept = delete;
        public:     inline metadata<declaration_type> & operator=(const metadata<declaration_type> & o) = delete;
        public:     inline metadata<declaration_type> & operator=(metadata<declaration_type> && o) noexcept = delete;
        };
    };

    template <typename declaration_type>
    int64 referenceable::metadata<declaration_type>::increase(void) {
        count = count + 1;
        return count;
    }

    template <typename declaration_type>
    int64 referenceable::metadata<declaration_type>::decrease(void) {
        count = count - 1;
        return count;
    }

    template <typename declaration_type>
    int64 referenceable::metadata<declaration_type>::usage(void) {
        return count;
    }

    template <typename declaration_type>
    referenceable::metadata<declaration_type>::metadata(declaration_type * origin) : origin(origin), count(0) {
        if (origin != nil) count = 1;

        critical_quick_throw_check(origin == nil, exceptional::invalid::implementation, count = 0);
    }

    template <typename declaration_type>
    referenceable::metadata<declaration_type>::~metadata(void) {
        origin = dynamical::rel(origin);

        // critical_quick_throw_check(count != 0, exceptional::invalid::implementation, (void)(0));
    }

    template <typename declaration_type>
    declaration_type & referenceable::metadata<declaration_type>::at(declaration::type::pointer::distance index) const {
        critical_quick_throw_check(origin == nil || count == 0, exceptional::invalid::implementation, (void)(0));

        return origin[index];
    }

    template <typename element_type>
    struct reference final {
    public:     typedef element_type                            declaration_type;
    private:    declaration_type *                              v;
    private:    referenceable::metadata<declaration_type> *     meta;
    public:     inline declaration_type * get(void) noexcept;
    public:     inline const declaration_type * get(void) const noexcept;
    public:     inline int64 count(void) const;
    private:    inline void release(void);
    // public:     inline reference(declaration_type * origin, referenceable::metadata<declaration_type> * meta); // ### 20250825 | UPGRADE | 상속하여 특수하게 사용할 수 있는 레퍼런스 클래스를 사용할 수 있도록 하자.
    public:     inline explicit reference(declaration_type * origin);
    public:     inline reference(void);
    public:     inline ~reference(void);
    public:     inline reference(const reference<declaration_type> & o);
    public:     inline reference(reference<declaration_type> && o) noexcept;
    public:     inline reference<declaration_type> & operator=(const reference<declaration_type> & o);
    public:     inline reference<declaration_type> & operator=(reference<declaration_type> && o) noexcept;
    public:     inline declaration_type & operator*(void) const;
    public:     inline declaration_type * operator->(void) const noexcept;
    public:     inline declaration_type & operator[](declaration::type::pointer::distance index) const;
    public:     inline explicit operator bool(void) const noexcept;
    };

    template <typename left_declaration_type, typename right_declaration_type>
    inline bool operator==(const reference<left_declaration_type> & left, const reference<right_declaration_type> & right) noexcept {
        return left.get() == right.get();
    }

    template <typename declaration_type>
    inline bool operator==(const reference<declaration_type>& left, declaration::type::null right) noexcept {
        return left.get() == nil;
    }

    template <typename declaration_type>
    inline bool operator==(declaration::type::null left, const reference<declaration_type>& right) noexcept {
        return right.get() == nil;
    }

    template<typename declaration_type>
    reference<declaration_type>::reference(declaration_type * origin) : v(origin), meta(nil) {
        if (origin != nil) meta = new referenceable::metadata<declaration_type>(origin);
    }

    template<typename declaration_type>
    reference<declaration_type>::reference(void) : v(nil), meta(nil) {}

    template<typename declaration_type>
    reference<declaration_type>::~reference(void) {
        release();
    }

    template<typename declaration_type>
    reference<declaration_type>::reference(const reference<declaration_type> & o) : v(o.v), meta(o.meta) {
        if (o.meta != nil) meta->increase();
    }

    template<typename declaration_type>
    reference<declaration_type>::reference(reference<declaration_type> && o) noexcept : v(o.v), meta(o.meta) {}

    template<typename declaration_type>
    reference<declaration_type> & reference<declaration_type>::operator=(const reference<declaration_type> & o) {
        if (pointof(o) != this) {
            release();
            v = o.v;
            meta = o.meta;
            if (meta != nil) meta->increase();
        }
        return *this;
    }

    template<typename declaration_type>
    reference<declaration_type> & reference<declaration_type>::operator=(reference<declaration_type> && o) noexcept {
        if (pointof(o) != this) {
            release();
            v = o.v;
            meta = o.meta;
            o.v = nil;
            o.meta = nil;
        }
        return *this;
    }

    template<typename declaration_type>
    declaration_type & reference<declaration_type>::operator*(void) const {
        critical_quick_throw_check(v == nil, exceptional::nullpointer, exit(0));

        return  *v;
    }

    template<typename declaration_type>
    declaration_type * reference<declaration_type>::operator->(void) const noexcept {
        return v;
    }

    template<typename declaration_type>
    declaration_type & reference<declaration_type>::operator[](declaration::type::pointer::distance index) const {
        critical_quick_throw_check(v == nil, exceptional::nullpointer, exit(0));

        return  v[index];
    }

    template<typename declaration_type>
    reference<declaration_type>::operator bool(void) const noexcept {
        return v != nil;
    }

    template<typename declaration_type>
    int64 reference<declaration_type>::count(void) const {
        return meta == nil ? 0 : meta->usage();
    }

    template<typename declaration_type>
    void reference<declaration_type>::release(void) {
        v = nil;
        if (meta != nil && meta->decrease() == 0) delete meta;
    }

    template<typename declaration_type>
    declaration_type * reference<declaration_type>::get(void) noexcept {
        return v;
    }

    template<typename declaration_type>
    const declaration_type * reference<declaration_type>::get(void) const noexcept {
        return v;
    }
}

#endif // __POKEMONISM_POKEMON_REFERENCE__HH__