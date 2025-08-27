//
// Created by snorlax on 25. 8. 25..
//

#include <cstdio>
#include <memory>

#include <pokemonism.hh>

#include <pokemon/exception.hh>
#include <pokemon/dynamical.hh>

using namespace pokemon;

namespace persianImpl {

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
        if (meta != nil) meta->increase();
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

#include <iostream>

namespace persianReferenceImpl1 { int check(); }
namespace persianReferenceImpl2 { int check(); }
namespace persianReferenceImpl3 { int check(); }
namespace persianReferenceImpl4 { int check(); }

int main(int argc, char ** argv) {
    persianReferenceImpl1::check();
    persianReferenceImpl3::check();
    persianReferenceImpl4::check();

    return 0;
}

namespace persianReferenceImpl1 {
    using namespace persianImpl;

    struct Foo
    {
        int id{0};
        Foo(int i = 0) : id{i} { std::cout << "Foo::Foo(" << i <<  ")\n"; }
        ~Foo() { std::cout << "Foo::~Foo(), id=" << id << '\n'; }
    };

    struct D
    {
        void operator()(Foo* p) const
        {
            std::cout << "Call delete from function object. Foo::id=" << p->id << '\n';
            delete p;
        }
    };

    int check()
    {
        {
            std::cout << "1) constructor with no managed object\n";
            persianImpl::reference<Foo> sh1;
        }

        {
            std::cout << "2) constructor with object\n";
            persianImpl::reference<Foo> sh2(new Foo{10});
            std::cout << "sh2.use_count(): " << sh2.count() << '\n';
            persianImpl::reference<Foo> sh3(sh2);
            std::cout << "sh2.use_count(): " << sh2.count() << '\n';
            std::cout << "sh3.use_count(): " << sh2.count() << '\n';
        }

        // {
        //
        //     std::cout << "3) constructor with object and deleter\n";
        //     std::shared_ptr<Foo> sh4(new Foo{11}, D());
        //     // std::shared_ptr<Foo> sh4(new Foo{11}, D());
        //     std::shared_ptr<Foo> sh5(new Foo{12}, [](auto p)
        //     {
        //         std::cout << "Call delete from lambda... p->id=" << p->id << '\n';
        //         delete p;
        //     });
        // }

        return 0;
    }
}

namespace persianReferenceImpl2 {
    // struct S
    // {
    //     S() { std::cout << "S::S()\n"; }
    //     ~S() { std::cout << "S::~S()\n"; }
    //     struct Deleter
    //     {
    //         void operator()(S* s) const
    //         {
    //             std::cout << "S::Deleter()\n";
    //             delete s;
    //         }
    //     };
    // };
    //
    // int check()
    // {
    //     auto sp = std::shared_ptr<S>{new S, S::Deleter{}};
    //
    //     auto use_count = [&sp](char c)
    //     {
    //         std::cout << c << ") use_count(): " << sp.use_count() << '\n';
    //     };
    //
    //     use_count('A');
    //     {
    //         auto sp2 = sp;
    //         use_count('B');
    //         {
    //             auto sp3 = sp;
    //             use_count('C');
    //         }
    //         use_count('D');
    //     }
    //     use_count('E');
    //
    //     //  sp.reset();
    //     //  use_count('F'); // would print "F) use_count(): 0"
    // }
}

#include <iostream>
#include <memory>
#include <string_view>

namespace persianReferenceImpl3 {
    using namespace persianImpl;

    int check()
    {
        auto output = [](std::string_view msg, int const* pInt)
        {
            std::cout << msg << *pInt << " in " << pInt << '\n';
        };

        int* pInt = new int(42);
        reference<int> pShared = reference<int>(new int(42));

        output("Naked pointer: ", pInt);
        //  output("Shared pointer: ", pShared); // compiler error
        output("Shared pointer: ", &*pShared); // OK, calls operator*, then takes addr
        output("Shared pointer with get(): ", pShared.get());

        delete pInt;

        std::cout << "\nThe shared_ptr's aliasing constructor demo.\n";
        struct Base1 { int i1{}; };
        struct Base2 { int i2{}; };
        struct Derived : Base1, Base2 { int i3{}; };

        reference<Derived> p(new Derived());
        // reference<Base2> q(p, static_cast<Base2*>(p.get()));
        // std::cout << "q shares ownership with p, but points to Base2 subobject:\n"
        //           << "p.get(): " << p.get() << '\n'
        //           << "q.get(): " << q.get() << '\n'
        //           << "&(p->i1): " << &(p->i1) << '\n'
        //           << "&(p->i2): " << &(p->i2) << '\n'
        //           << "&(p->i3): " << &(p->i3) << '\n'
        //           << "&(q->i2): " << &(q->i2) << '\n';
        return 0;
    }
}

namespace persianReferenceImpl4 {
    using namespace persianImpl;

    void fun(reference<int> sp)
    {
        std::cout << "in fun(): sp.use_count() == " << sp.count()
                  << " (object @ " << *sp << ")\n";
    }

    int check()
    {
        auto sp1 = reference<int>(new int(5));
        std::cout << "in main(): sp1.use_count() == " << sp1.count()
                  << " (object @ " << *sp1 << ")\n";

        fun(sp1);
        return 0;
    }
}