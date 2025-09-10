/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_SOCKET_HH__
#define   __POKEMONISM_SDK_INTERFACE_SOCKET_HH__

#include <sys/socket.h>

#include <pokemonism/sdk/interface/descriptor.hh>

namespace pokemonism::sdk::interface {

    class socket : public interface::descriptor {
    public:     struct state : public interface::descriptor::state {
                public:     struct type : public interface::descriptor::state::type {
                            public:     constexpr static unsigned int open      = interface::descriptor::state::type::open;
                            public:     constexpr static unsigned int in        = interface::descriptor::state::type::in;
                            public:     constexpr static unsigned int out       = interface::descriptor::state::type::out;
                            public:     constexpr static unsigned int exception = interface::descriptor::state::type::exception;
                            public:     constexpr static unsigned int close     = interface::descriptor::state::type::close;
                            public:     constexpr static unsigned int shutdown  = interface::descriptor::state::type::max;
                            public:     constexpr static unsigned int max       = interface::descriptor::state::type::max + 1;
                            };
                };
    public:     struct method {
                public:     struct shutdown {
                            public:     constexpr static int in  = SHUT_RD;
                            public:     constexpr static int out = SHUT_WR;
                            public:     constexpr static int all = SHUT_RDWR;
                            };
                };
    public:     virtual int shutdown(int how) = 0;
    public:     socket(void) {}
    public:     ~socket(void) override {}
    public:     socket(const interface::socket & o) = delete;
    public:     socket(interface::socket && o) noexcept = delete;
    public:     interface::socket & operator=(const interface::socket & o) = delete;
    public:     interface::socket & operator=(interface::socket && o) noexcept = delete;
    };

}

#endif // __POKEMONISM_SDK_INTERFACE_SOCKET_HH__