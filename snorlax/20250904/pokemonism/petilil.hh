// /**
//  * @file            pokemonism/petilil.hh
//  * @brief
//  * @details
//  *
//  * @author          snorlax <snorlax@pokemonism.dev>
//  * @since           9월 03, 2025
//  */
//
// #ifndef   __POKEMONISM_PETILIL_HH__
// #define   __POKEMONISM_PETILIL_HH__
//
// #include <pokemonism/pokemon.hh>
// #include <pokemonism/pokemon/faint.hh>
//
// namespace pokemonism {
//
//     class petilil : public pokemon {
//     public:     static petilil * go(void);
//     protected:  void (*retreat)(petilil *);
//     public:     const char * name(void) const override { return "petilil"; }
//     public:     virtual petilil * start(void);
//     public:     inline void stop(void (*f)(petilil *));
//     protected:  petilil(void);
//     protected:  ~petilil(void) override;
//     public:     petilil(const petilil & o) = delete;
//     public:     petilil(petilil && o) noexcept = delete;
//     public:     petilil & operator=(const petilil & o) = delete;
//     public:     petilil & operator=(petilil && o) noexcept = delete;
//     };
//
//     inline void petilil::stop(void (*f)(petilil *)) {
//         pokemon_training_check(f == nullptr, f = pokemon::retreat<petilil>);
//
//         retreat = f;
//     }
//
// }
//
// #endif // __POKEMONISM_PETILIL_HH__