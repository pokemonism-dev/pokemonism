/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 10, 2025
 */

#ifndef   __POKEMONISM_SDK_GENERIC_DESCRIPTORABLE_UNIX_HH__
#define   __POKEMONISM_SDK_GENERIC_DESCRIPTORABLE_UNIX_HH__

#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

#include <pokemonism/sdk/allocator.hh>
#include <pokemonism/sdk/generic/descriptor.hh>

namespace pokemonism::sdk::generic::descriptorable {

    template <class descriptor = interface::descriptor>
    class unix : public descriptor {
    public:     typedef int     type;
    protected:  int             value;
    public:     int nonblockSet(void) override;
    public:     int nonblockDel(void) override;
    public:     int close(void) override;
    protected:  long read(void) override;
    protected:  long read(unsigned char * storage, unsigned long capacity) override;
    protected:  long write(void) override;
    protected:  long write(const unsigned char * storage, unsigned long n) override;
    public:     inline explicit unix(unsigned int properties);
    public:     inline unix(int value, unsigned int properties);
    public:     inline unix(void);
    public:     virtual inline ~unix(void) override;
    public:     unix(const generic::descriptorable::unix<descriptor> & o) = delete;
    public:     unix(generic::descriptorable::unix<descriptor> && o) noexcept = delete;
    public:     generic::descriptorable::unix<descriptor> & operator=(const generic::descriptorable::unix<descriptor> & o) = delete;
    public:     generic::descriptorable::unix<descriptor> & operator=(generic::descriptorable::unix<descriptor> && o) noexcept = delete;
    };

    template <class descriptor>
    int unix<descriptor>::nonblockSet(void) {
        int flags = fcntl(value, F_GETFL, 0);

        if (flags == declaration::fail) {
            this->exceptionSet(new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::fcntl), errno));
            return declaration::fail;
        }

        flags = flags | O_NONBLOCK;

        if (fcntl(value, F_SETFL, flags) != declaration::fail) {
            this->exceptionSet(new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::fcntl), errno));
            return declaration::fail;
        }

        return declaration::success;
    }

    template <class descriptor>
    int unix<descriptor>::nonblockDel(void) {
        int flags = fcntl(value, F_GETFL, 0);

        if (flags == declaration::fail) {
            this->exceptionSet(new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::fcntl), errno));
            return declaration::fail;
        }

        flags = flags & (~(O_NONBLOCK));

        if (fcntl(value, F_SETFL, flags) != declaration::fail) {
            this->exceptionSet(new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::fcntl), errno));
            return declaration::fail;
        }

        return declaration::success;
    }

    template <class descriptor>
    int unix<descriptor>::close(void) {
        if (value > declaration::invalid) {
            if (::close(value) != declaration::success) {
                // ### 20250910 | ERROR HANDLING
            }

            value = declaration::invalid;
            this->stateSet(interface::descriptor::state::none);
            this->onState(interface::descriptor::state::type::close, declaration::success);
        }

        return declaration::success;
    }

    template <class descriptor>
    long unix<descriptor>::read(void) {
        return descriptor::read();
    }

    template <class descriptor>
    long unix<descriptor>::read(unsigned char * storage, unsigned long capacity) {
        pokemon_develop_check(storage == nullptr || capacity == 0 || value <= declaration::invalid, return value > declaration::invalid ? declaration::success : declaration::fail);

        const long result = ::read(value, storage, capacity);

        if (result > 0) {
            this->stateSet(interface::descriptor::state::in);
            this->onState(interface::descriptor::state::type::in, result);

            return result;
        }

        this->stateDel(interface::descriptor::state::in);

        if (result == 0) return result;
        if (errno == EAGAIN) return declaration::success;

        this->exceptionSet(new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::read), errno), interface::descriptor::state::type::in, result);

        return result;
    }

    template <class descriptor>
    long unix<descriptor>::write(void) {
        return descriptor::write();
    }

    template <class descriptor>
    long unix<descriptor>::write(const unsigned char * storage, unsigned long n) {
        pokemon_develop_check(storage == nullptr || n == 0 || value <= declaration::invalid, return value > declaration::invalid ? declaration::success : declaration::fail);

        const long result = ::write(value, storage, n);

        if (result > 0) {
            this->stateSet(interface::descriptor::state::out);
            this->onState(interface::descriptor::state::type::out, result);

            return result;
        }

        this->stateDel(interface::descriptor::state::out);

        if (result == 0) return result;
        if (errno == EAGAIN) return declaration::success;

        this->exceptionSet(new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::write), errno), interface::descriptor::state::type::out, result);

        return result;
    }

    template <class descriptor>
    inline unix<descriptor>::unix(unsigned int properties) : descriptor(properties), value(declaration::invalid) {
    }

    template <class descriptor>
    inline unix<descriptor>::unix(int value, unsigned int properties) : descriptor(properties), value(value) {
    }

    template <class descriptor>
    inline unix<descriptor>::unix(void) : value(declaration::invalid) {

    }

    template <class descriptor>
    inline unix<descriptor>::~unix(void) {
        close();
    }

}

#endif // __POKEMONISM_SDK_GENERIC_DESCRIPTORABLE_UNIX_HH__