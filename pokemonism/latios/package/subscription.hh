// /**
//  * @file        pokemonism/latios/package/subscription.hh
//  * @brief
//  * @details
//  *
//  * @author      snorlax <snorlax@pokemonism.dev>
//  * @since       Aug 29, 2025
//  */
//
// #ifndef   __POKEMONISM_LATIOS_PACKAGE_SUBSCRIPTION__HH__
// #define   __POKEMONISM_LATIOS_PACKAGE_SUBSCRIPTION__HH__
//
// #include <pokemonism/latios/package/eventable.hh>
//
// namespace pokemonism {
//     namespace latios {
//         namespace package {
//
//             template <class object, class objectable, class generatable = void>
//             class subscription : public eventable<object, objectable, generatable>::subscription {
//             public:     inline const object * objectGet(void) const override { return this->target; }
//             public:     inline subscription(void) {}
//             public:     inline ~subscription(void) override {}
//             public:     subscription(const subscription<object, objectable, generatable> & o) = delete;
//             public:     subscription(subscription<object, objectable, generatable> && o) noexcept = delete;
//             public:     subscription<object, objectable, generatable> & operator=(const subscription<object, objectable, generatable> & o) = delete;
//             public:     subscription<object, objectable, generatable> & operator=(subscription<object, objectable, generatable> && o) noexcept = delete;
//             };
//
//         }
//     }
// }
//
// #endif // __POKEMONISM_LATIOS_PACKAGE_SUBSCRIPTION__HH__
