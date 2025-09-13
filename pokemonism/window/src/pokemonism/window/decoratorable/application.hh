// /**
//  * @file
//  * @brief
//  * @details
//  *
//  * @author          snorlax <snorlax@pokemonism.dev>
//  * @since           9월 13, 2025
//  */
//
// #ifndef   __POKEMONISM_WINDOW_DECORATORABLE_APPLICATION_HH__
// #define   __POKEMONISM_WINDOW_DECORATORABLE_APPLICATION_HH__
//
// #include <pokemonism/window/interface/application.hh>
//
// namespace pokemonism::window::decoratorable {
//
//     template <class Super = pokemonism::window::interface::Application>
//     class Application : public Super {
//     protected:  pokemonism::window::interface::Application & adapter;
//     protected:  explicit Application(pokemonism::window::interface::Application & adapter);
//     protected:  Application(void) = delete;
//     protected:  ~Application(void) override;
//     public:     Application(const Application & o) = delete;
//     public:     Application(Application && o) noexcept = delete;
//     public:     Application & operator=(const Application & o) = delete;
//     public:     Application & operator=(Application && o) noexcept = delete;
//     };
//
//     template<class Super>
//     Application<Super>::Application(pokemonism::window::interface::Application & adapter) : adapter(adapter) {
//
//     }
//
//     template<class Super>
//     Application<Super>::~Application() {
//
//     }
//
// }
//
// #endif // __POKEMONISM_WINDOW_DECORATORABLE_APPLICATION_HH__