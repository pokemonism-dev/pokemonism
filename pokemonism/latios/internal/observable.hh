// /**
//  * @file        pokemonism/latios/internal/observable.hh
//  * @brief
//  * @details
//  *
//  * @author      snorlax <snorlax@pokemonism.dev>
//  * @sicne       Aug 29, 2025
//  */
//
// #ifndef   __POKEMONISM_LATIOS_INTERNAL_OBSERVABLE__HH__
// #define   __POKEMONISM_LATIOS_INTERNAL_OBSERVABLE__HH__
//
// #include <pokemonism/mareep.hh>
//
// namespace pokemonism {
//     namespace latios {
//         namespace internal {
//             template <class element>
//             class observable : public pokemonism::observable<element>, public virtual object {
//             public:     mareep::subscription * subscribe(mareep::observer<element> * o) override { throw pokemonism::exception(); }
//             public:     mareep::subscription * subscribe(const mareep::observer<element> & o) override { throw pokemonism::exception(); }
//             public:     mareep::subscription * subscribe(const mareep::observer<element> && o) override { throw pokemonism::exception(); }
//             public:     observable(void) {}
//             public:     ~observable(void) override {}
//             public:     observable(const observable<element> & o) = delete;
//             public:     observable(observable<element> && o) noexcept = delete;
//             public:     observable<element> & operator=(const observable<element> & o) = delete;
//             public:     observable<element> & operator=(observable<element> && o) noexcept = delete;
//             };
//         }
//     }
// }
//
// #endif // __POKEMONISM_LATIOS_INTERNAL_OBSERVABLE__HH__