/**
 * @file        pokemon/meowth/variant.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 25, 2025
 */

#include <pokemon/meowth.hh>

#include <variant>

namespace pokemon { namespace meowth {

} }

int main(int argc, char ** argv) {

    printf("sizeof(variant<char, int, short, long, double>) => %ld\n", sizeof(std::variant<char, int, short, long, double>));

    return 0;
}