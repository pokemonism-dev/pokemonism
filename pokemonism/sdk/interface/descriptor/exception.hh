/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 09, 2025
 */

#ifndef   __POKEMONISM_SDK_INTERFACE_DESCRIPTOR_EXCEPTION_HH__
#define   __POKEMONISM_SDK_INTERFACE_DESCRIPTOR_EXCEPTION_HH__

#include <pokemonism/sdk/exception.hh>

// ReSharper disable once CppUnusedIncludeDirective
#include <pokemonism/sdk/interface/descriptor.hh>

namespace pokemonism::sdk::interface {

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

}

#endif // __POKEMONISM_SDK_INTERFACE_DESCRIPTOR_EXCEPTION_HH__