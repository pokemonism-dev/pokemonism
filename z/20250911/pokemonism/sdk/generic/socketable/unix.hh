/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_GENERIC_SOCKETABLE_UNIX_HH__
#define   __POKEMONISM_SDK_GENERIC_SOCKETABLE_UNIX_HH__

#include <pokemonism/sdk/interface/socket.hh>
#include <pokemonism/sdk/generic/descriptorable/unix.hh>
#include <pokemonism/sdk/protocol/transmission/control/protocol.hh>

namespace pokemonism::sdk {

    namespace generic::socketable {

        template <class tag, class descriptor = interface::socket>
        class unix : public descriptorable::unix<descriptor> {
        public:     typedef descriptorable::unix<descriptor>::type  type;
        public:     using linker = interface::socket::linker<type, tag>;
        public:     struct connection {
                    public:     unix<tag, descriptor>::type       value;
                    public:     interface::socket::address * addr;
                    };
        public:     int open(void) override;
        public:     int shutdown(int how) override;
        public:     inline explicit unix(unsigned int properties);
        public:     inline unix(unix<tag, descriptor>::type value, unsigned int properties);
        public:     inline unix(void);
        public:     inline ~unix(void) override;
        public:     unix(const generic::socketable::unix<tag, descriptor> & o) = delete;
        public:     unix(generic::socketable::unix<tag, descriptor> && o) noexcept = delete;
        public:     generic::socketable::unix<tag, descriptor> & operator=(const generic::socketable::unix<tag, descriptor> & o) = delete;
        public:     generic::socketable::unix<tag, descriptor> & operator=(generic::socketable::unix<tag, descriptor> && o) noexcept = delete;
        };

        template <class tag, class descriptor>
        int unix<tag, descriptor>::open(void) {
            printf("%s\n", linker::name);
            pokemon_develop_check(this->addr == nullptr, return declaration::fail);

            if (this->value <= declaration::invalid) {
                this->e = allocator::del(this->e);
                this->value = linker::open(this->value, pointof(this->status), pointof(this->e));

                if (this->value != declaration::success || this->e != nullptr) {
                    this->exceptionSet(this->e, interface::descriptor::state::type::open, declaration::fail);
                    return declaration::fail;
                }
            }

            if ((this->properties & interface::descriptor::property::nonblock) || this->stateChk(interface::descriptor::state::engine)) {
                if (this->nonblockSet() != declaration::success) {
                    this->close();
                    return declaration::fail;
                }
            }

            if (linker::link(this->value, this->addr->value, this->addr->size, pointof(this->status), pointof(this->e)) != declaration::success) {
                this->exceptionSet(this->e, interface::descriptor::state::type::open, declaration::fail);
                return declaration::fail;
            }

            if (this->stateChk(interface::socket::state::link::end)) this->onState(interface::descriptor::state::type::open, declaration::success);

            return declaration::success;
        }

        // ReSharper disable once CppDFAConstantFunctionResult
        template <class tag, class descriptor>
        int unix<tag, descriptor>::shutdown(int how) {
            pokemon_develop_check(this->value <= declaration::invalid, return declaration::success);

            if (::shutdown(this->value, how) != declaration::success) {
                // ### 20250910 | ERROR HANDLING
            }

            if (how == interface::socket::flag::shutdown::in) {
                this->stateDel(interface::socket::state::in | interface::socket::state::link::in);
                this->onState(interface::socket::state::type::shutdown, interface::socket::flag::shutdown::in);
            } else if (how == interface::socket::flag::shutdown::out) {
                this->stateDel(interface::socket::state::out | interface::socket::state::link::out);
                this->onState(interface::socket::state::type::shutdown, interface::socket::flag::shutdown::out);
            } else if (how == interface::socket::flag::shutdown::all) {
                this->stateDel(interface::socket::state::out | interface::socket::state::link::out | interface::socket::state::in | interface::socket::state::link::in);
                this->onState(interface::socket::state::type::shutdown, interface::socket::flag::shutdown::all);
                this->close();
            }

            return declaration::success;
        }

        template <class tag, class descriptor>
        inline unix<tag, descriptor>::unix(unsigned int properties) : descriptorable::unix<descriptor>(properties) {

        }

        template <class tag, class descriptor>
        inline unix<tag, descriptor>::unix(unix<tag, descriptor>::type value, unsigned int properties) : descriptorable::unix<descriptor>(value, properties) {

        }

        template <class tag, class descriptor>
        inline unix<tag, descriptor>::unix(void) {

        }

        template <class tag, class descriptor>
        inline unix<tag, descriptor>::~unix(void) {

        }

    }


    namespace interface {

        template <> struct socket::linker<int, pokemonism::protocol::transmission::control::protocol::socket::session> {
        public:     constexpr static const char * name = "pokemonism::protocol::transmission::control::protocol::socket::session";
        public:     static int link(int & value, const void * addr, unsigned int len, unsigned int * status, interface::descriptor::exception ** e);
        public:     static int open(int & value, unsigned int * status, interface::descriptor::exception ** e);
        };

        template <> struct socket::linker<int, pokemonism::protocol::transmission::control::protocol::socket::server> {
        public:     constexpr static const char * name = "pokemonism::protocol::transmission::control::protocol::socket::server";
        public:     static int link(int & value, const void * addr, unsigned int len, unsigned int * status, interface::descriptor::exception ** e);
        public:     static int open(int & value, unsigned int * status, interface::descriptor::exception ** e);
        };

        template <> struct socket::linker<int, pokemonism::protocol::transmission::control::protocol::socket::client> {
        public:     constexpr static const char * name = "pokemonism::protocol::transmission::control::protocol::socket::client";
        public:     static int link(int & value, const void * addr, unsigned int len, unsigned int * status, interface::descriptor::exception ** e);
        public:     static int open(int & value, unsigned int * status, interface::descriptor::exception ** e);
        };

    };

}

#endif // __POKEMONISM_SDK_GENERIC_SOCKETABLE_UNIX_HH__