/**
 * @file        pokemon/meowth/primitivable-object.cc
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.ev>
 * @since       Aug 27, 2025
 */

#include <pokemon/primitivable.hh>

using namespace pokemon;

int main(int argc, char ** argv) {
    primitivable::object * o = primitivable::object::gen(1);

    printf("%p\n", o);

    return 0;
}