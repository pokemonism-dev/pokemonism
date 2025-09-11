/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 11, 2025
 */

#ifndef   __POKEMONISM_SDK_GENERIC_LINKABLE_SOCKET_UNIX_HH__
#define   __POKEMONISM_SDK_GENERIC_LINKABLE_SOCKET_UNIX_HH__

#include <errno.h>
#include <unistd.h>

#include <pokemonism/sdk/interface/socket.hh>

namespace pokemonism::sdk::generic::linkable::socket {

    struct unix : public interface::socket::linker<int> {};

    namespace server {
        struct unix : public interface::socket::linker<int> {
        public:     template <const interface::socket::tag * tag> static int link(int & value, const void * addr, unsigned long len, unsigned int * status, interface::descriptor::exception ** e);
        public:     template <const interface::socket::tag * tag> static int link(int & value, const void * addr, unsigned long len, int backlog, unsigned int * status, interface::descriptor::exception ** e);
        };

        template <const interface::socket::tag * tag>
        int unix::link(int & value, const void * addr, unsigned long len, unsigned int * status, interface::descriptor::exception ** e) {
            pokemon_develop_check(addr == nullptr || len == 0, return declaration::fail);

            if (::bind(value, static_cast<const sockaddr *>(addr), len) != declaration::success) {
                ::close(value);
                value = declaration::invalid;
                *e = new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::bind), errno);
                return declaration::fail;
            }

            if (::listen(value, SOMAXCONN) != declaration::success) {
                ::close(value);
                value = declaration::invalid;
                *e = new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::listen), errno);
                return declaration::fail;
            }

            *status = *status | (interface::socket::state::link::begin | interface::socket::state::link::in | interface::socket::state::link::end);

            return value;
        }

        template <const interface::socket::tag * tag>
        int unix::link(int & value, const void * addr, unsigned long len, int backlog, unsigned int * status, interface::descriptor::exception ** e) {
            pokemon_develop_check(value <= declaration::invalid || addr == nullptr || len == 0, return declaration::fail);

            if (::bind(value, static_cast<const sockaddr *>(addr), len) != declaration::success) {
                ::close(value);
                value = declaration::invalid;
                *e = new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::bind), errno);
                return declaration::fail;
            }

            if (::listen(value, SOMAXCONN) != declaration::success) {
                ::close(value);
                value = declaration::invalid;
                *e = new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::listen), errno);
                return declaration::fail;
            }

            *status = *status | (interface::socket::state::link::begin | interface::socket::state::link::in | interface::socket::state::link::end);

            return value;
        }
    }

    namespace client {
        struct unix : public interface::socket::linker<int> {
        public:     template <const interface::socket::tag * tag> static int link(int & value, const void * addr, unsigned long len, unsigned int * status, interface::descriptor::exception ** e);
        };

        template <const interface::socket::tag * tag>
        int unix::link(int & value, const void * addr, unsigned long len, unsigned int * status, interface::descriptor::exception ** e) {
            pokemon_develop_check(value <= declaration::invalid || addr == nullptr || len == 0, return declaration::fail);

            if (::connect(value, static_cast<const sockaddr *>(addr), len) != declaration::success) {
                ::close(value);
                value = declaration::invalid;
                *e = new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::connect), errno);
                return declaration::fail;
            }

            return declaration::success;
        }

    }

    namespace session {
        struct unix : public pokemonism::sdk::generic::linkable::socket::unix {};
    }

}

#endif // __POKEMONISM_SDK_GENERIC_LINKABLE_SOCKET_UNIX_HH__