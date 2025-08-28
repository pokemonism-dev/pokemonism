//
// Created by snorlax on 25. 8. 25..
//

#include <cstdio>

#include <pokemonism.hh>

using namespace pokemon;

// 마스크에 따라서 다른 소멸자 호출

class base {
public:     inline int get(void) { return 0; }
};

class virtualable : public base {
public:     inline int get(void){ return 2; }
public:     virtualable(void){ printf("construct virtualable\n"); }
public:     virtual ~virtualable(void){ printf("destruct virtualable\n"); }
};

class nonvirtualable : public base {
public:     inline int get(void){ return 1; }
public:     nonvirtualable(void){ printf("construct nonvirtualable\n"); }
public:     ~nonvirtualable(void){ printf("destruct nonvirtualable\n"); }
};

namespace persianImpl {
    template <typename element>
    union variable {
    public:     virtualable ex1;
    public:     nonvirtualable ex2;
    public:     inline variable(void) { printf("construct\n"); }
    public:     inline ~variable(void) { printf("destruct\n"); }
    public:     inline explicit variable(virtualable && o) { ex1 = std::move(o); }
    public:     inline explicit variable(nonvirtualable && o) { ex2 = std::move(o); }
    public:     inline variable & operator=(virtualable && o) {
                    ex1 = std::move(o);
                    return *this;
                }
    };
}

using namespace persianImpl;

int main(int argc, char ** argv) {
    printf("sizeof(variable<int>) => %ld\n", sizeof(variable<int>));

    {
        printf("sizeof(variable<int>) => %ld\n", sizeof(variable<int>));
        variable<int> o;
    }

    {
        printf("sizeof(variable<int>) => %ld\n", sizeof(variable<int>));
        variable<int> o(std::move(virtualable()));
    }

    {
        printf("sizeof(variable<int>) => %ld\n", sizeof(variable<int>));
        variable<int> o(std::move(nonvirtualable()));
    }

    {
        printf("1. sizeof(variable<int>) => %ld\n", sizeof(variable<int>));
        variable<int> o(std::move(nonvirtualable()));

        printf("%d\n", o.ex1.get());
        printf("%d\n", o.ex2.get());

        o = std::move(virtualable());

    }

    {
        printf("sizeof(variable<int>) => %ld\n", sizeof(variable<int>));
        nonvirtualable v1 = nonvirtualable();
        virtualable v2 = virtualable();

        base & v = v1;

        printf("%d == %d\n", v.get(), v1.get());

        // variable<int> o(std::move(nonvirtualable()));
        //
        // printf("%d\n", o.ex1.get());
        // printf("%d\n", o.ex2.get());

        // o = std::move(virtualable());
    }

    return 0;
}