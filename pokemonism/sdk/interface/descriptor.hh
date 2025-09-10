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

#include <pokemonism/sdk/exception.hh>
#include <pokemonism/sdk/synchronizable.hh>

namespace pokemonism::sdk::interface {

    class descriptor : public synchronizable {
    public:     typedef int type;
    public:     struct state {
                public:     struct type {
                            public:     constexpr static unsigned int open      = 0;
                            public:     constexpr static unsigned int in        = 1;
                            public:     constexpr static unsigned int out       = 2;
                            public:     constexpr static unsigned int exception = 3;
                            public:     constexpr static unsigned int close     = 4;
                            public:     constexpr static unsigned int max       = 5;
                            };
                public:     constexpr static unsigned int none      = (0x00000000U <<  0U);
                public:     constexpr static unsigned int open      = (0x00000001U <<  0U);
                public:     constexpr static unsigned int in        = (0x00000001U <<  1U);
                public:     constexpr static unsigned int out       = (0x00000001U <<  2U);
                public:     constexpr static unsigned int exception = (0x00000001U <<  3U);
                };
    public:     struct property {
                public:     constexpr static unsigned int none      = (0x00000000U <<  0U);
                public:     constexpr static unsigned int socket    = 1;
                public:     struct console {
                            public:     constexpr static unsigned int input  = 2;
                            public:     constexpr static unsigned int output = 3;
                            };
                };
    public:     class event;
    public:     class exception;
    protected:  int lock(void) noexcept override { return declaration::fail; }
    protected:  int unlock(void) noexcept override { return declaration::fail; }
    protected:  int wait(void) noexcept override { return declaration::fail; }
    protected:  int wakeup(void) noexcept override { return declaration::fail; }
    protected:  int wait(long second, long nano) noexcept override { return declaration::fail; }
    protected:  int wakeup(bool all) noexcept override { return declaration::fail; }
    public:     virtual int open(void);
    public:     virtual int close(void) = 0;
    protected:  virtual long read(void);
    protected:  virtual long read(unsigned char * storage, unsigned long capacity);
    protected:  virtual long write(void);
    protected:  virtual long write(const unsigned char * storage, unsigned long n);
    public:     virtual unsigned int check(unsigned int state) const = 0;
    protected:  virtual void clear(void);
    protected:  virtual void clean(void);
    protected:  virtual void reset(void);
    protected:  inline virtual void onState(unsigned int state, long result, descriptor::exception * e = nullptr);
    protected:  virtual void exceptionSet(descriptor::exception * e, unsigned int state = declaration::none, long result = declaration::fail) = 0;
    public:     inline explicit descriptor(type value);
    public:     inline descriptor(void);
    public:     inline ~descriptor(void) override;
    public:     descriptor(const interface::descriptor & o) = delete;
    public:     descriptor(interface::descriptor && o) noexcept = delete;
    public:     interface::descriptor & operator=(const interface::descriptor & o) = delete;
    public:     interface::descriptor & operator=(interface::descriptor && o) noexcept = delete;
    };

    inline void descriptor::clear(void) {

    }

    inline void descriptor::clean(void) {

    }

    inline void descriptor::reset(void) {

    }

    inline int descriptor::open(void) {
        pokemon_develop_throw(return declaration::fail);
    }

    inline long descriptor::read(void) {
        pokemon_develop_throw(return declaration::fail);
    }

    inline long descriptor::read(unsigned char * storage, unsigned long capacity) {
        pokemon_develop_throw(return declaration::fail);
    }

    inline long descriptor::write(void) {
        pokemon_develop_throw(return declaration::fail);
    }

    inline long descriptor::write(const unsigned char * storage, unsigned long n) {
        pokemon_develop_throw(return declaration::fail);
    }

    inline void descriptor::onState(unsigned int state, long result, exception * e) {

    }

    inline descriptor::descriptor(type value) {
        pokemon_develop_throw(return);
    }

    inline descriptor::descriptor(void) {

    }

    inline descriptor::~descriptor(void) {

    }

}

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/sdk/interface/descriptor/event.hh>
#include <pokemonism/sdk/interface/descriptor/exception.hh>

#endif // __POKEMONISM_SDK_INTERFACE_DESCRIPTOR_HH__