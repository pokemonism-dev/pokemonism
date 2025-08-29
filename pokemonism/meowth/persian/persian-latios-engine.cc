/**
 * @file        meowth/persian/persian-latios-engine.cc
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 28, 2025
 */

#include <pokemonism/latios.hh>

#include <pokemonism/latios/internal/command/event.hh>

using namespace pokemonism::latios::internal;

int main(int argc, char ** argv) {
    command::event o(1, nullptr);

    return pokemonism::engine::run();
}