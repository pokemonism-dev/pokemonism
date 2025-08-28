//
// Created by snorlax on 25. 8. 24..
//

#include <new>
#include <cstdio>
#include <cstddef>
#include <ctime>
#include <cstdlib>

class example {
public:    int value;
public:     example(void){ }
public:     virtual void rel(){ delete this; }
// public:     example(const example & o) { value = static_cast<int *>(malloc(100 * sizeof(int))); }
// public:     example & operator=(const example & o) { return *this; }
// public:     example & operator=(example && o) noexcept { return *this; }
// public:     example(example && o) noexcept : value(o.value) { o.value = nullptr; }
public:     virtual ~example(void) {  }
};

int main(int argc, char ** argv) {
    printf("%ld\n", sizeof(example));
    srand(time(nullptr));

    constexpr int64_t total = 1000000LU;

    example o;
    struct timespec start;
    clock_gettime(CLOCK_REALTIME, &start);
    struct timespec end;

    for (int64_t i = 1; i <= total; i = i + 1) {
         example * o2 = new example();

        (o2->value) = random();
        if ((i % 100000000) == 0) {
            clock_gettime(CLOCK_REALTIME, &end);
            printf("%ld %d\n", end.tv_sec - start.tv_sec, (o2->value));
        }
        o2->rel();
    }

    clock_gettime(CLOCK_REALTIME, &end);


    return 0;
}