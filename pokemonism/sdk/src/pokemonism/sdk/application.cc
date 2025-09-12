/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 11, 2025
 */


#include "../../application.hh"

namespace pokemonism::sdk {

    Application::Application(void) : synchronizer(nullptr), observable(nullptr) {

    }

    Application::~Application(void) {

    }

}

// int main(int argc, char ** argv) {
//     pokemonism::sdk::Application application;
//
//     return application.run();
// }