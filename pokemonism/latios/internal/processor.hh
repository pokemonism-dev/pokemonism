// /**
//  * @file        pokemonism/latios/internal/processor.hh
//  * @brief
//  * @details
//  *
//  * @author      snorlax <snorlax@pokemonism.dev>
//  * @since       Aug 29, 2025
//  */
//
// #ifndef   __POKEMONISM_LATIOS_INTERNAL_PROCESSOR__HH__
// #define   __POKEMONISM_LATIOS_INTERNAL_PROCESSOR__HH__
//
// #include <pokemonism/latios/external/event.hh>
// #include <pokemonism/latios/external/subscription.hh>
//
// namespace pokemonism {
//     namespace latios {
//         namespace internal {
//             class processor {
//             public:     static int on(pokemonism::subscription * subscription, uint32 type, pokemonism::event * event) { return declaration::success; }
//             public:     processor(void) {}
//             public:     virtual ~processor(void) {}
//             public:     processor(const processor & o) = delete;
//             public:     processor(processor && o) noexcept = delete;
//             public:     processor & operator=(const processor & o) = delete;
//             public:     processor & operator=(processor && o) noexcept = delete;
//             };
//         }
//     }
// }
//
// #endif // __POKEMONISM_LATIOS_INTERNAL_PROCESSOR__HH__
