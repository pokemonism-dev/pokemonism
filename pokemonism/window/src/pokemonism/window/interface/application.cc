// /**
//  * @file
//  * @brief
//  * @details
//  *
//  * @author          snorlax <snorlax@pokemonism.dev>
//  * @since           9월 13, 2025
//  */
//
//
// #include "application.hh"
//
// #include "window.hh"
//
// namespace pokemonism::window::interface {
//
//     Application::Application(void) : size(declaration::zero), head(nullptr), tail(nullptr) {
//
//     }
//
//     Application::~Application(void) {
//         clear();
//     }
//
//     Window * Application::add(Window * node) {
//         return Collection::add(this, node);
//     }
//
//     Window * Application::del(Window * node) {
//         return Collection::del(this, node);
//     }
//
//     void Application::clear(void) {
//         Collection::clear(this);
//     }
//
// }