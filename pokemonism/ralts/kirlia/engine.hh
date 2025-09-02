// /**
//  * @file            pokemonism/ralts/kirlia/engine.hh
//  * @brief
//  * @details
//  *
//  * @author          snorlax <snorlax@pokemonism.dev>
//  * @since           9월 02, 2025
//  */
//
// #ifndef   __POKEMONISM_KIRLIA_ENGINE_HH__
// #define   __POKEMONISM_KIRLIA_ENGINE_HH__
//
// #include <pokemonism/pokemon/command.hh>
//
// namespace pokemonism {
//     namespace kirlia {
//
//         namespace command {
//             class subscription;
//         }
//
//         class engine {
//         public:     static kirlia::command::subscription * reg(pokemon::command * target, uint32 properties, const pokemon::command::callback::set & callback);
//         protected:  engine(void);
//         protected:  virtual ~engine(void);
//         public:     engine(const kirlia::engine & o) = delete;
//         public:     engine(kirlia::engine && o) noexcept = delete;
//         public:     kirlia::engine & operator=(const kirlia::engine & o) = delete;
//         public:     kirlia::engine & operator=(kirlia::engine && o) noexcept = delete;
//         };
//
//     }
// }
//
// #endif // __POKEMONISM_KIRLIA_ENGINE_HH__