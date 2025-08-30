/**
 * @file        latios/engine.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 28, 2025
 */

#ifndef   __POKEMONISM_LATIOS_ENGINE__HH__
#define   __POKEMONISM_LATIOS_ENGINE__HH__


#include <pokemonism/latios/external/engine.hh>

namespace pokemonism {
    namespace latios {


        // subscription, ... subscription, envelope, object, envelope ...

        class engine : public object {
        // public:     static external::engine * singleton;
        // public:     static int on(void (*bootstrap)(pokemonism::latios::external::engine &));
        // public:     static int run(void);
        public:     template <class output = primitivable::object> static
                    subscription<pokemon::general::command<output>, envelope<output, message<output>>> * reg(pokemon::general::command<output> * command, uint32 properties, const command::callback<output>::type *, uint32 n);
        public:     engine(void);
        public:     ~engine(void) override;
        public:     engine(const engine & o) = delete;
        public:     engine(engine && o) noexcept = delete;
        public:     engine & operator=(const engine & o) = delete;
        public:     engine & operator=(engine && o) noexcept = delete;
        };

        template <class output>
        subscription<pokemon::general::command<output>, envelope<output, message<output>>> * engine::reg(pokemon::general::command<output> * command, uint32 properties, const command::callback<output>::type * callbacks, uint32 n) {
            subscription<pokemon::general::command<output>, envelope<output, message<output>>> * subscription =

                singleton->reg(command, properties, callbacks, n);
        }


    }

    using engine = latios::engine;

}

#endif // __POKEMONISM_LATIOS_ENGINE__HH__