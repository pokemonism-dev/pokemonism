/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_GENERIC_SOCKET_HH__
#define   __POKEMONISM_SDK_GENERIC_SOCKET_HH__

#include <pokemonism/sdk/allocator.hh>
#include <pokemonism/sdk/interface/socket.hh>
#include <pokemonism/sdk/generic/descriptor.hh>

namespace pokemonism::sdk::generic {

    template <class socketable = interface::socket>
    class socket : public generic::descriptor<socketable> {
    protected:  typedef socketable::type    type;
    protected:  struct address {
                public:     unsigned long   size;
                public:     unsigned char   storage[];
                };
    protected:  struct connection {
                public:     type            value;
                public:     address         addr;
                };
    protected:  address * addr;
    protected:  const interface::socket::method * method;
    protected:  inline socket(const interface::socket::method * method, const socket<socketable>::address & addr);
    protected:  inline socket(const interface::socket::method * method, socket<socketable>::address * addr);
    protected:  inline socket(const interface::socket::method * method, const unsigned char * addr, unsigned long addrLen);
    protected:  inline explicit socket(const interface::socket::method * method);
    public:     inline socket(void);
    public:     inline ~socket(void) override;
    public:     socket(const generic::socket<socketable> & o) = delete;
    public:     socket(generic::socket<socketable> && o) noexcept = delete;
    public:     generic::socket<socketable> & operator=(const generic::socket<socketable> & o) = delete;
    public:     generic::socket<socketable> & operator=(generic::socket<socketable> && o) noexcept = delete;
    };

    // template <class socketable>
    // int socket<socketable>::open(void) {
    //     pokemon_develop_check(method == nullptr, return declaration::fail);
    //
    //     if (this->value <= declaration::invalid) {
    //         this->value = ::socket(method->domain, method->type, method->protocol);
    //
    //         if (this->value <= declaration::invalid) {
    //             this->exceptionSet(new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::socket), errno), interface::descriptor::state::type::open, declaration::fail);
    //             return declaration::fail;
    //         }
    //
    //         if (this->properties & interface::descriptor::property::nonblock)
    //     }
    //
    //     return declaration::success;
    // }

    template <class socketable>
    inline socket<socketable>::socket(const interface::socket::method * method, const socket<socketable>::address & addr) : addr(nullptr), method(method) {
        this->addr = static_cast<socket<socketable>::address *>(allocator::gen(addr.size));

        memcpy(this->addr, pointof(addr), addr.size);
    }

    template <class socketable>
    inline socket<socketable>::socket(const interface::socket::method * method, socket<socketable>::address * addr) : addr(addr), method(method) {

    }

    template <class socketable>
    inline socket<socketable>::socket(const interface::socket::method * method, const unsigned char * addr, unsigned long addrLen) : method(method) {
        this->addr = static_cast<socket<socketable>::address *>(allocator::gen(addrLen));

        memcpy(this->addr->storage, addr, addrLen - sizeof(unsigned long));
        this->addr->size = addrLen;
    }

    template <class socketable>
    inline socket<socketable>::socket(const interface::socket::method * method) : addr(nullptr), method(method) {

    }

    template <class socketable>
    inline socket<socketable>::socket(void) : addr(nullptr), method(nullptr) {

    }

    template <class socketable>
    inline socket<socketable>::~socket(void) {
        method = nullptr;
    }

}

#endif // __POKEMONISM_SDK_GENERIC_SOCKET_HH__