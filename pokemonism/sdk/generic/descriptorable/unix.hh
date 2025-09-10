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

#include <pokemonism/sdk/allocator.hh>
#include <pokemonism/sdk/generic/descriptor.hh>

namespace pokemonism::sdk::generic::descriptorable {

    template <class descriptor = interface::descriptor>
    class unix : public descriptor {
    public:     typedef int                                 type;
    protected:  int                                         value;
    protected:  unsigned int                                status;
    protected:  unsigned int                                properties;
    protected:  interface::descriptor::exception *          exception;
    public:     int close(void) override;
    protected:  long read(void) override;
    protected:  long read(unsigned char * storage, unsigned long capacity) override;
    protected:  long write(void) override;
    protected:  long write(const unsigned char * storage, unsigned long n) override;
    public:     unsigned int check(unsigned int state) const override;
    protected:  void clear(void) override;
    protected:  void clean(void) override;
    protected:  void reset(void) override;
    protected:  inline void exceptionSet(interface::descriptor::exception * e, unsigned int state = declaration::none, long result = declaration::fail) override;
    public:     inline explicit unix(int value, unsigned int properties = interface::descriptor::property::none);
    public:     inline unix(void);
    public:     inline ~unix(void) override;
    public:     unix(const generic::descriptorable::unix<descriptor> & o) = delete;
    public:     unix(generic::descriptorable::unix<descriptor> && o) noexcept = delete;
    public:     generic::descriptorable::unix<descriptor> & operator=(const generic::descriptorable::unix<descriptor> & o) = delete;
    public:     generic::descriptorable::unix<descriptor> & operator=(generic::descriptorable::unix<descriptor> && o) noexcept = delete;
    };

    template <class descriptor>
    int unix<descriptor>::close(void) {
        if (value > declaration::invalid) {
            if (::close(value) != declaration::success) {
                // ### 20250910 | ERROR HANDLING
            }

            value = declaration::invalid;
            status = interface::descriptor::state::none;
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
            status = status | interface::descriptor::state::in;

            this->onState(interface::descriptor::state::type::in, result);

            return result;
        }

        status = status & (~(interface::descriptor::state::in));

        if (result == 0) return result;
        if (errno == EAGAIN) return declaration::success;

        exceptionSet(new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::read), errno), interface::descriptor::state::type::in, result);

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
            status = status | interface::descriptor::state::out;

            this->onState(interface::descriptor::state::type::out, result);

            return result;
        }

        status = status & (~(interface::descriptor::state::out));

        if (result == 0) return result;
        if (errno == EAGAIN) return declaration::success;

        exceptionSet(new interface::descriptor::exception(interface::descriptor::exception::category::sys, reinterpret_cast<void *>(::write), errno), interface::descriptor::state::type::out, result);

        return result;
    }

    template <class descriptor>
    unsigned int unix<descriptor>::check(unsigned int state) const {
        return (status & state);
    }

    template <class descriptor>
    void unix<descriptor>::clear(void) {
        status = status & (~(interface::descriptor::state::exception));
        exception = allocator::del(exception);
    }

    template <class descriptor>
    void unix<descriptor>::clean(void) {
        status = status & (~(interface::descriptor::state::exception));
        exception = allocator::del(exception);
    }

    template <class descriptor>
    void unix<descriptor>::reset(void) {
        status = status & (~(interface::descriptor::state::exception));
        exception = allocator::del(exception);
    }

    template <class descriptor>
    inline void unix<descriptor>::exceptionSet(pokemonism::sdk::interface::descriptor::exception * e, unsigned int state, long result) {
        pokemon_develop_check(e == nullptr, return);

        if (exception != nullptr) {
            this->onState(state, result, e);
            delete e;
            return;
        }

        exception = e;
        this->onState(state, result, e);
    }

    template <class descriptor>
    inline unix<descriptor>::unix(int value, unsigned int properties) : value(value), properties(properties), exception(nullptr) {
        status = value > declaration::invalid ? pokemonism::sdk::interface::descriptor::state::open : pokemonism::sdk::interface::descriptor::state::none;
    }

    template <class descriptor>
    inline unix<descriptor>::unix(void) : value(declaration::invalid), status(pokemonism::sdk::interface::descriptor::state::none), properties(pokemonism::sdk::interface::descriptor::property::none), exception(nullptr) {

    }

    template <class descriptor>
    inline unix<descriptor>::~unix(void) {
        close();

        exception = allocator::del(exception);
    }

}

#endif // __POKEMONISM_SDK_GENERIC_DESCRIPTORABLE_UNIX_HH__