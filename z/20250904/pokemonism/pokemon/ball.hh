// /**
//  * @file            pokemonism/pokemon/ball.hh
//  * @brief
//  * @details
//  *
//  * @author          snorlax <snorlax@pokemonism.dev>
//  * @since           9월 04, 2025
//  */
//
// #ifndef   __POKEMONISM_POKEMON_BALL_HH__
// #define   __POKEMONISM_POKEMON_BALL_HH__
//
// #include <pokemonism/sync.hh>
//
// #include <pokemonism/pokemon.hh>
//
// namespace pokemonism {
//
//     class pokemon::ball : public sync {
//     public:     static int recall(pokemon * mon);
//     public:     ball(void) {}
//     public:     ~ball(void) override {}
//     public:     ball(const pokemon::ball & o) = delete;
//     public:     ball(pokemon::ball && o) noexcept = delete;
//     public:     pokemon::ball & operator=(const pokemon::ball & o) = delete;
//     public:     pokemon::ball & operator=(pokemon::ball && o) noexcept = delete;
//     };
//
// }
//
// #endif // __POKEMONISM_POKEMON_BALL_HH__