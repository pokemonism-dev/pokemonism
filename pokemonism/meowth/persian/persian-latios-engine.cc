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

#include <pokemonism/latios/internal/process/event.hh>
#include <pokemonism/latios/internal/descriptor/event.hh>
#include <pokemonism/latios/internal/socket/event.hh>

using namespace pokemonism::latios::internal;

int main(int argc, char ** argv) {
    {
        try {
            command::event event(1, nullptr);
            command::subscription subscription;
            command::node node;
            command::generator generator(nullptr);
        } catch (...) {

        }

        printf("%u\n", command::event::max);
    }


    {
        try {
            process::event event(1, nullptr);
        } catch (...) {

        }

        printf("%u\n", process::event::max);
    }

    {
        try {
            socket::event event(1, nullptr);
        } catch (...) {

        }
        printf("%u\n", socket::event::max);
    }

    {
        try {
            descriptor::event event(1, nullptr);
        } catch (...) {

        }
        printf("%u\n", descriptor::event::max);
    }

    return pokemonism::engine::run();
}