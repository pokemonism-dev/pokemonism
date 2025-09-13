// /**
//  * @file
//  * @brief
//  * @details
//  *
//  * @author          snorlax <snorlax@pokemonism.dev>
//  * @since           9월 13, 2025
//  */
//
// #ifndef   __POKEMONISM_WINDOW_INTERFACE_APPLICATION_HH__
// #define   __POKEMONISM_WINDOW_INTERFACE_APPLICATION_HH__
//
// #include <pokemonism/applicationable.hh>
// #include <pokemonism/sdk/linked/list.hh>
//
// namespace pokemonism::window::interface {
//
//     class WindowApp {
//
//     };
//
//     class WindowApplication {
//
//     };
//
//
//     class Window;
//     class WindowConfig;
//
//     class Application : public Applicationable {
//     protected:  using Collection =  pokemonism::sdk::LinkedList<Application, Window>;
//     protected:  unsigned long size;
//     protected:  Window * head;
//     protected:  Window * tail;
//     protected:  Window * add(Window * node);
//     protected:  Window * del(Window * node);
//     protected:  void clear(void);
//     public:     virtual Window * gen(const WindowConfig & config) = 0;
//     public:     Application(void);
//     public:     ~Application(void) override;
//     public:     Application(const Application & o) = delete;
//     public:     Application(Application && o) noexcept = delete;
//     public:     Application & operator=(const Application & o) = delete;
//     public:     Application & operator=(Application && o) noexcept = delete;
//     public:     friend Collection;
//     public:     friend Window;
//     };
//
// }
//
// #endif // __POKEMONISM_WINDOW_INTERFACE_APPLICATION_HH__