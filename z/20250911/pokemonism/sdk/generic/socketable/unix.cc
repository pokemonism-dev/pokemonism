/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */


#include "unix.hh"

namespace pokemonism::sdk {

    namespace interface {

        // ReSharper disable once CppParameterMayBeConstPtrOrRef
        int socket::linker<int, pokemonism::protocol::transmission::control::protocol::socket::session>::link(int & value, const void * addr, unsigned int len, unsigned int * status, interface::descriptor::exception ** e) {
            if (value <= declaration::invalid) return value;

            *status = *status | interface::socket::state::link::all;
            return value;
        }

        // ReSharper disable once CppParameterMayBeConstPtrOrRef
        int socket::linker<int, pokemonism::protocol::transmission::control::protocol::socket::session>::open(int & value, unsigned int * status, interface::descriptor::exception ** e) {
            *status = *status | interface::socket::state::open;
            return value;
        }

        int socket::linker<int, pokemonism::protocol::transmission::control::protocol::socket::server>::link(int & value, const void * addr, unsigned int len, unsigned int * status, interface::descriptor::exception ** e) {
            pokemon_develop_check(value <= declaration::invalid || addr == nullptr || len == 0, return declaration::fail);

            if (::bind(value, static_cast<const sockaddr *>(addr), len) != declaration::success) {
                *e = new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::bind), errno);
                *status = *status | interface::socket::state::exception;
                ::close(value);
                value = declaration::invalid;
                return declaration::fail;
            }

            if (::listen(value, SOMAXCONN) != declaration::success) {
                *e = new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::listen), errno);
                *status = *status | interface::socket::state::exception;
                ::close(value);
                value = declaration::invalid;
                return declaration::fail;
            }

            *status = *status | (interface::socket::state::link::begin | interface::socket::state::link::in | interface::socket::state::link::end);
            return declaration::success;
        }

        int socket::linker<int, pokemonism::protocol::transmission::control::protocol::socket::server>::open(int & value, unsigned int * status, interface::descriptor::exception ** e) {
            if (value > declaration::invalid) {
                *status = *status | interface::descriptor::state::open;
                return value;
            }

            value = ::socket(pokemonism::protocol::transmission::control::protocol::socket::server::domain, pokemonism::protocol::transmission::control::protocol::socket::server::type, pokemonism::protocol::transmission::control::protocol::socket::server::protocol);

            if (value <= declaration::invalid) {
                *e = new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::socket), errno);
                *status = *status | interface::socket::state::exception;
                value = declaration::invalid;
                return declaration::fail;
            }

            *status = *status | interface::socket::state::open;
            return value;
        }

        int socket::linker<int, pokemonism::protocol::transmission::control::protocol::socket::client>::link(int & value, const void * addr, unsigned int len, unsigned int * status, interface::descriptor::exception ** e) {
            pokemon_develop_check(value <= declaration::invalid || addr == nullptr || len == 0, return declaration::fail);

            if (::connect(value, static_cast<const sockaddr *>(addr), len) != declaration::success) {
                if (errno != EINPROGRESS) {
                    *e = new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::bind), errno);
                    *status = *status | interface::socket::state::exception;
                    ::close(value);
                    value = declaration::invalid;
                    return declaration::fail;
                }

                *status = *status | interface::socket::state::link::begin;
                return declaration::success;
            }

            *status = *status | (interface::socket::state::link::begin | interface::socket::state::link::in | interface::socket::state::link::out | interface::socket::state::link::end);
            return declaration::success;
        }

        int socket::linker<int, pokemonism::protocol::transmission::control::protocol::socket::client>::open(int & value, unsigned int * status, interface::descriptor::exception ** e) {
            if (value > declaration::invalid) {
                *status = *status | interface::descriptor::state::open;
                return value;
            }

            value = ::socket(pokemonism::protocol::transmission::control::protocol::socket::server::domain, pokemonism::protocol::transmission::control::protocol::socket::server::type, pokemonism::protocol::transmission::control::protocol::socket::server::protocol);

            if (value <= declaration::invalid) {
                *e = new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::socket), errno);
                *status = *status | interface::socket::state::exception;
                value = declaration::invalid;
                return declaration::fail;
            }

            *status = *status | interface::descriptor::state::open;
            return value;
        }

    };
}
