/**
 * @file        pokemon/meowth/persian/latios-engine.cc
 * @brief
 * @details
 *
 * @author      snorlax <developer@snorlax.dev>
 * @since       Aug 27, 2025
 */

#include <pokemon/latios/engine.hh>

using namespace pokemon;

int main(int argc, char ** argv) {
    printf("%s\n", latios::engine::singleton.name());

    return 0;
}