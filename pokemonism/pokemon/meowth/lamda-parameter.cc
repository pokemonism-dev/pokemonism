/**
 * @file        pokemon/meowth/lamda-parameter.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#include <pokemon/meowth.hh>

using namespace pokemon::meowth;

#include <functional>

static void lambda(void (*func)(void));
static void lambda(const std::function<void ()> & func);
static void lambda(const functionObjectVoid & func);

class example {
};

int main(int argc, char ** argv) {
    functionObjectVoid func;

    lambda(functionVoid);
    lambda(func);
    lambda([&func]()-> void {});
    lambda(static_cast<void (*)(void)>([](void)-> void {}));

    return 0;
}

static void lambda(void (*func)(void)) {
    printf("1. function pointer\n");
    func();
}

static void lambda(const std::function<void ()> & func) {
    printf("2. std::function\n");
    func();
}

static void lambda(const functionObjectVoid & func) {
    printf("3. pokemon::function\n");
    func();
}

