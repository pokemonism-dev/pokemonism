// /**
//  * @file
//  * @brief
//  * @details
//  *
//  * @author          snorlax <snorlax@pokemonism.dev>
//  * @since           9월 01, 2025
//  */
//
// #ifndef   __POKEMONISM_LATIOS_SUBSCRIPTION_HH__
// #define   __POKEMONISM_LATIOS_SUBSCRIPTION_HH__
//
// #include <pokemonism/ralts/kirlia/subscription.hh>
//
// namespace pokemonism {
//     namespace latios {
//
//         template <typename objectable>
//         class subscription : public kirlia::subscription {
//
//         public:     subscription(void) {}
//         public:     ~subscription(void) override {}
//         public:     subscription(const latios::subscription<objectable> & o) = delete;
//         public:     subscription(latios::subscription<objectable> && o) noexcept = delete;
//         public:     latios::subscription<objectable> & operator=(const latios::subscription<objectable> & o) = delete;
//         public:     latios::subscription<objectable> & operator=(latios::subscription<objectable> && o) noexcept = delete;
//         };
//     }
// }
//
// #endif // __POKEMONISM_LATIOS_SUBSCRIPTION_HH__