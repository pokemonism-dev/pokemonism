/**
 * @file        meowth/persian/persian-latios-engine.cc
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 28, 2025
 */

#include <pokemonism/latios.hh>

#include <pokemonism/latios/internal/command/node.hh>
#include <pokemonism/latios/internal/command/event.hh>
#include <pokemonism/latios/internal/command/generator.hh>
#include <pokemonism/latios/internal/command/subscription.hh>

using namespace pokemonism::latios::internal;

int main(int argc, char ** argv) {
    command::event event(1, nullptr);
    command::subscription subscription;
    command::node node;
    command::generator generator(nullptr);

    return pokemonism::engine::run();
}