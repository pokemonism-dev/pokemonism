/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 09, 2025
 */

#ifndef   __POKEMONISM_SDK_DESCRIPTORABLE_UNIX_HH__
#define   __POKEMONISM_SDK_DESCRIPTORABLE_UNIX_HH__

#include <unistd.h>
#include <errno.h>

#include <pokemonism/sdk/allocator.hh>
#include <pokemonism/sdk/descriptorable.hh>
#include <pokemonism/sdk/interface/descriptor.hh>

namespace pokemonism::sdk {

    template <class descriptor>
    class descriptorable::unix : public descriptor {
    public:     typedef int                         type;
    protected:  type                                value;
    protected:  unsigned int                        status;
    protected:  interface::descriptor::exception *  exception;
    protected:  inline int valueGet(void) const;
    public:     inline int open(void) override;
    protected:  inline void clear(void) override;
    protected:  inline void clean(void) override;
    protected:  inline void reset(void) override;
    protected:  long write(const unsigned char * storage, unsigned long n) override;
    protected:  long read(unsigned char * storage, unsigned long capacity) override;
    public:     inline int close(void) override;
    public:     inline unsigned int check(unsigned int state) const override;
    protected:  inline void exceptionSet(interface::descriptor::exception * e, unsigned int state = declaration::none, long result = declaration::fail) override;
    protected:  inline explicit unix(type value);
    public:     inline unix(void);
    public:     inline ~unix(void) override;
    public:     unix(const descriptorable::unix<descriptor> & o) = delete;
    public:     unix(descriptorable::unix<descriptor> && o) noexcept = delete;
    public:     descriptorable::unix<descriptor> & operator=(const descriptorable::unix<descriptor> & o) = delete;
    public:     descriptorable::unix<descriptor> & operator=(descriptorable::unix<descriptor> && o) noexcept = delete;
    };

    template <class descriptor>
    inline int descriptorable::unix<descriptor>::valueGet(void) const {
        return value;
    }

    template <class descriptor>
    inline int descriptorable::unix<descriptor>::open(void) {
        return value > declaration::invalid ? declaration::success : declaration::fail;
    }

    template <class descriptor>
    inline int descriptorable::unix<descriptor>::close(void) {
        if (value > declaration::invalid) {
            if (::close(value) != declaration::success) {
                // ### 20250909 | ERROR HANDLING
            }

            value = declaration::invalid;

            this->stateOn(interface::descriptor::event::close, declaration::success);

            clear();
        }

        return declaration::success;
    }

    template <class descriptor>
    inline void descriptorable::unix<descriptor>::clear(void) {

    }

    template <class descriptor>
    inline void descriptorable::unix<descriptor>::clean(void) {

    }

    template <class descriptor>
    inline void descriptorable::unix<descriptor>::reset(void) {

    }

    template <class descriptor>
    inline unsigned int descriptorable::unix<descriptor>::check(unsigned int state) const {
        return (status & state);
    }

    template <class descriptor>
    inline void descriptorable::unix<descriptor>::exceptionSet(interface::descriptor::exception * e, unsigned int state, long result) {
        if (exception == nullptr) {
            exception = e;
            this->stateOn(state, result, exception);
            return;
        }

        this->stateOn(state, result, e);
        delete e;
    }

    template <class descriptor>
    inline descriptorable::unix<descriptor>::unix(type value) : value(value), status(value > declaration::invalid ? descriptor::state::open : descriptor::state::none), exception(nullptr) {

    }

    template <class descriptor>
    inline descriptorable::unix<descriptor>::unix(void) : value(declaration::invalid), status(declaration::none), exception(nullptr) {

    }

    template <class descriptor>
    inline descriptorable::unix<descriptor>::~unix(void) {
        // ReSharper disable once CppVirtualFunctionCallInsideCtor
        close();
        status = descriptor::state::none;
        exception = allocator::del(exception);
    }

    template <class descriptor>
    long descriptorable::unix<descriptor>::write(const unsigned char * storage, unsigned long n) {
        pokemon_develop_check(storage == nullptr || n == 0, (value > declaration::invalid ? declaration::success : declaration::fail));

        if (value > declaration::invalid) {
            const long result = ::write(value, storage, n);

            if (result > 0) {
                status = status | descriptor::state::out;
                this->stateOn(descriptor::state::out, result);
                return result;
            }

            status = status & (~(descriptor::state::out));

            if (result == 0) return result;

            if (errno == EAGAIN) return declaration::success;

            exceptionSet(new descriptor::exception(descriptor::exception::category::sys, reinterpret_cast<void *>(::write), errno), descriptor::state::out, result);
        }

        return declaration::fail;
    }

    template <class descriptor>
    long descriptorable::unix<descriptor>::read(unsigned char * storage, unsigned long capacity) {
        pokemon_develop_check(storage == nullptr || capacity == 0, (value > declaration::invalid ? declaration::success : declaration::fail));

        if (value > declaration::invalid) {
            const long result = ::read(value, storage, capacity);

            if (result > 0) {
                status = status | descriptor::state::in;
                this->stateOn(descriptor::state::in, result);
                return result;
            }

            status = status & (~(descriptor::state::in));

            if (result == 0) {
                exceptionSet(new descriptor::exception(descriptor::exception::category::lib, reinterpret_cast<void *>(::read), descriptor::exception::code::eof), descriptor::state::in, result);
                return result;
            }

            if (errno == EAGAIN) return declaration::success;

            exceptionSet(new descriptor::exception(descriptor::exception::category::sys, reinterpret_cast<void *>(::read), errno), descriptor::state::in, result);
        }

        return declaration::fail;
    }

}

#endif // __POKEMONISM_SDK_DESCRIPTORABLE_UNIX_HH__
