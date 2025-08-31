/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */


#include "engine.hh"

#include <pokemonism/pokemon/exception.hh>

namespace pokemonism {
    namespace latios {

        latios::engine * latios::engine::singleton = nullptr;

        pokemon::interface::terminatable<1, latios::engine *> latios::engine::T;

        pokemon::interface::terminator<latios::engine *> terminator;

        void engine::t1000(latios::engine * o) {}

        void engine::on(latios::engine::bootstrapper bootstrap, wattrel::engine::bootstrapper wattrel) {
            T.func[0] = engine::t1000;
            T.basic = engine::t1000;
            if (singleton != nullptr) throw exception();

            singleton = new latios::engine();

            if (bootstrap != nullptr) bootstrap(*singleton);

            if (singleton->queue == nullptr) singleton->queue = new wattrel::queue();
            if (singleton->generator.command == nullptr) singleton->generator.command = new latios::command::generator(singleton);


            singleton->wattrel::engine::on(wattrel);
        }

        void engine::off(latios::engine::cancellation t1000, wattrel::engine::cancellation t800) {
            if (singleton == nullptr) throw exception();

            if (latios::terminator == nullptr && t1000 == nullptr) {
                latios::terminator = T-1000;
            } else if (latios::terminator == nullptr) {
                latios::terminator = t1000;
            }

            if (singleton->terminator == nullptr && t800 == nullptr) {
                singleton->terminator = wattrel::engine::T-800;
            } else if (singleton->terminator == nullptr) {
                singleton->terminator = t800;
            }
        }

        void engine::off(pokemon::interface::terminator<latios::engine *> t1000, pokemon::interface::terminator<wattrel::engine *> t800) {
            if (singleton == nullptr) throw exception();

            if (latios::terminator == nullptr && t1000 == nullptr) {
                latios::terminator = T-1000;
            } else if (latios::terminator == nullptr) {
                latios::terminator = t1000;
            }

            if (singleton->terminator == nullptr && t800 == nullptr) {
                singleton->terminator = wattrel::engine::T-800;
            } else if (singleton->terminator == nullptr) {
                singleton->terminator = t800;
            }
        }

        int engine::run(int n) {
            if (singleton == nullptr) throw exception();

            const int ret = singleton->wattrel::engine::run();

            if (latios::terminator != nullptr) latios::terminator.terminate(singleton);

            delete singleton;
            singleton = nullptr;

            return ret;
        }

        engine::engine(void) {

        }

        engine::~engine(void) {

        }

    }
}