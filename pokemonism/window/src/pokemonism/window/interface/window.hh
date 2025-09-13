// /**
//  * @file
//  * @brief
//  * @details
//  *
//  * @author          snorlax <snorlax@pokemonism.dev>
//  * @since           9월 13, 2025
//  */
//
// #ifndef   __POKEMONISM_WINDOW_INTERFACE_WINDOW_HH__
// #define   __POKEMONISM_WINDOW_INTERFACE_WINDOW_HH__
//
// #include <pokemonism/sdk/linked/list.hh>
//
// namespace pokemonism::window::interface {
//
//     class Application;
//
//     class Window {
//     protected:  Application * container;
//     protected:  Window * prev;
//     protected:  Window * next;
//     public:     Window(void);
//     public:     virtual ~Window(void);
//     public:     Window(const Window & o) = delete;
//     public:     Window(Window && o) noexcept = delete;
//     public:     Window & operator=(const Window & o) = delete;
//     public:     Window & operator=(Window && o) noexcept = delete;
//     public:     friend pokemonism::sdk::LinkedList<Application, Window>;
//     };
//
// }
//
// #endif // __POKEMONISM_WINDOW_INTERFACE_WINDOW_HH__