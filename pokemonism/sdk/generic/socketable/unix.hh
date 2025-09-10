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
    public:     int shutdown(int how) override;
    // protected:  inline explicit unix(const interface::socket::method * method, const socket<socketable>::address & addr);
    // protected:  inline explicit unix(const interface::socket::method * method, socket<socketable>::address * addr);
    // protected:  inline unix(const interface::socket::method * method, const unsigned char * addr, unsigned long addrLen);
    // protected:  inline unix(generic::socket<socketable>::type value, const interface::socket::method * method, const socket<socketable>::address & addr);
    // protected:  inline unix(generic::socket<socketable>::type value, const interface::socket::method * method, socket<socketable>::address * addr);
    // protected:  inline unix(generic::socket<socketable>::type value, const interface::socket::method * method, const unsigned char * addr, unsigned long addrLen);
    // protected:  inline unix(generic::socket<socketable>::type value, const interface::socket::method * method);
    public:     inline explicit unix(int value, unsigned int properties = interface::descriptor::property::none);
    public:     inline unix(void);
    public:     inline ~unix(void) override;
    public:     unix(const generic::socketable::unix<descriptor> & o) = delete;
    public:     unix(generic::socketable::unix<descriptor> && o) noexcept = delete;
    public:     generic::socketable::unix<descriptor> & operator=(const generic::socketable::unix<descriptor> & o) = delete;
    public:     generic::socketable::unix<descriptor> & operator=(generic::socketable::unix<descriptor> && o) noexcept = delete;
    };

    // ReSharper disable once CppDFAConstantFunctionResult
    template <class descriptor>
    int unix<descriptor>::shutdown(int how) {
        pokemon_develop_check(this->value <= declaration::invalid, return declaration::success);

        if (shutdown(this->value, how) != declaration::success) {
            // ### 20250910 | ERROR HANDLING
        }

        if (how == interface::socket::method::shutdown::in) {
            this->status = this->status & (~(interface::socket::state::in));
            this->onState(interface::socket::state::type::shutdown, interface::socket::method::shutdown::in);
        } else if (how == interface::socket::method::shutdown::out) {
            this->status = this->status & (~(interface::socket::state::out));
            this->onState(interface::socket::state::type::shutdown, interface::socket::method::shutdown::out);
        } else if (how == interface::socket::method::shutdown::all) {
            this->status = this->status & (~(interface::socket::state::out | interface::socket::state::in));
            this->onState(interface::socket::state::type::shutdown, interface::socket::method::shutdown::all);
        }

        return declaration::success;
    }

    template <class descriptor>
    inline unix<descriptor>::unix(int value, unsigned int properties) : descriptorable::unix<descriptor>(value, properties) {
    }

    template <class descriptor>
    inline unix<descriptor>::unix(void) {

    }

    template <class descriptor>
    inline unix<descriptor>::~unix(void) {
    }

}

#endif // __POKEMONISM_SDK_GENERIC_SOCKETABLE_UNIX_HH__