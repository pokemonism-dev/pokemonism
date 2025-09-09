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

#include <pokemonism/sdk/allocator.hh>
#include <pokemonism/sdk/descriptorable.hh>
#include <pokemonism/sdk/interface/descriptor.hh>

namespace pokemonism::sdk {

    class descriptorable::unix : public interface::descriptor {
    public:     typedef int                         type;
    protected:  type                                value;
    protected:  unsigned int                        status;
    protected:  interface::descriptor::exception *  exception;
    protected:  inline int valueGet(void) const;
    public:     inline int open(void) override;
    protected:  long write(const unsigned char * storage, unsigned long n) override;
    protected:  long read(unsigned char * storage, unsigned long capacity) override;
    public:     inline int close(void) override;
    public:     inline unsigned int check(unsigned int state) const override;
    public:     inline void exceptionSet(descriptor::exception * e, unsigned int state = declaration::none, long result = declaration::fail) override;
    protected:  inline explicit unix(type value);
    public:     inline unix(void);
    public:     inline ~unix(void) override;
    public:     unix(const descriptorable::unix & o) = delete;
    public:     unix(descriptorable::unix && o) noexcept = delete;
    public:     descriptorable::unix & operator=(const descriptorable::unix & o) = delete;
    public:     descriptorable::unix & operator=(descriptorable::unix && o) noexcept = delete;
    };

    inline int descriptorable::unix::valueGet(void) const {
        return value;
    }

    inline int descriptorable::unix::open(void) {
        return value > declaration::invalid ? declaration::success : declaration::fail;
    }

    inline int descriptorable::unix::close(void) {
        if (value > declaration::invalid) {
            if (::close(value) != declaration::success) {
                // ### 20250909 | ERROR HANDLING
            }

            value = declaration::invalid;

            stateOn(interface::descriptor::event::close, declaration::success);

            clear();
        }

        return declaration::success;
    }

    inline unsigned int descriptorable::unix::check(unsigned int state) const {
        return (status & state);
    }

    inline void descriptorable::unix::exceptionSet(descriptor::exception * e, unsigned int state, long result) {
        if (exception == nullptr) {
            exception = e;
            stateOn(state, result, exception);
            return;
        }

        stateOn(state, result, e);
        delete e;
    }

    inline descriptorable::unix::unix(type value) : value(value), status(value > declaration::invalid ? descriptor::state::open : descriptor::state::none), exception(nullptr) {

    }

    inline descriptorable::unix::unix(void) : value(declaration::invalid), status(declaration::none), exception(nullptr) {

    }

    inline descriptorable::unix::~unix(void) {
        // ReSharper disable once CppVirtualFunctionCallInsideCtor
        close();
        status = descriptor::state::none;
        exception = allocator::del(exception);
    }

}

#endif // __POKEMONISM_SDK_DESCRIPTORABLE_UNIX_HH__