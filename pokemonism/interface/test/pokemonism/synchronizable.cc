/**
* @file
 * @brief
 * @details
 *
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 11, 2025
 */

#include <cstdio>

#include <pokemonism/synchronizable.hh>
#include <pokemonism/runnable.hh>

class ExampleSynchronizable : public pokemonism::Synchronizable<> {
public:     int lock(void) override { return -1; }
public:     int unlock(void) override { return -1; }
public:     int wait(void) override { return -1; }
public:     int wakeup(void) override { return -1; }
public:     int wait(long second, long nano) override { return -1; }
public:     int wakeup(bool all) override { return -1; }
};

class ExampleSynchronizableRunnable : public pokemonism::Synchronizable<pokemonism::Runnable<>> {
public:     int lock(void) override { return -1; }
public:     int unlock(void) override { return -1; }
public:     int wait(void) override { return -1; }
public:     int wakeup(void) override { return -1; }
public:     int wait(long second, long nano) override { return -1; }
public:     int wakeup(bool all) override { return -1; }
public:     int run(void) override {
                printf("hello\n");
                return 0;
            }
};

int main(int argc, char ** argv) {
    ExampleSynchronizable o;
    return 0;
}