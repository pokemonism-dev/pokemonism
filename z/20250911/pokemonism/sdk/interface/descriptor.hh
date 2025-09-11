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

#include <pokemonism/sdk/allocator.hh>
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
                public:     constexpr static unsigned int engine    = (0x00000001U << 31U);
                };
    public:     struct property {
                public:     constexpr static unsigned int none      = (0x00000000U <<  0U);
                public:     constexpr static unsigned int socket    = 1;
                public:     struct console {
                            public:     constexpr static unsigned int input  = 2;
                            public:     constexpr static unsigned int output = 3;
                            };
                public:     constexpr static unsigned int nonblock  = (0x00010000U <<  0U);
                };
    public:     class event;
    public:     class exception;
    protected:  unsigned int                status;
    protected:  unsigned int                properties;
    protected:  descriptor::exception *     e;
    protected:  int lock(void) noexcept override { return declaration::fail; }
    protected:  int unlock(void) noexcept override { return declaration::fail; }
    protected:  int wait(void) noexcept override { return declaration::fail; }
    protected:  int wakeup(void) noexcept override { return declaration::fail; }
    protected:  int wait(long second, long nano) noexcept override { return declaration::fail; }
    protected:  int wakeup(bool all) noexcept override { return declaration::fail; }
    public:     virtual int open(void);
    public:     inline virtual bool readable(void) const;
    public:     inline virtual bool writeable(void) const;
    public:     virtual int nonblockSet(void) = 0;
    public:     virtual int nonblockDel(void) = 0;
    protected:  inline virtual long read(void);
    protected:  inline virtual long read(unsigned char * storage, unsigned long capacity);
    protected:  inline virtual long write(void);
    protected:  inline virtual long write(const unsigned char * storage, unsigned long n);
    public:     virtual int close(void) = 0;
    public:     inline virtual void stateSet(unsigned int v);
    public:     inline virtual void stateDel(unsigned int v);
    public:     inline virtual unsigned int stateChk(unsigned int v) const;
    public:     inline virtual unsigned int propertyChk(unsigned int v) const;
    protected:  inline virtual void clear(void);
    protected:  inline virtual void clean(void);
    protected:  inline virtual void reset(void);
    protected:  inline virtual void onState(unsigned int state, long result, descriptor::exception * caution = nullptr);
    protected:  inline virtual void exceptionSet(descriptor::exception * caution, unsigned int state, long result);
    protected:  inline virtual void exceptionSet(descriptor::exception * caution);
    public:     inline explicit descriptor(unsigned int properties);
    public:     inline descriptor(void);
    public:     inline ~descriptor(void) override;
    public:     descriptor(const interface::descriptor & o) = delete;
    public:     descriptor(interface::descriptor && o) noexcept = delete;
    public:     interface::descriptor & operator=(const interface::descriptor & o) = delete;
    public:     interface::descriptor & operator=(interface::descriptor && o) noexcept = delete;
    };

    class descriptor::exception : public pokemonism::sdk::exception {
    public:     struct category {
                public:     constexpr static unsigned int none = declaration::none;
                public:     constexpr static unsigned int sys = 1;
                public:     constexpr static unsigned int lib = 2;
                public:     constexpr static unsigned int user = 3;
                };
    public:     struct code {
                public:     constexpr static unsigned int none = declaration::none;
                public:     constexpr static unsigned int eof = 1;
                public:     constexpr static unsigned int nil = 2;
                public:     struct invalid {
                            public:     constexpr static unsigned int parameter = 3;
                            };
                };
    protected:  unsigned int    tag;
    protected:  void *          func;
    protected:  unsigned int    number;
    public:     inline unsigned int categoryGet(void) const;
    public:     inline void * functionGet(void) const;
    public:     inline unsigned int numberGet(void) const;
    public:     inline exception(void);
    public:     exception(unsigned int category, void * func, unsigned int number);
    public:     ~exception(void) override;
    public:     exception(const descriptor::exception & o);
    public:     exception(descriptor::exception && o) noexcept;
    public:     descriptor::exception & operator=(const descriptor::exception & o);
    public:     descriptor::exception & operator=(descriptor::exception && o) noexcept;
    };

    inline unsigned int descriptor::exception::categoryGet(void) const {
        return tag;
    }

    inline void * descriptor::exception::functionGet(void) const {
        return func;
    }

    inline unsigned int descriptor::exception::numberGet(void) const {
        return number;
    }

    inline descriptor::exception::exception(void) : tag(declaration::none), func(nullptr), number(declaration::none) {

    }

    inline descriptor::exception::exception(unsigned int category, void * func, unsigned int number) : tag(category), func(func), number(number) {

    }

    inline descriptor::exception::~exception(void) {

    }

    inline descriptor::exception::exception(const descriptor::exception & o) : pokemonism::sdk::exception(o), tag(o.tag), func(o.func), number(o.number) {

    }

    inline descriptor::exception::exception(descriptor::exception && o) noexcept : pokemonism::sdk::exception(std::move(o)), tag(o.tag), func(o.func), number(o.number) {
        o.tag = declaration::none;
        o.func = nullptr;
        o.number = declaration::none;
    }


    inline descriptor::exception & descriptor::exception::operator=(const descriptor::exception & o) {
        if (pointof(o) != this) {
            pokemonism::sdk::exception::operator=(o);
            tag = o.tag;
            func = o.func;
            number = o.number;
        }
        return *this;
    }

    inline descriptor::exception & descriptor::exception::operator=(descriptor::exception && o) noexcept {
        if (pointof(o) != this) {
            pokemonism::sdk::exception::operator=(std::move(o));
            tag = o.tag;
            func = o.func;
            number = o.number;

            o.tag = declaration::none;
            o.func = nullptr;
            o.number = declaration::none;
        }
        return *this;
    }

    inline void descriptor::clear(void) {
        e = allocator::del(e);
        status = descriptor::state::none;
    }

    inline void descriptor::clean(void) {
        e = allocator::del(e);
    }

    inline void descriptor::reset(void) {
        e = allocator::del(e);
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

    inline void descriptor::stateSet(unsigned int v) {
        status = status | v;
    }

    inline void descriptor::stateDel(unsigned int v) {
        status = status & (~v);
    }

    inline unsigned int descriptor::stateChk(unsigned int v) const {
        return status & v;
    }

    inline unsigned int descriptor::propertyChk(unsigned int v) const {
        return properties & v;
    }

    inline void descriptor::onState(unsigned int state, long result, exception * caution) {

    }

    inline void descriptor::exceptionSet(descriptor::exception * caution, unsigned int state, long result) {
        if (e != nullptr) {
            onState(state, result, caution);
            delete caution;
            return;
        }

        e = caution;
        onState(state, result, caution);
    }

    inline void descriptor::exceptionSet(descriptor::exception * caution) {
        if (e != nullptr) {
            delete caution;
            return;
        }

        e = caution;
    }

    inline bool descriptor::readable(void) const {
        return false;
    }

    inline bool descriptor::writeable(void) const {
        return false;
    }

    inline descriptor::descriptor(unsigned int properties) : status(descriptor::state::none), properties(properties), e(nullptr) {

    }

    inline descriptor::descriptor(void) : status(descriptor::state::none), properties(descriptor::property::none), e(nullptr) {

    }

    inline descriptor::~descriptor(void) {

    }

}

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/sdk/interface/descriptor/event.hh>
#include <pokemonism/sdk/interface/descriptor/exception.hh>

#endif // __POKEMONISM_SDK_INTERFACE_DESCRIPTOR_HH__