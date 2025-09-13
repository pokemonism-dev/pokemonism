// /**
//  * @file
//  * @brief
//  * @details
//  *
//  * @author          snorlax <snorlax@pokemonism.dev>
//  * @since           9월 13, 2025
//  */
//
// #ifndef   __POKEMONISM_WINDOW_INTERFACE_WINDOW_CONFIG_HH__
// #define   __POKEMONISM_WINDOW_INTERFACE_WINDOW_CONFIG_HH__
//
// #include <pokemonism.hh>
//
// namespace pokemonism::window::interface {
//
//     class WindowConfig {
//     public:     WindowConfig(void);
//     public:     virtual ~WindowConfig(void);
//     public:     WindowConfig(const WindowConfig & o);
//     public:     WindowConfig(WindowConfig && o) noexcept;
//     public:     WindowConfig & operator=(const WindowConfig & o);
//     public:     WindowConfig & operator=(WindowConfig && o) noexcept;
//     };
//
//     inline WindowConfig::WindowConfig(void) {
//
//     }
//
//     inline WindowConfig::~WindowConfig(void) {
//
//     }
//
//     inline WindowConfig::WindowConfig(const WindowConfig & o) {
//
//     }
//
//     inline WindowConfig::WindowConfig(WindowConfig && o) noexcept {
//
//     }
//
//     inline WindowConfig & WindowConfig::operator=(const WindowConfig & o) {
//         return *this;
//     }
//
//     inline WindowConfig & WindowConfig::operator=(WindowConfig && o) noexcept {
//         return *this;
//     }
//
// }
//
// #endif // __POKEMONISM_WINDOW_INTERFACE_WINDOW_CONFIG_HH__