// /**
//  * @file
//  * @brief
//  * @details
//  *
//  * @author          snorlax <snorlax@pokemonism.dev>
//  * @since           8월 31, 2025
//  */
//
// #ifndef   __POKEMONISM_EVENT_HH__
// #define   __POKEMONISM_EVENT_HH__
//
// #include <pokemonism.hh>
//
// #include <pokemonism/mareep/subscription.hh>
//
// namespace pokemonism {
//     namespace pokemon {
//         class event {
//         public:     struct type {
//                     public:     constexpr static uint32 gen = 0;
//                     public:     constexpr static uint32 rel = 1;
//                     public:     constexpr static uint32 add = 2;
//                     public:     constexpr static uint32 del = 3;
//                     public:     constexpr static uint32 max = 4;
//                     };
//         public:     struct subscription : public mareep::subscription {
//                     public:     struct property {
//                                 public:     constexpr static uint32 release_object_on_rel   = (0x00000001U << 30U);
//                                 public:     constexpr static uint32 release_on_del          = (0x00000001U << 31U);
//                                 };
//                     public:     subscription(void) {}
//                     public:     ~subscription(void) override {}
//                     public:     subscription(const subscription & o) = delete;
//                     public:     subscription(subscription && o) noexcept = delete;
//                     public:     subscription & operator=(const subscription & o) = delete;
//                     public:     subscription & operator=(subscription && o) noexcept = delete;
//                     };
//         public:     virtual uint32 eventGet(void) const = 0;
//         public:     event(void) {}
//         public:     virtual ~event(void) {}
//         public:     event(const event & o) = delete;
//         public:     event(event && o) noexcept = delete;
//         public:     event & operator=(const event & o) = delete;
//         public:     event & operator=(event && o) noexcept = delete;
//         };
//     }
// }
//
// #endif // __POKEMONISM_EVENT_HH__