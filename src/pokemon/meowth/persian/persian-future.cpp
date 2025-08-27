/**
 * @file        pokemon/meowth/meowth-future.cpp
 * @brief
 * @details
 *
 * @author      snorlax <devloper@snorlax.dev>
 * @since       Aug 24, 2025
 */

#include <variant>
#include <pokemon/future.hh>

using namespace pokemon;

int main(int argc, char ** argv) {

    future<int> o(future<int>::original::fail);

    printf("%s\n", o.done() ? "true" : "fail");
    printf("%s\n", o.rejected() ? "true" : "fail");

    exception_throw_check([&o]() { printf("%d\n", o.get()); });

    future<int> success(future<int>::response(10));

    printf("%s\n", success.done() ? "true" : "fail");
    printf("%s\n", success.rejected() ? "true" : "fail");

    printf("%d\n", success.get());

    printf("sizeof(o) => %ld\n", sizeof(o));
    printf("sizeof(success) => %ld\n", sizeof(success));
    printf("sizeof(future<int>::response) => %ld\n", sizeof(future<int>::response));

    printf("variant size => %ld\n", sizeof(std::variant<int, long, unsigned long, std::string>));

    return 0;
}