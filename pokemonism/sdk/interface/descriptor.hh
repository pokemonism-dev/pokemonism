/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 08, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_DESCRIPTOR_HH__
#define   __POKEMONISM_SDK_INTERFACE_DESCRIPTOR_HH__

#include <pokemonism.hh>
#include <pokemonism/sdk/synchronizable.hh>

namespace pokemonism::sdk::interface {

    class descriptor : public synchronizable {
    public:     typedef int type;
    public:     class event;
    public:     struct state {
                public:     constexpr static unsigned int none      = (0x00000000U <<  0U);
                public:     constexpr static unsigned int open      = (0x00000001U <<  0U);
                public:     constexpr static unsigned int in        = (0x00000001U <<  1U);
                public:     constexpr static unsigned int out       = (0x00000001U <<  2U);
                public:     constexpr static unsigned int exception = (0x00000001U <<  3U);
                };
    public:     class exception;
    protected:  int lock(void) noexcept override { return declaration::fail; }
    protected:  int unlock(void) noexcept override { return declaration::fail; }
    protected:  int wait(void) noexcept override { return declaration::fail; }
    protected:  int wakeup(void) noexcept override { return declaration::fail; }
    protected:  int wait(long second, long nano) noexcept override { return declaration::fail; }
    protected:  int wakeup(bool all) noexcept override { return declaration::fail; }
    public:     virtual int open(void) = 0;
    public:     virtual int close(void) = 0;
    protected:  virtual long read(void) = 0;
    protected:  virtual long read(unsigned char * storage, unsigned long capacity) = 0;
    protected:  virtual long write(void) = 0;
    protected:  virtual long write(const unsigned char * storage, unsigned long n) = 0;
    public:     virtual unsigned int check(unsigned int state) const = 0;
    protected:  virtual void clear(void) = 0;
    protected:  virtual void clean(void) = 0;
    protected:  virtual void reset(void) = 0;
    protected:  inline virtual void stateOn(unsigned int state, long result, exception * e = nullptr);
    protected:  virtual void exceptionSet(descriptor::exception * e, unsigned int state = declaration::none, long result = declaration::fail) = 0;
    public:     inline explicit descriptor(type value);
    public:     inline descriptor(void);
    public:     inline ~descriptor(void) override;
    public:     descriptor(const interface::descriptor & o) = delete;
    public:     descriptor(interface::descriptor && o) noexcept = delete;
    public:     interface::descriptor & operator=(const interface::descriptor & o) = delete;
    public:     interface::descriptor & operator=(interface::descriptor && o) noexcept = delete;
    };

    inline void descriptor::stateOn(unsigned int state, long result, exception * e) {

    }

    inline descriptor::descriptor(type value) {

    }

    inline descriptor::descriptor(void) {

    }

    inline descriptor::~descriptor(void) {

    }

}

#include <pokemonism/sdk/interface/descriptor/event.hh>
#include <pokemonism/sdk/interface/descriptor/exception.hh>

#endif // __POKEMONISM_SDK_INTERFACE_DESCRIPTOR_HH__