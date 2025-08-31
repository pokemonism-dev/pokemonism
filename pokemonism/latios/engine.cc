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

        static wattrel::engine * internal = nullptr;

        void engine::on(wattrel::engine::bootstrapper bootstrap) {
            if (internal != nullptr) throw exception();

            internal = new wattrel::engine();

            internal->on(bootstrap);
        }

        void engine::off(wattrel::engine::terminator executor) {
            if (internal == nullptr) throw exception();

            internal->off(executor);
        }

        int engine::run(void) {
            if (internal == nullptr) throw exception();

            const int ret = internal->run();

            internal = allocator::del(internal);

            return ret;
        }

        engine::engine(void) {

        }

        engine::~engine(void) {

        }

        //
        // static wattrel::engine * internal = nullptr;
        //
        // void engine::on(bootstrapper bootstrap) {
        //     if (internal == nullptr) {
        //         internal = new wattrel::engine();
        //
        //         if (bootstrap != nullptr) bootstrap(*internal);
        //     }
        // }
        //
        // void engine::off(terminator executor) {
        //     if (singleton == nullptr) throw exception();
        //
        //     singleton->wattrel::engine::off(reinterpret_cast<wattrel::engine::terminator>(executor));
        // }
        //
        // int engine::run(void) {
        //     if (singleton == nullptr) throw exception();
        //
        //     return singleton->wattrel::engine::run();
        // }


        // public:     static void off(terminator executor);
        // public:     static int run(void);
        // protected:  engine(void);
        // protected:  ~engine(void) override;
    }
}