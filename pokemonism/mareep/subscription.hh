// /**
//  * @file
//  * @brief
//  * @details
//  *
//  * @author          snorlax <snorlax@pokemonism.dev>
//  * @since           8월 31, 2025
//  */
//
// #ifndef   __POKEMONISM_MAREEP_SUBSCRIPTION_HH__
// #define   __POKEMONISM_MAREEP_SUBSCRIPTION_HH__
//
// #include <pokemonism.hh>
//
// namespace pokemonism {
//     namespace mareep {
//         class subscription {
//         public:     virtual bool cancel(void) = 0;
//         public:     subscription(void) {}
//         public:     virtual ~subscription(void) {}
//         public:     subscription(const subscription & o) = delete;
//         public:     subscription(subscription && o) = delete;
//         public:     subscription & operator=(const subscription & o) = delete;
//         public:     subscription & operator=(subscription && o) = delete;
//         };
//     }
//
//     namespace pokemon {
//         using subscription = mareep::subscription;
//     }
// }
//
// #endif // __POKEMONISM_MAREEP_SUBSCRIPTION_HH__