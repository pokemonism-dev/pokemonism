// /**
//  * @file
//  * @brief
//  * @details
//  *
//  * @author          snorlax <snorlax@pokemonism.dev>
//  * @since           8월 31, 2025
//  */
//
// #ifndef   __POKEMONISM_LATIOS_COMMAND_HH__
// #define   __POKEMONISM_LATIOS_COMMAND_HH__
//
// #include <pokemonism.hh>
//
// #include <pokemonism/wattrel/command.hh>
// #include <pokemonism/pokemon/generic/command.hh>
// #include <pokemonism/latios/subscription.hh>
//
// #include "pokemon/event.hh"
//
// namespace pokemonism {
//     namespace latios {
//
//         namespace command {
//             struct tag {};
//
//
//             template <class messageable = wattrel::command::envelope::message>
//             class envelope : public wattrel::command::envelope, public pokemon::generic::command<messageable>::envelope {
//             public:     typedef messageable             message;
//             public:     inline message * pop(void) override { return dynamic_cast<messageable *>(output); }
//             public:     inline envelope(void) {}
//             public:     inline explicit envelope(pokemon::exception * e) : wattrel::command::envelope(e) {}
//             public:     inline ~envelope(void) override {}
//             public:     envelope(const envelope & o) = delete;
//             public:     envelope(envelope && o) noexcept = delete;
//             public:     envelope & operator=(const envelope & o) = delete;
//             public:     envelope & operator=(envelope && o) noexcept = delete;
//             };
//         }
//
//         template <class objectable>
//         class subscription<objectable, typename objectable::output, pokemon::command::tag> : public virtual wattrel::subscription {
//         public:     constexpr static const char * name = "command";   // ### 20250901 | REMOVE THIS FOR DEBUG
//         public:     explicit subscription(uint32 properties) : wattrel::subscription(properties) {}
//         public:     subscription(void) = delete;
//         public:     ~subscription(void) override {}
//         public:     subscription(const subscription & o) = delete;
//         public:     subscription(subscription && o) noexcept = delete;
//         public:     subscription & operator=(const subscription & o) = delete;
//         public:     subscription & operator=(subscription && o) noexcept = delete;
//         };
//
//         namespace command {
//
//             template <typename objectable> class subscription;
//
//             class generator : public wattrel::command::generator {
//             public:     template <class outputable, class objectable = pokemon::generic::command<outputable>> latios::command::subscription<objectable> * reg(objectable * target, uint32 properties, objectable::callback::type * callbacks, uint32 n);
//             public:     inline explicit generator(wattrel::engine * engine) : wattrel::command::generator(engine) {}
//             public:     generator(void) = delete;
//             public:     inline ~generator(void) override {}
//             public:     generator(const generator & o) = delete;
//             public:     generator(generator && o) noexcept = delete;
//             public:     generator & operator=(const generator & o) = delete;
//             public:     generator & operator=(generator && o) noexcept = delete;
//             };
//
//             template <typename objectable>
//             class subscription : public latios::subscription<objectable>, public wattrel::command::subscription {
//             public:     constexpr static const char * name = "generic subscription";
//             public:     typedef objectable      command;
//             public:     inline command * objectGet(void) const override { return dynamic_cast<command *>(object); }
//             public:     inline explicit subscription(command * object, uint32 properties, const command::callback::type * callbacks, uint32 n) :
//                         latios::subscription<objectable>(properties),
//                         wattrel::command::subscription(object, reinterpret_cast<const wattrel::command::callback::type *>(callbacks), n),
//                         wattrel::subscription(properties) {
//
//                         }
//             public:     subscription(void) = delete;
//             public:     inline ~subscription(void) override {}
//             public:     subscription(const subscription & o) = delete;
//             public:     subscription(subscription && o) noexcept = delete;
//             public:     subscription & operator=(const subscription & o) = delete;
//             public:     subscription & operator=(subscription && o) noexcept = delete;
//             };
//         }
//
//     }
// }
//
// #endif // __POKEMONISM_LATIOS_COMMAND_HH__