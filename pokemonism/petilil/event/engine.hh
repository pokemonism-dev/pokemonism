/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 05, 2025
 */

#ifndef   __POKEMONISM_PETILIL_ENGINE_HH__
#define   __POKEMONISM_PETILIL_ENGINE_HH__

#include <pokemonism/petilil.hh>

namespace pokemonism {

    class petilil::event::engine : public sync {
    protected:  template <typename type> static type * objectRel(type * o);
    public:     struct set {
                public:     petilil::commandable::generator * command;
                public:     inline set(void) : command(nullptr) {}
                public:     ~set(void);
                };
    protected:  petilil::event::engine::set generator;
    protected:  petilil::event::queue * queue;
    protected:  void (*cancel)(petilil::event::engine &);
    public:     virtual int on(void);
    public:     virtual int run(void);
    public:     inline engine(void) : queue(nullptr), cancel(nullptr) {}
    protected:  ~engine(void) override;
    public:     engine(const petilil::event::engine & o) = delete;
    public:     engine(petilil::event::engine && o) noexcept = delete;
    public:     petilil::event::engine & operator=(const petilil::event::engine & o) = delete;
    public:     petilil::event::engine & operator=(petilil::event::engine && o) noexcept = delete;
    };

    template <typename type>
    type * petilil::event::engine::objectRel(type * o) {
        if (o != nullptr) delete o;
        return nullptr;
    }

}

#endif // __POKEMONISM_PETILIL_ENGINE_HH__