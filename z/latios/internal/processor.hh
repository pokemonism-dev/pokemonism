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
// #include <pokemonism/latios/internal/event.hh>
//
// namespace pokemonism {
//     namespace latios {
//         namespace internal {
//
//             template <class objectable, class generatable>
//             class processor : protected general::processor {
//             public:     typedef objectable      target;
//             public:     typedef generatable     generator;
//             public:     static int on(target::subscription * subscription, uint32 type, internal::event<objectable, generator> * event) { return declaration::success; }
//             public:     processor(void) {}
//             public:     ~processor(void) override {}
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
