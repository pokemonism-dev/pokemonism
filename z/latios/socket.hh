/**
 * @file        pokemonism/latios/socket.hh
 * @brief
 * @details
 *
 * @author      snorlax <snorlax@pokemonism.dev>
 * @since       Aug 27, 2025
 */

#ifndef   __POKEMONISM_LATIOS_SOCKET__HH__
#define   __POKEMONISM_LATIOS_SOCKET__HH__

#include <pokemonism/latios/descriptor.hh>

namespace pokemonism {
    namespace latios {

        class socket : public descriptor {
        public:     inline ~socket(void) override {}
        public:     socket(const socket & o) = delete;
        public:     socket(socket && o) noexcept = delete;
        public:     socket & operator=(const socket & o) = delete;
        public:     socket & operator=(socket && o) noexcept = delete;
        };

    }

    using socket = latios::socket;
}

#endif // __POKEMONISM_LATIOS_SOCKET__HH__