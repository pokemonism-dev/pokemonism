/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           8월 31, 2025
 */


#include "engine.hh"

namespace pokemonism {

    namespace wattrel {

        static void t800(engine * o) {}
        static engine * o = nullptr;

        int engine::run(void) {
            if (o != nullptr) {
                while (o->cancel == nullptr) {

                }
                o->cancel(o);
                delete o;
            }
            return declaration::success;
        }

        engine & engine::on(bootstrapper bootstrap) {
            if (o == nullptr) {
                o = new engine();

                if (bootstrap) bootstrap(*o);
            }

            return *o;
        }

        void engine::off(engine::terminator executor) {
            if (o != nullptr) {
                if (o->cancel == nullptr && executor == nullptr) o->cancel = executor;

                o->cancel = t800;

            }
        }

        engine::engine(void) : cancel(nullptr) {

        }

        engine::~engine(void) {

        }

    }
}