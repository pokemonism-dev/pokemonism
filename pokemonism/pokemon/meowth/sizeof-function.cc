/**
 * @file        pokemon/meowth/sizeof-function.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#include <pokemon/meowth.hh>

#include <functional>

int main(int argc, char ** argv) {
    printf("sizeof(std::function<void (void)>) => %ld\n", sizeof(std::function<void (void)>));
    std::function<void (void)> o;
    return 0;
}
