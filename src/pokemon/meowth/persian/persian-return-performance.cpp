//
// Created by snorlax on 25. 8. 24..
//

#include <cstdio>
#include <cstddef>
#include <ctime>
#include <cstdlib>

class example {
public:     int * value;
public:     example() : value(nullptr) { value = static_cast<int *>(malloc(sizeof(int))); }
public:     ~example(void) { free(value); }
};


int main(int argc, char ** argv) {
    printf("%ld\n", sizeof(example));
    srand(time(nullptr));

    example o;
    struct timespec start;
    clock_gettime(CLOCK_REALTIME, &start);
    struct timespec end;

    for (int64_t i = 1; i <= 10000000000LU; i = i + 1) {
        example o2;
        *(o2.value) = random();
        if ((i % 1000000000) == 0) {
            clock_gettime(CLOCK_REALTIME, &end);
            printf("%ld %d\n", end.tv_sec - start.tv_sec, *(o2.value));
        }
    }

    clock_gettime(CLOCK_REALTIME, &end);


    return 0;
}