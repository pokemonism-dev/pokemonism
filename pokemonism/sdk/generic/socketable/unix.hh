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

namespace pokemonism::sdk::generic::socketable {

    template <class descriptor = interface::socket>
    class unix : public descriptorable::unix<descriptor> {
    public:     typedef descriptorable::unix<descriptor>::type  type;
    public:     struct connection {
                public:     unix<descriptor>::type       value;
                public:     interface::socket::address * addr;
                };
    public:     int open(void) override;
    public:     int shutdown(int how) override;
    public:     inline explicit unix(unsigned int properties);
    public:     inline unix(descriptorable::unix<descriptor>::type value, unsigned int properties);
    public:     inline unix(void);
    public:     inline ~unix(void) override;
    public:     unix(const generic::socketable::unix<descriptor> & o) = delete;
    public:     unix(generic::socketable::unix<descriptor> && o) noexcept = delete;
    public:     generic::socketable::unix<descriptor> & operator=(const generic::socketable::unix<descriptor> & o) = delete;
    public:     generic::socketable::unix<descriptor> & operator=(generic::socketable::unix<descriptor> && o) noexcept = delete;
    };

    template <class descriptor>
    int unix<descriptor>::open(void) {
        pokemon_develop_check(this->method == nullptr, return declaration::fail);

        if (this->value <= declaration::invalid) {
            this->value = ::socket(this->method->domain, this->method->type, this->method->protocol);

            if (this->value <= declaration::invalid) {
                this->exceptionSet(new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::socket), errno), interface::descriptor::state::type::open, declaration::fail);
                return declaration::fail;
            }

            if ((this->properties & interface::descriptor::property::nonblock) || this->stateChk(interface::descriptor::state::engine)) {
                if (this->nonblockSet() != declaration::success) {
                    this->close();
                    return declaration::fail;
                }
            }

            if (this->link() != declaration::success) {
                this->close();
                return declaration::fail;
            }
        }

        return declaration::success;
    }

    // ReSharper disable once CppDFAConstantFunctionResult
    template <class descriptor>
    int unix<descriptor>::shutdown(int how) {
        pokemon_develop_check(this->value <= declaration::invalid, return declaration::success);

        if (shutdown(this->value, how) != declaration::success) {
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

    template <class descriptor>
    inline unix<descriptor>::unix(unsigned int properties) : descriptorable::unix<descriptor>(properties) {

    }

    template <class descriptor>
    inline unix<descriptor>::unix(typename descriptorable::unix<descriptor>::type value, unsigned int properties) : descriptorable::unix<descriptor>(value, properties) {

    }

    template <class descriptor>
    inline unix<descriptor>::unix(void) {

    }

    template <class descriptor>
    inline unix<descriptor>::~unix(void) {

    }


}

#endif // __POKEMONISM_SDK_GENERIC_SOCKETABLE_UNIX_HH__