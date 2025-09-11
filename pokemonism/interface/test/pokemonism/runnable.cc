/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 11, 2025
 */

#include <cstdio>

#include <pokemonism/runnable.hh>

class ExampleRunnable : public pokemonism::Runnable<> {
public:     int run(void) override {
                printf("Hello\n");
                return 0;
            }
};

int main(int argc, char ** argv) {
    ExampleRunnable o;
    return o.run();
}