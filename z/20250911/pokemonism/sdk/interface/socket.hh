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
                            public:     constexpr static unsigned int link      = interface::descriptor::state::type::max + 1;
                            public:     constexpr static unsigned int max       = interface::descriptor::state::type::max + 2;
                            };
                public:     constexpr static unsigned int none                  = interface::descriptor::state::none;       // (0x00000000U <<  0U);
                public:     constexpr static unsigned int open                  = interface::descriptor::state::open;       // (0x00000001U <<  0U);
                public:     constexpr static unsigned int in                    = interface::descriptor::state::in;         // (0x00000001U <<  1U);
                public:     constexpr static unsigned int out                   = interface::descriptor::state::out;        // (0x00000001U <<  2U);
                public:     constexpr static unsigned int exception             = interface::descriptor::state::exception;  // (0x00000001U <<  3U);
                public:     struct link {
                            public:     constexpr static unsigned int begin     = (0x00000001U <<  4U);
                            public:     constexpr static unsigned int in        = (0x00000001U <<  5U);
                            public:     constexpr static unsigned int out       = (0x00000001U <<  6U);
                            public:     constexpr static unsigned int end       = (0x00000001U <<  7U);
                            public:     constexpr static unsigned int all       = (interface::socket::state::link::begin | interface::socket::state::link::in | interface::socket::state::link::out | interface::socket::state::link::end);
                            };
                public:     constexpr static unsigned int engine                = interface::descriptor::state::engine;     // (0x00000001U << 31U);
                };
    public:     struct flag {
                public:     struct shutdown {
                            public:     constexpr static int in  = SHUT_RD;
                            public:     constexpr static int out = SHUT_WR;
                            public:     constexpr static int all = SHUT_RDWR;
                            };
                };
    public:     struct tag {
                public:     constexpr static int domain     = declaration::zero;
                public:     constexpr static int type       = declaration::zero;
                public:     constexpr static int protocol   = declaration::zero;
                };
    public:     struct address {
                public:     unsigned long size;
                public:     unsigned char value[];
                };
    public:     template <typename type, class tag = interface::socket::tag> struct linker {
                public:     constexpr static const char * name = "interface::socket::linker";
                public:     static int link(type & value, const void * addr, unsigned int len, unsigned int * status, interface::descriptor::exception ** e);
                public:     static type open(type & value, unsigned int * status, interface::descriptor::exception ** e);
                };
    public:
    protected:  socket::address * addr;
    public:     virtual int shutdown(int how) = 0;
    protected:  inline virtual int link(void);
    public:     inline virtual void addressSet(const void * o, unsigned long len);
    public:     inline virtual void addressSet(socket::address * o);
    public:     inline explicit socket(unsigned int properties);
    public:     inline socket(void);
    public:     inline ~socket(void) override;
    public:     socket(const interface::socket & o) = delete;
    public:     socket(interface::socket && o) noexcept = delete;
    public:     interface::socket & operator=(const interface::socket & o) = delete;
    public:     interface::socket & operator=(interface::socket && o) noexcept = delete;
    };

    template <typename type, class tag>
    int socket::linker<type, tag>::link(type & value, const void * addr, unsigned int len, unsigned int * status, interface::descriptor::exception ** e) {
        return value;
    }

    template <typename type, class tag>
    type socket::linker<type, tag>::open(type & value, unsigned int * status, interface::descriptor::exception ** e) {
        return value;
    }

    inline int socket::link(void) {
        if (stateChk(interface::descriptor::state::open)) {
            stateSet(interface::socket::state::link::begin);
            return declaration::success;
        }
        return declaration::fail;
    }

    inline void socket::addressSet(const void * o, unsigned long len) {
        if (addr != nullptr && addr->size != len) addr = allocator::del(addr);

        if (addr == nullptr && len > 0) addr = static_cast<socket::address *>(allocator::gen(len));

        if (addr != nullptr) {
            addr->size = len;
            memcpy(addr->value, o, len);
        }
    }

    inline void socket::addressSet(socket::address * o) {
        if (addr != nullptr) delete addr;

        addr = o;
    }

    inline socket::socket(unsigned int properties) : interface::descriptor(properties), addr(nullptr) {

    }

    inline socket::socket(void) : addr(nullptr) {

    }

    inline socket::~socket(void) {
        addr = allocator::del(addr);
    }

}

#endif // __POKEMONISM_SDK_INTERFACE_SOCKET_HH__